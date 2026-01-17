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
Playfield Engine を使ってみる
=========================

Playfield Engine
-----------------------

Playfield Engine(https://github.com/awemorris/PlayfieldEngine)は、2Dゲームエンジンです。Playfield Scriptで書かれたスクリプトを使ってグラフィックをレンダリングし、サウンドを再生します。
C/JavaScriptのようなスクリプト言語であるPlayfield Scriptと、ポータブルなゲームライブラリであるStratoHALによって駆動され、Windows、macOS、Linux、Chromebook、WebAssembly、iOS、Android、およびコンソールなど、幅広いプラットフォームで動作します。
ランタイムはWindowsで約1.4MBと非常に小さく、古いマシンや低スペックのマシンでもスムーズに動作するように設計されており、誰もがゲーム開発にアクセスできるようにすることを目指しています。

以下の手順でNetBSDにインストールしてみます。

必要なパッケージのインストール
--------------------------------

 pkginをインストールします。パッケージの置いてある場所をrepositories.confに追加します。
 
:: 

 pkg_add pkgin
  vi /usr/pkg/etc/pkgin/repositories.conf
 http://cdn.netbsd.org/pub/NetBSD/misc/jun/raspberry-pi/`uname -p`/2025
 
 pkgin install git-base
 pkgin install cmake
 pkgin install ninja-build


プログラムのインストール
-----------------------------

リポジトリをクローンして、cmake経由でプログラムを作成します。

::

 git clone --recursive https://github.com/awemorris/PlayfieldEngine.git
 cd PlayfieldEngine
 git submodule update --init
 mkdir build
 cd build
 cmake -DCMAKE_INSTALL_RPATH=/usr/X11R7/lib ..
 make
 check /usr/local
 make install
 check /usr/local

サンプルプログラムの実行
-------------------------

::

 cd ../samples/shoot2/
 ./playfield

実行ファイルをまとめる
--------------------------

/usr/local/以下に必要なファイルを集めて、配布用にまとめてみます。

::

 cp -r samples /usr/local
 cd /usr/local
 tar czvf /root/playfield-`uname -p`-nightly-20251026-7cbe585.tgz /usr/local


