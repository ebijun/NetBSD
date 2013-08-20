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

.. イメージファイルは圧縮すること



NetBSD
--------
 NetBSDは１個のソースツリーをコンパイルすることで実行イメージを作ることができます。

ソースコードから作る
""""""""""""""""""""
 tar 形式のファイルをダウンロード＆展開し、build.shというスクリプトでコンパイルすると、NetBSDの実行イメージができます。

 このtarファイルの中には、これまでNetBSDがサポートしてきた50種類以上のハードウェアと、無数の周辺機器の仕様が含まれています。しかもコンパイルすると、実際にハードウェア上でNetBSDが動作します。

 NetBSDのコンパイルはNetBSDでも、NetBSDではないOSでも、どのハードウェアでも、ほぼ同じ手順でコンパイルできます。（できるはずです）

::

 # ftp ftp://ftp.netbsd.org/pub/NetBSD/NetBSD-current/tar_files/src.tar.gz
 # tar xzvf src.tar.gz
 # ./build.sh -U -m i386 release     .... -U:root以外で作成,この場合i386向け

Xを含んだシステムを作る
"""""""""""""""""""""""""

::

 # ftp ftp://ftp.netbsd.org/pub/NetBSD/NetBSD-current/tar_files/xsrc.tar.gz
 # tar xzvf xsrc.tar.gz
 # cd src
 # ./build.sh -u -U -m i386 -x -X ../xsrc release ... -u:更新,-xX Xも作る

CD-ROMイメージを作る
"""""""""""""""""""""

::

 # ./build.sh -m i386 iso-image　　　... CD-ROMイメージ作成

pkgsrc - ソースコードからソフトウェアを作る
""""""""""""""""""""""""""""""""""""""""""""

 tar 形式のファイルをダウンロード＆展開し、*ソフトウェアのジャンル/ソフトウェア名* 以下のディレクトリでmakeコマンドを実行すると、10000種類以上のソフトウェアをコンパイル・インストールすることができます。

 このtarファイルの中には、10000種類以上のソフトウエアをコンパイルし、インストールする方法が含まれています。しかもコンパイルすると、実際にそのソフトウェアを動かすこともできます。ソフトウェアのインストールはNetBSDでも、NetBSDではないOSでも、ほぼ同じ手順でコンパイル・インストールできます。（できるはずです）

::

 # cd /usr
 # ftp://ftp.netbsd.org/pub/NetBSD/NetBSD-current/tar_files/pkgsrc.tar.gz
 # tar xzvf pkgsrc.tar.gz
 (# cd /usr/pkgsrc/bootstrap;# ./bootstrap) .. NetBSD以外のOSで実行する
 # cd /usr/pkgsrc/net/mikutter
 # make package-install

ソースコードの更新
"""""""""""""""""""""

::

 http://cvsweb.netbsd.org/
 # cd src
 # cvs update -PAd                 ... 最新に更新
 # cvs update -Pd -r netbsd-6-1-1-RELEASE  ... NetBSD6.1.1
 # cd pkgsrc
 # cvs update -PAd                 ... 最新に更新
 # cvs update -Pd -r pkgsrc-2013Q2 ... 2013Q2に更新


