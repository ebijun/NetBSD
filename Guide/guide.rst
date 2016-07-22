.. 
 Copyright (c) 2013-2016 Jun Ebihara All rights reserved.
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

.. todo:: もしかしてRPIだとそのまま動画が録画できるか
.. todo:: インストールが進むにつれてバックトラックをふやす
.. todo:: 無線LANの設定
.. todo:: rabbitのようなものでプレゼンできるか
.. todo:: bccksで豆本にできるか
.. todo:: latexに変換してみる
.. todo:: latex環境設定
.. todo:: facebookページとの連携：主なニュース取得とか
.. todo:: raid設定
.. todo:: tmpfs/unionfsまわり
.. todo:: http://www.fml.org/home/fukachan/ja/tech.netbsd.html
.. todo:: brasero,cheese,rhythmbox,sound juicer,totem
.. todo:: firefox,thunderbird
.. todo:: http://www.sekaichizu.jp/atlas/japan/area.html

==============================
NetBSDのご紹介        
==============================

こういうOSが欲しい
-----------------

 世界中にあるコンピュータ、昔の計算機から最近のパソコン、組み込み系まで、身の回りで目についたすべてのコンピュータで動くOSは、どのようなものでしょうか？コンピュータに接続できる機器もたくさんあります。手持ちの周辺機器を全部利用できるOSを考えてみましょう。これまでに利用したことのあるソフトウェアすべてを動かすことのできるOSはどのようなものであればよいでしょうか？ソースコードを自由に読んだり、書いたり、引用したり、配布したり、売ったり買ったりできるOSを、世界中の人々と共同で作るためにはどのような枠組みがあればよいでしょうか？
 
NetBSD
-------

 NetBSDは、4.3/4.4BSD&386BSDベースのOSです。
 プロジェクトは1993年3月21日から開始していて、現在も活発に開発が進んでいます。
 60種類以上のハードウェアを、単一ソースツリーでサポートしています。
 
 ハードウェア依存/非依存部分を分離しており、IPv6をはじめとする最新のネットワークプロトコルをサポートしています。
 ソースコードは、商用ルータ・プリンタ・家電製品・ゲーム機など、幅広い機器に組み込まれています。
 OSとして組み込まれることもあれば、ネットワーク機能など、一部のコードが取り込まれることもあります。
 
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
 2. バイナリー形式の再配布においては、上記の著作権表示、この条件の列挙、下記の注意書きを、
    配布物に附属した文書および/または他のものに再現させること。
 
 このライセンスの前には著作権表示そのものが付きます。この後には注意書きが付き、このソフトウェアに関して問題が生じても、作者は責任を負わないと述べます。 

BSDライセンスとNetBSD
~~~~~~~~~~~~~~~~~~~~~~
 NetBSDのソースコードを自由に売ることができます。 NetBSDのソースコードから作ったバイナリを売ることもできます。バイナリのソースコードを公開する義務はありません。

ライセンス条項が異なるソースを分離する
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 NetBSDの配布物には、2 条項 BSD ライセンスのソースコードで書かれているソフトウェアと、そうでないソフトウェアが含まれています。NetBSDでは、ライセンス条項が違うソースコードをディレクトリごとに分けて管理しています。

::

 %  ls /usr/src/external/
 CVS             atheros         gpl2            intel-fw-eula   mit
 Makefile        broadcom        gpl3            intel-fw-public public-domain
 README          bsd             historical      lgpl2           realtek
 apache2         cddl            ibm-public      lgpl3           zlib

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
--------------------------------------

ソースコードからNetBSDのインストールCDをコンパイルしてみましょう。

ダウンロード
~~~~~~~~~~~~

ソースコードをダウンロードします。

::

 % ftp ftp://ftp.jp.NetBSD.org/pub/NetBSD/NetBSD-current/tar_files/src.tar.gz

展開
~~~~~

ソースコードを展開します。

::

 % tar xvzf src.tar.gz


コンパイル
~~~~~~~~~~~

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

正常に終了すると、NetBSD/i386のCD-ROMイメージができています。このイメージは、VirtualBoxなどでも利用できます。

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
---------------

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

X Window システムの初期設定
----------------------------

X Windowシステムも含めてインストールした場合、以下の手順で設定ファイルを作ります。

::

 % su root                  .... root権限で実行します。
 # X -configure             .... /root/xorg.conf.new ができます。
 # mv /root/xorg.conf.new /etc/X11/xorg.conf
 % startx                   .... twmの画面が出てくれば成功です！twm!twm!
 % xeyes &                  .... 浮動小数点チェック：ちゃんと目が回るかな？

.xinitrc のコピー
~~~~~~~~~~~~~~~~~~

::

 cp /etc/X11/xinit/xinitrc ~/.xinitrc

キーボードレイアウトの変更
~~~~~~~~~~~~~~~~~~~~~~~~~

コンソール画面ではwsconsを利用して、キーボードレイアウトを変更します。

::

 % more /etc/wscons.conf
      :
 # Select a kernel builtin keyboard map by uncommenting the following line and
 # altering the country code to your requirements
 # (choose from user, us, uk, be, cz, dk, nl, fi, fr, de, gr, hu, it, jp, no,
 # pl, pt, ru, es, sv, sf, sg, ua)
 # See wsconsctl(8), pckbd(4), ukbd(4) etc. for more details.
 #encoding us.swapctrlcaps
 encoding jp.swapctrlcaps    .... この行を追加します

X Window システムでは、setxkbmapコマンドを利用して、レイアウトを切り替えます。

::

 setxkbmap -model jp106 jp -option ctrl:swapcap 


外部ディスプレイへの出力切り替え
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

 外部ディスプレイへの出力は、xrandrコマンドで行います。xrandrを実行すると、X画面が表示されますが、色がおかしい場合、コンソールを一度、X以外に切り替えてからX画面に戻ると正しく表示されます。うまく切り替わらない場合は、/etc/rc.confに、wscons=YESが指定してあるか確認してください。

::

 % grep wscons /etc/rc.conf
 wscons=YES
 % xrandr --auto    ... 外部ディスプレイ端子に出力されます。
 Control+Alt+F4 を押して、コンソール画面に切り替えます。
 Control+Alt+F5 を押して、X画面に戻ります。

ネットワーク設定
---------------

DHCPでつないでみる
~~~~~~~~~~~~~~~~~~

::

 # dhcpcd ale0

無線LANの設定(WEP)
~~~~~~~~~~~~~~~~~~~

::

 # ifconfig ath0 up
 # ifconfig ath0 ssid "SSIDをここに書く" nwkey "WEPキーをここに書く"

無線LANの設定(WPA-PSK)
~~~~~~~~~~~~~~~~~~~~~~~

::

 % cat wpa.conf
 ctrl_interface=/var/run/wpa_supplicant
 
 ctrl_interface_group=wheel
 
 network={
        ssid="SSIDをここに書く"
        scan_ssid=1
        key_mgmt=WPA-PSK
        psk="pskをここに書く"
 }
 # /usr/sbin/wpa_supplicant -B -i athn0 -c wpa.conf
 # dhcpcd athn0

rc.d
-----

::

 # ls /etc/rc.d
 DAEMON          downinterfaces  ldpd            perusertmp      savecore
 DISKS           envsys          local           pf              screenblank
 LOGIN           fccache         lpd             pf_boot         securelevel
 NETWORKING      fsck            lvm             pflogd          sshd
 RCS             fsck_root       makemandb       postfix         staticroute
 SERVERS         ftp_proxy       mdnsd           powerd          swap1
 accounting      ftpd            mixerctl        ppp             swap2
 altqd           gpio            mopd            pwcheck         sysctl
 amd             hostapd         motd            quota           sysdb
 apmd            httpd           mountall        racoon          syslogd
 bluetooth       identd          mountcritlocal  raidframe       timed
 bootconf.sh     ifwatchd        mountcritremote raidframeparity tpctl
 bootparams      inetd           mountd          random_seed     ttys
 ccd             ipfilter        moused          rarpd           veriexec
 cgd             ipfs            mrouted         rbootd          virecover
 cleartmp        ipmon           named           rndctl          wdogctl
 cron            ipnat           ndbootd         root             wpa_supplicant
 dbus            ipsec           network         route6d         wscons
 devpubd         irdaattach      newsyslog       routed          wsmoused
 dhclient        iscsi_target    nfsd            rpcbind         xdm
 dhcpcd          isdnd           nfslocking      rtadvd          xfs
 dhcpd           isibootd        npf             rtclocaltime    ypbind
 dhcrelay        kdc             ntpd            rtsold          yppasswdd
 dmesg           ldconfig        ntpdate         rwho            ypserv
 # cat /etc/rc.conf
     :
 wscons=YES
 rtclocaltime=YES
 hostname=yourhostname.example.com
 ip6mode=autohost
 rtsol=YES
 sshd=YES
 powerd=YES
 dbus=YES

httpdの起動方法
~~~~~~~~~~~~~~~
 NetBSDには、標準でbozohttpdというhttpdプログラムが含まれています。以下の手順で起動できます。

::

 # cat > /var/www/index.html << EOF
 <TITLE>test page</TITLE>
 test
 EOF
 # /etc/rc.d/httpd onestart
 # grep httpd /etc/rc.conf
 httpd=YES
 # /etc/rc.d/httpd start
 # /etc/rc.d/httpd stop

Tier I/II/III
------------

Tier I
~~~~~~~~

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
~~~~~~~~~

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
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

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

daily-snapshot
~~~~~~~~~~~~~~~~~~

ftp://nyftp.netbsd.org/pub/NetBSD-daily/ 以下には、
毎日コンパイルされているNetBSDの動作イメージがあります。
ミラーサイトは、http://nycdn.netbsd.org/pub/NetBSD-daily/ にあります。

.. csv-table:: ftp://nyftp.netbsd.org/pub/NetBSD-daily/ の一覧

 名前,サイズ, 最終更新日時
 HEAD,,2013年07月10日 01時00分00秒
 ファイル:README, 1 KB, 2012年11月21日 00時00分00秒
 netbsd-5, 2013年07月10日, 01時00分00秒
 netbsd-5-1, 2013年07月05日, 01時00分00秒
 netbsd-5-2, 2013年07月01日, 01時00分00秒
 netbsd-6, 2013年07月04日, 01時00分00秒
 netbsd-6-0, 2013年07月03日, 01時00分00秒

.. csv-table:: ftp://nyftp.netbsd.org/pub/NetBSD-daily/HEAD の一覧

   名前, サイズ, 最終更新日時
 201307060520Z, ,2013年07月06日 18時13分00秒
 201307070030Z, ,2013年07月07日 12時23分00秒
 201307071220Z, ,2013年07月08日 00時24分00秒
 201307080020Z, ,2013年07月08日 12時17分00秒
 201307081220Z, ,2013年07月09日 00時15分00秒
 201307090630Z, ,2013年07月09日 18時29分00秒

PCでどの程度起動するか確認する
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

::

 ftp://nyftp.netbsd.org/pub/NetBSD-daily/HEAD/201307080020Z/images/NetBSD-6.99.23-amd64-install.img.gz

RPIでどの程度起動するか確認する
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

::

 ftp://nyftp.netbsd.org/pub/NetBSD-daily/HEAD/201307080020Z/evbarm/binary/gzimg/rpi.img.gz
 ftp://nyftp.netbsd.org/pub/NetBSD-daily/HEAD/201307080020Z/evbarm/binary/gzimg/rpi_inst.img.gz 

ておくれイメージ
~~~~~~~~~~~~~~~~

筒井さんが配布しているNetBSD/i386,amd64,WZero3で動作する
イメージファイルがあります。
NetBSDの設定例としても優れているので、一読をおすすめします。

::

 http://www.ceres.dti.ne.jp/tsutsui/netbsd/liveimage  ...i386/amd64 
 http://www.ceres.dti.ne.jp/tsutsui/netbsd/liveimage/wzero3.html ..WZero3

::

 http://www.youtube.com/watch?v=Jl0BZVfVSLs ... WZero3起動動画
 http://www.slideshare.net/tsutsuii/netbsdcrossliveimage
 http://www.ceres.dti.ne.jp/tsutsui/osc12do/NetBSD-cross-liveimage.html


RaspberryPI用NetBSDイメージ
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

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
* http://www.NetBSD.org/about/features.html
* ZFS? Google Summer of Code

2038年問題
~~~~~~~~~~

1970/1/19 0:0:0 GMTからの経過秒数
 2^31-1=2147483647
 2,147,483,648秒以上を表示できるか

対応済み：date -r 2147483648
 Tue Jan 19 12:14:08 JST 2038
未対応：date -r 2147483648
 Tue Jan 19 12:14:07 JST 2038

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
    NetBSD 6.0.2 ,18 May 2013
    NetBSD 6.1 ,18 May 2013


Automated Testing Framework
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

http://www-soc.lip6.fr/~bouyer/NetBSD-tests/xen/ に、i386/amd64に関する自動テストレポートがあります。
 
::

 # cd /usr/tests;
 # atf-run | atf-report

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
* http://www.NetBSD.org/foundation/

developer
~~~~~~~~~~~
* 直接ソースを変更できる
* CVS/FTP/WWWサーバの内容
* 世界中で256人
* GNATSでバグ管理
* cvsweb.netbsd.org
* 日本人40人
* http://www.NetBSD.org/people/developers.html

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

.. csv-table:: 

 May 21 03:00,PM -0700,America/Los_Angeles
 May 21 06:00,PM -0400,America/New_York
 May 21 11:00,PM +0100,Europe/London
 May 22 00:00,AM +0200,Europe/Berlin
 May 22 01:00,AM +0300,Europe/Helsinki
 May 22 07:00,AM +0900,Asia/Tokyo
 May 22 08:00,AM +1000,Australia/Melbourne

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
~~~~~~~~~~~~~~~~~~~~~
* Linuxエミュレーション
* i386以外のバイナリも動くようにする
* FreeBSD
* Windows2000/XP
* PECOFF
* Win32アプリケーションをそのまま動かす
  ゲーム/WINE
 Unixware

NetBSD開発者情報
-----------------
ftp/WWW/CVS/SUPサーバ
 http://www.jp.NetBSD.org/ja/JP/sites.html
開発環境設定方法
 http://www.NetBSD.org/developers/
 http://releng.NetBSD.org  

ソースコード取得方法
~~~~~~~~~~~~~~~~~~~~
* ftp
* Cvs
* cvsup
* Sup
* Anonymous CVS
* rsync

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

