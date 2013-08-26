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
.. puppetで設定できるようにする
.. 典型的なCMSインストール方法を追加する

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

NetBSD
--------
 NetBSDは１個のソースツリーをコンパイルすることで実行イメージを作ることができます。

ソースコードから作る
~~~~~~~~~~~~~~~~~~~~~~
 tar 形式のファイルをダウンロード＆展開し、build.shというスクリプトでコンパイルすると、NetBSDの実行イメージができます。

 このtarファイルの中には、これまでNetBSDがサポートしてきた50種類以上のハードウェアと、無数の周辺機器の仕様が含まれています。しかもコンパイルすると、実際にハードウェア上でNetBSDが動作します。

 NetBSDのコンパイルはNetBSDでも、NetBSDではないOSでも、どのハードウェアでも、ほぼ同じ手順でコンパイルできます。（できるはずです）

::

 # ftp ftp://ftp.netbsd.org/pub/NetBSD/NetBSD-current/tar_files/src.tar.gz
 # tar xzvf src.tar.gz
 # ./build.sh -U -m i386 release     .... -U:root以外で作成,この場合i386向け

Xを含んだシステムを作る
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

::

 # ftp ftp://ftp.netbsd.org/pub/NetBSD/NetBSD-current/tar_files/xsrc.tar.gz
 # tar xzvf xsrc.tar.gz
 # cd src
 # ./build.sh -u -U -m i386 -x -X ../xsrc release ... -u:更新,-xX Xも作る

CD-ROMイメージを作る
~~~~~~~~~~~~~~~~~~~~

::

 # ./build.sh -m i386 iso-image　　　... CD-ROMイメージ作成

pkgsrc - ソースコードからソフトウェアを作る
-------------------------------------------

 tar 形式のファイルをダウンロード＆展開し、*ソフトウェアのジャンル/ソフトウェア名* 以下のディレクトリでmakeコマンドを実行すると、10000種類以上のソフトウェアをコンパイル・インストールすることができます。

 このtarファイルの中には、10000種類以上のソフトウエアをコンパイルし、インストールする方法が含まれています。しかもコンパイルすると、実際にそのソフトウェアを動かすこともできます。ソフトウェアのインストールはNetBSDでも、NetBSDではないOSでも、ほぼ同じ手順でコンパイル・インストールできます。（できるはずです）

::

 # cd /usr
 # ftp://ftp.netbsd.org/pub/NetBSD/NetBSD-current/tar_files/pkgsrc.tar.gz
 # tar xzvf pkgsrc.tar.gz
 (# cd /usr/pkgsrc/bootstrap;# ./bootstrap) .. NetBSD以外のOSで実行する
 # cd /usr/pkgsrc/net/mikutter
 # make package-install

baserCMS
""""""""""""

 典型的なCMSは、この手順でインストールできます。

::

 # cd /usr/pkgsrc/www/ap-php ... php54+apache
 # make package-install
 # vi /usr/pkg/etc/httpd/httpd.conf
 LoadModule php5_module lib/httpd/mod_php5.so
 AddHandler application/x-httpd-php .php
 
 # cd /usr/pkgsrc/converters/php-mbstring
 # make package-install
 
 # vi /usr/pkg/etc/php.ini
 extension=mbstring.so
 
 # vi /usr/pkg/etc/httpd/httpd.conf
 DirectoryIndex index.php index.html
 
 # vi /etc/rc.conf
 apache=YES
 # cp /usr/pkg/share/examples/rc.d/apache/etc/rc.d/apache
 # /etc/rc.d/apache start
 
 basercms.netからzipファイルをダウンロード
 # cd /usr/pkg/share/httpd/htdocs
 # unzip basercms-2.1.2.zip
 # chown -R www.www basercms
 # http://localhost/basercms 
 管理者のアカウントとパスワードがメールで飛んでくる！！

ソースコードの更新
--------------------

::

 http://cvsweb.netbsd.org/
 # cd src
 # cvs update -PAd                 ... 最新に更新
 # cvs update -Pd -r netbsd-6-1-1-RELEASE  ... NetBSD6.1.1
 # cd pkgsrc
 # cvs update -PAd                 ... 最新に更新
 # cvs update -Pd -r pkgsrc-2013Q2 ... 2013Q2に更新

ライセンスを許可する
"""""""""""""""""""

 pkgsrcに含まれるソフトウェアのライセンスを見てみましょう。

::

 % cd /usr/pkgsrc/licenses
 % ls |wc -l
 205 
 % ls |head
 % ls |head
 2-clause-bsd
 3proxy-0.5-license
 CVS
 acm-license
 adobe-acrobat-license
 adobe-flashsupport-license
 amap-license
 amaya-license
 amazon-software-license
 amiwm-license
    :

 特定のライセンスを持つソフトウェアのインストールを許可する・許可しないよう、/etc/mk.confファイルで定義できます。

::

 % grep ACCEPTABLE /etc/mk.conf |head
 ACCEPTABLE_LICENSES+= ruby-license
 ACCEPTABLE_LICENSES+= xv-license
 ACCEPTABLE_LICENSES+= mplayer-codec-license
 ACCEPTABLE_LICENSES+= flash-license
 ACCEPTABLE_LICENSES+= adobe-acrobat-license
 ACCEPTABLE_LICENSES+= adobe-flashsupport-license
 ACCEPTABLE_LICENSES+= skype-license
 ACCEPTABLE_LICENSES+= lha-license
 ACCEPTABLE_LICENSES+= opera-eula
 ACCEPTABLE_LICENSES+= lame-license

pkgsrc/packages
""""""""""""""""""
 コンパイルしたパッケージは、pkgsrc/packages以下に生成されます。

::

 % cd /usr/pkgsrc/packages/All/
 % ls *.tgz |head
 GConf-2.32.4nb7.tgz
 GConf-ui-2.32.4nb11.tgz
 ORBit2-2.14.19nb4.tgz
 SDL-1.2.15nb7.tgz
 SDL_mixer-1.2.12nb5.tgz
 acroread9-jpnfont-9.1.tgz
    :
 # pkg_add gedit-2.30.4nb17.tgz  ... インストール
 # pkg_info                      ... 一覧表示
 # pkg_del gedit                 ... 削除

pkgsrcに何か追加したい
"""""""""""""""""""""""

::

 # cd /usr/pkgsrc/pkgtools/url2pkg
 # make package-install
 # cd /usr/pkgsrc/ジャンル/名前
 # url2pkg ダウンロードURL
 Makefileとかができる

バグレポート・追加差分
"""""""""""""""""""""
 www.NetBSD.org から"send-pr"
ライセンスを許可する
"""""""""""""""""""

 pkgsrcに含まれるソフトウェアのライセンスを見てみましょう。

::

 % cd /usr/pkgsrc/licenses
 % ls |wc -l
 205 
 % ls |head
 % ls |head
 2-clause-bsd
 3proxy-0.5-license
 CVS
 acm-license
 adobe-acrobat-license
 adobe-flashsupport-license
 amap-license
 amaya-license
 amazon-software-license
 amiwm-license
    :

 特定のライセンスを持つソフトウェアのインストールを許可する・許可しないよう、/etc/mk.confファイルで定義できます。

::

 % grep ACCEPTABLE /etc/mk.conf |head
 ACCEPTABLE_LICENSES+= ruby-license
 ACCEPTABLE_LICENSES+= xv-license
 ACCEPTABLE_LICENSES+= mplayer-codec-license
 ACCEPTABLE_LICENSES+= flash-license
 ACCEPTABLE_LICENSES+= adobe-acrobat-license
 ACCEPTABLE_LICENSES+= adobe-flashsupport-license
 ACCEPTABLE_LICENSES+= skype-license
 ACCEPTABLE_LICENSES+= lha-license
 ACCEPTABLE_LICENSES+= opera-eula
 ACCEPTABLE_LICENSES+= lame-license

pkgsrc/packages
""""""""""""""""""
 コンパイルしたパッケージは、pkgsrc/packages以下に生成されます。

::

 % cd /usr/pkgsrc/packages/All/
 % ls *.tgz |head
 GConf-2.32.4nb7.tgz
 GConf-ui-2.32.4nb11.tgz
 ORBit2-2.14.19nb4.tgz
 SDL-1.2.15nb7.tgz
 SDL_mixer-1.2.12nb5.tgz
 acroread9-jpnfont-9.1.tgz
    :
 # pkg_add gedit-2.30.4nb17.tgz  ... インストール
 # pkg_info                      ... 一覧表示
 # pkg_del gedit                 ... 削除

pkgsrcに何か追加したい
"""""""""""""""""""""""

::

 # cd /usr/pkgsrc/pkgtools/url2pkg
 # make package-install
 # cd /usr/pkgsrc/ジャンル/名前
 # url2pkg ダウンロードURL
 Makefileとかができる

バグレポート・追加差分
"""""""""""""""""""""
 www.NetBSD.org から"send-pr"

