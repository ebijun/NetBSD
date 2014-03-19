.. 
 Copyright (c) 2013-4 Jun Ebihara All rights reserved.
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

 .. todo:: apache+php+mysql設定
 .. todo:: uim-pref-gtk
 .. todo:: webkit-gtk
 .. todo:: icewmの設定方法を書く
 .. todo:: btキーボード・マウス
 .. todo:: deforaos-* をテスト
 .. todo:: lang/ocamlをテスト
 .. todo:: lang/squeak
 .. todo:: www/wordpress
 .. todo:: puppetまたはansibleで設定する
 .. todo:: KOBO起動方法＆テスト
 .. todo:: beaglebone black テスト v7
 .. todo:: port-arm:2013/8/29 Radoslaw Kujawa
 .. todo:: For I2C consult the iic(4) man page, also see the i2cscan(8) utility and its source.
 .. todo:: For GPIO see gpio(4) man page.
 .. todo:: For SPI as far as I know there are no generic user-space components provided, besides support for SPI flashes.
 .. todo:: .build.sh -j -u -U -a earmhf -m evbarm iso-image

=================================
RaspberryPIでNetBSDを使ってみる
=================================

特徴
----

* NetBSDをRaspberryPIで利用するために、ディスクイメージを用意しました。
* Xが動いて、ご家庭のテレビでmikutterが動きます。
* うまく動いたら、動いた記念写真をツイートだ！
* fossil(http://www.fossil-scm.org/)も入れてあります。家庭内Webサーバとかチケットシステムとかwikiサーバになるんでないかい。

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

 earmhf (EARM：ハードフロート 通常はこちらを利用してください)
 # ftp ftp://ftp.netbsd.org/pub/NetBSD/misc/jun/raspberry-pi/
 2014-03-22-earmhf/2014-03-22-netbsd-raspi.img.gz
 
 evbarm (ソフトフロート：hpcarm/zaurus互換)
 # ftp ftp://ftp.netbsd.org/pub/NetBSD/misc/jun/raspberry-pi/
 2013-09-09-02-netbsd-evbarm.img.gz

* 2GB以上のSDカードを準備します。
* ダウンロードしたディスクイメージを、SDカード上で展開します。

::

	disklabel sd0  ..... 必ずインストールするSDカードか確認してください。
	gunzip < 2014-03-22-netbsd-raspi.img.gz|dd of=/dev/rsd0d bs=1m

RaspberryPIの起動
------------------
#. HDMIケーブル／USBキーボード/USBマウス/有線ネットワークをRPIにさします。
#. 電源を入れてRPIを起動します。
#. 少し待つと、HDMIからNetBSDの起動メッセージが表示されます。
#. 起動しない場合、まず基板上のLEDを確認してください。
#. 赤いランプのみ点灯している場合、OSを正しく読み込めていません。1) 少なくともMSDOS領域に各種ファームウェアファイルが見えていることを確認する。2) SDカードの接触不良の可能性があるので、SDカードを挿しなおしてみる。3) ファームウェアが古いため起動しない
#. 緑のランプも点灯している場合、OSは起動しているのに画面をHDMIに表示できていません。1) HDMIケーブルを差した状態で電源ケーブルを抜き差しして、HDMIディスプレイに何か表示するか確認する。2) HDMIケーブル自体の接触不良。ケーブルを何度か差し直してください。3) 電源アダプタ容量に余裕がない。少なくとも800mA程度の容量を持つアダプタをまず使ってみてください。スマートフォン用のアダプタならまず大丈夫です。

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
* 青い鳩を消したいとき：mikutterのプラグインを試してみる

::

% touch ~/.mikutter/plugin/display_requirements.rb

　すると、鳩が消えます。
mikutterはプラグインを組み込むことで、機能を追加できる自由度の高いtwitterクライアントです。プラグインに関しては、「mikutterの薄い本 プラグイン」で検索してみてください。

fossilを使ってみよう
----------------------
fossilは、Wiki/チケット管理システム/HTTPサーバ機能を持つ、コンパクトなソースコード管理システムです。fossilバイナリひとつと、リポジトリファイルひとつにすべての情報が集約されています。

::

 % fossil help
 Usage: fossil help COMMAND
 Common COMMANDs:  (use "fossil help -a|--all" for a complete list)
 add         changes     finfo       merge       revert      tag       
 addremove   clean       gdiff       mv          rm          timeline  
 all         clone       help        open        settings    ui        
 annotate    commit      import      pull        sqlite3     undo      
 bisect      diff        info        push        stash       update    
 branch      export      init        rebuild     status      version   
 cat         extras      ls          remote-url  sync      
 %  fossil init sample-repo
 project-id: bcf0e5038ff422da876b55ef07bc8fa5eded5f55
 server-id:  5b21bd9f4de6877668f0b9d90b3cff9baecea0f4
 admin-user: jun (initial password is "f73efb")
 %  ls -l 
 total 116
 -rw-r--r--  1 jun  users  58368 Nov 14 18:34 sample-repo
 % fossil server sample-repo -P 12345 &
 ブラウザでポート12345にアクセスし、fossil initを実行した時のユーザとパスワードでログインします。

キーマップの設定を変更する
--------------------------
* ログインした状態でのキーマップは/etc/wscons.confで設定します。

::

	encoding jp.swapctrlcaps .... 日本語キーボード,CtrlとCAPSを入れ替える。

* Xでのキーマップは.xinitrcで設定します。

::

	setxkbmap -model jp106 jp -option ctrl:swapcap


コンパイル済パッケージをインストールする
--------------------------------------------------
* コンパイルしたパッケージを以下のURLに用意しました。

::

 % cat /etc/pkg_install.conf
　PKG_PATH=ftp://ftp.netbsd.org/pub/NetBSD/misc/jun/raspberry-pi/2014-03-22-earmhf/packages

* パッケージのインストール

 pkg_addコマンドで、あらかじめコンパイル済みのパッケージをインストールします。関連するパッケージも自動的にインストールします。

::

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
 2014/03/15時点のpkgsrc-currentが/usr/pkgsrcに展開してあります。
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
　root権限で作業するユーザーの場合：
	# useradd -m jun -G wheel
       # passwd jun

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

 # vnconfig vnd0 2014-03-22-netbsd-raspi.img
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
https://raw.github.com/Evilpaul/RPi-config/master/config.txt

::

 ↓console=fbを消します。
 root=ld0a 
 #fb=1280x1024           # to select a mode, otherwise try EDID 
 #fb=disable             # to disable fb completely

起動ディスクを変えるには
------------------------
* MSDOS領域にある設定ファイルcmdline.txtの内容を変更してください。

::

 root=sd0a console=fb ←ld0をsd0にするとUSB接続したディスクから起動します
 #fb=1280x1024           # to select a mode, otherwise try EDID 
 #fb=disable             # to disable fb completely

最小構成のディスクイメージ
--------------------------
  NetBSD-currentのディスクイメージに関しては、以下の場所にあります。日付の部分は適宜読み替えてください。

::

 # ftp://nyftp.netbsd.org/pub/NetBSD-daily/HEAD/201310161210Z/evbarm-earmhf/binary/gzimg/rpi_inst.bin.gz
 # gunzip < rpi_inst.bin.gz |dd of=/dev/rsd3d bs=1m   .... sd3にコピー。

  RaspberryPIにsdカードを差して、起動すると、#　プロンプトが表示されます。
 # sysinst      .... NetBSDのインストールプログラムが起動します。

X11のインストール
------------------
 rpi.bin.gzからインストールした場合、Xは含まれていません。追加したい場合は、

　ftp://nyftp.netbsd.org/pub/NetBSD-daily/HEAD/201310161210Z/evbarm-earmhf/binary/sets/ 以下にあるtarファイルを展開します。tarで展開するときにpオプションをつけて、必要な権限が保たれるようにしてください。

::

 tar xzpvf xbase.tar.gz -C /     .... pをつける

クロスビルドの方法
------------------
* ソースファイル展開
* ./build.sh -U -m evbarm -a earmhf release
* earm{v[4567],}{hf,}{eb} earmv4hf
* http://mail-index.netbsd.org/tech-kern/2013/11/12/msg015933.html

.. csv-table::

 acorn26,armv2
 acorn32,armv3 armv4 (strongarm)
 cats shark netwinder, armv4 (strongarm)
 iyonix,armv5
 hpcarm,armv4 (strongarm) armv5.
 zaurus,armv5
 evbarm,armv5/6/7


pkgsrcを最新にしてみる
----------------------
* cd /usr/pkgsrc
* cvs update -PAd

外付けUSB端子
--------------
  NetBSDで利用できるUSBデバイスは利用できる（はずです)。電源の制約があるので、十分に電源を供給できる外付けUSBハブ経由で接続したほうが良いです。動作しているRPIにUSBデバイスを挿すと、電源の関係でRPIが再起動してしまう場合があります。その場合、電源を増強する基板を利用する方法もあります。

外付けSSD
--------------
 コンパイルには、サンディスク X110 Series SSD 64GB（読込 505MB/s、書込 445MB/s） SD6SB1M-064G-1022I　を外付けディスクケース経由で使っています。NFSが使える環境なら、NFSを使い、pkgsrcの展開をNFSサーバ側で実行する方法もあります。RPIにSSDを接続した場合、OSの種類と関係なく、RPI基板の個体差により、SSDが壊れる場合があるので十分注意してください。


液晶ディスプレイ
-----------------
  液晶キット( http://www.aitendo.com/page/28 )で表示できています。
aitendoの液晶キットはモデルチェンジした新型になっています。
On-Lap 1302でHDMI出力を確認できました。
HDMI-VGA変換ケーブルを利用する場合、MSDOS領域にある設定ファイルcmdline.txtで解像度を指定してください。

::

 https://twitter.com/oshimyja/status/399577939575963648
 とりあえずうちの1024x768の液晶の場合、 hdmi_group=2 hdmi_mode=16 の2行をconfig.txtに書いただけ。なんと単純。disable_borderはあってもなくても関係なし。


inode
-------
  inodeが足りない場合は、ファイルシステムを作り直してください。このイメージでは以下のようにファイルシステムを作成しています。

	# newfs -n 600000 /dev/rvnd0a

bytebench
--------------
  おおしまさん(@oshimyja)がbytebenchの結果を測定してくれました。

 https://twitter.com/oshimyja/status/400306733035184129/photo/1
 https://twitter.com/oshimyja/status/400303304573341696/photo/1


壁紙
-----
  おおしまさん(@oshimyja)ありがとうございます。

::

  http://www.yagoto-urayama.jp/~oshimaya/netbsd/Proudly/2013/


関連バグ
--------

PR 47798
 今回、mikutterのアイコンがでなくて落ちるバグに悩みました。つついさんに感謝します。
	http://gnats.netbsd.org/cgi-bin/query-pr-single.pl?number=47798

pkg/48128: icewm build broken on 6.99.23
 直っています。

port-evbarm/48132: devel/tradcpp build broken on evbearmv6hf-el 6.99.23
 直っています。

port-evbarm/48288:Update firmware from today 2013-10-15. 
 直っています。MSDOS領域に書かれたファームウェアが古い場合、512MBモデルで起動しません。

DMA support and (initial) isoc transfer support.
  http://mail-index.netbsd.org/source-changes/2013/10/15/msg048238.html
  これでUSBカメラが使えるはずですが、、

port-arm/48215: pkg_add fails on recent NetBSD/evbearmv6hf-el current
port-arm/48267: pkg_add thinks it's running on earm even though it's running on earmhf
  http://mail-index.netbsd.org/source-changes/2013/10/26/msg048721.html

harfbuzzからicuが呼ばれているけどicuがコンパイルできない。
  http://mail-index.netbsd.org/pkgsrc-changes/2013/11/05/msg097227.html

pkgsrc/devel/bison
  http://mail-index.netbsd.org/pkgsrc-changes/2013/11/09/msg097366.html

pkgsrc/multimedia/libvpx
  http://mail-index.netbsd.org/pkgsrc-changes/2013/11/09/msg097365.html


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

