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

.. puppetで設定できるようにする
.. contaoとか説明した方がいいのか。
.. PSPとBSDライセンス
.. BSDの略称説明

BSDライセンス
--------------
 BSDは、Berkeley Software Distibutionの略称です。

#. http://ja.wikipedia.org/wiki/BSD
#. /usr/src/share/misc/bsd-family-tree
 
BSDライセンスとNetBSD
~~~~~~~~~~~~~~~~~~~~~~
 NetBSDのソースコードは、自由に配布したり売ることができます。 NetBSDのソースコードから作ったバイナリを売ることもできます。バイナリのソースコードを公開する義務はありません。


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

NetBSD
--------
 NetBSDは１個のソースツリーをコンパイルすることで実行イメージを作ることができます。

ソースコードから作る
~~~~~~~~~~~~~~~~~~~~~~
 tar 形式のファイルをダウンロード＆展開し、build.shというスクリプトでコンパイルすると、NetBSDの実行イメージができます。

 このtarファイルの中には、これまでNetBSDがサポートしてきた50種類以上のハードウェアと、無数の周辺機器の仕様が含まれています。しかもコンパイルすると、実際にハードウェア上でNetBSDが動作します。

 NetBSDのコンパイルはNetBSDでも、NetBSDではないOSでも、どのハードウェアでも、ほぼ同じ手順でコンパイルできます。（できるはずです）

::

 # ftp ftp://ftp.NetBSD.org/pub/NetBSD/NetBSD-current/tar_files/src.tar.gz
 # tar xzvf src.tar.gz
 # ./build.sh -U -m i386 release     .... -U:root以外で作成,この場合i386向け

Xを含んだシステムを作る
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


::

 # ftp ftp://ftp.NetBSD.org/pub/NetBSD/NetBSD-current/tar_files/xsrc.tar.gz
 # tar xzvf xsrc.tar.gz
 # cd src
 # ./build.sh -u -U -m i386 -x -X ../xsrc release ... -u:更新,-xX Xも作る

CD-ROMイメージを作る
~~~~~~~~~~~~~~~~~~~~

::

 # ./build.sh -m i386 iso-image　　　... CD-ROMイメージ作成


pkgsrc - ソースコードからソフトウェアを作る
-------------------------------------------

世界中にあるいろいろなプログラムをコンパイル・インストールする手順は、プログラムごとにまちまちです。世界中のプログラムを、すべて同じ手順でコンパイルして、インストールするためには、どのような枠組みがあればよいでしょうか？

ソースコードからプログラムをコンパイル・インストールする時、NetBSDでは主に、pkgsrcを利用します。pkgsrcでは、13000種類以上のプログラムについて、コンパイル手順を分野ごとにまとめて、収集しています。

 pkgsrcの役割を挙げてみます。

#. 適切なサイトからソースコードをダウンロード展開する。
#. 適切なオプションをつけて、コンパイルする。
#. インストールする。
#. コンパイルした結果からパッケージを作る。
#. 他のマシンにパッケージをインストールする。

 それではpkgsrcを実際に使ってみましょう。pkgsrc.tar.gzというファイルを展開して利用します。ここでは、すぐれたtwitterクライアントであるmikutterをインストールします。makeコマンドを実行すると、関連するソフトウェアをインストールします。

::

 # cd /usr
 # ftp://ftp.NetBSD.org/pub/NetBSD/NetBSD-current/tar_files/pkgsrc.tar.gz
 # tar xzvf pkgsrc.tar.gz
 (cd /usr/pkgsrc/bootstrap;./bootstrap) .. NetBSD以外のOSで実行する
 # cd /usr/pkgsrc/net/mikutter
 # make package-install

 pkgsrc.tar.gz ファイルの中には、12000種類以上のソフトウエアをコンパイルし、インストールする方法が含まれています。しかもコンパイルすると、実際にそのソフトウェアを動かすこともできます。ソフトウェアのインストールはNetBSDでも、NetBSDではないOSでも、ほぼ同じ手順でコンパイル・インストールできます。（できるはずです）


gitをインストールしてみる
~~~~~~~~~~~~~~~~~~~~~~~~~~~

::

 # cd /usr/pkgsrc/devel/git-base  
 # make install
 # which git
 /usr/pkg/bin/git

baserCMSをインストールしてみる
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

 典型的なCMSは、この手順でインストールできます。

::

 # cd /usr/pkgsrc/www/ap-php ... php54+apache
 # make package-install      .... 関連するソフトウェアが全部コンパイル・インストール
 # vi /usr/pkg/etc/httpd/httpd.conf
 LoadModule php5_module lib/httpd/mod_php5.so
 AddHandler application/x-httpd-php .php
 
 # cd /usr/pkgsrc/converters/php-mbstring
 # make package-install
 
 # vi /usr/pkg/etc/php.ini
 extension=mbstring.so
 
 baserCMSはMySQLをインストールしなくても利用できますが、利用する場合
 # cd /usr/pkgsrc/databases/php-mysql  ... php+mysqlインストール
 # vi /usr/pkg/etc/php.ini
 extension=mysql.so
 
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
 
 pkgsrcを使う場合：
 # cd /usr/pkgsrc/www/php-basercms
 # make package-install

SSL設定
"""""""""

証明書のファイルを指定して、httpd.confのコメントを外して、apacheを再起動します。

::

 /usr/pkg/etc/httpd/httpd-ssl.conf
 SSLCertificateFile
 SSLCertificateKeyFile
 SSLCertificateChainFile
 
 /usr/pkg/etc/httpd/httpd.conf
 Include etc/httpd/httpd-ssl.conf  ... コメントはずす

日本語Wordpress
"""""""""""""""""""

::

 # cd /usr/pkgsrc/www/php-ja-wordpress
 # make package-install


LibreOfficeを動かしてみる
~~~~~~~~~~~~~~~~~~~~~~~~~~~
LibreOffice5をインストールしてみましょう。

::

 # cd /usr/pkgsrc/misc/libreoffice
 # make package-install
     : 9時間くらいかかります。
 # which soffice
 /usr/pkg/bin/soffice

インストールするソフトウェアのライセンスを意識する
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
あるソフトウェアのソースコードをどのように取り扱えばいいのかは、ソフトウェアに含まれるライセンスに書かれています。
GNUやBSDやMITやApacheなど有名なライセンスもあれば、有名なライセンスを少しだけ入れ替えて、目的にあったライセンスに作り替えたものなど、まちまちです。
pkgsrcでは、pkgsrcに含まれるソフトウェアのライセンスを収集しています。実際に見てみましょう。

::

 % cd /usr/pkgsrc/licenses  ... ライセンス条項が集まっている
 % ls |wc -l
 214 
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

特定のライセンスを持つソフトウェアのインストールを許可するかどうかは、 
/etc/mk.conf ファイルで定義します。
星の数ほどあるソフトウェアのライセンスを受け入れるかどうかを、自分で決めることができます。

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
~~~~~~~~~~~~~~~~~~~~~
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
~~~~~~~~~~~~~~~~~~~~~~~~

::

 # cd /usr/pkgsrc/pkgtools/url2pkg
 # make package-install
 # cd /usr/pkgsrc/ジャンル/名前
 # url2pkg ダウンロードURL
 Makefileとかができる

/usr/pkgsrc以下のメンテナンス
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

::

 # cd /usr/pkgsrc/pkgtools/lintpkgsrc
 # make package-install
 # cd /usr/pkgsrc;cvs update -PAd  ... /usr/pkgsrcを最新にする
 # lintpkgsrc -pr   ....  古くなったバイナリパッケージを消す
 # lintpkgsrc -or   ....  古くなったソースファイルを消す
 # lintpkgsrc -mr   ....  ソースファイルのチェックサムが/usr/pkgsrcと合っているか

pkgsrcの更新
~~~~~~~~~~~~~~
pkg_chkを使う方法

::

 # cd /usr/pkgsrc/pkgtools/pkg_chk
 # make package-install
 # cd /usr/pkgsrc
 # cvs update -PAd
 # pkg_chk -u         .... 古いパッケージをコンパイルして更新する

pkg_rolling-replaceを使う方法:依存関係に従って更新する

::

 # cd /usr/pkgsrc/pkgtools/pkg_rolling-replace
 # make package-install
 # cd /usr/pkgsrc
 # cvs update -PAd
 # pkg_rolling-replace -u

ソースコードの更新
~~~~~~~~~~~~~~~~~~~~

::

 http://cvsweb.NetBSD.org/
 # cd src
 # cvs update -PAd                 ... 最新に更新
 # cvs update -Pd -r netbsd-7-0-RC3  ... NetBSD7.0RC3
 # cd pkgsrc
 # cvs update -PAd                 ... 最新に更新
 # cvs update -Pd -r pkgsrc-2015Q2 ... 2015Q2に更新


バグレポート・追加差分
~~~~~~~~~~~~~~~~~~~~~~~~
 http://www.NetBSD.org → Support →Report a bug / Query bug database.

NetBSDとブース展示
-------------------------
 日本NetBSDユーザーグループは、日本各地のオープンソースイベントに参加し、ブース出展とセミナー枠を利用して、NetBSD関連の情報をまとめています。オープンソースカンファレンスへの積極的な参加が認められ、2014年2月に「第1回OSCアワード」を受賞しています。

ブース出展
~~~~~~~~~~~

オープンソース関連のイベントでは、たいてい幅1.8m程度の長机と椅子二つ程度のブースを出展します。各地域でのイベント開催に合わせて、最新の活動成果を展示しようとします。

セミナー枠
~~~~~~~~~~~~~

セミナー枠では、NetBSDに関する情報を紙にまとめて配布して、出版物でカバーできないような情報をイベント毎にまとめています。開催地にある電子部品店・コンピュータショップ・古書店・クラフトビールバー等、生活に必要な情報もまとめています。

シール関連まとめ
~~~~~~~~~~~~~~~~~~~~

NetBSDブースでは、NetBSDのシールや、NetBSDがサポートしている・サポートしようとしている・みんなが好きで利用しているソフトウェアに関連したシールを持ち寄って配っています。
OSの展示は単調になりがちで、OS開発やNetBSDについて通りすがりの数秒で理解してもらうのは不可能でしたが、シールなら数秒で何かわかってもらえます。
かさばらないので、誰にも受け取ってもらいやすく、優れたデザインのシールに人気が出ると、ブース全体に活気が生まれて、思いもよらない進展を呼ぶことがあります。

.. csv-table::
 :widths: 70 70

 みくったーシールずかん,http://togetter.com/li/566230
 らこらこシール作成の記録,http://togetter.com/li/554138
