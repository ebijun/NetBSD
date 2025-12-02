## NetBSD RaspberryPi カスタムイメージ作成 仕様

この `Makefile` は、NetBSD の日次ビルドバイナリと特定のパッケージソースを使用して、Raspberry Pi (RPI) 向けのブータブルイメージファイル（`.img`）を作成・更新するためのものです。主な機能は、ディスクパーティションの設定、ファイルシステムの作成、基本システムセットの展開、ファームウェアのコピー、カーネルの更新、およびパッケージ管理のための準備です。

## 1\. 環境設定・変数

| 変数名                     | 値/内容                                                                                                                                      | 説明                                                            |
| :---------------------- | :---------------------------------------------------------------------------------------------------------------------------------------- | :------------------------------------------------------------ |
| `ARCH`                  | `earmv7hf`                                                                                                                                | ターゲットとするアーキテクチャ。Raspberry Pi 向け ARMv7 ハードフロート環境。              |
| `BINARY`                | `nycdn.netbsd.org/pub/NetBSD-daily/HEAD/20251110022047Z/evbarm-earmv7hf/binary`                                                           | NetBSD のバイナリセットが置かれているリモートパス。                                 |
| `PKG_PATH`              | `http://cdn.netbsd.org/pub/NetBSD/misc/jun/raspberry-pi/${ARCH}/2025/`                                                                    | パッケージ管理システム（`pkgin`）が使用するパッケージリポジトリのパス。                       |
| `KERNELDIR`             | `RPI.${5}` (`${BINARY}/kernel/netbsd-RPI2.gz`から抽出)                                                                                        | カーネルが格納されているディレクトリ名。                                          |
| `PKGSRC`                | `../../../../pkgsrc/pkgsrc-2016Q1.tar.gz`                                                                                                 | パッケージソース（`pkgsrc`）のアーカイブファイルへの相対パス。                           |
| `FILE`                  | `日付-netbsd-armv7-${ARCH}.img`                                                                                                             | 最終的に作成されるイメージファイル名。例: `2025-12-02-netbsd-armv7-earmv7hf.img`。 |
| `FILE_TMP`              | `a.img`                                                                                                                                   | 一時的な作業用イメージファイル名。                                             |
| `SETS`                  | `${BINARY}/sets`                                                                                                                          | 基本システムセット（`.tgz`ファイル）が置かれているディレクトリ。                           |
| `RPI`                   | `${BINARY}/gzimg/armv7.img`                                                                                                               | 既存の RPI ベースイメージのパス。                                           |
| `LIST`                  | `man modules xbase xcomp xetc xfont xserver`                                                                                              | 初期展開されるシステムセットのリスト。                                           |
| `LIST_UPDATE`           | `base base32 comp debug debug32 dtb games gpufw kern-GENERIC man manhtml modules rescue tests text xbase xetc xcomp xdebug xfont xserver` | 更新時に使用されるシステムセットのリスト（`image-update`ターゲットで使用）。                 |
| `FIRM`                  | `LICENCE.broadcom bootcode.bin ... start_x.elf` (複数のファイル名)                                                                                | Raspberry Pi 用のブートファームウェアファイル群。                               |
| `FIRMPATH`              | `/usr/local/NetBSD/RPI/Firmware/firmware/boot`                                                                                            | ファームウェアファイルがローカルに格納されているパス。                                   |
| `MNT`/`VND`             | `/mnt`, `vnd0`                                                                                                                            | FFS (ルート) パーティションのマウントポイントと仮想ネットワークデバイス名。                     |
| `MNT_CDROM`/`VND_CDROM` | `/mnt1`, `vnd1`                                                                                                                           | CD-ROM イメージまたは別のマウントポイントとデバイス名 (このMakefileでは未使用)。             |
| `MNT_TMP`/`VND_TMP`     | `/mnt2`, `vnd2`                                                                                                                           | 一時的なマウントポイントとデバイス名。                                           |

## 2\. ターゲット

| ターゲット名          | 実行内容                                                                           | 処理の概要                                                                                                                                                     |
| :-------------- | :----------------------------------------------------------------------------- | :-------------------------------------------------------------------------------------------------------------------------------------------------------- |
| `all`           | `file rpi extract bwfm-firmware firm`                                          | イメージファイルの作成、パーティション設定、既存イメージからの復元、システムセット展開、Wi-FiファームウェアとRPIファームウェアのコピーを含む、フルビルド/セットアップを実行するメインターゲット。                                                     |
| `file`          | `dd if=/dev/zero...`                                                           | サイズ 5160960\*512 バイト（約 2.5GB）の空のイメージファイル（`${FILE}`）を作成する。                                                                                                 |
| `rpi`           | `vnconfig`, `fdisk`, `disklabel`, `newfs`, `gunzip`, `dump`/`restore`, `mount` | イメージファイルにディスクラベルを設定し、FFS (`a`パーティション) と MSDOS (`e`パーティション) のファイルシステムを作成する。次に、元の RPI イメージ (`${RPI}.gz`) を展開し、その内容を新しく作成したパーティションに `dump`/`restore` でコピーする。 |
| `extract`       | `vnconfig`, `mount`, `tar xzpf...`, `umount`                                   | イメージファイルのマウントポイント (`${MNT}`) に、`${LIST}` で指定された基本システムセット（`.tgz`）をリモートパスから展開する。                                                                            |
| `pkg`           | `vnconfig`, `mount`, `sed`, `echo...`, `umount`                                | イメージ内の `/etc/fstab` から `log` オプションを削除し、`/etc/rc.conf` に `sshd=NO`, `syslogd=NO` などの設定を追記し、システムの自動起動サービスを停止させる。                                            |
| `pkg-back`      | `vnconfig`, `mount`, `cp`, `echo...`, `umount`                                 | `/etc/rc.conf` を元のファイルに戻し、`pkgin` のリポジトリ設定 (`${PKG_PATH}`) を追記する。                                                                                         |
| `release`       | `vnconfig`, `mount`, `tar cf...`, `echo...`, `umount`                          | `etc` や `root` の設定ファイル群をイメージにコピーし、`PKG_PATH` を `/etc/pkg_install.conf` に設定する。                                                                             |
| `logclean`      | `vnconfig`, `mount`, `rm -f`, `touch`, `chgrp`, `rm -rf`, `umount`             | イメージ内の各種ログファイル（`dmesg.boot`, `lastlogx`, `wtmpx`, `wtmp`, `dhcpcd-*.lease` など）を削除または初期化する。                                                                |
| `firm`          | `vnconfig`, `mount_msdos`, `cp`, `umount`                                      | Raspberry Pi のファームウェアファイル（`${FIRM}`）を、MSDOS パーティション (`/dev/${VND}e`) にマウントした `/boot` ディレクトリにコピーする。また、dtb ファイルもコピーする。                                      |
| `kernel-update` | `vnconfig`, `mount`, `mv`, `cp`, `umount`                                      | MSDOS パーティションにマウントされた `/boot` 内のカーネルファイル (`kernel7.img`) をバックアップし、指定された新しいカーネルファイル (`netbsd77.img`) に置き換える。                                               |
| `bwfm-firmware` | `vnconfig`, `mount`, `mkdir -p`, `cp -p`, `umount`                             | Broadcom Wi-Fi モジュール（`bwfm`）用のファームウェアファイルを、イメージ内の `/libdata/firmware/if_bwfm/` ディレクトリにコピーする。                                                              |

| `fetch` | `./NewestISO \|tee Fetch`, `sh Fetch`, `rm Fetch` | `NewestISO` スクリプトを実行し、最新の ISO イメージまたはバイナリを取得する（具体的な手順は外部スクリプトに依存）。 |
|---|---|---|---|
| `mikutter-key` | `vnconfig`, `mount`, `patch`, `umount` | `mikutter` プラグインの設定ファイルをパッチで更新し、キー情報を設定する。 |
| `image-update` | `@echo mount /dev/sd0a /mnt`, `@for i in...` | イメージを `/dev/sd0a` にマウントし、`${LIST_UPDATE}` で指定された基本システムセットと GENERIC カーネルをコピーする手順を出力する（実際の実行はコメントアウトされており、手動での実行を促す意図がある）。 |

## 3\. 使用される主なコマンドとツール

  * **`vnconfig`**: 仮想ネットワークデバイス（`vnd`）を設定し、イメージファイルをデバイスとして扱えるようにする。
  * **`fdisk`**: ディスクのパーティションテーブルを操作（NetBSD/MBR の設定）。
  * **`disklabel`**: NetBSD のディスクラベルを設定。
  * **`newfs` / `newfs_msdos`**: FFS (NetBSD のファイルシステム) および FAT/MSDOS (ブートパーティション) のファイルシステムを作成。
  * **`mount` / `mount_msdos` / `umount`**: ファイルシステムをマウント/アンマウント。
  * **`tar`**: システムセット（`.tgz`）の展開や設定ファイルのアーカイブ/展開に使用。
  * **`dd`**: イメージファイルの作成。
  * **`dump` / `restore`**: 既存のファイルシステムの内容を新しいファイルシステムに効率よくコピーするために使用。
  * **`cp`**: ファームウェアや設定ファイルのコピー。
  * **`sed` / `echo`**: 設定ファイルの編集。

