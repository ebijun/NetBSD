.. 
 Copyright (c) 2013 Jun Ebihara All rights reserved.
 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions
 are met:
 1. Redistributions of source code must retain the above copyright
    notice, this list of conditions and the following disclaimer.
 2. Redistributions in binary form must reproduce the above copyright
    notice, this list of conditions and the following disclaimer in the
    documentation and/or other materials provided with the distribution.
 THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

==============================
NetBSDのご紹介        
==============================

こういうOSが欲しい
-----------------
 世界中にあるコンピュータ、昔の計算機から最近のパソコン、組み込み系まで、身の回りで目についたすべてのコンピュータで動くOSは、どのようなものでしょうか？コンピュータに接続できる機器もたくさんあります。手持ちの周辺機器を全部利用できるOSを考えてみましょう。これまでに利用したことのあるソフトウェアすべてを動かすことのできるOSはどのようなものであればよいでしょうか？ソースコードを自由に読んだり、書いたり、引用したり、配布したり、売ったり買ったりできるOSを、世界中の人々と共同で作るためにはどのような枠組みがあればよいでしょうか？

NetBSD
-------
 NetBSDは、4.3/4.4BSD&386BSDベースのOSです。プロジェクトは1993年3月21日から開始していて、現在も活発に開発が進んでいます。60種類以上のハードウェアを、単一ソースツリーでサポートしています。

 ハードウェア依存/非依存部分を分離しており、IPv6をはじめとする最新のネットワークプロトコルをサポートしています。ソースコードは、商用ルータ・プリンタ・家電製品・ゲーム機など、幅広い機器に組み込まれています。OSとして組み込まれることもあれば、ネットワーク機能など、一部のコードが取り込まれることもあります。

 NetBSDのウエブサイトは、http://www.NetBSD.org/ です。

 NetBSD全般に関するガイドは、http://www.NetBSD.org/docs/guide/en/ にあります。

BSDライセンス
-------------

2 条項 BSD ライセンス
~~~~~~~~~~~~~~~~~~~~~
 http://www.jp.NetBSD.org/ja/about/redistribution.html

 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions
 are met:
 
 1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
 2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

2条項BSDライセンス(訳)
~~~~~~~~~~~~~~~~~~~~~~
 http://www.jp.NetBSD.org/ja/about/redistribution.html

 ソースおよびバイナリー形式の再配布および使用を、変更の有無にかかわらず、
 以下の条件を満たす場合に認める:
 
 1. ソースコードの再配布においては、上記の著作権表示、この条件の列挙、下記の注意書きを残すこと。
 2. バイナリー形式の再配布においては、上記の著作権表示、この条件の列挙、下記の注意書きを、配布物に附属した文書および/または他のものに再現させること。
 
 このライセンスの前には著作権表示そのものが付きます。 この後には注意書きが付き、 このソフトウェアに関して問題が生じても、作者は責任を負わないと述べます。 

BSDライセンスとNetBSD
~~~~~~~~~~~~~~~~~~~~~~
 NetBSDのソースコードを自由に売ることができます。NetBSDのソースコードから作ったバイナリを売ることもできます。バイナリのソースコードを公開する義務はありません。

ライセンス条項が異なるソースを分離する
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 NetBSDの配布物には、2 条項 BSD ライセンスのソースコードで書かれているソフトウェアと、そうでないソフトウェアが含まれています。
NetBSDでは、ライセンス条項が違うソースコードをディレクトリごとに分けて管理しています。

::

 %  ls /usr/src/external/
 CVS             atheros         gpl2            intel-fw-eula   mit
 Makefile        broadcom        gpl3            intel-fw-public public-domain
 README          bsd             historical      lgpl2           realtek
 apache2         cddl            ibm-public      lgpl3           zlib

NetBSDを使う時
--------------
* OSをインストールする
* pkgsrc.tar.gzを展開
* 必要なパッケージをインストール
* tcsh,icewm,kterm,anthy-elisp,ja-less
* openoffice,firefox,gimp

pkgsrcをダウンロード
~~~~~~~~~~~~~~~~~~~~
 pkgsrcのWebサイトはhttp://www.pkgsrc.org/です。pkgsrcは、一年に4回定期的にリリースされます。

::

 % ftp ftp://ftp.pkgsrc.org/pub/pkgsrc/
   pkgsrc-2012Q4
   pkgsrc-2013Q1
   pkgsrc-2013Q2
     :
 % ftp ftp://ftp.pkgsrc.org/pub/pkgsrc/stable/pkgsrc.tar.gz
 日本のミラーの場合：
 % ftp ftp://ftp7.jp.NetBSD.org/pub/pkgsrc/stable/pkgsrc.tar.gz　

/usr/pkgsrcにダウンロードしたtar ファイルを展開してみましょう。

::

 % su
 # tar xzvf pkgsrc.tar.gz -C /usr   ... /usr以下に展開します。
 # ls /usr/pkgsrc
 CVS          comms        finance      math         pkglocate    wip
 Makefile     converters   fonts        mbone        pkgtools     wip-jp
 README       cross        games        meta-pkgs    print        wm
 archivers    databases    geography    misc         regress      www
 audio        devel        graphics     mk           security     x11
 benchmarks   distfiles    ham          multimedia   shells
 biology      doc          inputmethod  net          sysutils
 bootstrap    editors      lang         news         templates
 cad          emulators    licenses     packages     textproc
 chat         filesystems  mail         parallel     time

ソフトウェアをコンパイルしてインストールする枠組みが、/usr/pkgsrc/ジャンル/ソフトウェア名 以下にあります。
OpenOfficeをコンパイルして、インストールしたいときには、次のようにコマンドを実行します。

::

 # cd /usr/pkgsrc/misc/openoffice
 # make package-install

うまくコンパイルしてインストールできると、openofficeを実行出来ます。

::

 % soffice

pkgsrcを使ってみる
~~~~~~~~~~~~~~~~~~
 「RaspberryPIでmikutterというtwitterクライアントを使いたい」場合を考えてみます。
インストールできそうなソフトウェアは、/usr/pkgsrc/ジャンル名以下にディレクトリがあります。
ここに使いたいソフトウェアがあれば、コンパイルしてインストールできるかもしれません。

::

 % ls /usr/pkgsrc/* |grep mikutter
 mikutter                        .... pkgsrcにmikutterがある!
 % cd /usr/pkgsrc/*/mikutter     .... ジャンルはわからないけど移動
 % pwd
 /usr/pkgsrc/net/mikutter        .... "net" の下にあった
 % ls
 CVS       DESCR     Makefile  PLIST     distinfo  files
 % cat DESCR                     .... ソフトウェアの説明
 Mikutter is a Twitter client aim for endsville Twitter client For all of
 Miku-aholics and Twitter-holics.
 % cat Makefile
 # $NetBSD: Makefile,v 1.68 2013/06/23 01:09:43 tsutsui Exp $
 #
  
 DISTNAME=       mikutter.0.2.2.1264    ... mikutterのバージョンとか
 PKGNAME=        ${RUBY_PKGPREFIX}-${DISTNAME:S/./-/}
 CATEGORIES=     net 
 MASTER_SITES=   http://mikutter.hachune.net/bin/  ... 配布サイト
 
 MAINTAINER=     obache@NetBSD.org　　　　　　　　　　 ... このパッケージを管理している人
 HOMEPAGE=       http://mikutter.hachune.net/      ... ソフトウェアのホームページ
 COMMENT=        Simple, powerful, and moeful twitter client  .. 一行説明
 LICENSE=        gnu-gpl-v3 AND cc-by-sa-v3.0      ... ソフトウェアのライセンス
 
 RUBY_VERSION_SUPPORTED= 193
 
 .include "../../lang/ruby/rubyversion.mk"
 
 DEPENDS+=       xdg-utils-[0-9]*:../../misc/xdg-utils　　... 依存しているソフトウェア
 DEPENDS+=       ${RUBY_PKGPREFIX}-hmac>=0.4.0:../../security/ruby-hmac
                 :
 % cat PLIST　　　　　　　　　　　　　　　　　　 ... インストールするファイルの一覧です
 @comment $NetBSD: PLIST,v 1.23 2013/05/15 11:24:14 obache Exp $
 bin/mikutter                          　　... /usr/pkg/bin/mikutterにインストールされます                 
 share/applications/mikutter.desktop      
 share/doc/mikutter/README
 share/mikutter/core/boot/check_config_permission.rb
 share/mikutter/core/boot/load_plugin.rb
 share/mikutter/core/boot/mainloop.rb
 share/mikutter/core/boot/option.rb
 
 % distinfo  .... ダウンロードするファイルの一覧とチェックサム
 $NetBSD: distinfo,v 1.60 2013/06/16 08:58:06 obache Exp $
 
 SHA1 (mikutter.0.2.2.1264.tar.gz) = f93757ca51f3fe9f555df32c86c2ed7021992887
 RMD160 (mikutter.0.2.2.1264.tar.gz) = bd3f4a49eb8d96a225b4cc704115995fe390e42a
 Size (mikutter.0.2.2.1264.tar.gz) = 2318031 bytes

mikutterと、mikutterをインストールするために必要なソフトウェアをインストールします。

::

 % su
 # cd /usr/pkgsrc/net/mikutter
 # make package-install

RaspberryPIで使いそうなソフトを一気にインストールする
""""""""""""""""""""""""""""""""""""""""""""""""""""
/usr/pkgsrc/ジャンル名を眺めて、使いそうなソフトウェアをリストアップします。

::

 % cat List 
 kterm
 tcsh
 vlgothic-ttf
 icewm
 xli
 mikutter
 uim
 fossil
 sudo
 scmgit-base
 zsh
 dillo

簡単なシェルスクリプトを作って、実行します。コンパイルがうまく進めば、必要なソフトウェアがすべてソースコードからコンパイル・インストールされた状態になります。

::

 % cat Package
 for i in `cat List`
 do
   cd /usr/pkgsrc/*/$i
   make package-install
 done
 % su
 # sh Package
 # pkg_info      .... インストールされたパッケージの一覧を表示します。

pkgsrcを更新する
~~~~~~~~~~~~~~~~
まず/usr/pkgsrcを更新し、次に、必要なソフトウェアを再コンパイルします。

* /usr/pkgsrcを更新します

::

 # cd /usr/pkgsrc
 # cvs update -PAd               ... 最新版に上げる
 # cvs update -Pdr pkgsrc-2013Q2 ... 2013Q2に上げる

* 更新が必要なソフトウェアを更新します
 pkg_chkコマンド、またはpkg_rolling-replaceコマンドで更新します。

::

 # pkg_chk -u
 
 # cd /usr/pkgsrc/pkgtools/pkg_rolling-replace 
 # make package-install
 # /usr/pkg/bin/pkg_rolling-replace

単一ソースツリー
---------------

NetBSDは、単一ソースツリーで15種類のCPUアーキテクチャと58種類以上のプラットホームで動きます。

::

 % ls /usr/src/sys/arch
 CVS          bebox        hp300        m68k         pmax         sun3
 Makefile     cats         hp700        mac68k       powerpc      sun68k
 README       cesfic       hpc          macppc       prep         usermode
 acorn26      cobalt       hpcarm       mips         rs6000       vax
 acorn32      dreamcast    hpcmips      mipsco       sandpoint    x68k
 algor        emips        hpcsh        mmeye        sbmips       x86
 alpha        epoc32       hppa         mvme68k      sgimips      xen
 amd64        evbarm       i386         mvmeppc      sh3          zaurus
 amiga        evbmips      ia64         netwinder    sh5
 amigappc     evbppc       ibmnws       news68k      shark
 arc          evbsh3       iyonix       newsmips     sparc
 arm          evbsh5       landisk      next68k      sparc64
 atari        ews4800mips  luna68k      ofppc        sun2

ソースコードからNetBSDをコンパイルする
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

ソースコードからNetBSDのインストールCDをコンパイルしてみましょう。

ダウンロード
""""""""""""
ソースコードをダウンロードします。

::

 % ftp ftp://ftp.jp.NetBSD.org/pub/NetBSD/NetBSD-current/tar_files/src.tar.gz

展開
""""

ソースコードを展開します。

::

 % tar xvzf src.tar.gz


コンパイル
""""""""""
ここではbuild.shを利用して、i386用のバイナリを作ってみます。

* -U
 スーパーユーザー以外の権限でコンパイルするときに指定します。

* -m 機種種類
 どの機種向けの実行ファイルを作るのか指定します。

::

 % cd src
 % ./build.sh -U -m i386 release
        :
 ===> Successful make release
 ===> build.sh ended:      Tue Jul  2 15:37:03 JST 2013
 ===> Summary of results:
         build.sh command:    ./build.sh -U -m i386 release
         build.sh started:    Tue Jul  2 17:38:40 JST 2013
         NetBSD version:      6.99.22
         MACHINE:             i386
         MACHINE_ARCH:        i386
         Build platform:      Linux 2.6.32-358.11.1.el6.centos.plus.x86_64 x86_64
         HOST_SH:             /bin/sh
         No $TOOLDIR/bin/nbmake, needs building.
	 Bootstrapping nbmake
	  MAKECONF file:       /etc/mk.conf (File not found)
	 TOOLDIR path:        /home/jun/NetBSD/src/obj/tooldir.Linux-2.6.32-358.11.1.el6.centos.plus.x86_64-x86_64
	 DESTDIR path:        /home/jun/NetBSD/src/obj/destdir.i386
	 RELEASEDIR path:     /home/jun/NetBSD/src/obj/releasedir
	 Created /home/jun/NetBSD/src/obj/tooldir.Linux-2.6.32-358.11.1.el6.centos.plus.x86_64-x86_64/bin/nbmake
	 Updated makewrapper: /home/jun/NetBSD/src/obj/tooldir.Linux-2.6.32-358.11.1.el6.centos.plus.x86_64-x86_64/bin/nbmake-i386
	 Successful make release
	 build.sh ended:      Tue Jul  2 19:37:03 JST 2013
 ===> .

コンパイルが正常に終了しました。NetBSD/i386のファイルができています。

::

 % ls /home/jun/NetBSD/src/obj/releasedir/i386
 INSTALL.html  INSTALL.more  INSTALL.ps  INSTALL.txt  binary  installation
 $ ls /home/jun/NetBSD/src/obj/releasedir/i386/binary/sets/
 MD5       etc.tgz              kern-XEN3PAE_DOM0.tgz  man.tgz      text.tgz
 SHA512    games.tgz            kern-XEN3PAE_DOMU.tgz  misc.tgz
 base.tgz  kern-GENERIC.tgz     kern-XEN3_DOM0.tgz     modules.tgz
 comp.tgz  kern-MONOLITHIC.tgz  kern-XEN3_DOMU.tgz     tests.tgz

次に、OSのCD-ROMイメージを作ってみましょう。

::

 % ./build.sh -U -m i386 iso-image
       :
     RELEASEDIR path:     /home/jun/NetBSD/src/obj/releasedir
       :
     Successful make iso-image

正常に終了すると、NetBSD/i386のCD-ROMイメージができています。

::

 $ ls /home/jun/NetBSD/src/obj/releasedir/images/
 NetBSD-6.99.22-i386.iso          ..... CDROMイメージができました！

次に、USBメモリに書き込むとブートするインストールイメージを作ってみましょう。

::

 % ./build.sh -U -m i386 install-image
  RELEASEDIR path:     /home/jun/NetBSD/src/obj/releasedir
       :
  Successful make install-image
 $ ls /home/jun/NetBSD/src/obj/releasedir/images/
 MD5  NetBSD-6.99.22-i386-install.img.gz  NetBSD-6.99.22-i386.iso  SHA512
     ...... USBメモリにコピーするとインストールできるイメージができました！

次に、USBメモリに書き込むとそのまま使えるLiveイメージを作ってみましょう。

::

 % ./build.sh -U -m i386 live-image
  RELEASEDIR path:     /home/jun/NetBSD/src/obj/releasedir
 $ ls  /home/jun/NetBSD/src/obj/releasedir/images/
 MD5
 NetBSD-6.99.22-i386-install.img.gz
 NetBSD-6.99.22-i386-live-sd0root.img.gz ... liveイメージができました！
 NetBSD-6.99.22-i386-live-wd0root.img.gz
 NetBSD-6.99.22-i386.iso
 SHA512

X11も作ってみる
"""""""""""""""
X11を含んだ形のCD-ROMイメージを作ってみましょう。

::

 % cd ..
 % ls
 src  src.tar.gz
 % ftp ftp://ftp.jp.NetBSD.org/pub/NetBSD/NetBSD-current/tar_files/xsrc.tar.gz
 % tar xzvf xsrc.tar.gz
 % ls
 src  src.tar.gz  xsrc  xsrc.tar.gz
 % cd src
 % ./build.sh -U -u -X ../xsrc -x -m i386 release
 -u オプション: 初期化しない
 -X [パス名]  : Xを作る。パス名を指定しない場合/usr/xsrc

Xのコンパイルができました。X関連のtgzファイルができています。

::

 % $ ls /home/jun/NetBSD/src/obj/releasedir/i386/binary/sets
 MD5       games.tgz              kern-XEN3_DOM0.tgz  tests.tgz  xfont.tgz
 SHA512    kern-GENERIC.tgz       kern-XEN3_DOMU.tgz  text.tgz   xserver.tgz
 base.tgz  kern-MONOLITHIC.tgz    man.tgz             xbase.tgz
 comp.tgz  kern-XEN3PAE_DOM0.tgz  misc.tgz            xcomp.tgz
 etc.tgz   kern-XEN3PAE_DOMU.tgz  modules.tgz         xetc.tgz

Xを含むCD-ROM/起動イメージを作ってみましょう。

::

 % ./build.sh -U -u -m i386 iso-image
 % ./build.sh -U -u -m i386 install-image
 % ./build.sh -U -u -m i386 live-image
 % ls ls /home/jun/NetBSD/src/obj/releasedir/images/
 MD5
 NetBSD-6.99.22-i386-install.img.gz
 NetBSD-6.99.22-i386-live-sd0root.img.gz
 NetBSD-6.99.22-i386-live-wd0root.img.gz
 NetBSD-6.99.22-i386.iso
 SHA512

TireI/II/III
~~~~~~~~~~~~~~

Tier I
""""""
.. csv-table:: Tier I: Focus — support is part of NetBSD's strategy 

 Port, CPU, Machines, Latest Release
 amd64, x86_64, 64-bit x86-family machines with AMD and Intel CPUs, 6.1
 evbarm, arm, ARM evaluation boards, 6.1
 evbmips, mips, MIPS-based evaluation boards, 6.1
 evbppc, powerpc, PowerPC-based evaluation boards, 6.1
 hpcarm, arm, StrongARM based Windows CE PDA machines, 6.1
 i386, i386, 32-bit x86-family generic machines ("PC clones"), 6.1
 sparc64, sparc, Sun UltraSPARC (64-bit), 6.1
 xen, i386 x86_64, Xen Virtual Machine Monitor, 6.1

Tier II
"""""""

.. csv-table:: Tier II: Organic — evolving at its own pace

 Port,CPU,Machines,Latest Release
 acorn26,arm,"Acorn Archimedes, A-series and R-series systems",6.1
 acorn32,arm,Acorn RiscPC/A7000/NC and compatibles,6.1
 algor,mips,Algorithmics MIPS evaluation boards,6.1
 alpha,alpha,Digital Alpha (64-bit),6.1
 amiga,m68k,"Commodore Amiga, MacroSystem DraCo",6.1
 amigappc,powerpc,PowerPC-based Amiga boards,6.1
 arc,mips,Machines following the Advanced RISC Computing spec,6.1
 atari,m68k,"Atari TT030, Falcon, Hades",6.1
 bebox,powerpc,Be Inc's BeBox,6.1
 cats,arm,Chalice Technology's Strong Arm evaluation board,6.1
 cesfic,m68k,CES's FIC8234 VME processor board,6.1
 cobalt,mips,Cobalt Networks' Microservers,6.1
 dreamcast,sh3,Sega Dreamcast game console,6.1
 emips,mips,"Machines based on ""Extensible MIPS""",6.1
 evbsh3,sh3,Evaluation boards with Renesas (Hitachi) Super-H SH3 and SH4 CPUs,6.1
 ews4800mips,mips,NEC's MIPS based EWS4800 workstations,6.1
 hp300,m68k,Hewlett-Packard 9000/300 and 400 series,6.1
 hp700,hppa,Hewlett-Packard 9000/700 series,6.1
 hpcmips,mips,MIPS based Windows CE PDA machines,6.1
 hpcsh,sh3,Renesas (Hitachi) SH3 and SH4 based Windows CE PDA machines,6.1
 ia64,itanium,Itanium family of processors,none
 ibmnws,powerpc,IBM Network Station Series 1000,6.1
 iyonix,arm,Iyonix ARM pc,6.1
 landisk,sh3,SH4 based NAS appliances by I-O DATA,6.1
 luna68k,m68k,OMRON Tateisi Electronics' LUNA series,6.1
 mac68k,m68k,Apple Macintosh,6.1
 macppc,powerpc,Apple Power Macintosh and clones,6.1
 mipsco,mips,Mips family of workstations and servers,6.1
 mmeye,sh3,Brains' mmEye Multi Media Server,6.1
 mvme68k,m68k,Motorola MVME 68k SBCs,6.1
 mvmeppc,powerpc,Motorola MVME PowerPC SBCs,6.1
 netwinder,arm,StrongARM based NetWinder machines,6.1
 news68k,m68k,"Sony's m68k based ""NET WORK STATION"" series",6.1
 newsmips,mips,"Sony's MIPS based ""NET WORK STATION"" series",6.1
 next68k,m68k,NeXT 68k 'black' hardware,6.1
 ofppc,powerpc,Generic OpenFirmware compliant PowerPC machines,6.1
 pmax,mips,Digital MIPS-based DECstations and DECsystems,6.1
 prep,powerpc,PReP (PowerPC Reference Platform) and CHRP machines,6.1
 rs6000,powerpc,MCA-based IBM RS/6000 workstations,6.1
 sandpoint,powerpc,Motorola Sandpoint reference platform,6.1
 sbmips,mips,Broadcom SiByte evaluation boards,6.1
 sgimips,mips,Silicon Graphics' MIPS-based workstations,6.1
 shark,arm,"Digital DNARD (""shark"")",6.1
 sparc,sparc,Sun SPARC (32-bit),6.1
 sun2,m68k,Sun 2,6.1
 sun3,m68k,Sun 3 and 3x,6.1
 vax,vax,Digital VAX,6.1
 x68k,m68k,Sharp X680x0 series,6.1
 zaurus,arm,Sharp C7x0/C860/C1000/C3x00 series PDA,6.1

Tier III: Life Support — severely incapacitated or broken
""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
 TierIII状態のPortはありません。

サポートしているCPU
-------------------

.. csv-table:: Ports by CPU architecture

 CPU,Tier(s),Port(s)
 alpha,II,alpha
 arm,"I, II",acorn26  acorn32  cats  evbarm  hpcarm  iyonix  netwinder  shark  zaurus  
 hppa,II,hp700
 i386,I,i386  xen 
 m68010,II,sun2 
 m68k,II,amiga  atari  cesfic  hp300  luna68k  mac68k  mvme68k  news68k  next68k  sun3  x68k 
 mipseb,"I, II",emips  evbmips ews4800mips  mipsco  newsmips  sbmips sgimips 
 mipsel,"I, II",algor  arc  cobalt  evbmips  hpcmips  pmax  sbmips 
 powerpc,"I, II",amigappc  bebox  evbppc ibmnws macppc  mvmeppc  ofppc  prep  rs6000  sandpoint 
 sh3eb,II,evbsh3 mmeye 
 sh3el,II,dreamcast  evbsh3  landisk  hpcsh 
 sparc,II,sparc 
 sparc64,I,sparc64 (Can also run sparc binaries)
 vax,II,vax
 x86_64,I,"amd64 (Can also run i386 binaries), xen"

NetBSDを使ってみる
------------------

ておくれイメージ
~~~~~~~~~~~~~~~~

筒井さんが配布しているNetBSD/i386,amd64,WZero3で動作する
イメージファイルがあります。
NetBSDの設定例としても優れているので、一読をおすすめします。

::

 http://www.ceres.dti.ne.jp/tsutsui/netbsd/liveimage  ...i386/amd64 
 http://www.ceres.dti.ne.jp/tsutsui/netbsd/liveimage/wzero3.html ..WZero3

RaspberryPI用NetBSDイメージ
~~~~~~~~~~~~~~~~~~~~~~~~~~~
RaspberryPI用NetBSDイメージを配布しています。SDカードにコピーして、RaspberryPIから起動すると動作します。

::

 ftp://ftp.netbsd.org/pub/NetBSD/misc/jun/raspberry-pi/
 ftp://ftp.netbsd.org/pub/NetBSD/misc/jun/raspberry-pi/README-RPI.pdf


ドリームキャスト版CD
~~~~~~~~~~~~~~~~~~~~

http://ftp.netbsd.org/pub/NetBSD/misc/tsutsui/dreamcast/
 dreamcastbootcd-20101010.tar.gz
#. CD-R付きNetBSDマシンで展開します。
#. CD-R入れる
#. makeすると、バイナリをダウンロードしてブートCDが焼ける
#. dreamcastに入れるとNetBSDが起動します。

X68030エミュレータ XM6i
~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Windows/NetBSD/CentOS上で動くX68000エミュレータです。

* NetBSD/x68kがブートします
* http://xm6i.org/
* OSC広島で祭り
* 21世紀のX68→実機デバッグ＆エミュレータデバッグ
* CPU内部の挙動を細かく観測できる
* ATCエントリが見える

WindowsCE向けNetBSD
~~~~~~~~~~~~~~~~~~~~~

MIPS系CPU搭載
 NEC MobileGear
 SHARP Tellios
SH系CPU搭載
 HP Jornadaシリーズ
 SEGA　DreamCast
ARM系CPU搭載
 Compaq iPAQ
 HP Jornadaシリーズ
 WZero3

ブートまでの流れ
""""""""""""""""
コンパクトフラッシュを２分割します
 WindowsCEの領域
 NetBSD/hpcmipsの領域
WindowsCE上のブートローダからブート
 メモリ空間を取れるだけ確保する
カーネルファイルをメモリ空間に送り込んで
 NetBSDを起動します

NetBSD/hpcsh
""""""""""""""
* SH搭載WindowsCEマシン向け
* HP Jornada680 690 620LX
* 日立ペルソナ　HPW50　２３０
* (NetBSD/sh3+NetBSD/hpcmips)/2＋α
* 従来の開発ノウハウとソフトウェア資産
* NetBSD/hpcmipsとのソース共有化
* NetBSD/Dreamcast互換

NetBSD/hpcarm
""""""""""""""""
* StrongArm搭載WindowsCEマシン向け
* SA-1100/1110対応
* HP　Jornada７２０
* WZero3
* Compaq　iPAQ
* hpcファミリー中最速

NetBSD/evbarm
"""""""""""""""
* RPI
* Gumstix
* Netwalker
* (KOBO)

新しく移植するときには
--------------------

#. まず、機種に依存しない部品を組み合わせます CPU..バス..
#. 次に機種依存部分だけを追加します
#. 足りない部分を作りこみます
#. 自分で自分をコンパイルして、配布できる状態にします
#. pkgsrcにあるソフトウェアを実際に動かしてみます
#. 何か目的を持った配布イメージを配ってみます
　twitterクライアント,Webサーバ....

移植成果をNetBSDに組み込む
--------------------------
* カーネル部分を移植する
* セルフコンパイルでスナップショット作成
* パッケージソフトウェアセットを作る
* ドキュメント整備
* Web・マニュアル・FAQ
* インストーラを作る
* メーリングリストを作る

プログラミング以外にすること
~~~~~~~~~~~~~~~~~~~~~~~~~~
* Port登録　NetBSD/???? 部分
* Webページ作成
* バグレポートデータベース作成
* GNATS
* マニュアル作成
* インストールマニュアル・マニュアル・FAQ
* メーリングリスト作成
* ニュースとして報告

アーキテクチャに共通する部分
~~~~~~~~~~~~~~~~~~~~~~~~~~
* Package system
* バス　USB、CardBus
* デバイスドライバ
* オーディオフレームワーク
* OSエミュレーション
* バスサポート

仮想デバイス
~~~~~~~~~~~~
* Concatenated disk driver
* Memory disk driver
* RAIDframe disk
* Random device
* Vnode disk

物理デバイス
~~~~~~~~~~~~
* オーディオデバイス
* WSCONS - ワークステーションコンソール
* wsdisplay
* wskbd
* wsmouse

4.4BSD由来の機能
~~~~~~~~~~~~~~~~
* nullfs – loopbackマウント
* unionfs – ファイルシステムを重ねる
* lfs – 高速書き込み性能
* NFS – NFSv3 NFSoverTCP
* IP virtual hosting

NetBSD独自の改良
~~~~~~~~~~~~~~~~
* NFS – WebNFS
* NFS over IPv6
* UVM　virtual memory system
* UBC  unified buffer cache system
* Cardbus
* Wscons
* USB ver2.0
* 64bit clean
* Wireless networking
  http://www.NetBSD.org/about/features.html
  ZFS? Google Summer of Code

2038年問題
~~~~~~~~~~
* 1970/1/19 0:0:0 GMTからの経過秒数
* 2^31-1=2147483647
* 2,147,483,648秒以上を表示できるか
* 対応済み：date -r 2147483648
* Tue Jan 19 12:14:08 JST 2038
* 未対応：date -r 2147483648
* Tue Jan 19 12:14:07 JST 2038

NetBSD：カーネル
----------------
* 機種に依存する部分
  i386/MIPS/SH/68000…
* デバイスに依存する部分
  PCIバス/ISAバス/PCMCIA…
* その他
  メモリ管理

新しいマシンをサポートするには
~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* 搭載CPUがサポートされているか？
* 搭載バスがサポートされているか？
* 搭載デバイスがサポートされているか？
* 共有部分はすべてで共有できる
* サポートされていない部分だけを作り、CVSツリーに追加する

Package - /usr/pkgsrc 
------------------------
* 簡単にソフトウェアをコンパイル・インストール
* 1997年8月開始
* 201?-Q[1-4] もうすぐ準備
* 41種類のジャンル
* 9963種類以上のソフトウェア
* Make installでソフトウェアのインストール

各CPUアーキテクチャ間で共通
~~~~~~~~~~~~~~~~~~~~~~~~~~
* mipsel –mips endian little
* arc – MIPSで動くNTマシン
* cobalt – Cobalt Qube1/2
* pmax – DEC station
* hpcmips – MIPS搭載WinCE

/usr/pkgsrc/emulators
~~~~~~~~~~~~~~~~~~~~~~~~
* gxemul
* mips (pmax,hpcmips)
* dreamcast
* simh
* NetBSD/vax
* tme
* sun2,sun3,SPARCstation 2
* QEMU
* PC
* USBデバッグ

Packagesジャンル一覧
~~~~~~~~~~~~~~~~~~~~~

.. csv-table:: The NetBSD Packages Collection

   x11, Packages to support the X window system
   archivers, Archivers
   audio, Audio tools
   benchmarks, Benchmarking tools
   biology, Software for the biological sciences
   cad, CAD tools
   chat, Communication programs
   comms, Communication utilities
   converters, Document format and character code converters
   cross, Cross-platform development utilities
   databases, Databases
   devel, Development utilities
   editors, Editors
   emulators, Emulators for other operating systems
   filesystems, File systems and file system related packages
   finance, Monetary financial and related applications
   fonts, Fonts
   games, Games
   geography, Software for geographical-related uses
   graphics, Graphics tools and libraries
   ham, Wireless communication tools and applications
   inputmethod, Input method tools and libraries
   lang, Programming languages
   mail, Electronic mail utilities
   math, Mathematics
   mbone, Multi-cast backBone applications
   meta-pkgs, Collections of other packages
   misc, Miscellaneous utilities
   multimedia, Multimedia utilities
   net, Networking tools
   news, Network news
   parallel, Applications dealing with parallelism in computing
   pkgtools, Tools for use in the packages collection
   print, Desktop publishing
   security, Security tools
   shells, Shells
   sysutils, System utilities
   textproc, Text processing utilities (does not include desktop publishing)
   time,Clocks calendars daily planners and other time related applications
   wm, X11 window managers configuration tools and themes
   www, Packages related to the World Wide Web

ソフトウェアのコンパイル／インストール
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
drupal

::

 cd /usr/pkgsrc/www/drupal6
 make package
 make install

OpenOffice

::

 cd /usr/pkgsrc/misc/openoffice3
 make package
 make install
 /usr/pkg/bin/soffice ....

目的別
~~~~~~
* デスクトップ向け
* 組み込み向け
* pkgsrc/meta-pkgにいくつかある

Package対応プラットフォーム
~~~~~~~~~~~~~~~~~~~~~~~~~~~

#. NetBSD
#. Solaris / SmartOS / illumos
#. Linux
#. Darwin (Mac OS X)
#. FreeBSD
#. OpenBSD
#. IRIX
#. AIX
#. DragonFlyBSD
#. OSF/1
#. HP-UX
#. QNX
#. Haiku
#. MirBSD
#. Minix3
#. Cygwin

NetBSD以外でpkgsrc
~~~~~~~~~~~~~~~~~~

::

 # tar xzvf pkgsrc.tgz
 # cd pkgsrc/bootstrap
 # ./bootstrap

Packageとライセンスの取扱い
~~~~~~~~~~~~~~~~~~~~~~~~~~~
* 個々のパッケージごとにLICENSE定義
* 受け入れられるライセンスを制御したい
* ツールとライブラリのライセンスが違う
* ツールがGPL,ライブラリがLGPL
* GPLv2とv3が混在する例
  rubyとreadline6
* GPL2とGPL2 or laterの区別
* GPL3とリンクできるかできないか
  http://d.hatena.ne.jp/obache/20090922/

NetBSDのリリース
----------------
リリース版
 2.0 3.0 4.0 5.0......
マイナーリリース　
 2.1.. 3.1...
パッチリリース　　　
 2.1.1... 3.1.1...
開発版　
 2.99 3.99 4.99 5.99...
カーネルAPIの変更があるとき 
 2.99.1...

NetBSD開発ロードマップ
~~~~~~~~~~~~~~~~~~~~~~

.. csv-table:: NetBSD release announcements

    NetBSD 0.8 ,20 Apr 1993
    NetBSD 0.9 ,23 Aug 1993
    NetBSD 1.0 ,26 Oct 1994
    NetBSD 1.1 ,26 Nov 1995
    NetBSD 1.2 ,04 Oct 1996
    NetBSD 1.2.1 ,20 May 1997
    NetBSD 1.3 ,04 Jan 1998
    NetBSD 1.3.1 ,09 Mar 1998
    NetBSD 1.3.2 ,29 May 1998
    NetBSD 1.3.3 ,23 Dec 1998
    NetBSD 1.4 ,12 May 1999
    NetBSD 1.4.1 ,26 Aug 1999
    NetBSD 1.4.2 ,19 Mar 2000
    NetBSD 1.4.3 ,25 Nov 2000
    NetBSD 1.5 ,06 Dec 2000
    NetBSD 1.5.1 ,11 Jul 2001
    NetBSD 1.5.2 ,13 Sep 2001
    NetBSD 1.5.3 ,22 July 2002
    NetBSD 1.6 ,14 Sep 2002
    NetBSD 1.6.1 ,21 Apr 2003
    NetBSD 1.6.2 ,01 Mar 2004
    NetBSD 2.0 ,09 Dec 2004
    NetBSD 2.0.2 ,14 Apr 2005
    NetBSD 2.0.3 ,31 Oct 2005
    NetBSD 2.1 ,02 Nov 2005
    NetBSD 3.0 ,23 Dec 2005
    NetBSD 3.0.1 ,24 July 2006
    NetBSD 3.0.2 ,04 Nov 2006
    NetBSD 3.1 ,04 Nov 2006
    NetBSD 4.0 ,19 Dec 2007
    NetBSD 4.0.1 ,14 Oct 2008
    NetBSD 5.0 ,29 Apr 2009
    NetBSD 5.0.1 ,02 Aug 2009
    NetBSD 5.0.2 ,12 Feb 2010
    NetBSD 5.1 ,19 Nov 2010
    NetBSD 5.1.2 ,02 Feb 2012
    NetBSD 5.2 ,03 Dec 2012
    NetBSD 6.0 ,17 Oct 2012
    NetBSD 6.0.1 ,26 Dec 2012
    NetBSD 6.1 ,26 Dec 2012


Automated Testing Framework
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
| cd /usr/tests;
| atf-run | atf-report

組織構成
-------

* Core 5人　テクニカルマネージメント
* Port maintainer　28人
  各実装に関する担当者
* Developer
  CVS/WWW/FTP等開発資産に書き込みできる
* アクティブなのは188人

NetBSD Foundation,Inc
~~~~~~~~~~~~~~~~~~~~~~~~
* デラウェア州の法人組織
* サーバマシンを所有
* お金と寄付を管理
* NetBSDの版権を管理

developer
~~~~~~~~~~~
* 直接ソースを変更できる
* CVS/FTP/WWWサーバの内容
* 世界中で188人
* GNATSでバグ管理
* cvsweb.netbsd.org
* 日本人38人

NetBSD開発者世界分布図
~~~~~~~~~~~~~~~~~~~~~~
.. 地図

NetBSD開発者分布図
~~~~~~~~~~~~~~~~~~
.. 地図

Developerになるには（1）
~~~~~~~~~~~~~~~~~~~~~~~~
* PGP/GnuPGの鍵を作る
* fingerprint印刷
* gpg --fingerprint jun@soum.co.jp
* fingerprint交換
* 他のDeveloperとfingerprint印刷を交換
* 本人確認
* 公的証明書を見せあって本人確認

Developerになるには(2)
~~~~~~~~~~~~~~~~~~~~~~~
* 相手の鍵を取り込んで、fingerprint照合
* gpg-email-confirm soda@netbsd.org..
* ランダムな文字列を送る
* メールを暗号化して送り返してもらう
* 送った文字列とメールアドレスを照合する
* 鍵にサインしてもらって送り返してもらう
* Developerサイン入り自分の鍵ができる
* 自分の鍵束にimport
* pgp.mit.eduにサイン入り自分の鍵を登録する

世界中で打ち合わせをする時間
~~~~~~~~~~~~~~~~~~~~~~~~~~
| May 21 03:00 PM -0700 America/Los_Angeles
| May 21 06:00 PM -0400 America/New_York
| May 21 11:00 PM +0100 Europe/London
| May 22 00:00 AM +0200 Europe/Berlin
| May 22 01:00 AM +0300 Europe/Helsinki
| May 22 07:00 AM +0900 Asia/Tokyo
| May 22 08:00 AM +1000 Australia/Melbourne

Port-maintainer
~~~~~~~~~~~~~~~~~
* 移植責任者
* 57種類のうち15種類以上は日本人が担当
* 日本人担当ハードウェア15/56
* NetBSD動作マシン＠日本

日本からの貢献
~~~~~~~~~~~~~
* 国産ハードウェアサポート
* ゲーム機・携帯情報端末サポート
* IPv6/ IPSEC
* Pkgsrc
* CardBusサポート
* MIPS/SH/m68K
* NetBSD書籍が世界一多く出版される
* developer53人

クロス開発環境
-------------
NetBSD/i386でクロスコンパイル
 build.sh –m hpcmips 
* Pkgsrc/cross以下に各種パッケージ
* Windows環境でクロスコンパイル
* Cygwinなど
* Linux上でクロスコンパイル
* FreeBSD上でクロスコンパイル
* distcc - コンパイルだけ速いマシンで
* pkgsrcをクロスコンパイル
* pkgsrcのcrossbuildでググる！
* http://www.lins.jp/~obata/diary/200803242.html
* クロス用toolsを作る

バイナリ互換性を利用する
~~~~~~~~~~~~~~~~~~~~~~~
* Cobalt　Qube２でhpcmipsバイナリ作成
* MIPSでendian little =mipsel同士なら動く
* ユーザランドはほとんどそのまま動く
* パッケージも共通化
* NetBSD/{pmax,cobalt,arc,hpcmips}で共通
* 数GBある各種アプリケーション群を共通にする

エミュレーション環境
~~~~~~~~~~~~~~~~~~~
* Linux
* I386以外のバイナリも動くようにする
* FreeBSD
* Windows2000/XP
* PECOFF
* Win32アプリケーションをそのまま動かす
  ゲームなど
  Unixware

NetBSD開発者情報
-----------------
ftp/WWW/CVS/SUPサーバ
 http://www.jp.netbsd.org/ja/JP/sites.html
開発環境設定方法
 http://www.netbsd.org/developers/
メーリングリスト
 http://www.jp.netbsd.org/ja/JP/ml.html
netbsd-request@re.soum.co.jp
 1994/11- 　10年以上！　参加者600名
 http://releng.netbsd.org  

ソースコード取得方法
~~~~~~~~~~~~~~~~~~~~
* ftp
* Cvs
* cvsup
* Sup
* Anonymous CVS
* rsync

Japan NetBSD Users’ Group
-----------------------------
* 1999年8月21日成立
* 日本のNetBSDユーザに便宜を図る
* FTP/CVS/WWWサーバの管理
* ドキュメント・WWWページ翻訳
* KOF,OSCに全て参加(.DB/.cloud除く)
* 回線提供：IIJ
*  http://www.jp.NetBSD.org/
* http://www.facebook.com/NetBSD.jp/
* 年一度定期総会・BoFを実施
* 2013/7/13
* 東京 根津　東大武田先端知ビル

www.netbsd.org　翻訳
----------------------
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

国内BSDユーザグループ
----------------------
.. toggetter URL
* http://www.netbsd.org/gallery/groups.html
* BBQ
* BSD Users Group,Shinshu
* Chofu *BSD Users’ Group
* Chiba *BSD Users’ Group
* Daibou East *BSD Users Group
* Echigo BSD Users Group
* Kansai *BSD Users Group
* Nagoya *BSD Users Group
* Northern land BSD Users Group
* Shikoku *BSD Users Group
* Tohoku BSD Users Group

オープンソースカンファレンスこの一年
----------------------------------

.. csv-table::

 OSC2013名古屋NBUG&NetBSDブース展示の記録 ,1031 view,Luna88K&Luna68K
 名古屋*BSDユーザグループ(NBUG)2013/5月例会の記録 ,210 view 
 NetBSDでuARM, 788 view
 名古屋*BSDユーザグループ(NBUG)2013/4月例会の記録 ,354 view
 名古屋*BSDユーザグループ(NBUG)2013 花見の記録 ,301 view 
 名古屋*BSDユーザグループ(NBUG)2013/3月例会の記録, 410 view
 NetBSD/sparcをQEMUで動かす会の記録, 723 view
 AsiaBSDCon 2013の記録 ,1259 view
 OSC2013徳島 NetBSDブース展示の記録 ,755 view
 OSC2013 東京春 NetBSDブース展示の記録 ,742 view
 名古屋*BSDユーザグループ(NBUG)2013/2月例会の記録,368 view
 OSC2013 浜松 NetBSDブース展示の記録,466 view
 名古屋*BSDユーザグループ(NBUG)2013/1月例会の記録,443 view
 名古屋*BSDユーザグループ(NBUG)2012/12月例会の記録,482 view
 OSC2012 福岡 NetBSDブース展示の記録,689 view
 名古屋*BSDユーザグループ(NBUG)2012/11月例会の記録,872 view
 関西オープンソース2012 NetBSDブース展示の記録,919 view
 OSC2012 会津 NetBSDブース展示の記録,1756 view
 OSC2012 大分秋 NetBSDブース展示の記録,595 view
 OSC2012 広島 NetBSDブース展示の記録,2906 view
 名古屋*BSDユーザグループ(NBUG)2012/10月例会の記録,425 view
 名古屋*BSDユーザグループ(NBUG)2012/9 例会の記録,461 view
 OSC2012沖縄 NetBSDブース展示の記録,392 view
 OSC2012 東京秋 NetBSDブース展示の記録,1661 view
 OSC2012 島根 NetBSDブース展示の記録,855 view
 名古屋*BSDユーザグループ(NBUG)2012/8 例会の記録,651 view
 OSC2012 京都 NetBSDブース展示の記録,2399 view
 名古屋*BSDユーザグループ(NBUG)2012/7 例会の記録,1351 view
 OSC2012 仙台 NetBSDブース展示の記録,610 view
 日本NetBSDユーザーグループ第十四回定期総会 および NetBSD BoF 2012,885 view

まとめ
----------------------
* NetBSDはいろんなハードで動きます
* 自作ソフトをいろんなCPUで試せます
* 最初から移植を考えて設計されています
* 試作機に移植する工数が最小ですみます
* 自分の専門分野だけを組み込めます
* 自由に利用可能で再配布可能なOSです
* 移植するとIPv6マシンに変貌
* さまざまなCPU向けIPv6スタックがあります
* 愛着あるハードウェアが生き返ります
* 最新のネットワークコードが利用できます
* もしかしたらリサイクル団体なんでしょうか？
 作成日
 |today|

このドキュメント
---------------
* http://github.com/ebijun/NetBSD/Guide
* /usr/pkgsrc/textproc/py-sphinx
* /usr/pkgsrc/editors/gedit
* /usr/pkgsrc/pring/evince

.. OSCのことを書く
.. TODO
