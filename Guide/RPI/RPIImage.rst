.. 
 Copyright (c) 2013-5 Jun Ebihara All rights reserved.
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

===========================================
RaspberryPIでNetBSDを使ってみる(イメージ作成)
===========================================


Raspberry PIのイメージをつくろう
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Raspberry　PIで動くイメージファイルの作り方を説明します。

ISOイメージ取得
--------------------
NetBSDのISOイメージをダウンロードします。
ダウンロードには、以下のRubyスクリプトを使っています。

::

　https://github.com/ebijun/NetBSD/blob/master/RPI/RPIimage/Image/NewestISO

編集するところ：ftpサーバを選ぶ

::

 FTP="nyftp.netbsd.org"
 #FTP="ftp.jp.netbsd.org"
 #FTP="ftp7.jp.netbsd.org"

編集するところ: アーキテクチャ選択

::

 #ARCH="earmv7hf"
 ARCH="earmv6hf"
 #ARCH="earm"

コマンドを実行すると、指定したftpサーバが持っている最新のイメージをダウンロードするためのスクリプトを生成します。

::

  $ ./NewestISO 
  ftp ftp://nyftp.netbsd.org/pub/NetBSD-daily/HEAD/201511241720Z/images/NetBSD-7.99.21-evbarm-earmv6hf.iso
  mv NetBSD-7.99.21-evbarm-earmv6hf.iso ./NetBSD-7.99.21-evbarm-earmv6hf-201511241720Z.iso

コマンドの出力結果をshに渡すとダウンロードを実行します。

::

  $ ./NewestISO |sh

ダウンロードがうまくいくと、以下のようなisoイメージをダウンロードできます。

::

  NetBSD-7.99.21-evbarm-earmv6hf-201511241720Z.iso


イメージ作成用Makefile
--------------------------

イメージファイルを作るためにMakefileを作っています。

::

 https://github.com/ebijun/NetBSD/blob/master/RPI/RPIimage/Image/Makefile

編集するところ： イメージファイルの置き場所とかを指定します。

::

 ARCH=earmv6hf
 #ARCH=earmhf
 #ARCH=earm
 PKG_PATH=ftp://ftp.netbsd.org/pub/NetBSD/misc/jun/raspberry-pi/${ARCH}/2015-11-14/
 # iso file information
 IMAGE=/usr/release/images/NetBSD-7.99.21-evbarm-${ARCH}-201511091610Z.iso
 PKGSRC=../../../pkgsrc/pkgsrc-2015Q3.tar.gz 


make を実行するとイメージファイルができます。
make releaseを実行すると、初期設定ファイル等をコピーします。
make pkgを実行すると、パッケージをインストールするための準備ができます。

::

  # make
  # make release
  # make pkg

./Copy を実行して、パッケージをSDカードにコピーします。

::

  https://github.com/ebijun/NetBSD/blob/master/RPI/RPIimage/Image/Copy より：
  DEVICE=rsd2d
  
  #BOARD=raspi-earm
  BOARD=raspi-earmv6hf
  #BOARD=raspi-earmv7hf
  
  COMPRESS=-z
  SUFFIX=.gz
  #COMPRESS=
  
  #DATE=`date +%Y-%m-%d`
  #DATE=2015-11-10
  
  progress $COMPRESS -f ${DATE}-netbsd-${BOARD}.img${SUFFIX} dd of=/dev/${DEVICE} bs=4m

RPIでパッケージのインストール
----------------------------

RPI2にSDカードをさして、ブートするか確認します。rootでログインして、必要なパッケージをインストールします。

::

  cd Package 
  edit Install
  ./Install

インストールが終わったら再起動して、fontconfigを実行しておきます。
RPIに差し替えて起動して、dmesgを出力しておきます。

::

  # dmesg > dmesg  ...RPIの場合
  # dmesg > dmesg7 ...RPI2の場合

イメージをSDカードから書き戻すためのスクリプトを実行します。

::

  https://github.com/ebijun/NetBSD/blob/master/RPI/RPIimage/Image/03_back

tmp日付ディレクトリにRPI,RPI2のdmesgとpkginfoができます。

一時起動時にできたログファイルを消して、配布用イメージを作ります。

::

 make logclean
 make release

./Copy (https://github.com/ebijun/NetBSD/blob/master/RPI/RPIimage/Image/Copy)を実行して、できたイメージをSDカードに書き戻します。RPIにさして起動して、自動リサイズが正しく起動するか確認します。

rootでログインします。startxを実行します。mikutterを起動します。認証し、何かツィートしてみます。
あひる焼きを含む文章をツィートして、何か返事があればできあがりです。

::
  
  http://movapic.com/ebijun/pic/5287850

できたことを知らせる
-----------------------

port-armメーリングリストにリリースメールを書きます。mail-indexに載ったらURLをツィートします。

::

  https://github.com/ebijun/NetBSD/blob/master/RPI/RPIimage/README に書いて、
  http://mail-index.netbsd.org/port-arm/2015/11/11/msg003550.html 

dmesg/pkginfoを書きます。

::

  https://github.com/ebijun/NetBSD/blob/master/dmesg/earmv6hf/RPI
  https://github.com/ebijun/NetBSD/blob/master/dmesg/earmv6hf/RPI2
  https://github.com/ebijun/NetBSD/blob/master/RPI/RPIimage/pkgsrc/pkginfo


RPIのフォーラムにも投げます。

::

  https://www.raspberrypi.org/forums/viewforum.php?f=86


..

 .. csv-table:: 2015年に作ったRPIイメージ一覧
 :widths: 20 130

 2015/2/7,http://mail-index.netbsd.org/port-arm/2015/02/04/msg002833.html
 2015/2/28,http://mail-index.netbsd.org/port-arm/2015/02/26/msg002883.html
 2015/3/13,http://mail-index.netbsd.org/port-arm/2015/03/10/msg002918.html
 2015/4/19,http://mail-index.netbsd.org/port-arm/2015/04/19/msg003100.html
 2015/5/23,http://mail-index.netbsd.org/port-arm/2015/05/21/msg003185.html
 2015/6/13,http://mail-index.netbsd.org/port-arm/2015/06/06/msg003243.html
 2015/6/30,http://mail-index.netbsd.org/port-arm/2015/06/30/msg003266.html (7.0RC1)
 2015/7/4,http://mail-index.netbsd.org/port-arm/2015/07/02/msg003268.html
 2015/7/30,http://mail-index.netbsd.org/port-arm/2015/07/31/msg003351.html (7.0RC2)
 2015/8/8,http://mail-index.netbsd.org/port-arm/2015/08/06/msg003389.html
 2015/8/19,http://mail-index.netbsd.org/port-arm/2015/08/19/msg003428.html
 2015/8/22,http://mail-index.netbsd.org/port-arm/2015/08/20/msg003430.html
 2015/9/5,http://mail-index.netbsd.org/port-arm/2015/09/03/msg003439.html
 2015/9/19,http://mail-index.netbsd.org/port-arm/2015/09/14/msg003467.html
 2015/9/28,http://mail-index.netbsd.org/port-arm/2015/09/29/msg003496.html (7.0)
 2015/10/3,http://mail-index.netbsd.org/port-arm/2015/09/30/msg003497.html
 2015/10/25,http://mail-index.netbsd.org/port-arm/2015/10/20/msg003534.html
 2015/11/7,http://mail-index.netbsd.org/port-arm/2015/11/04/msg003546.html
 2015/11/14,http://mail-index.netbsd.org/port-arm/2015/11/11/msg003550.html
 2015/12/27,http://mail-index.netbsd.org/port-arm/2015/12/27/msg003586.html



