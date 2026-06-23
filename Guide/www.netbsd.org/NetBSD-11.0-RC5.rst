NetBSD 11.0 RC5 リリースのお知らせ (2026年6月16日)
==================================================

.. contents:: 目次

せっかちな方へのクイックリンク:
------------------------------

ダウンロード (CDN):
* `amd64 USB <https://cdn.NetBSD.org/pub/NetBSD/NetBSD-11.0_RC5/images/NetBSD-11.0_RC5-amd64-install.img.gz>`_
* `amd64 DVD <https://cdn.NetBSD.org/pub/NetBSD/NetBSD-11.0_RC5/images/NetBSD-11.0_RC5-amd64-dvd.iso>`_
* `i386 USB <https://cdn.NetBSD.org/pub/NetBSD/NetBSD-11.0_RC5/images/NetBSD-11.0_RC5-i386-install.img.gz>`_
* `i386 CD-ROM <https://cdn.NetBSD.org/pub/NetBSD/NetBSD-11.0_RC5/images/NetBSD-11.0_RC5-i386.iso>`_
* `sparc64 DVD <https://cdn.NetBSD.org/pub/NetBSD/NetBSD-11.0_RC5/images/NetBSD-11.0_RC5-sparc64-dvd.iso>`_
* `sparc64 CD-ROM <https://cdn.NetBSD.org/pub/NetBSD/NetBSD-11.0_RC5/images/NetBSD-11.0_RC5-sparc64.iso>`_
* `macppc CD-ROM <https://cdn.NetBSD.org/pub/NetBSD/NetBSD-11.0_RC5/images/NetBSD-11.0_RC5-macppc.iso>`_
* `RISC-V デバイス <https://cdn.NetBSD.org/pub/NetBSD/NetBSD-11.0_RC5/riscv-riscv64/binary/gzimg/riscv64.img.gz>`_
* `Cavium Octeon MIPS デバイス <https://cdn.NetBSD.org/pub/NetBSD/NetBSD-11.0_RC5/evbmips-mips64eb/binary/gzimg/octeon.img.gz>`_
* `Nintendo Wii <https://cdn.NetBSD.org/pub/NetBSD/NetBSD-11.0_RC5/evbppc/binary/gzimg/wii.img.gz>`_
* `各種 Arm デバイス <https://armbsd.org/>`_
* `その他全てのリリースディレクトリ <https://cdn.NetBSD.org/pub/NetBSD/NetBSD-11.0_RC5/>`_

配布物内の全ファイルの `ハッシュ値 <https://cdn.NetBSD.org/pub/NetBSD/security/hashes/NetBSD-11.0_RC5_hashes.asc>`_ は、`NetBSDセキュリティオフィサーのPGP鍵 <https://cdn.NetBSD.org/pub/NetBSD/security/PGP/security-officer@netbsd.org.asc>`_ で署名されています。

はじめに
--------

NetBSDプロジェクトは、NetBSDオペレーティングシステムの第19メジャーリリースの第5リリース候補である、NetBSD 11.0 RC5をアナウンスします。

アップグレード手順
------------------

既存のインストール環境は、インストールイメージから起動し「Upgrade」オプションを選択することでアップグレード可能です。他の更新方法を使用している場合は、まずカーネルとモジュールを更新し、再起動してからユーザ空間を更新してください。パッケージリポジトリのURLを調整し、すべてのサードパーティ製パッケージを更新する必要があります。また、新しいセットが追加されている点にも注意してください。これらは `sysinst(8) <https://man.NetBSD.org/NetBSD-11.0/sysinst.8>`_ を使用して個別にインストールする必要がある場合があります。以前のリリースからアップグレードする場合は、「非互換の変更」の項目に特に注意してください。

NetBSD 10.1 からの変更点
------------------------

ハイライト
~~~~~~~~~~

- RISC-Vプロセッサアーキテクチャへの新規ポート。NetBSD 11.0は、VisionFive 2、PINE64 STAR64などのStarFive JH71XXベースのデバイスやQEMUを含む、64ビットRISC-Vプラットフォームをサポートする初の安定版リリースです。
- POSIX.1-2024およびC23プログラミングインターフェース標準への準拠強化。
- `compat_linux(8) <https://man.NetBSD.org/NetBSD-11.0/compat_linux.8>`_ におけるLinuxシステムコールのサポート強化（epoll (kqueue上で実装)、POSIXメッセージキュー、statx、readahead、close_range、waitid、renameat2、clone3、sync_file_range、syncfs、inotifyを含む）。
- Qualcomm Snapdragon X Eliteプラットフォームへの初期サポート。
- `npf(7) <https://man.NetBSD.org/NetBSD-11.0/npf.7>`_ ファイアウォールの改善（レイヤ2フィルタリングおよびユーザ/グループフィルタリングを含む）。
- x86向けの新MICROVMカーネル。i386とamd64の両方をサポート。NetBSD 11.0は、極めて高速な仮想マシンブートのために設計された専用のMICROVMカーネルを導入しました。PVHブート、VirtIO MMIO、および複数のカーネル最適化を活用し、2020年頃のx86 CPU上で約10msでブート可能です。
- 新規virt68kポート。QEMUで準仮想化デバイスを使用してMotorola 68000ポートを動作させます。

ポート
~~~~~~

- aarch64 - Qualcomm Oryon CPUへの初期サポート。
- aarch64 - Qualcomm Snapdragon X Elite バッテリ＆充電器センサ、GPIO、I2Cコントローラのサポート追加。
- aarch64 - Advanced SIMDでアクセラレートされたX.Org最適化を有効化。
- alpha - Secure PLT ELFバイナリのサポート追加。
- amd64 - 一部のHPノートPCで見られるAMD GPIO用の `amdgpio(4) <https://man.NetBSD.org/NetBSD-11.0/amdgpio.4>`_ デバイスドライバを追加。
- amd64 - Siena、Turin Classic、Turin Dense、Strix Point、Zen 5 CPUの温度センササポートを追加。
- evbarm - ACPIベースシステム向けにNUMA認識を追加。
- evbarm - Arm SCMIパフォーマンスプロトコルサポートを追加。
- evbarm - Amlogic Meson I2Cコントローラ用ドライバを追加。
- evbarm - Libre Computer AML-S905X-CCのUSBコントローラをサポート。
- evbarm - Rockchip USB-C PHY用ドライバを追加。
- evbarm - NanoPi R4Sのサポートを改善。
- evbarm - UEFIでブート時のRaspberry Pi 5周辺機器のサポートを改善。
- evbarm - Allwinnerデバイス向けにDRM/KMSアトミックモードセッティングを実装。
- evbppc - Nintendo Wii DVDドライブ、 `bwi(4) <https://man.NetBSD.org/NetBSD-11.0/bwi.4>`_ WLAN、USB Geckoシリアルコンソール、ハードウェアAESエンジン（ディスク暗号化とWi-Fiの高速化に使用）、およびスタンドアロンブートローダーのサポートを追加。
- evbppc - WiiでのX.Orgパフォーマンスと色再現性を向上（GX RGBからYUY2へのビデオ変換高速化）。
- hp300 - 362および382向けに `sti(4) <https://man.NetBSD.org/NetBSD-11.0/sti.4>`_ フレームバッファサポートを追加。これらのマシンでX.Orgサーバが動作可能に。
- hppa - HP Visualize FXビデオカード用の新しい `summitfb(4) <https://man.NetBSD.org/NetBSD-11.0/hppa/summitfb.4>`_ ドライバ。
- hppa - HP HCRXビデオカード用の新しい `hyperfb(4) <https://man.NetBSD.org/NetBSD-11.0/hppa/hyperfb.4>`_ ドライバ。
- hppa - HPのNGLEファミリグラフィックスデバイス用専用X.Orgドライバを追加。Visualize EGでのアクセラレーションをサポート。
- m68k - 浮動小数点エミュレーションを改善。
- mac68k - PowerBook 1xxシリーズのサポートを改善（バックライト制御を含む）。新しい `pbbat(4) <https://man.NetBSD.org/NetBSD-11.0/mac68k/pbbat.4>`_ バッテリドライバを追加。
- macppc - G5/G4 I2C/OpenPICサポートを改善。
- macppc - PowerMac7,2向けファン制御を有効化。
- macppc - デフォルトでPaX MPROTECTおよびASLRセキュリティ緩和機能を有効化。
- mips - デフォルトでスタック破壊保護を有効化。mips64でRELRO緩和を有効化。
- riscv - QEMUへの初期サポート（Google Goldfish RTC、VirtIO (ネットワーク、ディスク等) デバイス、仮想化オーディオを含む）。
- riscv - Allwinner D1 SoC (MangoPi MQ ProやAllwinner Nezhaなどで使用) への初期基本サポート。GPIOおよびUARTシリアルコンソールサポートを含む。
- riscv - StarFive JH7110 SoC (VisionFive 2、STAR64などで使用) へのサポート。PCI/PCIe、TRNG、ピン、温度センサなどを含む。
- riscv - `crash(8) <https://man.NetBSD.org/NetBSD-11.0/crash.8>`_ カーネルデバッガへのサポート。
- x86 - pv(4) 擬似バス経由のカーネルコマンドラインパラメータで処理される、MMIO上のVirtIOデバイス検出をサポート。
- x86 - `pci(4) <https://man.NetBSD.org/NetBSD-11.0/pci.4>`_ のような既知のバスに接続されない全準仮想化デバイス向けに、pv(4) 擬似バスのサポートを追加。
- x86 - 非Xen PVHブート (例: QEMU -kernelオプション) をサポート。
- x86 - `tco(4) <https://man.NetBSD.org/NetBSD-11.0/tco.4>`_ において新しいIntel TCOウォッチドッグタイマーをサポート。
- x86 - サポートシステム上で充電動作の一部を制御するための `thinkpad(4) <https://man.NetBSD.org/NetBSD-11.0/thinkpad.4>`_ sysctlインターフェースを公開。
- x68k - フレームバッファコンソールへのSixelグラフィックスシーケンスサポートを追加。

カーネル
~~~~~~~~

- カーネル - 最適化: 各種ポートでソフト割り込みをトリガする際の不要なメモリバリアを省略。
- カーネル - 最適化: vdrainカーネルスレッドを2つのスレッドプールジョブに置き換え。
- カーネル - 最適化: SPARC、PowerPC、MIPS上でのバイトスワップ（特にAdiantumディスク暗号化向け）のパフォーマンスを改善。
- カーネル - O_CLOFORK実装を追加。
- procfs - Linux互換性のためにsysvipcおよびself/limitsのサポートを追加。
- zfs - rm/unlinkのパフォーマンスを改善。
- zfs - Xenで使用されるzvolのDIOCCACHESYNCを実装。
- `clock_getres(2) <https://man.NetBSD.org/NetBSD-11.0/clock_getres.2>`_ - CLOCK_PROCESS_CPUTIME_IDおよびCLOCK_THREAD_CPUTIME_IDをサポート。
- `memfd_create(2) <https://man.NetBSD.org/NetBSD-11.0/memfd_create.2>`_ - 新しいシステムコール。同名のLinuxシステムコールと互換性あり。
- `pipe(2) <https://man.NetBSD.org/NetBSD-11.0/pipe.2>`_ - パフォーマンス向上、ロック競合の削減。
- `ddb(4) <https://man.NetBSD.org/NetBSD-11.0/ddb.4>`_ - カーネル内デバッガに単純なshowコマンド（condvar, selinfo, sleepq）を追加。
- `dk(4) <https://man.NetBSD.org/NetBSD-11.0/dk.4>`_ - Atari TOSパーティションをディスクウェッジとして検出するサポートを追加。
- `drum(4) <https://man.NetBSD.org/NetBSD-11.0/drum.4>`_ - サブシステムをMPSAFE化。
- `nvmm(4) <https://man.NetBSD.org/NetBSD-11.0/nvmm.4>`_ - CPUIDにおけるVMware互換のTSCおよびLAPIC周波数検出を実装。
- `wscons(4) <https://man.NetBSD.org/NetBSD-11.0/wscons.4>`_ - VT100エミュレーションに輝度およびxtermスタイルの256色エスケープコードのサポートを追加。
- `wscons(4) <https://man.NetBSD.org/NetBSD-11.0/wscons.4>`_ - 現在のフォントに関する情報を取得するためのWSDISPLAYIO_GFONT ioctlを追加。
- `npf(7) <https://man.NetBSD.org/NetBSD-11.0/npf.7>`_ - レイヤ2フィルタリングサポートを追加。
- `npf(7) <https://man.NetBSD.org/NetBSD-11.0/npf.7>`_ - ユーザ/グループベースのフィルタリングサポートを追加。
- `heartbeat(9) <https://man.NetBSD.org/NetBSD-11.0/heartbeat.9>`_ - カーネルの進捗を確認するための新しいメカニズム。ハード割り込みを使用して低優先度のソフト割り込みの進捗を、あるCPUが別のCPUの進捗をチェックするために使用されます。

機械独立デバイスドライバ
~~~~~~~~~~~~~~~~~~~~~~~~

- `aac(4) <https://man.NetBSD.org/NetBSD-11.0/aac.4>`_ - Adaptec RAID 5445, 5805, 5085のサポートを追加。
- `apei(4) <https://man.NetBSD.org/NetBSD-11.0/apei.4>`_ - ACPI Platform Error Interfaces用ドライバ。
- `awge(4) <https://man.NetBSD.org/NetBSD-11.0/evbarm/awge.4>`_ - NET_MPSAFEカーネルオプションによる詳細なロックを改善。
- `axen(4) <https://man.NetBSD.org/NetBSD-11.0/axen.4>`_ - ASIX AX88179A USB Ethernetのサポートを追加。
- `bwi(4) <https://man.NetBSD.org/NetBSD-11.0/bwi.4>`_ - 不要な遅延を削除。
- `ds2482ow(4) <https://man.NetBSD.org/NetBSD-11.0/ds2482ow.4>`_ - Maxim DS2482-100およびDS2482-800 I2C-1-Wireブリッジチップ用ドライバ。
- `ds28e17iic(4) <https://man.NetBSD.org/NetBSD-11.0/ds28e17iic.4>`_ - DS28E17 1-Wire-I2Cブリッジチップ用ドライバ。
- `dse(4) <https://man.NetBSD.org/NetBSD-11.0/dse.4>`_ - DaynaPORT SCSI/Link Ethernetデバイス用ドライバ。これらのレガシーデバイスは、PiSCSIソフトウェアを動かすRaSCSIボードを搭載したRaspberry Piで現在エミュレーション可能です。
- `emcfan(4) <https://man.NetBSD.org/NetBSD-11.0/emcfan.4>`_ - Microchip Technology / SMSC EMC210XおよびEMC230Xファンコントローラ用ドライバ。
- `gftty(4) <https://man.NetBSD.org/NetBSD-11.0/gftty.4>`_ / `gfpic(4) <https://man.NetBSD.org/NetBSD-11.0/gfpic.4>`_ - "Goldfish" 仮想ハードウェアプラットフォーム用ドライバ。
- `gscan(4) <https://man.NetBSD.org/NetBSD-11.0/gscan.4>`_ - USB-CANバスアダプタ用ドライバ。
- `igc(4) <https://man.NetBSD.org/NetBSD-11.0/igc.4>`_ - TCP Segmentation Offload (TSO) のサポートを追加。
- `ikbd(4) <https://man.NetBSD.org/NetBSD-11.0/ikbd.4>`_ - I2C HIDキーボードドライバ。
- `lm(4) <https://man.NetBSD.org/NetBSD-11.0/lm.4>`_ - NCT6794D向けに5つの補助ファンセンサをサポート。
- `mcx(4) <https://man.NetBSD.org/NetBSD-11.0/mcx.4>`_ - NVIDIA Mellanox ConnectX-6仮想関数のサポートを追加。
- `ncm(4) <https://man.NetBSD.org/NetBSD-11.0/ncm.4>`_ - USB Network Control Model用ドライバ（新しいAndroidのUSBテザリングで使用）。
- `pms(4) <https://man.NetBSD.org/NetBSD-11.0/pms.4>`_ - PS/2マウスのホットプラグサポートを追加。
- `puc(4) <https://man.NetBSD.org/NetBSD-11.0/puc.4>`_ - BrainboxesおよびOxford Semiconductor PCIシリアルカードのサポートを追加。
- `pvscsi(4) <https://man.NetBSD.org/NetBSD-11.0/pvscsi.4>`_ - VMware準仮想化SCSIコントローラ用ドライバ。
- `rge(4) <https://man.NetBSD.org/NetBSD-11.0/rge.4>`_ - Realtek RTL8126 5Gbps Ethernetのサポートを追加。
- `u3g(4) <https://man.NetBSD.org/NetBSD-11.0/u3g.4>`_ - Sierra Wireless MC7304 LTEモデムをサポート。
- `uaudio(4) <https://man.NetBSD.org/NetBSD-11.0/uaudio.4>`_ - USB Audio Class 2.0互換デバイスをサポート。
- `udl(4) <https://man.NetBSD.org/NetBSD-11.0/udl.4>`_ - SANWA SUPPLY 500-KC002N USB-VGAアダプタのサポートを追加。
- `uftdi(4) <https://man.NetBSD.org/NetBSD-11.0/uftdi.4>`_ - ドライバが個別のインターフェースを選択的に拒否し、 `ugen(4) <https://man.NetBSD.org/NetBSD-11.0/ugen.4>`_ でマッチさせてlibusb経由でアクセス可能にする「マッチクォーク」メカニズムを追加。
- `umcpmio(4) <https://man.NetBSD.org/NetBSD-11.0/umcpmio.4>`_ - MCP-2221 / 2221AマルチIOチップ用ドライバ。
- `urndis(4) <https://man.NetBSD.org/NetBSD-11.0/urndis.4>`_ - 追加のデバイスタイプをマッチ対象に。
- `urtwn(4) <https://man.NetBSD.org/NetBSD-11.0/urtwn.4>`_ - Asus USB-N10 Nano B1 Wi-Fiアダプタのサポートを追加。
- `viaide(4) <https://man.NetBSD.org/NetBSD-11.0/viaide.4>`_ - 各種VIA IDE/PATA/SATAコントローラのサポートを改善（特にRAIDモード）。
- `viogpu(4) <https://man.NetBSD.org/NetBSD-11.0/viogpu.4>`_ - QEMU仮想GPU用ドライバ。
- `virtio(4) <https://man.NetBSD.org/NetBSD-11.0/virtio.4>`_ - VirtIOドライバをMPSAFEとマークし、巨大なカーネルロックを保持しないように変更。

ユーザ空間
~~~~~~~~~~

- build.sh - 新ターゲット ``pkg=CATEGORY/PACKAGE``。pkgsrcからCATEGORY/PACKAGEをクロスビルドし、pkgsrcをブートストラップします。
- libc - stdio FILEハンドル経由の書き込みパフォーマンスを向上。
- libc - ``ffsl(3)``, ``ffsll(3)``, ``mempcpy(3)``, ``wmempcpy(3)``, ``heapsort_r(3)``, ``mergesort_r(3)``, ``qsort_r(3)``, ``c8rtomb(3)``, ``mbrtoc8(3)``, ``timespec_getres(3)`` 関数を追加。
- libm - より多くのlong double版関数を追加。テストを拡充。
- libpthread - 不足していたPOSIX.1-2024キャンセルポイントを監査。
- `aiomixer(1) <https://man.NetBSD.org/NetBSD-11.0/aiomixer.1>`_ - 環境変数 ``NO_COLOR`` を設定して色を無効にするという非公式標準をサポート。
- `c17(1) <https://man.NetBSD.org/NetBSD-11.0/c17.1>`_ - POSIX.1-2024で要求されるISO 2017 Cコンパイラ用の新しいラッパースクリプト。
- `calendar(1) <https://man.NetBSD.org/NetBSD-11.0/calendar.1>`_ - 2026年の移動祝日データを更新。
- `crunchgen(1) <https://man.NetBSD.org/NetBSD-11.0/crunchgen.1>`_ - ライブラリディレクトリを設定するための -L オプションを尊重。
- `cut(1) <https://man.NetBSD.org/NetBSD-11.0/cut.1>`_ - -b オプション使用時にマルチバイト文字を分割しない -n オプションを追加。
- `date(1) <https://man.NetBSD.org/NetBSD-11.0/date.1>`_ - GNU date同様、RFC 5322形式で時刻を表示する -R オプションを追加。
- `df(1) <https://man.NetBSD.org/NetBSD-11.0/df.1>`_ - -M (非マウント引数を無視) および -q (警告を抑制) オプションを追加。
- `ftp(1) <https://man.NetBSD.org/NetBSD-11.0/ftp.1>`_ - ソケットバッファ処理を簡素化しパフォーマンスを向上。
- `gzip(1) <https://man.NetBSD.org/NetBSD-11.0/gzip.1>`_ - GNU互換のための --ascii および --license オプションを追加。
- `install(1) <https://man.NetBSD.org/NetBSD-11.0/install.1>`_ - -v (verbose) オプションを追加。
- `lint(1) <https://man.NetBSD.org/NetBSD-11.0/lint.1>`_ - C23コードのチェックをサポート。
- `lint(1) <https://man.NetBSD.org/NetBSD-11.0/lint.1>`_ - コード内のより多くの整数オーバーフロー型を検出。
- `make(1) <https://man.NetBSD.org/NetBSD-11.0/make.1>`_ - インクルードガードの認識、:Mおよび:Nによるパターンマッチングの改善など、各種パフォーマンス向上。
- `man(1) <https://man.NetBSD.org/NetBSD-11.0/man.1>`_ - ローカルパスをロードする -l フラグを追加。
- `patch(1) <https://man.NetBSD.org/NetBSD-11.0/patch.1>`_ - GNU patch互換のための --backup-if-mismatch および --no-backup-if-mismatch を追加。
- `patch(1) <https://man.NetBSD.org/NetBSD-11.0/patch.1>`_ - INT16_MAXを超える長さの行を処理。
- `pkill(1) <https://man.NetBSD.org/NetBSD-11.0/pkill.1>`_ - pidfileを使用する -F オプション、およびロックを確実にする -L を追加。
- `printf(1) <https://man.NetBSD.org/NetBSD-11.0/printf.1>`_ - 変換用無効値の検出と診断を改善。
- `printf(1) <https://man.NetBSD.org/NetBSD-11.0/printf.1>`_ - %C形式変換と、long doubleを使用する -L オプションを追加。
- `sh(1) <https://man.NetBSD.org/NetBSD-11.0/sh.1>`_ - POSIX Issue 8の要件に準拠するようチルダ展開を調整。
- `sh(1) <https://man.NetBSD.org/NetBSD-11.0/sh.1>`_ - シェル入力内のNUL文字を拒否するように変更。
- `sh(1) <https://man.NetBSD.org/NetBSD-11.0/sh.1>`_ - バージョン情報を表示する -r オプションを追加。
- `sh(1) <https://man.NetBSD.org/NetBSD-11.0/sh.1>`_ - read組み込みコマンドに -b および -nMAX オプションを追加。
- `sh(1) <https://man.NetBSD.org/NetBSD-11.0/sh.1>`_ - `csh(1) <https://man.NetBSD.org/NetBSD-11.0/csh.1>`_ 組み込みコマンド同様、suspendを組み込みとして実装。
- `sh(1) <https://man.NetBSD.org/NetBSD-11.0/sh.1>`_ - HISTFILEおよびHISTAPPEND変数を実装。
- `stat(1) <https://man.NetBSD.org/NetBSD-11.0/stat.1>`_ - シンボリックフラグの出力を追加。
- `touch(1) <https://man.NetBSD.org/NetBSD-11.0/touch.1>`_ - -d, -R, -D オプションを追加。
- `videoctl(1) <https://man.NetBSD.org/NetBSD-11.0/videoctl.1>`_ - フレームサイズの列挙を改善。
- `curses(3) <https://man.NetBSD.org/NetBSD-11.0/curses.3>`_ - ncurses拡張 `wgetscrreg(3) <https://man.NetBSD.org/NetBSD-11.0/wgetscrreg.3>`_ を実装。
- `proplib(3) <https://man.NetBSD.org/NetBSD-11.0/proplib.3>`_ - JSONシリアライズ形式のサポートを追加。
- `cribbage(6) <https://man.NetBSD.org/NetBSD-11.0/cribbage.6>`_ - 尋ねずにプレイし続ける -y オプションを追加。
- `tetris(6) <https://man.NetBSD.org/NetBSD-11.0/tetris.6>`_ - 環境変数 ``NO_COLOR`` を設定して色を無効にするという非公式標準をサポート。
- `worms(6) <https://man.NetBSD.org/NetBSD-11.0/worms.6>`_ - ワームをカラー表示する -C オプション、ワームの頭のバリエーションを増やす -H オプションを追加。
- `blocklistd(8) <https://man.NetBSD.org/NetBSD-11.0/blocklistd.8>`_ - /etc/blocklistd.conf.d のような設定ディレクトリ内の複数の設定ファイルをサポート。
- `chown(8) <https://man.NetBSD.org/NetBSD-11.0/chown.8>`_ - ファイルの所有者/グループを現在値に変更しないための -d フラグを追加。不必要な操作を回避。
- `cpuctl(8) <https://man.NetBSD.org/NetBSD-11.0/cpuctl.8>`_ - Intel Meteor LakeおよびEmerald Rapids CPUを認識。
- `dkctl(8) <https://man.NetBSD.org/NetBSD-11.0/dkctl.8>`_ - 新しいgetgeometryコマンドを追加。
- `envstat(8) <https://man.NetBSD.org/NetBSD-11.0/envstat.8>`_ - JSON出力をサポート。
- `gpt(8) <https://man.NetBSD.org/NetBSD-11.0/gpt.8>`_ - GUID管理の追加、開始/サイズを16進数で表示するオプション。
- `iostat(8) <https://man.NetBSD.org/NetBSD-11.0/iostat.8>`_ - 限定的な代替統計である -X オプションを追加。"-D" オプションに似ているが、xfers/sをスキップし、KB/sではなくMB/sを報告。デフォルトで1行あたり約50%多くのデバイスを表示可能に。
- `makefs(8) <https://man.NetBSD.org/NetBSD-11.0/makefs.8>`_ - -m でcd9660ファイルシステムのサイズ制限を可能にし、互換ブートROM用にversion=0 4.3BSD FFSファイルシステムの作成を許可。
- `mount_cd9660(8) <https://man.NetBSD.org/NetBSD-11.0/mount_cd9660.8>`_ - mask, dirmask, uid, gid マウントオプションのサポートを追加。
- `scsictl(8) <https://man.NetBSD.org/NetBSD-11.0/scsictl.8>`_ - デバイスを識別するVital Product Dataを報告するidentify vpdを追加。
- `syslogd(8) <https://man.NetBSD.org/NetBSD-11.0/syslogd.8>`_ - リモートメッセージの "kern" から "user" への変換を無効にする -k オプションを追加。

非互換の変更
~~~~~~~~~~~~

- 本リリースの新しいOpenSSHは、DSA鍵をサポートしなくなりました。これらを有効にしているカスタム設定がある場合、sshdの起動が失敗する可能性があります。設定を適宜調整してください。
- 互換ライブラリ（64ビットプラットフォーム上の32ビットバイナリ、MIPS上の64ビットバイナリ用）は、新しいbase32/base64、debug32/debug64セットに分割されました。
- HTMLマニュアルページは「man」セットから新しい「manhtml」セットに分割されました。
- aarch64でのCPU周波数を制御するsysctlインターフェースは、パフォーマンス単位ではなくMHzを使用するようになりました。
- `hdaudio(4) <https://man.NetBSD.org/NetBSD-11.0/hdaudio.4>`_ ドライバは、ミキサーコントロールのソートと命名が変更されました。スクリプトを更新する際は注意してください（特に、入力モニター（以前は "record" と呼ばれていたもの）やビープ音量を調整していた場合）。
- libc - `ctype(3) <https://man.NetBSD.org/NetBSD-11.0/ctype.3>`_ 関数にガードページを追加し、実行時におけるこのAPIの一般的な誤用を検出。以前誤った結果を返していたコードは、現在セグメンテーションフォールトを起こします。以前の動作に戻すには、環境変数 ``LIBC_ALLOWCTYPEABUSE`` を設定してください。
- i386 - dosbootからXMS固有のコードを削除。
- heimdal - sqlite3資格情報キャッシュ (SCC) を無効化し、sqlite3依存関係を削除。
- `Xorg(1) <https://man.NetBSD.org/NetBSD-11.0/Xorg.1>`_ - libXxf86miscライブラリを削除。この拡張のサポートは2008年にX.Orgから削除されており、どのXサーバもサポートしていません。
- `cp(1) <https://man.NetBSD.org/NetBSD-11.0/cp.1>`_ - ゼロサイズに見える場合でも、常に通常ファイルをコピーします。
- `expr(1) <https://man.NetBSD.org/NetBSD-11.0/expr.1>`_ - ":" および "length" においてバイト単位ではなくマルチバイトコードポイントを使用（POSIXで要求）。
- xfwp(1) - 削除。
- mkstr(1), xstr(1) - 削除（PDP-11時代の廃れたツール）。
- `curses(3) <https://man.NetBSD.org/NetBSD-11.0/curses.3>`_ - ncurses互換のため `define_key(3) <https://man.NetBSD.org/NetBSD-11.0/define_key.3>`_ の引数をconst化。
- `curses(3) <https://man.NetBSD.org/NetBSD-11.0/curses.3>`_ - `newterm(3) <https://man.NetBSD.org/NetBSD-11.0/newterm.3>`_ 、 `setterm(3) <https://man.NetBSD.org/NetBSD-11.0/setterm.3>`_ 関数の引数をconst化。
- `lagg(4) <https://man.NetBSD.org/NetBSD-11.0/lagg.4>`_ - laggに追加されたインターフェースへlaggのMTUをコピー。
- `ppp(4) <https://man.NetBSD.org/NetBSD-11.0/ppp.4>`_ - 機能していない複数のioctlを削除。
- `moused(8) <https://man.NetBSD.org/NetBSD-11.0/moused.8>`_ - 未公開のCオプションを削除。
- `mount(8) <https://man.NetBSD.org/NetBSD-11.0/mount.8>`_ - ``mount -v spec fs`` で出力される情報を削減。以前の出力には -vv を使用してください。

サードパーティコンポーネント
~~~~~~~~~~~~~~~~~~~~~~~~~~

- binutils - 2.42に更新。
- expat - 2.8.1に更新。
- openresolv - 3.16.3に更新。
- pam-u2f - 1.3.1に更新。
- tzdata, tzcode - 2026b (2026bgtzを使用) および tzcode2025bに更新。
- userspace-rsu - 0.15.0に更新。
- `Xorg(1) <https://man.NetBSD.org/NetBSD-11.0/Xorg.1>`_ - 21.1.22に更新。
- `awk(1) <https://man.NetBSD.org/NetBSD-11.0/awk.1>`_ - one true awk 20240817に更新。
- `ctwm(1) <https://man.NetBSD.org/NetBSD-11.0/ctwm.1>`_ - 4.1.0に更新。
- `gcc(1) <https://man.NetBSD.org/NetBSD-11.0/gcc.1>`_ - 12.5.0に更新。
- `gdb(1) <https://man.NetBSD.org/NetBSD-11.0/gdb.1>`_ - 15.1に更新。
- `less(1) <https://man.NetBSD.org/NetBSD-11.0/less.1>`_ - 643に更新。
- `mandoc(1) <https://man.NetBSD.org/NetBSD-11.0/mandoc.1>`_ - 1.14.6に更新。
- `openssl(1) <https://man.NetBSD.org/NetBSD-11.0/openssl.1>`_ - 3.5.7に更新。
- `pkg_add(1) <https://man.NetBSD.org/NetBSD-11.0/pkg_add.1>`_ - pkg_install-20250417に更新。
- `postfix(1) <https://man.NetBSD.org/NetBSD-11.0/postfix.1>`_ - 3.11.2に更新。
- `ssh(1) <https://man.NetBSD.org/NetBSD-11.0/ssh.1>`_ / `sshd(8) <https://man.NetBSD.org/NetBSD-11.0/sshd.8>`_ - 10.3に更新。
- `sqlite3(1) <https://man.NetBSD.org/NetBSD-11.0/sqlite3.1>`_ - 3.45.1に更新。
- `tmux(1) <https://man.NetBSD.org/NetBSD-11.0/tmux.1>`_ - 3.6bに更新。
- `yacc(1) <https://man.NetBSD.org/NetBSD-11.0/yacc.1>`_ - byacc-20240109に更新。
- `zstd(1) <https://man.NetBSD.org/NetBSD-11.0/zstd.1>`_ - 1.5.6に更新。
- `xz(1) <https://man.NetBSD.org/NetBSD-11.0/xz.1>`_ - 5.8.3に更新。
- `jemalloc(3) <https://man.NetBSD.org/NetBSD-11.0/jemalloc.3>`_ - 5.3.0に更新（sun2およびvaxを除く）。
- `libarchive(3) <https://man.NetBSD.org/NetBSD-11.0/libarchive.3>`_ - 3.7.7に更新。
- `pcap(3) <https://man.NetBSD.org/NetBSD-11.0/pcap.3>`_ - 1.10.5に更新。
- `openpam(3) <https://man.NetBSD.org/NetBSD-11.0/openpam.3>`_ - 20230627に更新。
- `terminfo(3) <https://man.NetBSD.org/NetBSD-11.0/terminfo.3>`_ - 20231209に更新。
- `zlib(3) <https://man.NetBSD.org/NetBSD-11.0/zlib.3>`_ - 1.3.1に更新。
- `acpi(4) <https://man.NetBSD.org/NetBSD-11.0/acpi.4>`_ - ACPICAを20241212に更新。
- `dhcpcd(8) <https://man.NetBSD.org/NetBSD-11.0/dhcpcd.8>`_ - 10.2.3に更新。
- `mdnsd(8) <https://man.NetBSD.org/NetBSD-11.0/mdnsd.8>`_ - 2559.1.1に更新。
- `named(8) <https://man.NetBSD.org/NetBSD-11.0/named.8>`_ - 9.20.22に更新。
- `ntpd(8) <https://man.NetBSD.org/NetBSD-11.0/ntpd.8>`_ - 4.2.8p18に更新。
- `pppd(8) <https://man.NetBSD.org/NetBSD-11.0/pppd.8>`_ - 2.5.2に更新。
- `tcpdump(8) <https://man.NetBSD.org/NetBSD-11.0/tcpdump.8>`_ - 4.99.5に更新。
- `unbound(8) <https://man.NetBSD.org/NetBSD-11.0/unbound.8>`_ - 1.25.1に更新。
- `wpa_supplicant(8) <https://man.NetBSD.org/NetBSD-11.0/wpa_supplicant.8>`_ / `hostapd(8) <https://man.NetBSD.org/NetBSD-11.0/hostapd.8>`_ - 2.11に更新。

完全な変更リストは、NetBSD 11.0リリースツリーのトップレベルディレクトリにある `CHANGES <https://cdn.NetBSD.org/pub/NetBSD/NetBSD-11.0_RC5/CHANGES>`_ および `CHANGES-11.0 <https://cdn.NetBSD.org/pub/NetBSD/NetBSD-11.0_RC5/CHANGES-11.0>`_ ファイルで確認できます。

NetBSD 11.0 RC5 の入手方法
--------------------------

NetBSD 11.0 RC5の完全なソースとバイナリは、世界中の多くのサイトからダウンロード可能です。`メインのCDN <https://cdn.NetBSD.org/pub/NetBSD/NetBSD-11.0_RC5/>`_ からダウンロードするか、お近くの `ミラーサイト <https://www.NetBSD.org/mirrors/>`_ を使用してください。NetBSD 11.0 RC5配布物のハッシュリストは、NetBSDセキュリティオフィサーのPGP鍵で署名されており、 `このファイル <https://cdn.NetBSD.org/pub/NetBSD/security/hashes/NetBSD-11.0_RC5_hashes.asc>`_ で入手できます。NetBSDは無料です。すべてのコードは制限のないライセンスの下にあり、誰にロイヤリティを支払うことなく使用可能です。無料のサポートサービスはメーリングリストやウェブサイト経由で利用可能です。商用サポートは様々なソースから提供されています。NetBSDに関するより広範な情報は、当社のウェブサイト `www.NetBSD.org <https://www.NetBSD.org/>`_ を参照してください。

NetBSD 11.0 がサポートするシステムファミリ
------------------------------------------

NetBSD 11.0リリースは、以下のシステムに対してサポートされたバイナリ配布物を提供します:

* `NetBSD/aarch64 <https://wiki.NetBSD.org/ports/aarch64/>`_ Arm 64-bit
* `NetBSD/acorn32 <https://wiki.NetBSD.org/ports/acorn32/>`_ Acorn RiscPC/A7000, VLSI RC7500
* `NetBSD/algor <https://wiki.NetBSD.org/ports/algor/>`_ Algorithmics, Ltd. MIPS評価ボード
* `NetBSD/alpha <https://wiki.NetBSD.org/ports/alpha/>`_ Digital/Compaq Alpha (64-bit)
* `NetBSD/amd64 <https://wiki.NetBSD.org/ports/amd64/>`_ Opteron、Athlon64などのAMDファミリプロセッサ、およびEM64T拡張を備えたIntel CPU
* `NetBSD/amiga <https://wiki.NetBSD.org/ports/amiga/>`_ Commodore AmigaおよびMacroSystem DraCo
* `NetBSD/amigappc <https://wiki.NetBSD.org/ports/amigappc/>`_ PowerPCベースAmigaボード
* `NetBSD/arc <https://wiki.NetBSD.org/ports/arc/>`_ Advanced RISC Computing仕様に従うMIPSベースマシン
* `NetBSD/atari <https://wiki.NetBSD.org/ports/atari/>`_ Atari TT030, Falcon, Hades
* `NetBSD/bebox <https://wiki.NetBSD.org/ports/bebox/>`_ Be Inc. BeBox
* `NetBSD/cats <https://wiki.NetBSD.org/ports/cats/>`_ Chalice Technology CATSおよびIntel EBSA-285評価ボード
* `NetBSD/cesfic <https://wiki.NetBSD.org/ports/cesfic/>`_ CES FIC8234 VMEプロセッサボード
* `NetBSD/cobalt <https://wiki.NetBSD.org/ports/cobalt/>`_ Cobalt Networks MIPSベースマイクロサーバ
* `NetBSD/dreamcast <https://wiki.NetBSD.org/ports/dreamcast/>`_ セガ ドリームキャスト
* `NetBSD/emips <https://wiki.NetBSD.org/ports/emips/>`_ Microsoft Research Extensible MIPSアーキテクチャ
* `NetBSD/epoc32 <https://wiki.NetBSD.org/ports/epoc32/>`_ Psion EPOC PDA
* `NetBSD/evbarm <https://wiki.NetBSD.org/ports/evbarm/>`_ 各種Armベース評価ボードおよびアプライアンス
* `NetBSD/evbmips <https://wiki.NetBSD.org/ports/evbmips/>`_ 各種MIPSベース評価ボードおよびアプライアンス
* `NetBSD/evbppc <https://wiki.NetBSD.org/ports/evbppc/>`_ 各種PowerPCベース評価ボードおよびアプライアンス
* `NetBSD/evbsh3 <https://wiki.NetBSD.org/ports/evbsh3/>`_ 各種Hitachi Super-H SH3およびSH4ベース評価ボードおよびアプライアンス
* `NetBSD/ews4800mips <https://wiki.NetBSD.org/ports/ews4800mips/>`_ NEC MIPSベースEWS4800ワークステーション
* `NetBSD/hp300 <https://wiki.NetBSD.org/ports/hp300/>`_ Hewlett-Packard 9000/300および400シリーズ
* `NetBSD/hpcarm <https://wiki.NetBSD.org/ports/hpcarm/>`_ StrongArmベースWindows CE PDAマシン
* `NetBSD/hpcmips <https://wiki.NetBSD.org/ports/hpcmips/>`_ MIPSベースWindows CE PDAマシン
* `NetBSD/hpcsh <https://wiki.NetBSD.org/ports/hpcsh/>`_ Hitachi Super-HベースWindows CE PDAマシン
* `NetBSD/hppa <https://wiki.NetBSD.org/ports/hppa/>`_ Hewlett-Packard 9000 Series 700ワークステーション
* `NetBSD/i386 <https://wiki.NetBSD.org/ports/i386/>`_ i486ファミリプロセッサ以降を搭載したIBM PCおよびPCクローン
* `NetBSD/ibmnws <https://wiki.NetBSD.org/ports/ibmnws/>`_ IBM Network Station 1000
* `NetBSD/iyonix <https://wiki.NetBSD.org/ports/iyonix/>`_ Castle Technology Iyonix ArmベースPC
* `NetBSD/landisk <https://wiki.NetBSD.org/ports/landisk/>`_ SH4プロセッサベースNASアプライアンス
* `NetBSD/luna68k <https://wiki.NetBSD.org/ports/luna68k/>`_ OMRON Tateisi Electric LUNAシリーズ
* `NetBSD/mac68k <https://wiki.NetBSD.org/ports/mac68k/>`_ Motorola 68k CPU搭載Apple Macintosh
* `NetBSD/macppc <https://wiki.NetBSD.org/ports/macppc/>`_ Apple PowerPCベースMacintoshおよびクローン
* `NetBSD/mipsco <https://wiki.NetBSD.org/ports/mipsco/>`_ MIPS Computer Systems Inc.ファミリのワークステーションおよびサーバ
* `NetBSD/mmeye <https://wiki.NetBSD.org/ports/mmeye/>`_ Brains mmEyeマルチメディアサーバ
* `NetBSD/mvme68k <https://wiki.NetBSD.org/ports/mvme68k/>`_ Motorola MVME 68kシングルボードコンピュータ
* `NetBSD/mvmeppc <https://wiki.NetBSD.org/ports/mvmeppc/>`_ Motorola PowerPC VMEシングルボードコンピュータ
* `NetBSD/netwinder <https://wiki.NetBSD.org/ports/netwinder/>`_ StrongArmベースNetWinderマシン
* `NetBSD/news68k <https://wiki.NetBSD.org/ports/news68k/>`_ Sony 68kベース「NET WORK STATION」シリーズ
* `NetBSD/newsmips <https://wiki.NetBSD.org/ports/newsmips/>`_ Sony MIPSベース「NET WORK STATION」シリーズ
* `NetBSD/next68k <https://wiki.NetBSD.org/ports/next68k/>`_ NeXT 68k「ブラック」ハードウェア
* `NetBSD/ofppc <https://wiki.NetBSD.org/ports/ofppc/>`_ OpenFirmware PowerPCマシン
* `NetBSD/pmax <https://wiki.NetBSD.org/ports/pmax/>`_ Digital MIPSベースDECstationsおよびDECsystems
* `NetBSD/prep <https://wiki.NetBSD.org/ports/prep/>`_ PReP (PowerPC Reference Platform) およびCHRPマシン
* `NetBSD/riscv <https://wiki.NetBSD.org/ports/riscv/>`_ RISC-Vベースデバイス
* `NetBSD/rs6000 <https://wiki.NetBSD.org/ports/rs6000/>`_ IBM RS/6000 MCAベースPowerPCマシン
* `NetBSD/sandpoint <https://wiki.NetBSD.org/ports/sandpoint/>`_ Motorola Sandpointリファレンスプラットフォーム（多くのPPCベースNASボックスを含む）
* `NetBSD/sgimips <https://wiki.NetBSD.org/ports/sgimips/>`_ Silicon Graphics MIPSベースワークステーション
* `NetBSD/shark <https://wiki.NetBSD.org/ports/shark/>`_ Digital DNARD ("shark")
* `NetBSD/sparc <https://wiki.NetBSD.org/ports/sparc/>`_ Sun SPARC (32-bit) およびUltraSPARC (32-bitモード)
* `NetBSD/sparc64 <https://wiki.NetBSD.org/ports/sparc64/>`_ Sun UltraSPARC (ネイティブ64-bitモード)
* `NetBSD/sun2 <https://wiki.NetBSD.org/ports/sun2/>`_ Motorola 68010 CPU搭載Sun Microsystems Sun 2マシン
* `NetBSD/sun3 <https://wiki.NetBSD.org/ports/sun3/>`_ Motorola 68020および030ベースSun 3および3xマシン
* `NetBSD/vax <https://wiki.NetBSD.org/ports/vax/>`_ Digital VAX
* `NetBSD/x68k <https://wiki.NetBSD.org/ports/x68k/>`_ Sharp X680x0シリーズ
* `NetBSD/xen <https://wiki.NetBSD.org/ports/xen/>`_ Xen仮想マシンモニタ
* `NetBSD/zaurus <https://wiki.NetBSD.org/ports/zaurus/>`_ Sharp Arm PDA

リリースに含まれるが、完全にはサポートされていない、または機能しないポート:

* `NetBSD/ia64 <https://wiki.NetBSD.org/ports/ia64/>`_ Itaniumファミリプロセッサ

謝辞
----

NetBSD Foundationは、長年にわたりコード、ハードウェア、ドキュメント、資金、サーバのコロケーション、ウェブページやその他のドキュメント、リリースエンジニアリング、その他のリソースに貢献してくださったすべての方々に感謝いたします。NetBSDを実現する人々に関する詳細情報は以下で入手可能です:
`www.NetBSD.org/people/ <https://www.netbsd.org/people/>`_

NetBSD について
---------------

NetBSDは、自由で高速、安全で移植性の高いUnixライクなオープンソースオペレーティングシステムです。大規模なサーバや強力なデスクトップシステムから、ハンドヘルドデバイスや組み込みデバイスまで、幅広いプラットフォームで利用可能です。そのクリーンな設計と高度な機能により、本番環境と研究環境の両方で優れた能力を発揮し、ソースコードはビジネスフレンドリーなライセンスの下で自由に利用可能です。NetBSDは、大規模で活発な国際的コミュニティによって開発・サポートされています。多くのアプリケーションは `pkgsrc, the NetBSD Packages Collection <https://pkgsrc.org>`_ を通じて容易に入手可能です。

NetBSD Foundation について
--------------------------

`NetBSD Foundation <https://www.netbsd.org/foundation/>`_ は1995年に設立され、NetBSDプロジェクトのコアサービスの監督、業界およびオープンソースコミュニティ内でのプロジェクトの推進、NetBSDコードベースの大部分に対する知的財産権の保持を任務としています。プロジェクトの日常的な運営はボランティアによって行われています。商業的後ろ盾のない非営利団体として、NetBSD Foundationはユーザからの寄付に依存しています。私たちの優れたオペレーティングシステムの継続的な制作を支援するために、`寄付 <https://www.netbsd.org/donations/>`_ を検討していただければ幸いです。寛大なご寄付は、継続的なアップグレードやメンテナンス、NetBSD Foundationの運営費を支援するために特に歓迎されます。寄付はPayPalから <paypal@NetBSD.org> へ、またはGoogle Checkout経由で行うことができ、米国では全額所得税控除の対象となります。詳細については `www.NetBSD.org/donations/ <https://www.netbsd.org/donations/#how-to-donate>`_ を参照するか、<finance-exec@NetBSD.org> へ直接ご連絡ください。

~~~~

出典: [Announcing NetBSD 11.0 RC5 (Jun 16, 2026)](https://www.netbsd.org/releases/formal-11/NetBSD-11.0.html)


