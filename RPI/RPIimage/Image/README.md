## NetBSD RaspberryPi カスタムイメージ作成 仕様

この `Makefile` は、Raspberry Pi (RPI) 向けに NetBSD のカスタムイメージを作成・管理するためのものです。ディスクイメージの作成、パーティション設定、ベースシステムの展開、ファームウェアの更新、パッケージ管理のための設定、および各種クリーンアップ処理を自動化します。

### 1\. 主要変数

| 変数名                  | 値 (または用途)                                                             | 説明                                           |
| :------------------- | :-------------------------------------------------------------------- | :------------------------------------------- |
| **`ARCH`**           | `earmv6hf`                                                            | ターゲットとするアーキテクチャ (Raspberry Pi向け)             |
| **`PKG_PATH`**       | `http://cdn.netbsd.org/pub/NetBSD/misc/jun/raspberry-pi/${ARCH}/2025` | パッケージの参照先URL                                 |
| **`FILE`**           | \`\`date +%Y-%m-%d`-netbsd-raspi-${ARCH}.img`                         | 作成されるディスクイメージのファイル名                          |
| **`RPI`**            | `${BINARY}/gzimg/rpi.img`                                             | 元となるRPIイメージ (`.gz`ファイル) のパス                  |
| **`LIST`**           | `man modules xbase xcomp xetc xfont xserver`                          | イメージに展開するNetBSDのセット一覧                        |
| **`FIRM`**           | `LICENCE.broadcom bootcode.bin ... start_cd.elf`                      | `firm`ターゲットでコピーされるRaspberry Piファームウェアファイルの一覧 |
| **`MNT`**, **`VND`** | `/mnt`, `vnd0`                                                        | イメージのマウントポイントと仮想デバイス名                        |

### 2\. 主要ターゲット

| ターゲット名              | 実行内容の概要                                                                                                                                                                       |
| :------------------ | :---------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **`all`**           | **メインのビルドターゲット。** `file`、`rpi`、`extract`、`bwfm-firmware`、`firm` の順に実行し、RPI用NetBSDイメージを完成させる。                                                                                  |
| **`file`**          | `dd` コマンドを使用して、指定されたサイズ (`5160960` blocks) の空のディスクイメージファイル (`${FILE}`) を作成する。                                                                                                 |
| **`rpi`**           | 1\. 仮想デバイスとしてイメージをアタッチ (`vnconfig`)。2. `fdisk` および `disklabel` でパーティション（FFS/MSDOS）を設定。3. `newfs`/`newfs_msdos` でファイルシステムを作成。4. 元のRPIイメージ (`${RPI}.gz`) を展開し、新しいイメージに内容を復元する。  |
| **`extract`**       | 1\. イメージのパーティションをマウント。2. `${LIST}` で指定されたNetBSDのセットを `/` 以下に展開する。                                                                                                             |
| **`pkg`**           | 1\. イメージのFFSパーティションをマウント。2. `/etc/fstab` や `/etc/rc.conf` を編集し、`sshd=NO` などの設定を書き込む。ディスクリサイズ関連の設定も行う。                                                                         |
| **`pkg-back`**      | 1\. イメージのFFSパーティションをマウント。2. `../etc/rc.conf` をコピーし、pkginリポジトリ設定 (`repositories.conf`) に `${PKG_PATH}` を追加する。                                                                  |
| **`release`**       | 1\. イメージのパーティションをマウント。2. 親ディレクトリから `etc` および `root` の設定ファイルをコピーし、`/etc/pkg_install.conf` に `PKG_PATH` を設定する。                                                                  |
| **`firm`**          | 1\. イメージのMSDOS (`/boot`) パーティションをマウント。2. `${FIRMPATH}` から新しいRaspberry Piファームウェアファイル (`${FIRM}` のリスト) およびDevice Tree Blob (`.dtb`) ファイルを `/mnt` にコピーする。RPI02W向けの特定ファイルの上書きも行う。 |
| **`bwfm-firmware`** | 1\. イメージのFFSパーティションをマウント。2. Broadcom Wi-Fi (`bwfm`) 用のファームウェアファイルを所定のディレクトリ (`/libdata/firmware/if_bwfm/`) にコピーする。                                                            |
| **`logclean`**      | イメージのパーティションをマウントし、各種ログファイルや一時ファイルを削除してクリーンアップする。                                                                                                                             |
| **`kernel-update`** | `/boot` パーティションをマウントし、`kernel.img` および `kernel7.img` を更新する。                                                                                                                   |
| **`pkgsrc-update`** | イメージ内の `/usr/pkgsrc` を `cvs update` で更新する。                                                                                                                                    |
| **`fetch`**         | `./NewestISO` スクリプトを実行し、最新のISOファイルイメージを取得する。                                                                                                                                  |
| **`libssls`**       | `/usr/lib` 内で `libssl.so.12` から `libssl.so.11` へのシンボリックリンクを作成する。                                                                                                              |

-----

**注記:**

  * コメントアウトされた行（`#`で始まる行）は実行されません。
  * `vnconfig`, `fdisk`, `disklabel`, `newfs`, `mount`, `umount` などのコマンドは、NetBSD 環境でのディスクおよびファイルシステム管理に使用されます。

