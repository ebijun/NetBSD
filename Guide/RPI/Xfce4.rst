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
RaspberryPIでNetBSDを使ってみる(Xfceとか)
===========================================

RaspberryPI向けNetBSDイメージ
-------------------------------
RaspberryPI上で動くNetBSDイメージを配布しています。SDにイメージをコピーして、
HDMIケーブルとUSBキーボード/マウス/有線ネットワークをつないで、
電源をつなぐと起動します。一度、SDカードのサイズまでパーティション領域を自動的に
ひろげて、勝手にリブートします。
そのあと、rootでログインできます。パスワードはつけていません。
rootアカウントにログインできるのはコンソールからだけです。
もうちょっと詳しい説明はこちらにあります。

::

  https://github.com/ebijun/NetBSD/blob/master/Guide/RPI.rst


startxと.xinitrc
------------------

コマンドプロンプトからstartxコマンドを実行すると、icewmが起動するように
なっています。

::

  # startx

このイメージの/root/.xinitrcは以下のURLにあります。

::

  https://github.com/ebijun/NetBSD/blob/master/RPI/RPIimage/root/.xinitrc


順番にざっとみてみましょう。
このあたりで、日本語キーボードに設定しています。
オプションにctrl:swapcapsと指定すると、コントロールキーとCAPSキーを入れ替えます。

::

 #set keyboard layout
 #setxkbmap -layout jp -option ctrl:swapcaps
 setxkbmap -model jp106 jp

次に、日本語入力の設定です。uim経由で入力できるように、環境変数XMODIFIERSを
設定します。uimの設定を細かく指定したい時は、uim-pref-gtkというアプリケーションを
起動して変更します。

::

 uim-xim &
 # To select input method via uim-pref-gtk userinterface.
 # uim-pref-gtk 
 export XMODIFIERS=@im=uim

もし、デスクトップ環境としてxfce4を使うときにはコメントアウトしてあるstartxfce4の
#をはずせば、ここでXfce4を起動できます。ディスク容量の関係でXfceをイメージには入れて
いないので、この後追加してみましょう。

::

 #to install: pkg_add xfce4
 #startxfce4;exit

icewmを使うときにはこのまま進みます。背景の色はxsetrootで決められます。
バックグラウンドでの画像表示はxsetbgを使っていますが、icewmの設定ファイルでも
指定できます。

::

  xsetroot -bg black -grey
  #kterm -geometry 80x25+0+0 -fk k14 -fn a14 -fr r14 -km euc&
  xsetbg NetBSD.png

mikutterを使いはじめるとき、twitterの認証画面をWebブラウザで表示します。
デフォルトのブラウザをdilloに指定しておくと、クリックしただけでdilloが
起動します。

::

  #for mikutter , click and start browser.
  export BROWSER=dillo

あとは、icewmが入っていればicewmを。なければtwmを起動します。

::

  xterm  -geometry 80x25+0+0 &
  
  if [ -f /usr/pkg/bin/icewm ]; then
    icewm
  else
    twm
  fi

Xfce4をインストールする
-------------------------

pkg_addコマンドでXfce4をインストールしてみましょう。正常に終わればXfce4がインストールできています。

::

  pkg_add xfce4


.xinitrcでコメントアウトされていたstartxfce4の行の#をはずして、startxコマンドを
実行してみましょう。画面が真っ黒になってびびりますが、そのまま待っているとねずみちゃんの
ような何かが表示されます。


Firefoxもインストールしてみる
-----------------------------

うまくいったらfirefoxもインストールしてみましょう。正常に終わればfirefoxがインストールできています。

::

  pkg_add firefox
  pkg_add firefox-l10n

コンパイル済みパッケージのありか
---------------------------------

このイメージではpkg_addコマンドでコンパイル済みパッケージをインストールできるようにしています。
コンパイル済みイメージの場所は、/etc/pkg_install.confに書いてあります。
そこにはftp://ftp.netbsd.org/pub/NetBSD/misc/jun/raspberry-pi/earmv6hf/2015-11-26/
のようなURLがかいてあります。自分でコンパイルしたパッケージを使う場合は、この部分を書き換えて
みてください。


