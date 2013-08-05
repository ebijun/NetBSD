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

 .. todo:: Ontapの液晶で写らない
 .. todo:: icewmの設定方法を書く
 .. todo:: btキーボード・マウス
 .. todo:: deforaos-* をテスト
 .. todo:: puppetまたはansibleで設定する
 .. todo:: KOBO起動方法＆テスト
 .. todo:: beaglebone black テスト

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

 # ftp ftp://ftp.netbsd.org/pub/NetBSD/misc/jun/raspberry-pi/2013-07-30-netbsd-raspi.img.gz
 MD5 (2013-07-30-netbsd-raspi.img.gz) = 915cafbbff8ad6d074516c1cca4f1867

* 2GB以上のSDカードを準備します。
* ダウンロードしたディスクイメージを、SDカード上で展開します。

::

	disklabel sd0  ..... 必ずインストールするSDカードか確認してください。
	gunzip < 2013-07-30-netbsd-raspi.img.gz|dd of=/dev/rsd0d bs=1m

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


コンパイル済パッケージをインストールする
--------------------------------------------------
* /root/Package以下に、今回のイメージに利用したパッケージをインストールしたスクリプトが入っています。
* コンパイル済みパッケージ

ここでは、筒井さん作成の、pkgsrc 2013Q2のARM向けコンパイル済みパッケージを利用します。
	http://teokurebsd.org/netbsd/packages/arm/6.1_2013Q1

* パッケージのインストール

 pkg_addコマンドで、あらかじめコンパイル済みのパッケージをインストールします。関連するパッケージも自動的にインストールします。

::

	# pkg_add http://teokurebsd.org/netbsd/packages/arm/6.1_2013Q1/All/パッケージ

* パッケージの一覧

 pkg_infoコマンドで、インストールされているパッケージの一覧を表示します。

::

	# pkg_info

* パッケージの削除

::

	# pkg_delete パッケージ名


/usr/pkgsrcを使ってみよう
--------------------------
 pkgsrc-2013Q2が/usr/pkgsrcに展開してあります。
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

::

 # vnconfig vnd0 2013-07-30-netbsd-raspi.img
 # disklabel vnd0
 # newfs /dev/rvnd0a
 # dump 0f - /dev/rsd3a | restore -xvf -
 # newfs_msdos /dev/rvnd0e

HDMIじゃなくシリアルコンソールで使うには
----------------------------------------
* MSDOS領域にある設定ファイルcmdline.txtの内容を変更してください。

::

 console=fb      ←この行を消します
 genfb.type=39
 root=ld0a 

起動ディスクを変えるには
------------------------
* MSDOS領域にある設定ファイルの内容を変更してください。

::

 console=fb
 genfb.type=39
 root=ld0a       ←ld0をsd0にするとUSB接続したディスクから起動します

最小構成のディスクイメージ
--------------------------
  NetBSD-currentのディスクイメージに関しては、以下の場所にあります。

::

 # ftp ftp7.jp.netbsd.org:/pub/NetBSD-daily/HEAD/日付/evbarm/gz.../rpi.bin.gz
 # ftp ftp7.jp.netbsd.org:/pub/NetBSD-daily/HEAD/日付/evbarm/gz.../rpi_inst.bin.gz
  HEADの部分を6.1に入れ替えるとNetBSD6.1のイメージがあります。
 # gunzip < rpi_inst.bin.gz |dd of=/dev/rsd3d bs=1m   .... sd3にコピー。

  RaspberryPIにsdカードを差して、起動すると、#　プロンプトが表示されます。
 # sysinst      .... NetBSDのインストールプログラムが起動します。

X11のインストール
------------------
 rpi.bin.gzからインストールした場合、Xは含まれていません。追加したい場合は、
 ftp://ftp7.jp.netbsd.org/pub/NetBSD-daily/HEAD/日付/evbarm/binary/sets/x* をダウンロードし、tarファイルを展開します。

::

 tar xzpvf xbase.tar.gz -C /

クロスビルドの方法
------------------
* ソースファイル展開
* ./build.sh -U -m evbarm release

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

#47798
------

今回、mikutterのアイコンがでなくて落ちるバグに悩みました。つついさんに感謝します。
	http://gnats.netbsd.org/cgi-bin/query-pr-single.pl?number=47798

パーティションサイズをSDカードに合わせる
-----------------------------------------
　2GB以上のSDカードを利用している場合、パーティションサイズをSDカードに合わせることができます。この手順はカードの内容が消えてしまう可能性もあるため、重要なデータはバックアップをとるようにしてください。
  手順は、http://wiki.netbsd.org/ports/evbarm/raspberry_pi/ のGrowing the root file-systemにあります。
 このイメージのために、つついさんにスクリプトを作っていただきました。

#. vi /etc/rc.confでrc_configured=NOに書き換え
#. reboot　.... シングルユーザで起動
#.  Enter pathname of shell or RETURN for /bin/sh: でリターン
#. cd /root/Extract/
#. sh expand-image-fssize-rpi.sh ... しばらくかかります
#.  リターンを押すと再起動します

どうしても失敗する場合は、SDカードにエラーが起きている場所があるかもしれません。

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

