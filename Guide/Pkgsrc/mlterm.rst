.. 
 Copyright (c) 2016-2025 Jun Ebihara All rights reserved.
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


=========================
mlterm-wscons を使ってみる
=========================

mlterm
------------

リソースの限られたマシンでは、Xを起動させるだけでリソースを使いきってしまう場合があります。
mlterm (pkgsrc/x11/mlterm) [mlterm]_ は、X上で動作する多言語ターミナルエミュレータですが、mlterm-fbを有効にしてコンパイルすると、フレームバッファ上で動作する多言語ターミナルエミュレータとして利用できます。

.. image:: ../Picture/2013/08/02/DSC_2283.jpg
 :width: 800

mlterm-wscons 向けオプション設定
------------------------------

/etc/mk.confに、mltermに与えるオプションを指定しておきます。pkgsrc/x11/mlterm以下を利用して、mltermをインストールします。

::

 % grep mlterm /etc/mk.conf
 PKG_OPTIONS.mlterm=xft2 mlterm-fb
 # cd /usr/pkgsrc/x11/mlterm
 # make package-install
 # which mlterm-wscons
 /usr/pkg/bin/mlterm-wscons

mlterm-wscons フォント設定
-------------------------------------

mlfc コマンドを実行すると、true typeフォントを検索して、
~/.mlterm/aafont と ~/.mlterm/font-fb ファイルを更新します。

::

 $ mlfc
 Updating /home/jun/.mlterm/aafont
 Updating /home/jun/.mlterm/font-fb


起動
-----------

 コンソール画面からmlterm-wsconsを起動します。

::

 % mlterm-wscons
 Shift-F1: 画面横分割
 Shift-F2: 画面縦分割
 Shift-F3: 画面移動
 % mlterm-wscons -p RPI2.png --contrast 70
 背景をRPI2.pngにします。コントラストを70%に設定します。


PCでのmlterm-fb起動
-----------------------

NetBSD/i386,amd64でmlterm-fbを利用する場合、起動時にVESAを指定します。 [はよーん]_

#. 起動オプションで5を選択
#. > プロンプトでvesa を指定
#. boot
#. 起動
#. ログイン
#. mlterm-wscons起動

テスト画像表示
---------------

 mlterm-wsconsを起動した状態で、catを利用して、画像イメージを表示します。

::

 % ftp http://mlterm.sourceforge.net/vimperator.six
 % cat vimperator.six

画像変換方法
--------------

 netpbmをインストールして、以下のコマンドを実行するとsixel形式に変換できます。

::

 # cd /usr/pkgsrc/graphics/netpbm;make package-install
 % jpegtopnm aaa.jpg |pnmquant 256 |ppmtosixel > aaa.sixel
 % pngtopnm  aaa.png |pnmquant 256 |ppmtosixel > aaa.sixel

mltermソースからmlterm-wsconsをコンパイルする
-------------------------------------------

::

 # ./configure --with-gui=xlib,fb
 # make install

回転させて表示
-----------------

NetBSD/zaurus C1000以降および、NetBSD/hpcarm WS011SHでは、そのまま起動すると、
mltermが縦画面で起動してしまいます。この場合、mltermに--rotateオプションをつけて起動するか、起動後に$ mlcc rotate_display trueすると回転します。
。
.. --rotateオプションの挙動を変更し、--rotate=rightで時計回りに、--rotate=leftで反時計回りに回転します。(WS011SHは反時計回り?)
この機能は最新版( http://t.co/l52DRJGwGf )　に追加されています。


mltermについて
-----------------

 *http://mlterm.sourceforge.net/* に、より詳しい情報があります。

mlterm-fb上でsayakaを動かしてみる
-------------------------------

mlterm-wscons上で日本語が表示できたら、sayaka [sayaka]_ を利用してmisskey.ioのタイムラインを表示してみましょう。

sayakaのインストール
-------------------

pkgsrcからsayakaをインストールします。

::

 # cd /usr/pkgsrc/net/sayaka
 # make package-install 

nanotodonのインストール
---------------------------

pkgsrcからnanotodon をインストールします。

::

 # cd /usr/pkgsrc/net/nanotodon
 # make package-install

.. rubic:: 

.. [mlterm] mlterm http://mlterm.sourceforge.net/
.. [tw] tw http://shokai.github.io/tw/
.. [はよーん] http://jnug.net/msg012914ja.html
.. [sayaka] https://github.com/isaki68k/sayaka

NetBSD/x68k での表示方法
----------------------------

::

 % mlterm-x68kgrf
 LANG=ja_JP.UTF-8ja
 
