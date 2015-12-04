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
RaspberryPIでNetBSDを使ってみる(omxplayerとか)
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


omxplayer
------------------

RaspberryPIにはGPUが載っていて、動画再生ソフトのomxplayer(https://github.com/popcornmix/omxplayer)をNetBSDでも使うことができます。
pkgsrc/multimedia/omxplayer です。

::

  # pkg_add omxplayer

youtube-dlのインストール
-----------------------

youtube-dl(http://rg3.github.io/youtube-dl/)もインストールしてみましょう。
pkgsrc/net/youtube-dl です。

::

  # pkg_add youtube-dl

youtube-dlとomxplayerで動画再生
-----------------------------------

youtube-dl経由でダウンロードしたビデオをomxplayerで再生してみます。
スペースキーで一時停止、qで終了します。

::

  # youtube-dl https://www.youtube.com/watch?v=wG8ZCC8IwvM
  # omxplayer *.mp4

livestreamerをインストールしてみる
----------------------

ストリームを再生するためのコマンドラインユーティリティ
livestreamer(http://livestreamer.tanuki.se/)をインストールしてみましょう。
pkgsrc/wip/livestreamerにもありますが、Pythonのpip経由をつかってみます。

::

  #  pkg_add py27-pip
  #  pip2.7 install livestreamer


livestreamer経由のストリーム再生
---------------------------
youtubeのビデオを、livestreamer経由でストリーム再生してみましょう。コマンドラインでプレーヤーと再生品質を指定して、livestreamerを起動します。crontabで起動するようにすると、定期的にビデオ再生をするシステムを簡単に作ることができます。

::

  #  livestreamer --player omxplayer --fifo --yes-run-as-root https://www.youtube.com/watch?v=wG8ZCC8IwvM --default-stream best


