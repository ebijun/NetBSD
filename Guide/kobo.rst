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

==============================================
RaspberryPIでNetBSDを使ってみる(softfloat版)
==============================================

特徴
----

* NetBSDをRaspberryPIで利用するために、ディスクイメージを用意しました。
* Xが動いて、ご家庭のテレビでmikutterが動きます。
* うまく動いたら、動いた記念写真をツイートだ！
* fossil(http://www.fossil-scm.org/)も入れてあります。家庭内Webサーバとかチケットシステムとかwikiサーバになるんでないかい。
* softfloat版では作ったpkgsrcバイナリをhpcarm(WZERO3とか),zaurusと共用できます。そのかわりhardfloat版より遅いはずです。
* おまけでKOBO用イメージを入れてあります。

準備するもの
-------------
* RaspberryPI本体
* HDMI入力のあるテレビ／ディスプレイ
* USBキーボード
* USBマウス
* 有線ネットワーク

起動ディスクの作成
-------------------
* ディスクイメージのダウンロード

::

 # ftp ftp://ftp.netbsd.org/pub/NetBSD/misc/jun/raspberry-pi/
 2013-09-09-netbsd-evbarm.img.gz

* 2GB以上のSDカードを準備します。
* ダウンロードしたディスクイメージを、SDカード上で展開します。

::

	disklabel sd0  ..... 必ずインストールするSDカードか確認してください。
	gunzip < 2013-09-09-netbsd-evbarm.img.gz |dd of=/dev/rsd0d bs=1m

RaspberryPIの起動
------------------
#. HDMIケーブル／USBキーボード/USBマウス/有線ネットワークをRPIにさします。
#. 電源を入れてRPIを起動します。
#. 少し待つと、HDMIからNetBSDの起動メッセージが表示されます。

ログイン
---------
 rootでログインできます。

::

	login: root


 startxでicewmが立ち上がります。

::

	# startx

mikutterを使ってみよう
----------------------
* xtermからdilloとmikutterを起動します。

::

	# dillo &
	# mikutter &

* しばらく待ちます。
* mikutterの認証画面がうまく出たら、httpsからはじまるURLをカットアンドペーストして、dilloのURL画面に張り付けます。URLをなぞって、マウスボタン両押しです。
* twitterのIDとパスワードを入力すると、pin番号が表示されます。pin番号をmikutterの認証画面に入力します。
* しばらくすると、mikutterの画面が表示されます。表示されるはずです。落ちてしまう場合は時計が合っているか確認してください。
* 漢字は[半角/全角]キーを入力すると漢字モードに切り替わります。anthyです。
* 青い鳥を消したいとき：「mikutter」「青い鳥」でぐぐってください。

キーマップの設定を変更する
--------------------------
* ログインした状態でのキーマップは/etc/wscons.confで設定します。

::

	encoding jp.swapctrlcaps .... 日本語キーボード,CtrlとCAPSを入れ替える。

* Xでのキーマップは.xinitrcで設定します。

::

	setxkbmap -layout jp -option ctrl:swapcap

* 106キーでのキーマップ

::

 on i386:
 "\|" key returns keycode 133
 "\_" key returns keycode 211

 on evbearmv6hf-el
 "\|" key returns keycode 8
 "\_" key returns keycode 8

コンパイル済パッケージをインストールする
--------------------------------------------------
* 筒井さんがWZERO3用にコンパイルしたイメージがそのまま利用できます。

::

 http://teokurebsd.org/netbsd/packages/arm/6.1_2013Q1/All/


* パッケージのインストール

 pkg_addコマンドで、あらかじめコンパイル済みのパッケージをインストールします。関連するパッケージも自動的にインストールします。

::

 # export PKG_PATH=http://teokurebsd.org/netbsd/packages/arm/6.1_2013Q1/All/
 # pkg_add zsh

* パッケージの一覧

 pkg_infoコマンドで、インストールされているパッケージの一覧を表示します。

::

	# pkg_info

* パッケージの削除

::

	# pkg_delete パッケージ名


/usr/pkgsrcを使ってみよう
--------------------------
 2013/9/6時点のpkgsrc-currentが/usr/pkgsrcに展開してあります。
 たとえばwordpressをコンパイル／インストールする時には、

::

	# cd /usr/pkgsrc/www/wordpress
	# make package-install

を実行すると、wordpressに関連したソフトウェアをコンパイル／インストールします。

ユーザー作成
--------------

::

	# useradd -m jun
	# passwd jun
	# /etc/groupを編集する
	wheel:*:0:root,jun

サービス起動方法
----------------
  /etc/rc.d以下にスクリプトがあります。dhcpクライアント(dhcpcd)を起動してみます。

::

 テスト起動：
   /etc/rc.d/dhcpcd onestart
 テスト停止：
   /etc/rc.d/dhcpcd onestop

 
正しく動作することが確認できたら/etc/rc.confに以下のとおり指定します。
   dhcpcd=YES
  /etc/rc.confでYESに指定したサービスは、マシン起動時に同時に起動します。

::

 起動:
   /etc/rc.d/dhcpcd start
 停止：
   /etc/rc.d/dhcpcd stop
 再起動：
  /etc/rc.d/dhcpcd restart

vnconfigでイメージ編集
------------------------

NetBSDの場合、vnconfigコマンドでイメージファイルの内容を参照できます。

::

 # vnconfig vnd0 2013-09-09-netbsd-raspi.img
 # vnconfig -l
 vnd0: /usr (/dev/wd0e) inode 53375639
 # disklabel vnd0
 　　 :
 8 partitions:
 #        size    offset     fstype [fsize bsize cpg/sgs]
 a:   3428352    385024     4.2BSD      0     0     0  # (Cyl.    188 -   1861)
 b:    262144    122880       swap                     # (Cyl.     60 -    187)
 c:   3690496    122880     unused      0     0        # (Cyl.     60 -   1861)
 d:   3813376         0     unused      0     0        # (Cyl.      0 -   1861)
 e:    114688      8192      MSDOS                     # (Cyl.      4 -     59)
 # mount_msdos /dev/vnd0e /mnt
 # ls /mnt
 LICENCE.broadcom    cmdline.txt         fixup_cd.dat        start.elf
 bootcode.bin        fixup.dat           kernel.img          start_cd.elf
 # cat /mnt/cmdline.txt
 root=ld0a console=fb
 #fb=1280x1024           # to select a mode, otherwise try EDID 
 #fb=disable             # to disable fb completely

 # umount /mnt
 # vnconfig -u vnd0

HDMIじゃなくシリアルコンソールで使うには
----------------------------------------
* MSDOS領域にある設定ファイルcmdline.txtの内容を変更してください。

::

 ↓console=fbを消します。
 root=ld0a 
 #fb=1280x1024           # to select a mode, otherwise try EDID 
 #fb=disable             # to disable fb completely

起動ディスクを変えるには
------------------------
* MSDOS領域にある設定ファイルの内容を変更してください。

::

 root=sd0a console=fb ←ld0をsd0にするとUSB接続したディスクから起動します
 #fb=1280x1024           # to select a mode, otherwise try EDID 
 #fb=disable             # to disable fb completely

最小構成のディスクイメージ
--------------------------
  NetBSD-currentのディスクイメージに関しては、以下の場所にあります。

::

 # ftp://nyftp.netbsd.org/pub/NetBSD-daily/HEAD/201309091320Z/evbarm/binary/gzimg/
 # gunzip < rpi_inst.bin.gz |dd of=/dev/rsd3d bs=1m   .... sd3にコピー。

  RaspberryPIにsdカードを差して、起動すると、#　プロンプトが表示されます。
 # sysinst      .... NetBSDのインストールプログラムが起動します。

X11のインストール
------------------
 rpi.bin.gzからインストールした場合、Xは含まれていません。追加したい場合は、
 ftp://nyftp.netbsd.org/pub/NetBSD-daily/HEAD/201309091320Z/evbarm/binary/sets/x*.tgz 
 をダウンロードし、tarファイルを展開します。

::

 tar xzpvf xbase.tar.gz -C /

pkgsrcを最新にしてみる
----------------------
* cd /usr/pkgsrc
* cvs update -PAd

外付けUSB端子
--------------
  NetBSDで利用できるUSBデバイスは利用できる（はずです)。電源の制約があるので、十分に電源を供給できる外付けUSBハブ経由で接続したほうが良いです。

液晶ディスプレイ
-----------------
  液晶キット( http://www.aitendo.com/page/28 )で表示できています。HDMI-VGA変換ではうまく表示できていません。（電源が足りない)

inode
-------
  inodeが足りない場合は、ファイルシステムを作り直してください。このイメージでは以下のようにファイルシステムを作成しています。

	# newfs -n 600000 /dev/rvnd0a

壁紙
-----
  おおしまさん(@oshimyja)ありがとうございます。


関連バグ
--------

PR 47798
 今回、mikutterのアイコンがでなくて落ちるバグに悩みました。つついさんに感謝します。
	http://gnats.netbsd.org/cgi-bin/query-pr-single.pl?number=47798

pkg/48128: icewm build broken on 6.99.23
 直っています。

--

パーティションサイズをSDカードに合わせる
-----------------------------------------
　2GB以上のSDカードを利用している場合、パーティションサイズをSDカードに合わせることができます。この手順はカードの内容が消えてしまう可能性もあるため、重要なデータはバックアップをとるようにしてください。
  手順は、http://wiki.netbsd.org/ports/evbarm/raspberry_pi/ のGrowing the root file-systemにあります。

 このイメージのために、つついさんにスクリプトを作っていただきました。（まだテスト中です）

#. vi /etc/rc.confでrc_configured=NOに書き換え
#. reboot　.... シングルユーザで起動
#.  Enter pathname of shell or RETURN for /bin/sh: でリターン
#. cd /root/Extract/
#. sh expand-image-fssize-rpi.sh ... しばらくかかります
#.  リターンを押すと再起動します

::

 Untested sh script that will expand NetBSD partition and BSD FFS partition in the RPI image prepared 
 by Jun Ebihara: http://mail-index.netbsd.org/port-arm/2013/06/19/msg001882.html
 https://gist.github.com/tsutsui/5814498

シングルユーザでの起動
"""""""""""""""""""""
#. /etc/rc.confのrc_configured=YESをNOにして起動します。
#.  戻すときはmount / ;vi /etc/rc.conf　でNOをYESに変更してrebootします。

参考URL
--------
* http://wiki.netbsd.org/ports/evbarm/raspberry_pi/
* NetBSD Guide http://www.netbsd.org/docs/guide/en/
* NetBSD/RPiで遊ぶ(SDカードへの書き込み回数を気にしつつ)  http://hachulog.blogspot.jp/2013/03/netbsdrpisd.html
* http://www.raspberrypi.org/phpBB3/viewforum.php?f=86 NetBSDフォーラム
* http://www.raspberrypi.org/phpBB3/viewforum.php?f=82 日本語フォーラム


=================================
KOBOでNetBSDを動かしてみる
=================================

目標
----

* KOBOでNetBSDを動かしてみます。
* KOBOにシリアルポート経由で接続します。
* バイナリイメージで試せるようにします。
* RPI向けイメージと同じイメージで起動します。

できることとできないこと
-------------------------

* NetBSDが起動します。
* 外部から電源を供給できるUSBハブ経由で接続したUSB機器を利用できるはずです。
* 電子インクは利用できません。

準備するもの
-------------
* KOBO
* 2GB 以上のmicro SDカード2枚
* シリアル接続ケーブル
* KOBOとシリアルを接続するジャンパ線

::

 秋月:FTDI 3.3V http://akizukidenshi.com/catalo
 TXD: 橙色
 RXD: 黄色
 GND: 黒色

microSDカードの設定
--------------------
 kobo touchには、内蔵microSDスロットと、脇部分にあるmicroSDスロットがあります。内蔵microSDスロットにubootイメージを書き込んだmicroSDを挿します。
脇部分にあるmicroSDスロットには、RPI用に作ったイメージを挿します。
元から刺さっていたmicroSDは大事に保管しておきます。
もしNetBSD起動に飽きた時でも、本来の電子図書として楽しく使えます。
KOBOではmicroSDに書き込んだPDFファイルも読めるので、
PDFビューワとしても便利です。

シリアルケーブル
------------------
 まず裏蓋を開けます。右下の部分にTX,RXと書いた基盤の穴があります。
ここにシリアルポートを接続します。

ソースコードからコンパイルする場合
----------------------------------
 まずKOBOパッチをあてていない状態でコンパイルができるか確認します。

* NetBSDを普通にインストールする
* cd /usr
* ftp ftp.jp.netbsd.org:/pub/NetBSD/NetBSD-current/tar_files/

::

  > bin
  > mget src.tar.gz xsrc.tar.gz

* tar xzvf src.tar.gz
* tar xzvf xsrc.tar.gz

コンパイル
-----------
* mkdir /usr/obj.evbarm
* cd /usr/src
* 以下のスクリプトを実行します。

::

 USR_OBJMACHINE=YES
 OBJMACHINE=YES
 MKX11=YES
 BSDOBJDIR=/usr/obj/evbarm
 DESTDIR=/usr/builds/evbarm
 RELEASEDIR=/usr/release
 ./build.sh -U -u -j 8 -m evbarm release
 ./build.sh -U -u -j 8 -m evbarm iso-image

KOBO用パッチ
-------------

::

 # cd /usr/src
 # ftp https://gist.github.com/hkenichi/6363751/download 
 # tar xzvf download
 # mv gist6363751-*/kobo.diff .
 # script
 # patch -p1 < kobo.diff
 # exit

::

 #  ./build.sh -U -u -j 8 -m evbarm kernel=KOBO
 #  cd /usr/src/sys/arch/evbarm/compile/KOBO
 #  tar czvf /usr/release/images/kernel-kobo.tgz netbsd*

uboot
-----
 KOBO用ubootイメージは以下の場所にあります。

::

 http://rappappararin.blogspot.jp/2012/09/kobou-boot.html
 http://rappappararin.blogspot.jp/2012/09/kobonetbsd.html
 https://docs.google.com/open?id=0B-K-8275486qNDk2VFVKS3ZaOHc

以下のコマンドでカーネルをロードして起動します。

::

    mmcinfo 1
    fatload mmc 1 0x70800000 kobo.bin
    go 0x70800000

または、環境変数に引数を設定しておきます。

::

 BR-1A # setenv bootcmd_netbsd 'mmcinfo 1;fatload mmc 1 0x70100000 kobo.bin; go 0x70100000'
 BR-1A # setenv bootcmd 'run bootcmd_netbsd'
 BR-1A # saveenv

