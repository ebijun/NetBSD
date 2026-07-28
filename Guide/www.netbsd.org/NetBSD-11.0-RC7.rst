NetBSD 11.0 RC7 リリースのお知らせ (2026年7月21日)
==================================================

急ぎの方へのクイックリンク
---------------------------------

CDNからNetBSD 11.0 RC7をダウンロードできます:

* `amd64 USB <https://cdn.NetBSD.org/pub/NetBSD/NetBSD-11.0_RC7/images/NetBSD-11.0_RC7-amd64-install.img.gz>`_
* `amd64 DVD <https://cdn.NetBSD.org/pub/NetBSD/NetBSD-11.0_RC7/images/NetBSD-11.0_RC7-amd64-dvd.iso>`_
* `i386 USB <https://cdn.NetBSD.org/pub/NetBSD/NetBSD-11.0_RC7/images/NetBSD-11.0_RC7-i386-install.img.gz>`_
* `i386 CD-ROM <https://cdn.NetBSD.org/pub/NetBSD/NetBSD-11.0_RC7/images/NetBSD-11.0_RC7-i386.iso>`_
* `sparc64 DVD <https://cdn.NetBSD.org/pub/NetBSD/NetBSD-11.0_RC7/images/NetBSD-11.0_RC7-sparc64-dvd.iso>`_
* `sparc64 CD-ROM <https://cdn.NetBSD.org/pub/NetBSD/NetBSD-11.0_RC7/images/NetBSD-11.0_RC7-sparc64.iso>`_
* `macppc CD-ROM <https://cdn.NetBSD.org/pub/NetBSD/NetBSD-11.0_RC7/images/NetBSD-11.0_RC7-macppc.iso>`_
* `RISC-V デバイス <https://cdn.NetBSD.org/pub/NetBSD/NetBSD-11.0_RC7/riscv-riscv64/binary/gzimg/riscv64.img.gz>`_
* `Cavium Octeon MIPS デバイス <https://cdn.NetBSD.org/pub/NetBSD/NetBSD-11.0_RC7/evbmips-mips64eb/binary/gzimg/octeon.img.gz>`_
* `Nintendo Wii <https://cdn.NetBSD.org/pub/NetBSD/NetBSD-11.0_RC7/evbppc/binary/gzimg/wii.img.gz>`_
* `各種 Arm デバイス <https://armbsd.org/>`_
* `その他のフルリリースディレクトリ <https://cdn.NetBSD.org/pub/NetBSD/NetBSD-11.0_RC7/>`_

配布物に含まれるすべてのファイルのハッシュ値は、`NetBSDセキュリティ担当者のPGP鍵 <https://cdn.NetBSD.org/pub/NetBSD/security/PGP/security-officer@netbsd.org.asc>`_ で署名されており、`こちら <https://cdn.NetBSD.org/pub/NetBSD/security/hashes/NetBSD-11.0_RC7_hashes.asc>`_ から入手可能です。

はじめに
-----------

NetBSDプロジェクトは、NetBSDオペレーティングシステムの19番目のメジャーリリースとなる第7リリース候補、NetBSD 11.0 RC7を発表します。

アップグレード手順
-------------------

既存のインストール環境は、インストールイメージで起動し、「Upgrade」オプションを選択することでアップグレード可能です。他の更新方法を使用している場合は、まずカーネルとモジュールを更新し、再起動してからユーザランドを更新してください。パッケージリポジトリのURLを調整し、すべてのサードパーティ製パッケージを更新する必要があります。また、`sysinst(8) <https://man.NetBSD.org/NetBSD-11.0/sysinst.8>`_ を使用して別途インストールが必要になる可能性のある、新しい「セット」が追加されている点にも注意してください。以前のリリースからアップグレードする場合は、「非互換の変更」に特に注意してください。

NetBSD 10.1 からの変更点
-----------------------------

ハイライト
~~~~~~~~~~~

* RISC-V プロセッサアーキテクチャへの新規ポート。NetBSD 11.0 は、64ビット RISC-V プラットフォームをサポートする初の安定版リリースです。VisionFive 2、PINE64 STAR64 などの StarFive JH71XX ベースのデバイスや、QEMU が含まれます。
* POSIX.1-2024 および C23 プログラミングインターフェース標準への準拠を強化。
* `compat_linux(8) <https://man.NetBSD.org/NetBSD-11.0/compat_linux.8>`_ におけるLinuxシステムコールのサポートを強化。epoll (kqueueで実装)、POSIXメッセージキュー、statx、readahead、close_range、waitid、renameat2、clone3、sync_file_range、syncfs、inotifyなどに対応。
* Qualcomm Snapdragon X Elite プラットフォームへの初期サポート。
* `npf(7) <https://man.NetBSD.org/NetBSD-11.0/npf.7>`_ ファイアウォールの改善（レイヤー2およびユーザー/グループフィルタリングを含む）。
* x86向けに新しいMICROVMカーネルを追加。i386とamd64の両方をサポート。PVHブート、VirtIO MMIO、および複数のカーネル最適化を活用し、極めて高速な仮想マシンブートを実現するように設計されており、2020年頃のx86 CPU上で約10ミリ秒でブート可能です。
* 新しい virt68k ポート。パラバーチャライズドデバイスを使用してQEMU上でMotorola 68000ポートを実行可能。

ポート
~~~~~~~

* Arm ハードウェアのサポート改善:
    * aarch64 - Qualcomm Oryon CPUへの初期サポート。
    * aarch64 - Qualcomm Snapdragon X Elite のバッテリー＆充電器センサー、GPIO、I2Cコントローラのサポート追加。
    * aarch64 - Advanced SIMDによるX.Org最適化を有効化。
    * evbarm - ACPIベースシステム向けのNUMA認識を追加。
    * evbarm - Arm SCMIパフォーマンスプロトコルサポートを追加。
    * evbarm - Amlogic Meson I2Cコントローラ用ドライバを追加。
    * evbarm - Libre Computer AML-S905X-CC のUSBコントローラをサポート。
    * evbarm - Rockchip USB-C PHY用ドライバを追加。
    * evbarm - NanoPi R4S のサポート改善。
    * evbarm - UEFIブート時のRaspberry Pi 5周辺機器のサポート改善。
    * evbarm - Allwinnerデバイス向けにDRM/KMSアトミックモードセッティングを実装。

* x86 ハードウェアのサポート改善:
    * amd64 - 一部のHP製ノートPCで見られるAMD GPIO用の `amdgpio(4) <https://man.NetBSD.org/NetBSD-11.0/amdgpio.4>`_ デバイスドライバを追加。
    * amd64 - Siena, Turin Classic, Turin Dense, Strix Point, Zen 5 CPU上の温度センサーサポートを追加。
    * x86 - `pv(4) <https://man.NetBSD.org/NetBSD-11.0/pv.4>`_ 擬似バスを介したカーネルコマンドラインパラメータによるMMIOデバイス検出を介したVirtIOサポート。
    * x86 - `pci(4) <https://man.NetBSD.org/NetBSD-11.0/pci.4>`_ のような既知のバスに接続されないすべてのパラバーチャライズドデバイスに対して、`pv(4) <https://man.NetBSD.org/NetBSD-11.0/pv.4>`_ 擬似バスサポートを追加。
    * x86 - 非Xen PVHブート（例: QEMU -kernel オプション）のサポートを追加。
    * x86 - 新しいIntel TCOウォッチドッグタイマーのサポートを `tco(4) <https://man.NetBSD.org/NetBSD-11.0/tco.4>`_ に追加。
    * x86 - 対応システムでの充電動作を制御する `thinkpad(4) <https://man.NetBSD.org/NetBSD-11.0/thinkpad.4>`_ sysctlインターフェースを公開。

* RISC-V アーキテクチャへの新規ポート:
    * riscv - QEMUへの初期サポート（Google Goldfish RTC、VirtIO（ネットワーク、ディスク等）デバイス、仮想オーディオを含む）。
    * riscv - Allwinner D1 SoC（MangoPi MQ Pro、Allwinner Nezha等で使用）の初期基本サポート。GPIOおよびUARTシリアルコンソールを含む。
    * riscv - StarFive JH7110 SoC（VisionFive 2、STAR64等で使用）をサポート。PCI/PCIe、TRNG、ピン、温度センサーなどを含む。
    * riscv - `crash(8) <https://man.NetBSD.org/NetBSD-11.0/crash.8>`_ カーネルデバッガをサポート。

* ヴィンテージハードウェアおよびその他のサポート改善:
    * alpha - Secure PLT ELFバイナリのサポートを追加。
    * evbppc - Nintendo Wii DVDドライブ、`bwi(4) <https://man.NetBSD.org/NetBSD-11.0/bwi.4>`_ WLAN、USB Geckoシリアルコンソール、ハードウェアAESエンジン（ディスク暗号化とWi-Fiを高速化）、スタンドアローンブートローダーのサポートを追加。
    * evbppc - WiiにおけるX.Orgパフォーマンスと色再現性の向上。GX RGBからYUY2へのビデオ変換加速を含む。
    * hp300 - 362および382向けの `sti(4) <https://man.NetBSD.org/NetBSD-11.0/sti.4>`_ フレームバッファサポートを追加。X.Orgサーバーがこれらのマシンで動作可能に。
    * hppa - HP Visualize FXビデオカード向けの新しい summitfb(4) ドライバ。
    * hppa - HP HCRXビデオカード向けの新しい hyperfb(4) ドライバ。
    * hppa - HP NGLEファミリーグラフィックスデバイス向けの新しい専用X.Orgドライバ。Visualize EGでのアクセラレーションをサポート。
    * m68k - 浮動小数点エミュレーションの改善。
    * mac68k - PowerBook 1xxシリーズのサポート改善（バックライト制御を含む）、新しい pbbat(4) バッテリードライバ。
    * macppc - G5/G4 I2C/OpenPICのサポート改善。
    * macppc - PowerMac7,2のファン制御を有効化。
    * macppc - PaX MPROTECTおよびASLRセキュリティ軽減機能をデフォルトで有効化。
    * mips - スタック破壊保護（Stack-smashing protector）をデフォルトで有効化。mips64ではRELRO軽減を有効化。
    * x68k - フレームバッファコンソールにSixelグラフィックスシーケンスサポートを追加。

カーネル
~~~~~~~~~~

* 様々なパフォーマンス向上:
    * 最適化: 各種ポートでソフト割り込みをトリガーする際の不要なメモリバリアを省略。
    * 最適化: vdrain カーネルスレッドを2つのスレッドプールジョブに置換。
    * 最適化: SPARC、PowerPC、MIPSにおけるバイトスワップ（特にAdiantumディスク暗号化用）のパフォーマンス向上。
    * `pipe(2) <https://man.NetBSD.org/NetBSD-11.0/pipe.2>`_ - パフォーマンス向上、ロック競合の削減。
    * `drum(4) <https://man.NetBSD.org/NetBSD-11.0/drum.4>`_ - サブシステムをMPSAFE化し、複数CPUでスケールするように。
    * netinet - RFC 6298で許可されている通り、初期RTO（再送タイムアウト）を3秒から1秒に短縮。
    * zfs - rm/unlinkのパフォーマンス向上。
* `npf(7) <https://man.NetBSD.org/NetBSD-11.0/npf.7>`_ ファイアウォールの改善:
    * レイヤー2フィルタリングサポートを追加。
    * ユーザー/グループベースのフィルタリングサポートを追加。
* その他の機能強化:
    * カーネル - O_CLOFORK実装を追加。
    * procfs - Linux互換性のためにsysvipcおよびself/limitsのサポートを追加。
    * zfs - Xenで使用されるzvolのDIOCCACHESYNCを実装。
    * `clock_getres(2) <https://man.NetBSD.org/NetBSD-11.0/clock_getres.2>`_ - CLOCK_PROCESS_CPUTIME_ID および CLOCK_THREAD_CPUTIME_ID をサポート。
    * `memfd_create(2) <https://man.NetBSD.org/NetBSD-11.0/memfd_create.2>`_ - 同名のLinuxシステムコールと互換性のある新しいシステムコール。
    * `ddb(4) <https://man.NetBSD.org/NetBSD-11.0/ddb.4>`_ - カーネル内デバッガにシンプルな表示コマンド（condvar, selinfo, sleepq）を追加。
    * `dk(4) <https://man.NetBSD.org/NetBSD-11.0/dk.4>`_ - Atari TOSパーティションをディスクウェッジとして検出するサポートを追加。
    * `nvmm(4) <https://man.NetBSD.org/NetBSD-11.0/nvmm.4>`_ - CPUIDにおけるVMware互換のTSCおよびLAPIC周波数検出を実装。
    * `wscons(4) <https://man.NetBSD.org/NetBSD-11.0/wscons.4>`_ - VT100エミュレーションに明るさとxterm形式の256色エスケープコードのサポートを追加。
    * `wscons(4) <https://man.NetBSD.org/NetBSD-11.0/wscons.4>`_ - 現在のフォント情報を取得するための WSDISPLAYIO_GFONT ioctl を追加。
    * `heartbeat(9) <https://man.NetBSD.org/NetBSD-11.0/heartbeat.9>`_ - カーネルの進捗を確認する新しいメカニズム。ハード割り込みを使用して低優先度ソフト割り込みの進捗を確認し、1つのCPUを使って別のCPUの進捗を確認する。

マシン独立デバイスドライバ
~~~~~~~~~~~~~~~~~~~~~~~~~~~

* 新しいマシン独立ドライバ:
    * `apei(4) <https://man.NetBSD.org/NetBSD-11.0/apei.4>`_ - ACPI Platform Error Interfaces用の新しいドライバ。
    * `ds2482ow(4) <https://man.NetBSD.org/NetBSD-11.0/ds2482ow.4>`_ - Maxim DS2482-100およびDS2482-800 I2C to 1-Wireブリッジチップ用ドライバ。
    * `ds28e17iic(4) <https://man.NetBSD.org/NetBSD-11.0/ds28e17iic.4>`_ - DS28E17 1-Wire to I2Cブリッジチップ用ドライバ。
    * `dse(4) <https://man.NetBSD.org/NetBSD-11.0/dse.4>`_ - DaynaPORT SCSI/Link Ethernetデバイス用ドライバ。
    * `emcfan(4) <https://man.NetBSD.org/NetBSD-11.0/emcfan.4>`_ - Microchip Technology / SMSC EMC210XおよびEMC230Xファンコントローラ用ドライバ。
    * `gftty(4) <https://man.NetBSD.org/NetBSD-11.0/gftty.4>`, `gfpic(4) <https://man.NetBSD.org/NetBSD-11.0/gfpic.4>` - "Goldfish" 仮想ハードウェアプラットフォーム用ドライバ。
    * `gscan(4) <https://man.NetBSD.org/NetBSD-11.0/gscan.4>`_ - USB to CANバスアダプタ用ドライバ。
    * `ikbd(4) <https://man.NetBSD.org/NetBSD-11.0/ikbd.4>`_ - i2c HIDキーボードデバイス用ドライバ（一部のノートPCなど）。
    * `ncm(4) <https://man.NetBSD.org/NetBSD-11.0/ncm.4>`_ - USB Network Control Model用ドライバ（新しいAndroidのUSBテザリングで使用）。
    * `pvscsi(4) <https://man.NetBSD.org/NetBSD-11.0/pvscsi.4>`_ - VMware準仮想化SCSIコントローラ用ドライバ。
    * `umcpmio(4) <https://man.NetBSD.org/NetBSD-11.0/umcpmio.4>`_ - MCP-2221 / 2221A マルチIOチップ用ドライバ。
    * `viogpu(4) <https://man.NetBSD.org/NetBSD-11.0/viogpu.4>`_ - QEMU仮想GPU用ドライバ。

* マシン独立ドライバの強化:
    * `aac(4) <https://man.NetBSD.org/NetBSD-11.0/aac.4>`_ - Adaptec RAID 5445, 5805, 5085をサポート。
    * `awge(4) <https://man.NetBSD.org/NetBSD-11.0/evbarm/awge.4>`_ - NET_MPSAFEカーネルオプションによるきめ細かなロック処理を改善。
    * `axen(4) <https://man.NetBSD.org/NetBSD-11.0/axen.4>`_ - ASIX AX88179A USB Ethernetをサポート。
    * `bwi(4) <https://man.NetBSD.org/NetBSD-11.0/bwi.4>`_ - 不要な遅延を削除。
    * `igc(4) <https://man.NetBSD.org/NetBSD-11.0/igc.4>`_ - TCP Segmentation Offload (TSO) をサポート。
    * `lm(4) <https://man.NetBSD.org/NetBSD-11.0/lm.4>`_ - NCT6794Dの5つの補助ファンセンサーをサポート。
    * `mcx(4) <https://man.NetBSD.org/NetBSD-11.0/mcx.4>`_ - NVIDIA Mellanox ConnectX-6仮想関数をサポート。
    * `pms(4) <https://man.NetBSD.org/NetBSD-11.0/pms.4>`_ - PS/2マウスのホットプラグをサポート。
    * `puc(4) <https://man.NetBSD.org/NetBSD-11.0/puc.4>`_ - BrainboxesおよびOxford Semiconductor PCIシリアルカードをサポート。
    * `rge(4) <https://man.NetBSD.org/NetBSD-11.0/rge.4>`_ - Realtek RTL8126 5Gbps Ethernetをサポート。
    * `u3g(4) <https://man.NetBSD.org/NetBSD-11.0/u3g.4>`_ - Sierra Wireless MC7304 LTEモデムをサポート。
    * `uaudio(4) <https://man.NetBSD.org/NetBSD-11.0/uaudio.4>`_ - USB Audio Class 2.0互換デバイスをサポート。
    * `udl(4) <https://man.NetBSD.org/NetBSD-11.0/udl.4>`_ - SANWA SUPPLY 500-KC002N USB to VGAアダプタをサポート。
    * `uftdi(4) <https://man.NetBSD.org/NetBSD-11.0/uftdi.4>`_ - 「マッチクワーク（match quirk）」メカニズムを追加。個別のインターフェースを選択的に拒否し、`ugen(4) <https://man.NetBSD.org/NetBSD-11.0/ugen.4>`_ でマッチさせてlibusb経由でアクセス可能に。
    * `urndis(4) <https://man.NetBSD.org/NetBSD-11.0/urndis.4>`_ - 追加のデバイスタイプをマッチング。
    * `urtwn(4) <https://man.NetBSD.org/NetBSD-11.0/urtwn.4>`_ - Asus USB-N10 Nano B1 Wi-Fiアダプタをサポート。
    * `viaide(4) <https://man.NetBSD.org/NetBSD-11.0/viaide.4>`_ - VIA IDE/PATA/SATAコントローラのサポート改善（特にRAIDモード）。
    * `virtio(4) <https://man.NetBSD.org/NetBSD-11.0/virtio.4>`_ - VirtIOドライバをMPSAFEとしてマークし、ビッグカーネルロックを保持しないように変更。

ユーザランド
~~~~~~~~~~~~~~~

* build.sh - 新しいターゲット `pkg=CATEGORY/PACKAGE` を追加。pkgsrcからCATEGORY/PACKAGEをクロスビルドし、pkgsrcをブートストラップする。
* libc - stdio FILEハンドル経由の書き込みパフォーマンスを改善。
* libc - `ffsl(3) <https://man.NetBSD.org/NetBSD-11.0/ffsl.3>`, `ffsll(3) <https://man.NetBSD.org/NetBSD-11.0/ffsll.3>`, `mempcpy(3) <https://man.NetBSD.org/NetBSD-11.0/mempcpy.3>`, `wmempcpy(3) <https://man.NetBSD.org/NetBSD-11.0/wmempcpy.3>`, `heapsort_r(3) <https://man.NetBSD.org/NetBSD-11.0/heapsort_r.3>`, `mergesort_r(3) <https://man.NetBSD.org/NetBSD-11.0/mergesort_r.3>`, `qsort_r(3) <https://man.NetBSD.org/NetBSD-11.0/qsort_r.3>`, `c8rtomb(3) <https://man.NetBSD.org/NetBSD-11.0/c8rtomb.3>`, `mbrtoc8(3) <https://man.NetBSD.org/NetBSD-11.0/mbrtoc8.3>`, `timespec_getres(3) <https://man.NetBSD.org/NetBSD-11.0/timespec_getres.3>` 関数を追加。
* libm - 関数のlong doubleバリエーションを追加。テストを拡充。
* libpthread - POSIX.1-2024のキャンセルポイントの監査と不足分を追加。
* `aiomixer(1) <https://man.NetBSD.org/NetBSD-11.0/aiomixer.1>` - 環境変数 `NO_COLOR` を設定して色の使用を無効化する非公式標準をサポート。
* `c17(1) <https://man.NetBSD.org/NetBSD-11.0/c17.1>` - POSIX.1-2024で要求されるISO 2017 Cコンパイラ用ラッパースクリプト。
* `calendar(1) <https://man.NetBSD.org/NetBSD-11.0/calendar.1>` - 2026年の移動祝日を更新。
* `crunchgen(1) <https://man.NetBSD.org/NetBSD-11.0/crunchgen.1>` - ライブラリディレクトリを設定する `-L` オプションを尊重。
* `cut(1) <https://man.NetBSD.org/NetBSD-11.0/cut.1>` - `-b` オプション使用時にマルチバイト文字を分割しない `-n` オプションを追加。
* `date(1) <https://man.NetBSD.org/NetBSD-11.0/date.1>` - GNU dateと同様に、時刻をRFC 5322形式で表示する `-R` オプションを追加。
* `df(1) <https://man.NetBSD.org/NetBSD-11.0/df.1>` - `-M` (マウントされていない引数を無視) および `-q` (警告を抑制) オプションを追加。
* `ftp(1) <https://man.NetBSD.org/NetBSD-11.0/ftp.1>` - パフォーマンス向上のためソケットバッファ処理を簡略化。
* `gzip(1) <https://man.NetBSD.org/NetBSD-11.0/gzip.1>` - GNU互換のための `--ascii` および `--license` オプションを追加。
* `install(1) <https://man.NetBSD.org/NetBSD-11.0/install.1>` - `-v` (冗長出力) オプションを追加。
* `lint(1) <https://man.NetBSD.org/NetBSD-11.0/lint.1>` - C23コードのチェックをサポート。より多くの整数オーバーフローを検出。
* `make(1) <https://man.NetBSD.org/NetBSD-11.0/make.1>` - includeガードの認識や `:M` および `:N` パターンマッチングの改善など、各種パフォーマンス向上。
* `man(1) <https://man.NetBSD.org/NetBSD-11.0/man.1>` - ローカルパスを読み込む `-l` フラグを追加。
* `patch(1) <https://man.NetBSD.org/NetBSD-11.0/patch.1>` - GNU patch互換のための `--backup-if-mismatch` および `--no-backup-if-mismatch` を追加。
* `patch(1) <https://man.NetBSD.org/NetBSD-11.0/patch.1>` - INT16_MAX を超える長さの行を処理可能に。
* `pkill(1) <https://man.NetBSD.org/NetBSD-11.0/pkill.1>` - pidfileを使用する `-F` オプション、ロックを確認する `-L` オプションを追加。
* `printf(1) <https://man.NetBSD.org/NetBSD-11.0/printf.1>` - 変換の無効な値に対する検出と診断を改善。`%C` フォーマット変換を追加。long doubleを使用する `-L` オプションを追加。
* `sh(1) <https://man.NetBSD.org/NetBSD-11.0/sh.1>` - POSIX Issue 8要件に準拠するようチルダ展開を調整。シェル入力のNUL文字を拒否。バージョン情報を表示する `-r` オプションを追加。read組み込みコマンドに `-b` および `-nMAX` オプションを追加。`csh(1) <https://man.NetBSD.org/NetBSD-11.0/csh.1>` 組み込みコマンドと同様に `suspend` を実装。`HISTFILE` および `HISTAPPEND` 変数を実装。
* `stat(1) <https://man.NetBSD.org/NetBSD-11.0/stat.1>` - シンボリックフラグの表示機能を追加。
* `touch(1) <https://man.NetBSD.org/NetBSD-11.0/touch.1>` - `-d`, `-R`, `-D` オプションを追加。
* `videoctl(1) <https://man.NetBSD.org/NetBSD-11.0/videoctl.1>` - フレームサイズの列挙を改善。
* `curses(3) <https://man.NetBSD.org/NetBSD-11.0/curses.3>` - ncurses拡張 `wgetscrreg(3) <https://man.NetBSD.org/NetBSD-11.0/wgetscrreg.3>` を実装（指定ウィンドウのスクロール領域を返す）。
* `proplib(3) <https://man.NetBSD.org/NetBSD-11.0/proplib.3>` - JSONシリアライズ形式のサポートを追加。
* `cribbage(6) <https://man.NetBSD.org/NetBSD-11.0/cribbage.6>` - 問い合わせなしでプレイを継続する `-y` オプションを追加。
* `tetris(6) <https://man.NetBSD.org/NetBSD-11.0/tetris.6>` - 環境変数 `NO_COLOR` を設定して色の使用を無効化する非公式標準をサポート。
* `worms(6) <https://man.NetBSD.org/NetBSD-11.0/worms.6>` - 色付きで表示する `-C` オプション、ワームの頭のバリエーションを増やす `-H` オプションを追加。
* `blocklistd(8) <https://man.NetBSD.org/NetBSD-11.0/blocklistd.8>` - `/etc/blocklistd.conf.d` のような設定ディレクトリ内の複数の設定ファイルをサポート。
* `chown(8) <https://man.NetBSD.org/NetBSD-11.0/chown.8>` - 現在の値と同一のオーナー/グループへの変更を回避する `-d` フラグを追加。
* `cpuctl(8) <https://man.NetBSD.org/NetBSD-11.0/cpuctl.8>` - Intel Meteor LakeおよびEmerald Rapids CPUを認識。
* `dkctl(8) <https://man.NetBSD.org/NetBSD-11.0/dkctl.8>` - 新しい `getgeometry` コマンドを追加。
* `envstat(8) <https://man.NetBSD.org/NetBSD-11.0/envstat.8>` - JSON出力をサポート。
* `gpt(8) <https://man.NetBSD.org/NetBSD-11.0/gpt.8>` - GUID管理への追加機能。開始位置/サイズを16進数で表示するオプション。
* `iostat(8) <https://man.NetBSD.org/NetBSD-11.0/iostat.8>` - `-X` オプションを追加。`-D` に似ているが、xfers/s をスキップし KB/s ではなく MB/s で報告。デフォルトで行あたりの表示デバイス数を約50%増加可能に。
* `makefs(8) <https://man.NetBSD.org/NetBSD-11.0/makefs.8>` - cd9660ファイルシステムを `-m` でサイズ制限可能に。互換性のあるブートROM用に version=0 4.3BSD FFS ファイルシステムの作成を許可。
* `mount_cd9660(8) <https://man.NetBSD.org/NetBSD-11.0/mount_cd9660.8>` - `mask`, `dirmask`, `uid`, `gid` マウントオプションをサポート。
* `scsictl(8) <https://man.NetBSD.org/NetBSD-11.0/scsictl.8>` - デバイスを識別する Vital Product Data を報告する `identify vpd` を追加。
* `syslogd(8) <https://man.NetBSD.org/NetBSD-11.0/syslogd.8>` - リモートメッセージの "kern" から "user" への変換を無効にする `-k` オプションを追加。

非互換の変更
~~~~~~~~~~~~~

* インストールプロセスの変更:
    * 互換ライブラリ（64ビットプラットフォーム上の32ビットバイナリ、MIPS上の64ビットバイナリ用）が、新しい `base32`/`base64` および `debug32`/`debug64` セットに分割されました。
    * HTMLマニュアルページが "man" セットから新しい "manhtml" セットに分割されました。

* 削除されたコンポーネント:
    * このリリースに含まれる新しいOpenSSHはDSA鍵をサポートしていません。これらを有効にするカスタム設定がある場合、sshdの起動が失敗する可能性があります。設定を適切に調整してください。
    * Heimdalのsqlite3クレデンシャルキャッシュ(SCC)を無効化、sqlite3依存関係を削除。
    * i386 dosbootブートローダーからXMS固有のコードを削除。
    * 以前 `xfwp(1)` として知られていたXファイアウォールプロキシを削除。
    * 旧式のPDP-11時代のツール `mkstr(1)` および `xstr(1)` を削除。
    * `libXxf86misc` ライブラリを削除。この拡張機能のサポートは2008年にX.Orgから削除されており、サポートしているXサーバーはありません。
    * `moused(8) <https://man.NetBSD.org/NetBSD-11.0/moused.8>` から非公開のCオプションを削除。
    * `ppp(4) <https://man.NetBSD.org/NetBSD-11.0/ppp.4>` から機能していないいくつかのioctlを削除。

* 開発者向けの変更:
    * `ctype(3) <https://man.NetBSD.org/NetBSD-11.0/ctype.3>` - このAPIの実行時における誤用を検出するためのガードページを追加。以前誤った結果を返していたコードはセグメンテーション違反（segfault）を起こすようになります。以前の動作に戻すには環境変数 `LIBC_ALLOWCTYPEABUSE` を設定してください。
    * `curses(3) <https://man.NetBSD.org/NetBSD-11.0/curses.3>` - `define_key(3) <https://man.NetBSD.org/NetBSD-11.0/define_key.3>` の引数をncurses互換にするために `const` 化。
    * `curses(3) <https://man.NetBSD.org/NetBSD-11.0/curses.3>` - `newterm(3) <https://man.NetBSD.org/NetBSD-11.0/newterm.3>`, `setterm(3) <https://man.NetBSD.org/NetBSD-11.0/setterm.3>` 関数の引数を `const` 化。

* その他の機能変更:
    * aarch64 上のCPU周波数を制御するsysctlインターフェースは、パフォーマンス単位ではなくMHzを使用するようになりました。これを調整するスクリプトは修正が必要です。
    * `hdaudio(4) <https://man.NetBSD.org/NetBSD-11.0/hdaudio.4>` ドライバは、ミキサーコントロールのソートと命名が変更されました。スクリプト（特に入力モニター（以前は "record" と呼ばれていたもの）やビープ音量を調整していた場合）は更新が必要です。
    * `cp(1) <https://man.NetBSD.org/NetBSD-11.0/cp.1>` - サイズがゼロに見える場合でも、常に通常のファイルをコピーします。
    * `expr(1) <https://man.NetBSD.org/NetBSD-11.0/expr.1>` - ":" および "length" において、POSIXで要求されるバイト単位ではなくマルチバイトコードポイントを使用します。
    * `lagg(4) <https://man.NetBSD.org/NetBSD-11.0/lagg.4>` - laggに追加されたインターフェースにlaggのMTUをコピーします。
    * `mount(8) <https://man.NetBSD.org/NetBSD-11.0/mount.8>` - `mount -v spec fs` で表示される情報を削減しました。以前の出力が必要な場合は `-vv` を使用してください。

サードパーティ製コンポーネント
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

* binutils - 2.42 に更新。
* expat - 2.8.2 に更新。
* openresolv - 3.16.3 に更新。
* pam-u2f - 1.3.1 に更新。
* tzdata, tzcode - 2026b (2026bgtzを使用) および tzcode2025b に更新。
* userspace-rsu - 0.15.0 に更新。
* `Xorg(1) <https://man.NetBSD.org/NetBSD-11.0/Xorg.1>` - 21.1.24 に更新。
* `awk(1) <https://man.NetBSD.org/NetBSD-11.0/awk.1>` - one true awk 20240817 に更新。
* `ctwm(1) <https://man.NetBSD.org/NetBSD-11.0/ctwm.1>` - 4.1.0 に更新。
* `gcc(1) <https://man.NetBSD.org/NetBSD-11.0/gcc.1>` - 12.5.0 に更新。
* `gdb(1) <https://man.NetBSD.org/NetBSD-11.0/gdb.1>` - 15.1 に更新。
* `less(1) <https://man.NetBSD.org/NetBSD-11.0/less.1>` - 643 に更新。
* `mandoc(1) <https://man.NetBSD.org/NetBSD-11.0/mandoc.1>` - 1.14.6 に更新。
* `openssl(1) <https://man.NetBSD.org/NetBSD-11.0/openssl.1>` - 3.5.7 に更新。
* `pkg_add(1) <https://man.NetBSD.org/NetBSD-11.0/pkg_add.1>` - pkg_install-20260227 に更新。
* `postfix(1) <https://man.NetBSD.org/NetBSD-11.0/postfix.1>` - 3.11.2 に更新。
* `ssh(1) <https://man.NetBSD.org/NetBSD-11.0/ssh.1>`, `sshd(8) <https://man.NetBSD.org/NetBSD-11.0/sshd.8>` - 10.3 に更新。
* `sqlite3(1) <https://man.NetBSD.org/NetBSD-11.0/sqlite3.1>` - 3.45.1 に更新。
* `tmux(1) <https://man.NetBSD.org/NetBSD-11.0/tmux.1>` - 3.6b に更新。
* `yacc(1) <https://man.NetBSD.org/NetBSD-11.0/yacc.1>` - byacc-20240109 に更新。
* `zstd(1) <https://man.NetBSD.org/NetBSD-11.0/zstd.1>` - 1.5.6 に更新。
* `xz(1) <https://man.NetBSD.org/NetBSD-11.0/xz.1>` - 5.8.3 に更新。
* `jemalloc(3) <https://man.NetBSD.org/NetBSD-11.0/jemalloc.3>` - 5.3.0 に更新 (sun2 と vax を除く)。
* `libarchive(3) <https://man.NetBSD.org/NetBSD-11.0/libarchive.3>` - 3.7.7 に更新。
* `pcap(3) <https://man.NetBSD.org/NetBSD-11.0/pcap.3>` - 1.10.5 に更新。
* `openpam(3) <https://man.NetBSD.org/NetBSD-11.0/openpam.3>` - 20230627 に更新。
* `terminfo(3) <https://man.NetBSD.org/NetBSD-11.0/terminfo.3>` - 20231209 に更新。
* `zlib(3) <https://man.NetBSD.org/NetBSD-11.0/zlib.3>` - 1.3.1 に更新。
* `acpi(4) <https://man.NetBSD.org/NetBSD-11.0/acpi.4>` - ACPICA を 20241212 に更新。
* `dhcpcd(8) <https://man.NetBSD.org/NetBSD-11.0/dhcpcd.8>` - 10.2.3 に更新。
* `mdnsd(8) <https://man.NetBSD.org/NetBSD-11.0/mdnsd.8>` - 2559.1.1 に更新。
* `named(8) <https://man.NetBSD.org/NetBSD-11.0/named.8>` - 9.20.24 に更新。
* `ntpd(8) <https://man.NetBSD.org/NetBSD-11.0/ntpd.8>` - 4.2.8p18 に更新。
* `pppd(8) <https://man.NetBSD.org/NetBSD-11.0/pppd.8>` - 2.5.2 に更新。
* `tcpdump(8) <https://man.NetBSD.org/NetBSD-11.0/tcpdump.8>` - 4.99.5 に更新。
* `unbound(8) <https://man.NetBSD.org/NetBSD-11.0/unbound.8>` - 1.25.1 に更新。
* `wpa_supplicant(8) <https://man.NetBSD.org/NetBSD-11.0/wpa_supplicant.8>`, `hostapd(8) <https://man.NetBSD.org/NetBSD-11.0/hostapd.8>` - 2.11 に更新。

変更点の完全なリストは、NetBSD 11.0 リリースツリーのトップレベルディレクトリにある `CHANGES <https://cdn.NetBSD.org/pub/NetBSD/NetBSD-11.0_RC7/CHANGES>`_ および `CHANGES-11.0 <https://cdn.NetBSD.org/pub/NetBSD/NetBSD-11.0_RC7/CHANGES-11.0>`_ ファイルで確認できます。

NetBSD 11.0 RC7 を入手する
--------------------------------

NetBSD 11.0 RC7 のソースとバイナリの完全なセットは、世界中の多くのサイトからダウンロード可能です。`メインCDN <https://cdn.NetBSD.org/pub/NetBSD/NetBSD-11.0_RC7/>`_ からダウンロードするか、お近くの `ミラーサイト <https://www.NetBSD.org/mirrors/>`_ をご利用ください。NetBSD 11.0 RC7 配布物のハッシュ値リスト（NetBSDセキュリティ担当者のPGP鍵で署名済み）は `こちらのファイル <https://cdn.NetBSD.org/pub/NetBSD/security/hashes/NetBSD-11.0_RC7_hashes.asc>`_ から入手可能です。

NetBSDはフリーソフトウェアです。すべてのコードは制限の緩やかなライセンスの下で提供されており、誰に対してもロイヤリティを支払うことなく使用できます。無料のサポートサービスはメーリングリストおよびウェブサイトを通じて提供されています。商用サポートもさまざまなソースから利用可能です。NetBSDに関するより広範な情報はウェブサイトをご覧ください: `www.NetBSD.org <https://www.NetBSD.org/>`_

NetBSD 11.0 がサポートするシステムファミリー
-------------------------------------------------

NetBSD 11.0 リリースでは、以下のシステム向けのサポート済みバイナリ配布を提供しています:

* `NetBSD/aarch64 <https://wiki.NetBSD.org/ports/aarch64/>`_ Arm 64-bit
* `NetBSD/acorn32 <https://wiki.NetBSD.org/ports/acorn32/>`_ Acorn RiscPC/A7000, VLSI RC7500
* `NetBSD/algor <https://wiki.NetBSD.org/ports/algor/>`_ Algorithmics, Ltd. MIPS evaluation boards
* `NetBSD/alpha <https://wiki.NetBSD.org/ports/alpha/>`_ Digital/Compaq Alpha (64-bit)
* `NetBSD/amd64 <https://wiki.NetBSD.org/ports/amd64/>`_ AMD family processors like Opteron, Athlon64, and Intel CPUs with EM64T extension
* `NetBSD/amiga <https://wiki.NetBSD.org/ports/amiga/>`_ Commodore Amiga and MacroSystem DraCo
* `NetBSD/amigappc <https://wiki.NetBSD.org/ports/amigappc/>`_ PowerPC-based Amiga boards.
* `NetBSD/arc <https://wiki.NetBSD.org/ports/arc/>`_ MIPS-based machines following the Advanced RISC Computing spec
* `NetBSD/atari <https://wiki.NetBSD.org/ports/atari/>`_ Atari TT030, Falcon, Hades
* `NetBSD/bebox <https://wiki.NetBSD.org/ports/bebox/>`_ Be Inc's BeBox
* `NetBSD/cats <https://wiki.NetBSD.org/ports/cats/>`_ Chalice Technology's CATS and Intel's EBSA-285 evaluation boards
* `NetBSD/cesfic <https://wiki.NetBSD.org/ports/cesfic/>`_ CES FIC8234 VME processor board
* `NetBSD/cobalt <https://wiki.NetBSD.org/ports/cobalt/>`_ Cobalt Networks' MIPS-based Microservers
* `NetBSD/dreamcast <https://wiki.NetBSD.org/ports/dreamcast/>`_ Sega Dreamcast game console
* `NetBSD/emips <https://wiki.NetBSD.org/ports/emips/>`_ The Extensible MIPS architecture from Microsoft Research
* `NetBSD/epoc32 <https://wiki.NetBSD.org/ports/epoc32/>`_ Psion EPOC PDAs
* `NetBSD/evbarm <https://wiki.NetBSD.org/ports/evbarm/>`_ Various Arm-based evaluation boards and appliances
* `NetBSD/evbmips <https://wiki.NetBSD.org/ports/evbmips/>`_ Various MIPS-based evaluation boards and appliances
* `NetBSD/evbppc <https://wiki.NetBSD.org/ports/evbppc/>`_ Various PowerPC-based evaluation boards and appliances
* `NetBSD/evbsh3 <https://wiki.NetBSD.org/ports/evbsh3/>`_ Various Hitachi Super-H SH3 and SH4-based evaluation boards and appliances
* `NetBSD/ews4800mips <https://wiki.NetBSD.org/ports/ews4800mips/>`_ NEC's MIPS-based EWS4800 workstation
* `NetBSD/hp300 <https://wiki.NetBSD.org/ports/hp300/>`_ Hewlett-Packard 9000/300 and 400 series
* `NetBSD/hpcarm <https://wiki.NetBSD.org/ports/hpcarm/>`_ StrongArm based Windows CE PDA machines
* `NetBSD/hpcmips <https://wiki.NetBSD.org/ports/hpcmips/>`_ MIPS-based Windows CE PDA machines
* `NetBSD/hpcsh <https://wiki.NetBSD.org/ports/hpcsh/>`_ Hitachi Super-H based Windows CE PDA machines
* `NetBSD/hppa <https://wiki.NetBSD.org/ports/hppa/>`_ Hewlett-Packard 9000 Series 700 workstations
* `NetBSD/i386 <https://wiki.NetBSD.org/ports/i386/>`_ IBM PCs and PC clones with i486-family processors and up
* `NetBSD/ibmnws <https://wiki.NetBSD.org/ports/ibmnws/>`_ IBM Network Station 1000
* `NetBSD/iyonix <https://wiki.NetBSD.org/ports/iyonix/>`_ Castle Technology's Iyonix Arm based PCs
* `NetBSD/landisk <https://wiki.NetBSD.org/ports/landisk/>`_ SH4 processor based NAS appliances
* `NetBSD/luna68k <https://wiki.NetBSD.org/ports/luna68k/>`_ OMRON Tateisi Electric's LUNA series
* `NetBSD/mac68k <https://wiki.NetBSD.org/ports/mac68k/>`_ Apple Macintosh with Motorola 68k CPU
* `NetBSD/macppc <https://wiki.NetBSD.org/ports/macppc/>`_ Apple PowerPC-based Macintosh and clones
* `NetBSD/mipsco <https://wiki.NetBSD.org/ports/mipsco/>`_ MIPS Computer Systems Inc. family of workstations and servers
* `NetBSD/mmeye <https://wiki.NetBSD.org/ports/mmeye/>`_ Brains mmEye multimedia server
* `NetBSD/mvme68k <https://wiki.NetBSD.org/ports/mvme68k/>`_ Motorola MVME 68k Single Board Computers
* `NetBSD/mvmeppc <https://wiki.NetBSD.org/ports/mvmeppc/>`_ Motorola PowerPC VME Single Board Computers
* `NetBSD/netwinder <https://wiki.NetBSD.org/ports/netwinder/>`_ StrongArm based NetWinder machines
* `NetBSD/news68k <https://wiki.NetBSD.org/ports/news68k/>`_ Sony's 68k-based “NET WORK STATION” series
* `NetBSD/newsmips <https://wiki.NetBSD.org/ports/newsmips/>`_ Sony's MIPS-based “NET WORK STATION” series
* `NetBSD/next68k <https://wiki.NetBSD.org/ports/next68k/>`_ NeXT 68k “black” hardware
* `NetBSD/ofppc <https://wiki.NetBSD.org/ports/ofppc/>`_ OpenFirmware PowerPC machines
* `NetBSD/pmax <https://wiki.NetBSD.org/ports/pmax/>`_ Digital MIPS-based DECstations and DECsystems
* `NetBSD/prep <https://wiki.NetBSD.org/ports/prep/>`_ PReP (PowerPC Reference Platform) and CHRP machines
* `NetBSD/riscv <https://wiki.NetBSD.org/ports/riscv/>`_ RISC-V-based devices
* `NetBSD/rs6000 <https://wiki.NetBSD.org/ports/rs6000/>`_ IBM RS/6000 MCA-based PowerPC machines.
* `NetBSD/sandpoint <https://wiki.NetBSD.org/ports/sandpoint/>`_ Motorola Sandpoint reference platform, including many PPC-based NAS boxes
* `NetBSD/sgimips <https://wiki.NetBSD.org/ports/sgimips/>`_ Silicon Graphics' MIPS-based workstations
* `NetBSD/shark <https://wiki.NetBSD.org/ports/shark/>`_ Digital DNARD (“shark”)
* `NetBSD/sparc <https://wiki.NetBSD.org/ports/sparc/>`_ Sun SPARC (32-bit) and UltraSPARC (in 32-bit mode)
* `NetBSD/sparc64 <https://wiki.NetBSD.org/ports/sparc64/>`_ Sun UltraSPARC (in native 64-bit mode)
* `NetBSD/sun2 <https://wiki.NetBSD.org/ports/sun2/>`_ Sun Microsystems Sun 2 machines with Motorola 68010 CPU
* `NetBSD/sun3 <https://wiki.NetBSD.org/ports/sun3/>`_ Motorola 68020 and 030 based Sun 3 and 3x machines
* `NetBSD/vax <https://wiki.NetBSD.org/ports/vax/>`_ Digital VAX
* `NetBSD/x68k <https://wiki.NetBSD.org/ports/x68k/>`_ Sharp X680x0 series
* `NetBSD/xen <https://wiki.NetBSD.org/ports/xen/>`_ The Xen virtual machine monitor
* `NetBSD/zaurus <https://wiki.NetBSD.org/ports/zaurus/>`_ Sharp Arm PDAs

本リリースに含まれるが、完全にはサポートされていない、あるいは動作しないポート:

* `NetBSD/ia64 <https://wiki.NetBSD.org/ports/ia64/>`_ Itanium family of processors

謝辞
-----

NetBSD Foundationは、長年にわたりコード、ハードウェア、ドキュメント、資金、サーバーのコロケーション、ウェブページ、その他ドキュメント、リリースエンジニアリング、およびその他のリソースを提供してくださったすべての方々に感謝いたします。NetBSDを実現している人々に関する詳細は以下で確認できます: `www.NetBSD.org/people/ <https://www.netbsd.org/people/>`_

NetBSDについて
--------------------

NetBSDは、フリーで、高速で、安全で、移植性の高いUnixライクなオープンソースオペレーティングシステムです。大規模サーバーや強力なデスクトップシステムから、ハンドヘルドデバイスや組み込みデバイスまで、幅広いプラットフォームで利用可能です。そのクリーンな設計と高度な機能は、本番環境と研究環境の両方に最適であり、ソースコードはビジネスフレンドリーなライセンスの下で自由に利用できます。NetBSDは、巨大で活気のある国際的なコミュニティによって開発およびサポートされています。多くのアプリケーションが `pkgsrc, the NetBSD Packages Collection <https://pkgsrc.org>`_ を通じてすぐに利用可能です。

NetBSD Foundationについて
---------------------------------

`NetBSD Foundation <https://www.netbsd.org/foundation/>`_ は1995年に設立され、NetBSDプロジェクトのコアサービスの監視、産業界およびオープンソースコミュニティ内でのプロジェクトの推進、NetBSDコードベースの多くに対する知的財産権の保持という任務を負っています。プロジェクトの日常業務はボランティアによって運営されています。商用バックアップを持たない非営利団体であるNetBSD Foundationは、ユーザーからの寄付に依存しており、優れたオペレーティングシステムの継続的な製造を支援するために、`寄付をご検討 <https://www.netbsd.org/donations/>`_ いただけますと幸いです。いただいた寛大な寄付は、進行中のアップグレードやメンテナンス、およびNetBSD Foundationの運営費に充てられます。寄付はPayPal経由で <paypal@NetBSD.org> へ、あるいはGoogle Checkout経由で行うことができ、米国では全額税控除の対象となります。詳細については `www.NetBSD.org/donations/ <https://www.netbsd.org/donations/#how-to-donate>`_ を参照するか、直接 <finance-exec@NetBSD.org> までお問い合わせください。

~~~~

出典: [Announcing NetBSD 11.0 RC7 (July 21, 2026)](https://www.netbsd.org/releases/formal-11/NetBSD-11.0.html)


