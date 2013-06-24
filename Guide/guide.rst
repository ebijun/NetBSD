==============
NetBSDのご紹介
==============

  #  こういうOSが欲しい
<br>
  世界中にあるコンピュータ、昔の計算機から最近のパソコン、組み込み系まで、身の回りで目についたすべてのコンピュータで動くOSは、どのようなものでしょうか？コンピュータに接続できる機器もたくさんあります。手持ちの周辺機器を全部利用できるOSを考えてみましょう。これまでに利用したことのあるソフトウエアすべてを動かすことのできるOSはどのようなものであればよいでしょうか？ソースコードを自由に読んだり、書いたり、引用したり、配布したり、売ったり買ったりできるOSを共同で作るためにはどのような枠組みがあればよいでしょうか？
  #  NetBSD
<br>
  NetBSDは、4.3/4.4BSD&386BSDベースのOSです。プロジェクトは1993年3月21日から開始していて、現在も活発に開発が進んでいます。60種類以上のハードウェアを、単一ソースツリーでサポートしています。
ハードウェア依存/非依存部分を分離しており、IPv6をはじめとする最新のネットワークプロトコルをサポートしています。ソースコードは、商用ルータ・プリンタ・家電製品・ゲーム機など、幅広い機器に組み込まれて
います。OSとして組み込まれることもあれば、ネットワーク機能など、一部のコードが取り込まれることもあります。
NetBSDのウエブサイトは、http://www.NetBSD.org/ です。
NetBSD全般に関するガイドは、http://www.NetBSD.org/docs/guide/en/ にあります。
  #  NetBSDで利用しているライセンス:2 条項 BSD ライセンス
<pre>
http://www.jp.NetBSD.org/ja/about/redistribution.html
Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions
are met:
  1. Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.
  2. Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the following disclaimer in the
     documentation and/or other materials provided with the distribution.
</pre>
  #  NetBSDで利用しているライセンス(訳)
<pre>
http://www.jp.NetBSD.org/ja/about/redistribution.html
ソースおよびバイナリー形式の再配布および使用を、変更の有無にかかわらず、
以下の条件を満たす場合に認める:
  1. ソースコードの再配布においては、上記の著作権表示、この条件の列挙、
     下記の注意書きを残すこと。
  2. バイナリー形式の再配布においては、上記の著作権表示、この条件の列挙、
     下記の注意書きを、配布物に附属した文書および/または他のものに再現
     させること。
このライセンスの前には著作権表示そのものが付きます。 この後には注意書きが付き、 このソフトウェアに関して問題が生じても、作者は責任を負わないと述べます。 
</pre>
  #  BSDライセンスとNetBSD
<pre>
NetBSDのソースコードを自由に売ることができます。NetBSDのソースコードから作ったバイナリを売ることもできます。バイナリのソースコードを公開する義務はありません。
</pre>
  #  ライセンス条項が異なるソースを分離する
<pre>
NetBSDの配布物には、2 条項 BSD ライセンスのソースコードで書かれているソフトウェアと、そうでないソフトウェアが含まれています。
NetBSDでは、ライセンス条項が違うソースコードをディレクトリごとに分けて管理しています。
/usr/src/dist:
  dhcp: http://www.isc.org/isc-license-1.0.html
  ipf: IPFILTER.LICENCE
  pdisk: READMEに書かれている
  :
/usr/src/crypto/dist
  ipsec-tools: 
/usr/src/external:
  atheros  gpl3       intel-fw-public public-domain
  bsd      historical lgpl2           realtek
  cddl     ibm-public lgpl3           zlib
  apache2  gpl2       intel-fw-eula   mit
</pre>
  #  単一ソースツリー
<pre>
NetBSDは、単一ソースツリーで15種類のCPUアーキテクチャと58種類以上のプラットホームで動きます。
CPU:

プラットホーム：

バス：
</pre>

16種類のバスサポート
ATA,CardBus,EISA,PCI,PCMCIA,VME
</pre>
  #  新しく移植するときには
<pre>
まず、機種に依存しない部品を組み合わせる
CPU..バス..
機種依存部分だけを追加する
サポートCPUアーキテクチャ
</pre>
  #  2008-2011年の変更点
<pre>
2011/8
GCC4.5.3
2010/6
add support for Cortex-A8
2010/4
add support for Sharp W-Zero3
2010/2
shared object file extension has been changed from .so to .pico
termcap database has been removed
2009/1
time_t and dev_t have been bumped to 64 bit quantities.
</pre>
  #  2038年問題
<pre>
1970/1/19 0:0:0 GMTからの経過秒数
2^31-1=2147483647
2,147,483,648秒以上を表示できるか
対応済み：date -r 2147483648
Tue Jan 19 12:14:08 JST 2038
未対応：date -r 2147483648
Tue Jan 19 12:14:07 JST 2038
</pre>
  #  Portsいろいろ
<pre>
Alpha
alpha
arm
acorn26
acorn32
cats
evbarm
hpcarm
Netwinder
shark
WZero3
evbarm
hppa
hp700
i386
i386
Pc98
IPv6 Hi-spec Routers
（FM Towns・FMR?)
m68010
sun2
m68k
Amiga
Atari
Cesfic
Hp300
Luna68k
Mac68k
Mvme68k
News68k
next68k
mips
Algor
Arc
Cobalt
evbmips
hpcmips
mipsco
newsmips
DEC Pmax
sbmips
Sgimips
Playstation2
Ns32k - 削除
pc532
powerpc
Amigappc
Bebox
evbppc
Macppc
mvmeppc
Ofppc
pmppc
Prep
Sandpoint
sh3
Dreamcast
Evbsh3
Hpcsh
Mmeye
IIJ SEIL
Home Routers
</pre>
  #  ドリームキャスト版CD
<pre>
http://ftp.netbsd.org/pub/NetBSD/misc/tsutsui/dreamcast/
dreamcastbootcd-20101010.tar.gz
CD-R付きNetBSDマシンで展開
CD-R入れる
makeすると、バイナリをダウンロードしてブートCDが焼ける
dreamcastに入れて起動
</pre>
sparc
sparc
sparc64
landisk
vax
vax
x86_64
AMD64
  #  Ｘ６８０３０
  # X68kエミュレータ
<pre>
XM6i
Windows上で動くX68000エミュレータ
NetBSDがブートします
http://www.xm6i.org/
OSC広島で祭り
21世紀のX68
CPU内部の挙動を細かく観測できる
 ATCエントリが見える
</pre>
  #  サポートハードウェア　56種類
  #  4.4BSD由来の機能
<pre>
Nullfs – loopbackマウント
Unionfs – ファイルシステムを重ねる
Lfs – 高速書き込み性能
NFS – NFSv3 NFSoverTCP
IP virtual hosting
</pre>
  #  NetBSD独自の改良
<pre>
NFS – WebNFS
NFS over IPv6
UVM　virtual memory system
UBC  unified buffer cache system
Cardbus
Wscons
USB ver2.0
64bit clean
Wireless networking
http://www.NetBSD.org/about/features.html
ZFS? Google Summer of Code
</pre>
  #  アーキテクチャに共通する部分
<pre>
Package system
バス　USB、CardBus
デバイスドライバ
オーディオフレームワーク
OSエミュレーション
バスサポート
</pre>
  #  仮想デバイス
<pre>
Concatenated disk driver
Memory disk driver
RAIDframe disk
Random device
Vnode disk
</pre>
  #  物理デバイス
<pre>
オーディオデバイス
WSCONS - ワークステーションコンソール
wsdisplay
wskbd
wsmouse
</pre>
  # NetBSD：カーネル
<pre>
機種に依存する部分
i386/MIPS/SH/68000…
デバイスに依存する部分
PCIバス/ISAバス/PCMCIA…
その他
メモリ管理
</pre>
  #  新しいマシンをサポートするには
<pre>
搭載CPUがサポートされているか？
搭載バスがサポートされているか？
搭載デバイスがサポートされているか？
共有部分はすべてで共有できる
サポートされていない部分だけを作り
　　　　CVSツリーに追加する
</pre>
  #  エミュレーション
  #  Package - /usr/pkgsrc 
<pre>
簡単にソフトウェアをコンパイル・インストール
1997年8月開始ー今年で13年目 
2011-Q2 もうすぐ準備
41種類のジャンル
9963種類以上のソフトウェア
Make installでソフトウェアのインストール
</pre>
  #  各CPUアーキテクチャ間で共通
<pre>
Mipsel –mips endian little
Arc – MIPSで動くNTマシン
Cobalt – Cobalt Qube1/2
Pmax – DEC station
Hpcmips – MIPS搭載WinCE
NetBSD/Solaris/Linux/Darwin/FreeBSD/OpenBSD/
IRIX/BSDOS/AIX/SUA(Interix)/DragonFlyBSD/OSF1/hpux
</pre>
  #  /usr/pkgsrc/emulators
<pre>
gxemul
mips (pmax,hpcmips)
dreamcast
simh
NetBSD/vax
tme
sun2,sun3,SPARCstation 2
QEMU
PC
USBデバッグ
</pre>
  #  Packagesジャンル一覧
  #  ソフトウェアのコンパイル／インストール
<pre>
drupal
cd /usr/pkgsrc/www/drupal6
make package
make install
関連するソフトウェアがインストール
OpenOffice
cd /usr/pkgsrc/misc/openoffice3
make package
make install
/usr/pkg/bin/soffice ....
</pre>
  #  NetBSDを使う時
<pre>
OSをインストールする
pkgsrc.tar.gzを取得
必要なパッケージをインストール
tcsh,icewm,kterm,anthy-elisp,ja-less
openoffice,firefox,gimp
</pre>
  #  目的別
<pre>
デスクトップ向け
組み込み向け
pkgsrc/meta-pkgにいくつかある
</pre>
  #  Package対応プラットフォーム
<pre>
NetBSD
FreeBSD
OpenBSD
BSD/OS
Solaris
Linux
DragonflyBSD
(SSD Linux)
</pre>
  #  Package – NetBSD以外での利用
  #  Packageとライセンスの取扱い
<pre>
個々のパッケージごとにLICENSE定義
受け入れられるライセンスを制御したい
ツールとライブラリのライセンスが違う
ツールがGPL,ライブラリがLGPL
GPLv2とv3が混在する例
rubyとreadline6
GPL2とGPL2 or laterの区別
GPL3とリンクできるかできないか
http://d.hatena.ne.jp/obache/20090922/
</pre>
  #  NetBSDのリリース
<pre>
リリース版2.0 3.0 4.0 5.0......
マイナーリリース　2.1.. 3.1...
パッチリリース　　　2.1.1... 3.1.1...
開発版　2.99 3.99 4.99 5.99...
カーネルAPIの変更があるとき 2.99.1...
</pre>
  #  NetBSD開発ロードマップ
  #  NetBSD5.1サポート機能
<pre>
RAIDframe parity maps, which greatly improve parity rewrite times  after unclean shutdown
X.Org updates
Support for many more network devices
Xen PAE dom0 support
Xen PCI pass-through support
</pre>
  #  NetBSD6.0に入れたい機能
<pre>
kernel modules
kernel scalability improvements
64bit time_t (solves year 2038 problem)
DTrace
ZFS
NILFS
Logical Volume Manager
NPF (New Packet Filter)
Thread Local Storage
Xen SMP support　
</pre>
  #  NetBSD6.0に入れたい機能(2)
<pre>
 automated tests
 improved puffs (Pass-to-Userspace Framework File System)
 improved rump (Runnable Userspace Meta Program kernel)
 UltraSPARC III(+) support
MIPS 64bit support
 a lot of updated and new 3rd party software
</pre>
  #  Automated Testing Framework
<pre>
cd /usr/tests;
atf-run | atf-report
</pre>
  #  組織構成
<pre>
Core 5人　テクニカルマネージメント
Port maintainer　28人
各実装に関する担当者
Developer
CVS/WWW/FTP等開発資産に書き込みできる
アクティブなのは188人
</pre>
  #  NetBSD Foundation,Inc
<pre>
デラウェア州の法人組織
サーバマシンを所有
お金と寄付を管理
NetBSDの版権を管理
</pre>
  #  developer
<pre>
直接ソースを変更できる
CVS/FTP/WWWサーバの内容
世界中で188人
GNATSでバグ管理
Cvsweb.netbsd.org
日本人38人
</pre>
NetBSD開発者世界分布図
NetBSD開発者分布図
  #  Developerになるには（1）
<pre>
	クリパでやったこと
PGP/GnuPGの鍵を作る
fingerprint印刷
gpg --fingerprint jun@soum.co.jp
fingerprint交換
他のDeveloperとfingerprint印刷を交換
本人確認
公的証明書を見せあって本人確認
</pre>
  #  Developerになるには(2)
<pre>
相手の鍵を取り込んで、fingerprint照合
gpg-email-confirm soda@netbsd.org..
ランダムな文字列を送る
メールを暗号化して送り返してもらう
送った文字列とメールアドレスを照合する
鍵にサインしてもらって送り返してもらう
Developerサイン入り自分の鍵ができる
自分の鍵束にimport
pgp.mit.eduにサイン入り自分の鍵を登録する
</pre>
  #  世界中で打ち合わせをする時間
<pre>
 May 21 03:00 PM -0700 America/Los_Angeles
 May 21 06:00 PM -0400 America/New_York
 May 21 11:00 PM +0100 Europe/London
 May 22 00:00 AM +0200 Europe/Berlin
 May 22 01:00 AM +0300 Europe/Helsinki
 May 22 07:00 AM +0900 Asia/Tokyo
 May 22 08:00 AM +1000 Australia/Melbourne
</pre>
  #  Port-maintainer
<pre>
移植責任者
57種類のうち15種類以上は日本人が担当
日本人担当ハードウェア15/56
NetBSD動作マシン＠日本
</pre>
  #  日本からの貢献
<pre>
国産ハードウェアサポート
ゲーム機・携帯情報端末サポート
IPv6/ IPSEC
Pkgsrc
CardBusサポート
MIPS/SH/m68K
NetBSD書籍が世界一多く出版される
developer53人
</pre>
  #  WindowsCE向けNetBSD
<pre>
MIPS系CPU搭載
NEC MobileGear
SHARP Tellios
SH系CPU搭載
HP　ジョルナダシリーズ
SEGA　DreamCast
StrongARM系CPU搭載
Ｃｏｍｐａｑ　ｉＰＡＱ
ＨＰ　ジョルナダシリーズ
WZero3
</pre>
  #  ブートまでの流れ
<pre>
コンパクトフラッシュを２分割
WindowsCEの領域
NetBSD/hpcmipsの領域
WindowsCE上のブートローダからブート
メモリ空間を取れるだけ確保する
カーネルファイルをメモリ空間に送り込んで
NetBSDの世界へ飛び込んでゆく
</pre>
  #  NetBSD/hpcsh
<pre>
SH搭載WindowsCEマシン向け
HP Jornada680 690 620LX
日立ペルソナ　HPW50　２３０
(NetBSD/sh3+NetBSD/hpcmips)/2＋α
従来の開発ノウハウとソフトウェア資産
NetBSD/hpcmipsとのソース共有化
NetBSD/Dreamcast互換
</pre>
  #  NetBSD/hpcarm
<pre>
StrongArm搭載WindowsCEマシン向け
SA-1100/1110対応
HP　Jornada７２０
WZero3
Compaq　iPAQ
hpcファミリー中最速
</pre>
  #  クロス開発環境
<pre>
NetBSD/i386でクロスコンパイル
build.sh –m hpcmips –D /hpcmips-root
Pkgsrc/cross以下に各種パッケージ
Windows環境でクロスコンパイル
Cygwinなど
Linux上でクロスコンパイル
FreeBSD上でクロスコンパイル
distcc - コンパイルだけ速いマシンで
pkgsrcをクロスコンパイル
pkgsrcのcrossbuildでググる！
http://www.lins.jp/~obata/diary/200803242.html
クロス用toolsを作る
</pre>
  #  バイナリ互換性を利用する
<pre>
Cobalt　Qube２でhpcmipsバイナリ作成
MIPSでendian little =mipsel同士なら動く
ユーザランドはほとんどそのまま動く
パッケージも共通化
NetBSD/{pmax,cobalt,arc,hpcmips}で共通
数GBある各種アプリケーション群を共通にする
</pre>
  #  エミュレーション環境
<pre>
Linux
I386以外のバイナリも動くようにする
FreeBSD
Windows2000/XP
PECOFF
Win32アプリケーションをそのまま動かす
ゲームなど
Unixware
</pre>
  #  移植成果をNetBSDに組み込む
<pre>
カーネル部分を移植する
セルフコンパイルでスナップショット作成
パッケージソフトウェアセットを作る
ドキュメント整備
Web・マニュアル・FAQ
インストーラを作る
メーリングリストを作る
</pre>
  #  プログラミング以外にすること
<pre>
Port登録　NetBSD/???? 部分
Webページ作成
バグレポートデータベース作成
GNATS
マニュアル作成
インストールマニュアル・マニュアル・FAQ
メーリングリスト作成
ニュースとして報告
</pre>
  #  EeePC&Netbook
<pre>
Escape押して起動ディスク選択
バックアップCDあり
ディスプレイ
82915GM
Attansic Technologies L2 100Mbit Ethernet Adapter
http://www.NetBSD.org/ports/i386/netbook.html
VAIO Type P
</pre>
  #  NetBSD開発者情報
<pre>
ftp/WWW/CVS/SUPサーバ
http://www.jp.netbsd.org/ja/JP/sites.html
開発環境設定方法
http://www.netbsd.org/developers/
メーリングリスト
http://www.jp.netbsd.org/ja/JP/ml.html
netbsd-request@re.soum.co.jp
1994/11- 　10年以上！　参加者600名
 http://releng.netbsd.org  
</pre>
  #  ソースコード取得方法
<pre>
ftp
Cvs
cvsup
Sup
Anonymous CVS
rsync
</pre>
  #  Japan NetBSD Users’ Group
<pre>
1999年8月21日成立
日本のNetBSDユーザに便宜を図る
FTP/CVS/WWWサーバの管理
ドキュメント・WWWページ翻訳
場所提供：IIJ
http://www.jp.netbsd.org/
年一度定期総会・BoFを実施
次回は2012/7/？
東京 根津　東大武田先端知ビル
</pre>
  #  www.netbsd.org　翻訳
<pre>
現在
www.netbsd.org上のCVSリポジトリ
削除→各国のwwwサーバ
各国の翻訳
ドイツ語
韓国語
ポーランド語
フランス語
緊急度の高い情報を正確に広報する
古いドキュメントでもあった方がいいか
そもそも英語のドキュメントは正確か
</pre>
  #  国内BSDユーザグループ
<pre>
http://www.netbsd.org/gallery/groups.html
BBQ
BSD Users Group,Shinshu
Chofu *BSD Users’ Group
Chiba *BSD Users’ Group
Daibou East *BSD Users Group
Echigo BSD Users Group
Kansai *BSD Users Group
Nagoya *BSD Users Group
Northern land BSD Users Group
Shikoku *BSD Users Group
Tohoku BSD Users Group
</pre>
  #  まとめ
<pre>
NetBSDはいろんなハードで動きます
自作ソフトをいろんなCPUで試せます
最初から移植を考えて設計されています
試作機に移植する工数が最小ですみます
自分の専門分野だけを組み込めます
自由に利用可能で再配布可能なOSです
移植するとIPv6マシンに変貌
さまざまなCPU向けIPv6スタックがあります
愛着あるハードウェアが生き返ります
最新のネットワークコードが利用できます
もしかしたらリサイクル団体なんでしょうか？
</pre>

