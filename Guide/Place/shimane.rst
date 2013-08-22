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

OSC2013島根の発表全部をNetBSDで動かしてみる
----------------------------------------------

 次に、OSとしてできることを考えます。この場所である発表をどこまでサポートできるか、サポートできないのはどこに問題があるのか考えてみます。

Ruby+4DDAM
"""""""""""""""

4DDAM
 商用。
Ruby
 Rubyのインストール

::

 # cd /usr/pkgsrc/lang/ruby
 # make install
 # which ruby
 /usr/pkg/bin/ruby

nanoc+github
""""""""""""""""

nanoc
~~~~~~~

::

 # cd /usr/pkgsrc/lang/ruby;make install
 # gem install nanoc 

github
"""""""""""

::

 # cd /usr/pkgsrc/devel/scmgit-base
 # make install
 # which git
 /usr/pkg/bin/git

redmine
""""""""""

::

 # /usr/pkgsrc/lang/ruby;make package-install
 # gem install bundler
 ソースコードダウンロード
 # ftp http://rubyforge.org/frs/download.php/77023/redmine-2.3.2.tar.gz
 # tar xzvf redmine-2.3.2.tar.gz
 # cd redmine-2.3.2
 # bundle install --without development test
 sqlite3:最近のNetBSDにはデフォルトで入ってます。
 # man sqlite3

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
 
AmazonEC2
""""""""""""""

::

 http://wiki.netbsd.org/amazon_ec2/
 http://wiki.netbsd.org/amazon_ec2/amis/
 ami-1b3fb11a

ADempiere
""""""""""""""

 これは何ができていればいいんでしょ？
::

 http://sourceforge.jp/projects/adempiere/
 # java+postgresql
 # openjdk
 # postgresql

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

OpenOffice.org/LibreOffice
""""""""""""""""""""""""""""""""

::

 # cd /usr/pkgsrc/misc/openoffice
 # make package-install
 # cd /usr/pkgsrc/misc/libreoffice
 # make package-install

問題
 openofficeが古い/
 libreofficeで漢字が入力できない 

sphinx
"""""""""

::

 # cd /usr/pkgsrc/textproc/py-sphinx
 # make package-install
 # which sphinx-quickstart
 /usr/pkg/bin/sphinx-quickstart
 # sphinx-quickstart
 # make html
 # ln -s _build/html /var/www/html
 # /etc/rc.d/httpd onestart

firefox
""""""""""

::

 # cd /usr/pkgsrc/www/firefox
 # make package-install
 # cd /usr/pkgsrc/www/firefox-l10n
 # make package-install
 # cd /usr/pkgsrc/multimedia/adobe-flash-plugin11
 # make package-install

gedit
""""""""

::

 # cd /usr/pkgsrc/editors/gedit
 # make package-install

icewm
"""""""""

::

 # cd /usr/pkgsrc/wm/icewm
 # make package-install

漢字入力
""""""""""

::

 # cd /usr/pkgsrc/inputmethod/mozc-server
 # make package-install
 # cd /usr/pkgsrc/inputmethod/ibus-mozc
 # make package-install
 
 % ls -l ~/.xinitrc
 .xinitrcが存在しない場合はコピーする  !! 上書きしないよう注意！ 
 % cp /etc/X11/xinit/xinitrc ~/.xinitrc
 % vi .xinitrc                     ... 以下の行を追加
 export LANG=ja_JP.UTF-8
 ibus-daemon --xim &
 export GTK_IM_MODULE="ibus"
 export XMODIFIERS="@im=ibus"
 export QT_IM_MODULE="ibus"

emacs
"""""""""

::

 # cd /usr/pkgsrc/editors/emacs
 # make package-install
 # cd /usr/pkgsrc/inputmethod/mozc-elisp/
 # make package-install
 # emacs ~/.emacs
 (set-language-environment "Japanese")
 (require 'mozc)
 (setq default-input-method "japanese-mozc")

gnome/xfce
""""""""""""

::

 # cd /usr/pkgsrc/meta-pkgs/gnome
 # make package-install
 # cd /usr/pkgsrc/meta-pkgs/xfce4
 # make package-install

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

松江
----

.. csv-table::

 ベニヤ模型,京町商店街の老舗模型店,http://www5e.biglobe.ne.jp/~beniya-m/
 EAD,松江大橋たもと、地下はDJ BAR MIX カフェバーEAD屋上にもバーがある。野菜カレーと豊の秋。とりあえずを頼むととりあえずが出てくる。,http://www.ead5.com/
 デンゲンパーツ,くにびきメッセ隣の電子部品・無線機屋 H8マイコンロボットやトリオのTR-5000がおいてある。,690-0826 松江市学園南1-5-7
 山崎電気,鍛冶橋から新大橋北詰に行く途中にある。電子部品/サトーパーツ/フジシャーシ/2SK30。旦那さんが作ったLUXのような手作りアンプは必見。,島根県松江市東本町4丁目157
 たぬき堂書店,伊勢宮のたぬき堂書店。, 島根県松江市伊勢宮町503
 八雲庵,サイン色紙と雑誌の紹介記事多数。,http://www.yakumoan.jp/
 ビアへるん, スタウト。Paddyスタウト瓶。ここに行ってスタウト。夕方18時までだから終わったらすぐ行く。　,http://www.rakuten.co.jp/beerhearun/ http://www.ichibata.co.jp/jibeer/
 國暉酒造,蔵しっく館　國暉,島根県松江市東茶町8 http://www.kokki.jp/
 島根県立美術館,佐伯祐三展,夕暮れを見る http://www1.pref.shimane.lg.jp/contents/sam/
 味蔵,会場裏割子そば定食しじみ汁アップグレード, 島根県松江市朝日町480-1
 塩見茶屋,ぼてぼて茶の具の種類,http://www.k2.dion.ne.jp/~yakumo/
 服部珈琲工房,冬珈琲 黒田店はオフハウス近く。,http://www.hattori-coffee.co.jp/
 国際宇宙・生物研究所,エドゥリスリオハ白,島根県松江市伊勢宮町501-11-2
 ホーランエンヤ,OSC2009のときサンライズから見た, http://ho-ran2009.city.matsue.shimane.jp/top.html
 あご野焼き,あご野焼きは、すだれのようなもので作る。包装の上からだんだんのつき方で何かが判別できる。,http://www.tokusen.info/suisan/agonoyaki/
 ジャズバーぽえむ,毎月末日曜の夜セッション, 島根県松江市白潟本町10 園山ビル2F.
 三英堂,若草を買う。,http://www.saneido.jp/

鳥取

.. csv-table::

 ガンバリウス,大山ゴールドとガンバセット
 鬼っ子ランド,鬼スライダーとは何か。
 植田正治美術館,生誕100周年記念展示 2013/9/29まで,
 白鳳の郷,　http://www.hakuhou.jp/oka_top.html
 むきばんだ史跡公園,http://www.pref.tottori.lg.jp/mukibanda/
 シュビドゥバー,鳥取駅近くのバー。ファミコン部屋あり。,http://www.anabamoguraya.com/shuvidubar.html
 鳥取環境大学,鳥取名産NEWSと観光ガイド。卒論の敵5インチMO。 NEWS。齊藤先生の研究室
 焼きそば樫 ,俺の愛を焼きそばに込めてFor you。, 鳥取県鳥取市河原町山手47-1
 風味堂,何屋か気になる喫茶店。,鳥取県鳥取市職人町29
 ハードオフ,スペンドールのスピーカを見る。

OSC松江展示物
--------------
#. sigmarion
#. persona
#. HP712/
#. zaurus/openbsd
#. Jornada680/690
#. Jornada710/720
#. chumby
#. cobalt
#. armadillo
#. mikutter

