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

PkgsrcでCMSを使ってみる
---------------------------

net commons
"""""""""""""""

::

 http://www.netcommons.org/
 NetCommons-2.4.1.0.tar.gz をダウンロード
 「推奨の組み合わせ: Linux, PHP 5.1.6, MySQL 5.0.22, Apache 2.2.3」
 
 # cd /usr/pkgsrc/lang/php53  ... netcommonsはphp54以降未サポート(2013/8/1)
 # cd /usr/pkgsrc/databases/php-mysql  ... php53+mysqlインストール
 # vi /usr/pkg/etc/php.ini
 extension=mysql.so
 
 # cd /usr/pkgsrc/www/ap-php   ... php53+apacheインストール
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
 
 # cp -r NetCommons-2.4.1.0/html/html /usr/pkg/share/httpd/htdocs/
 # cd /usr/pkg/share/httpd/htdocs
 # chown -R www.www html
 # mv html/* .

 2013/8/1現在php5.4未対応
 [Unknown_Condition_2048 ]:Non-static method LogFactory::getLog() should not be called statically,assuming $this from incompatible context in file /usr/pkg/share/httpd/htdocs/netcommons/maple/core/Controller.class.php line 122
 /usr/pkgsrc/lang/php53
 make package-install

SSL設定
""""""""""

::

 /usr/pkg/etc/httpd/httpd-ssl.conf
 SSLCertificateFile
 SSLCertificateKeyFile
 SSLCertificateChainFile
 
 /usr/pkg/etc/httpd/httpd.conf
 Include etc/httpd/httpd-ssl.conf  ... コメントはずす
 

