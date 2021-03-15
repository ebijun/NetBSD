.. 
 Copyright (c) 2013-2020 Jun Ebihara All rights reserved.
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

.. TODO:: 漢字変換の設定
.. TODO:: 無線LANの設定
.. TODO:: デスクトップ環境の構築(Gnome/Xfce/icewm)
.. TODO:: OpenOfficeの構築
.. todo:: inkscape/scribusの設定
.. todo:: プリンタ
.. todo:: samba
.. todo:: rabbitのようなものでプレゼンできるか
.. todo:: bccksで豆本にできるか
.. todo:: latexに変換してみる
.. todo:: latex環境設定
.. todo:: イベント関連の設定・ファイルを分ける？
.. todo:: facebookページとの連携：主なニュース取得とか
.. todo:: VirtualBoxで徐々にメモリを減らしたときどうなるか
.. todo:: othersrc/share/examples/ec2: build_ec2_img.sh
.. todo:: ansible とpuppet
.. todo:: html→pdf→epub→bccksできるか
.. todo:: FuelPHPの例

=======================================
pkgsrcでソフトウェアをインストールする
=======================================

 pkgsrcを利用すると、さまざまなソフトウェアをコンパイル、インストールすることができます。

#. まずOSをインストールします
#. pkgsrc.tar.gzを展開します
#. 必要なパッケージをコンパイル、インストールします

::

 tcsh,icewm,kterm,anthy-elisp,ja-less
 libreoffice4,firefox,gimp ...

pkgsrcをダウンロード
-----------------------
 pkgsrcのWebサイトはhttp://www.pkgsrc.org/です。pkgsrcは、一年に4回定期的にリリースされます。

::

 % ftp ftp://ftp.pkgsrc.org/pub/pkgsrc/
   pkgsrc-2012Q4
   pkgsrc-2013Q1
   pkgsrc-2013Q2
     :
 % ftp ftp://ftp.pkgsrc.org/pub/pkgsrc/stable/pkgsrc.tar.gz
 日本のミラーの場合：
 % ftp ftp://ftp7.jp.NetBSD.org/pub/pkgsrc/stable/pkgsrc.tar.gz　

/usr/pkgsrcにダウンロードしたtar ファイルを展開してみましょう。

::

 % su
 # tar xzvf pkgsrc.tar.gz -C /usr   ... /usr以下に展開します。
 # ls /usr/pkgsrc
 CVS          comms        finance      math         pkglocate    wip
 Makefile     converters   fonts        mbone        pkgtools     wip-jp
 README       cross        games        meta-pkgs    print        wm
 archivers    databases    geography    misc         regress      www
 audio        devel        graphics     mk           security     x11
 benchmarks   distfiles    ham          multimedia   shells
 biology      doc          inputmethod  net          sysutils
 bootstrap    editors      lang         news         templates
 cad          emulators    licenses     packages     textproc
 chat         filesystems  mail         parallel     time

ソフトウェアをコンパイルしてインストールする枠組みが、/usr/pkgsrc/ジャンル/ソフトウェア名 以下にあります。
LibreOfficeをコンパイルして、インストールしたいときには、次のようにコマンドを実行します。

::

 # cd /usr/pkgsrc/misc/libreoffice4
 # make package-install

うまくコンパイルしてインストールできると、LibreOfficeを実行出来ます。

::

 % soffice

pkgsrcを使ってみる
------------------

「RaspberryPIでmikutterというtwitterクライアントを使いたい」場合を考えてみます。
インストールできそうなソフトウェアは、/usr/pkgsrc/ジャンル名/ 以下にディレクトリがあります。
ここに使いたいソフトウェアがあれば、コンパイルしてインストールできるかもしれません。

::

 % ls /usr/pkgsrc/* |grep mikutter
 mikutter                        .... pkgsrcにmikutterがある!
 % cd /usr/pkgsrc/*/mikutter     .... ジャンルはわからないけど移動
 % pwd
 /usr/pkgsrc/net/mikutter        .... "net" の下にあった
 % ls
 CVS       DESCR     Makefile  PLIST     distinfo  files
 % cat DESCR                     .... ソフトウェアの説明
 Mikutter is a Twitter client aim for endsville Twitter client For all of
 Miku-aholics and Twitter-holics.
 % cat Makefile
 # $NetBSD: Makefile,v 1.68 2013/06/23 01:09:43 tsutsui Exp $
 #
  
 DISTNAME=       mikutter.0.2.2.1264    ... mikutterのバージョンとか
 PKGNAME=        ${RUBY_PKGPREFIX}-${DISTNAME:S/./-/}
 CATEGORIES=     net 
 MASTER_SITES=   http://mikutter.hachune.net/bin/  ... 配布サイト
 
 MAINTAINER=     obache@NetBSD.org　　　　　　　　　　 ... このパッケージを管理している人
 HOMEPAGE=       http://mikutter.hachune.net/      ... ソフトウェアのホームページ
 COMMENT=        Simple, powerful, and moeful twitter client  .. 一行説明
 LICENSE=        gnu-gpl-v3 AND cc-by-sa-v3.0      ... ソフトウェアのライセンス
 
 RUBY_VERSION_SUPPORTED= 193
 
 .include "../../lang/ruby/rubyversion.mk"
 
 DEPENDS+=       xdg-utils-[0-9]*:../../misc/xdg-utils　　... 依存しているソフトウェア
 DEPENDS+=       ${RUBY_PKGPREFIX}-hmac>=0.4.0:../../security/ruby-hmac
                 :
 % cat PLIST　　　　　　　　　　　　　　　　　　 ... インストールするファイルの一覧です
 @comment $NetBSD: PLIST,v 1.23 2013/05/15 11:24:14 obache Exp $
 bin/mikutter                          　　... /usr/pkg/bin/mikutterにインストールされます                 
 share/applications/mikutter.desktop      
 share/doc/mikutter/README
 share/mikutter/core/boot/check_config_permission.rb
 share/mikutter/core/boot/load_plugin.rb
 share/mikutter/core/boot/mainloop.rb
 share/mikutter/core/boot/option.rb
 
 % distinfo  .... ダウンロードするファイルの一覧とチェックサム
 $NetBSD: distinfo,v 1.60 2013/06/16 08:58:06 obache Exp $
 
 SHA1 (mikutter.0.2.2.1264.tar.gz) = f93757ca51f3fe9f555df32c86c2ed7021992887
 RMD160 (mikutter.0.2.2.1264.tar.gz) = bd3f4a49eb8d96a225b4cc704115995fe390e42a
 Size (mikutter.0.2.2.1264.tar.gz) = 2318031 bytes

mikutterと、mikutterをインストールするために必要なソフトウェアをインストールoします。

::

 % su
 # cd /usr/pkgsrc/net/mikutter
 # make package-install

RaspberryPIで使いそうなソフトを一気にインストールする
""""""""""""""""""""""""""""""""""""""""""""""""""""""""

/usr/pkgsrc/ジャンル名を眺めて、使いそうなソフトウェアをリストアップします。

::

 % cat List 
 kterm
 tcsh
 vlgothic-ttf
 icewm
 xli
 mikutter
 uim
 fossil
 sudo
 scmgit-base
 zsh
 dillo

簡単なシェルスクリプトを作って、実行します。コンパイルがうまく進めば、必要なソフトウェアがすべてソースコードからコンパイル・インストールされた状態になります。

::

 % cat Package
 for i in `cat List`
 do
   cd /usr/pkgsrc/*/$i
   make package-install
 done
 % su
 # sh Package
 # pkg_info      .... インストールされたパッケージの一覧を表示します。


デスクトップ環境を作ってみる
-----------------------------


デスクトップ環境の設定:Mateの場合
"""""""""""""""""""""""""""""""""

::

 # cd /usr/pkgsrc/meta-pkgs/mate
 # make package-install
 # pkg_info |wc        .... 関連パッケージがインストールされます
 % rehash              .... ログインシェルがcshの場合に必要です
 % echo mate-session >> .xinitrc  .... mate-sessionを.xinitrcに追加します
 % startx              .... mate環境が起動します
 % setenv LANG ja_JP.UTF-8   .... ログインシェルがcshの場合
 % export LANG=ja_JP.UTF-8   .... ログインシェルがshの場合
 % startx              .... 日本語版の環境が立ち上がります


デスクトップ環境の設定:Xfceの場合
"""""""""""""""""""""""""""""""""

::

 # cd /usr/pkgsrc/meta-pkgs/xfce4
 # make package-install
 # pkg_info |wc        .... 110個程度の関連パッケージがインストールされます
 % rehash              .... ログインシェルがcshの場合に必要です
 % startxfce4          .... 英語版の環境が立ち上がります
 % setenv LANG ja_JP.UTF-8   .... ログインシェルがcshの場合
 % export LANG=ja_JP.UTF-8   .... ログインシェルがshの場合
 % startxfce4          .... 日本語版の環境が立ち上がります

デスクトップ環境の設定:gnomeの場合
""""""""""""""""""""""""""""""""""

::

 # cd /usr/pkgsrc/meta-pkgs/desctop-gnome
 # make package-install
 # gnome-session

デスクトップ環境の設定: deforaos-desktopの場合
""""""""""""""""""""""""""""""""""""""""""""""

::

 RPIなどでは、/etc/mk.confに以下の行を追加します。
 PKG_OPTIONS.deforaos-terminal=embedded
 　
 # cd /usr/pkgsrc/meta-pkgs/deforaos-desktop
 # make package-install


ウィンドウマネージャの設定:icewmの場合
""""""""""""""""""""""""""""""""""""""

::

 # cd /usr/pkgsrc/wm/icewm
 # make package-install
 # which icewm 
 /usr/pkg/bin/icewm
 % cd 
 % ls .xinitrc     ..... .xinitrcがあるかどうか確認します。
 もし.xinitrcがない場合、以下の手順でコピーします。
 cp /etc/X11/xinit/xinitrc -/.xinitrc  ... XXX:上書きしないよう気をつけて！
 % vi .xinitrc     ..... 最後の5行を書き換えます。
 twm &
 xclock -geometry 50x50-1+1 &
 /usr/X11R7/bin/xterm -geometry 80x50+494+51 &
 /usr/X11R7/bin/xterm -geometry 80x20+494-0 &
 exec /usr/X11R7/bin/xterm -geometry 80x66+0+0 -name login
             ↓
 xclock -geometry 50x50-1+1 &
 /usr/X11R7/bin/xterm -geometry 80x50+494+51 &
 /usr/X11R7/bin/xterm -geometry 80x20+494-0 &
 /usr/X11R7/bin/xterm -geometry 80x66+0+0 &
 icewm
 % startx    ..... icewmが起動します。
 % cp -r /usr/pkg/share/icewm -/.icewm  .... メニューをカスタマイズ
 % vi -/.icewm/menu
 prog Kterm Kterm kterm -fk k14 -fn a14 -fr r14 -km euc
 prog SeaMonkey seamonkey seamonkey
 prog Mikutter mikutter miutter
 separator
 prog Shotwell shotwell shotwell
 prog GtkPod gtkpod gtkpod 
 prog Fossil fossil fossil server /usr/local/fossil/my-repo 
 separator
 prog OpenOffice soffice soffice
 prog Acroread acroread9 acroread9
 separator
 menuprog Gnome folder icewm-menu-gnome1 --list 
 menuprog Gnome folder icewm-menu-gnome2 --list 
 menuprog KDE folder icewm-menu-gnome --list 
 menufile Emulators folder programs          ... 階層構造
 menufile Games folder games
 % vi -/.icewm/programs          ... .icewmで指定した階層構造
 # This is an example for IceWM's toolbar definition file.
 #
 # Place your variants in /usr/pkg/etc/icewm or in $HOME/.icewm
 # since modifications to this file will be discarded when you
 # (re)install icewm.
 #
 prog Xnp2 xnp2 xnp2
 prog XM6i xm6i xm6i
 prog Minux Minux Minux
 % vi -/.icewm/preferences
         :
 #  Desktop background image
 # DesktopBackgroundImage=""    .... 壁紙のイメージをここで設定できます。

ウィンドウマネージャの設定:jwmの場合
"""""""""""""""""""""""""""""""""""""

::

 # cd /usr/pkgsrc/wm/jwm
 # make package-install

漢字変換&emacs
--------------

mozcを利用する場合
""""""""""""""""""

::

 % cd /usr/pkgsrc/inputmethod/ibus-mozc
 # make package-install

漢字変換に必要な環境変数を.xinitrc等で設定します。

::

 export LANG=ja_JP.eucJP
 export GTK_IM_MODULE="ibus"
 export XMODIFIERS="@im=ibus"
 export QT_IM_MODULE="ibus"
 ibus-daemon --xim &

emacsを利用する場合は、mozc-elispパッケージをインストールします。

::

 % cd /usr/pkgsrc/inputmethod/mozc-elisp
 # make package-install

anthyを利用する場合
"""""""""""""""""""

::

 # cd /usr/pkgsrc/inputmethod/anthy
 # make package-install
 # cd /usr/pkgsrc/inputmethod/uim
 # make package-install

.xinitrcに以下の行を追加します。

::

 export GTK_IM_MODULE=uim
 export LANG=ja_JP.eucJP
 export XMODIFIERS=@im=uim
 export QT_IM_MODULE="uim"
 uim-xim &

emacsを利用する場合は、anthy-elispパッケージをインストールします。

::

 % cd /usr/pkgsrc/inputmethod/anthy-elisp
 # make package-install

.emacs に、以下の記述を追加します。

::

 (set-language-environment "Japanese")
 (set-default-coding-systems 'utf-8)
 (set-language-environment "Japanese")
 (load-library "anthy")
 (setq default-input-method "japanese-anthy")
 ;
 (define-obsolete-variable-alias 'last-command-char 'last-command-event "at least 19.34") 


壁紙
----

::

 # cd /usr/pkgsrc/graphics/xli
 # make package-install

.xinitrcに以下の行を追加して、壁紙画像を表示するプログラムを起動します。

::

 例）
 xsetbg -/Desktop/penguindrum_wp1_1s.jpg

ソフトウェアのコンパイル／インストール
-------------------------------------------

gedit
""""""

::

 % cd /usr/pkgsrc/editors/gedit
 # make package-install

firefox
"""""""""

::

 % cd /usr/pkgsrc/www/firefox
 # make package-install
 % cd /usr/pkgsrc/www/firefox-l10n
 # make package-install
 # grep flashsupport /etc/mk.conf
 ACCEPTABLE_LICENSES+= adobe-flashsupport-license
 # cd /usr/pkgsrc/multimedia/adobe-flash-plugin11
 # make package-install

LibreOffice
""""""""""""
::

 # grep libreoffice4 /etc/mk.conf
 # cd /usr/pkgsrc/misc/libreoffice4
 # make package-install
 % /usr/pkg/bin/soffice 


LaTeX
"""""""

::

 # cd /usr/pkgsrc/print/ja-ptex
 # make package-install

CMSを使ってみる
---------------

drupal
""""""""
::

 # cd /usr/pkgsrc/www/drupal7
 # make package-install

wordpress
"""""""""""
::

 # cd /usr/pkgsrc/www/php-ja-wordpress
 # make package-install
 # cd /usr/pkgsrc/archivers/php-zlib
 # make package-install .... zip形式のテーマをインストールする時に必要
 AddHandler application/x-httpd-php .php


fossilを使ってみる
------------------

::

 # cd /usr/pkgsrc/devel/fossil
 # make package-install
 % ls /usr/pkg/bin/fossil
 % fossil help
 Usage: fossil help COMMAND
 Common COMMANDs:  (use "fossil help --all" for a complete list)
 add         changes     finfo       merge       revert      tag       
 addremove   clean       gdiff       mv          rm          timeline  
 all         clone       help        open        settings    ui        
 annotate    commit      import      pull        sqlite3     undo      
 bisect      diff        info        push        stash       update    
 branch      export      init        rebuild     status      version   
 cat         extras      ls          remote-url  sync      
 This is fossil version 1.25 [d2e07756d9] 2013-02-16 00:04:35 UTC
 % fossil init my-repo
 fossil init my-repo
 project-id: fdd587ee44f524d432186fe6a1dc379c51b26c1d
 server-id:  7873c960d27f3b0ef2d7da2294bfc6eb092dc61e
 admin-user: jun (initial password is "bb4867")
 % fossil server my-repo &
  .... ブラウザでポート8080にアクセスするとGUI画面が表示されます。

Gitのインストール
-----------------

::

 # cd /usr/pkgsrc/devel/git-base
 # make package-install
 % ls -l /usr/pkg/bin/git


エミュレータでNetBSD
--------------------

Qemu
"""""

::

 # cd /usr/pkgsrc/emulators/qemu
 # make package-install
 # qemu-img create -f qed NetBSD-sparc.qed 500M ... qedが動くかチェック
 # qemu-system-sparc -M SS-20 -m 64  -kernel netbsd-GENERIC -hda my-sun4c-disk.img  -hdb miniroot.fs -nographic -cdrom NetBSD-6.99.17-sparc.iso
 # qemu-system-sparc -M SS-20 -m 64  -kernel netbsd-sd -hda my-sun4c-disk.img  -nographic -net nic -net user -redir tcp:2222::22

Gxemul
""""""""

::

 # /usr/pkgsrc/emulators/gxemul
 # make package-install
 # gxemul -e mobilepro770 -M 128 -I 800000000 -d Z50.img -d c:/usr/release/images/NetBSD-6.99.14-hpcmips.iso netbsd-install

::

 # gxemul -e jornada680 -M 128 -I 800000000 -d c:/usr/release/iso/NetBSD-5.1.2-hpcmips.iso /mnt/netbsd

Package - /usr/pkgsrc 
------------------------
* 簡単にソフトウェアをコンパイル・インストール
* 1997年8月開始
* 201?-Q[1-4] もうすぐ準備
* 41種類のジャンル
* 9963種類以上のソフトウェア
* Make installでソフトウェアのインストール

各CPUアーキテクチャ間で共通
------------------------------
* mipsel –mips endian little
* arc – MIPSで動くNTマシン
* cobalt – Cobalt Qube1/2
* pmax – DEC station
* hpcmips – MIPS搭載WinCE

/usr/pkgsrc/emulators
------------------------
* gxemul
* mips (pmax,hpcmips)
* dreamcast
* simh
* NetBSD/vax
* tme
* sun2,sun3,SPARCstation 2
* QEMU
* PC
* USBデバッグ

Packagesジャンル一覧
---------------------

.. csv-table:: The NetBSD Packages Collection

   x11, Packages to support the X window system
   archivers, Archivers
   audio, Audio tools
   benchmarks, Benchmarking tools
   biology, Software for the biological sciences
   cad, CAD tools
   chat, Communication programs
   comms, Communication utilities
   converters, Document format and character code converters
   cross, Cross-platform development utilities
   databases, Databases
   devel, Development utilities
   editors, Editors
   emulators, Emulators for other operating systems
   filesystems, File systems and file system related packages
   finance, Monetary financial and related applications
   fonts, Fonts
   games, Games
   geography, Software for geographical-related uses
   graphics, Graphics tools and libraries
   ham, Wireless communication tools and applications
   inputmethod, Input method tools and libraries
   lang, Programming languages
   mail, Electronic mail utilities
   math, Mathematics
   mbone, Multi-cast backBone applications
   meta-pkgs, Collections of other packages
   misc, Miscellaneous utilities
   multimedia, Multimedia utilities
   net, Networking tools
   news, Network news
   parallel, Applications dealing with parallelism in computing
   pkgtools, Tools for use in the packages collection
   print, Desktop publishing
   security, Security tools
   shells, Shells
   sysutils, System utilities
   textproc, Text processing utilities (does not include desktop publishing)
   time,Clocks calendars daily planners and other time related applications
   wm, X11 window managers configuration tools and themes
   www, Packages related to the World Wide Web

目的別
------
* デスクトップ向け
* 組み込み向け
* pkgsrc/meta-pkgにいくつかある

Package対応プラットフォーム
---------------------------

#. NetBSD
#. Solaris / SmartOS / illumos
#. Linux
#. Darwin (Mac OS X)
#. FreeBSD
#. OpenBSD
#. IRIX
#. AIX
#. DragonFlyBSD
#. OSF/1
#. HP-UX
#. QNX
#. Haiku
#. MirBSD
#. Minix3
#. Cygwin
#. GNU/kFreeBSD
#. SCO OpenServer 5

NetBSD以外でpkgsrc
------------------

::

 # tar xzvf pkgsrc.tgz
 # cd pkgsrc/bootstrap
 # ./bootstrap

Packageとライセンスの取扱い
---------------------------

* 個々のパッケージごとにLICENSE定義
* 受け入れられるライセンスを制御したい
* ツールとライブラリのライセンスが違う
* ツールがGPL,ライブラリがLGPL
* GPLv2とv3が混在する例
  rubyとreadline6
* GPL2とGPL2 or laterの区別
* GPL3とリンクできるかできないか
  http://d.hatena.ne.jp/obache/20090922/

バイナリ互換性を利用する
---------------------------

* Cobalt Qube2でhpcmipsバイナリ作成
* MIPSでendian little =mipsel同士なら動く
* ユーザランドはほとんどそのまま動く
* パッケージも共通化
* NetBSD/{pmax,cobalt,arc,hpcmips}で共通
* 数GBある各種アプリケーション群を共通にする

pkgsrcを更新する
----------------
まず/usr/pkgsrcを更新し、次に、必要なソフトウェアを再コンパイルします。cvsで、/usr/pkgsrcを更新します。

::

 # cd /usr/pkgsrc
 # cvs update -PAd               ... 最新版に上げる
 # cvs update -Pdr pkgsrc-2013Q2 ... 2013Q2に上げる

更新が必要なソフトウェアを更新します。pkg_chkコマンド、またはpkg_rolling-replaceコマンドで更新します。

::

 # pkg_chk -u
 # /usr/pkg/sbin/pkg_chk -u -b -n -P /usr/local/src/NetBSD/pkgsrc-2013Q2/packages/All
 # /usr/pkg/sbin/pkg_chk -u -b -P /usr/local/src/NetBSD/pkgsrc-2013Q2/packages/All
 
 # cd /usr/pkgsrc/pkgtools/pkg_rolling-replace 
 # make package-install
 # /usr/pkg/bin/pkg_rolling-replace

pkgsrcの開発
----------------

http://mail-index.netbsd.org/tech-pkg/2020/05/29/msg023265.html

1. pkglintをインストールする

::

   # cd /usr/pkgsrc/pkgtools/pkglint
   # make install
   # pkglint -W all -C all ...

2. url2pkgをインストールする

::

   # cd /usr/pkgsrc/pkgtools/url2pkg
   # make install
   # url2pkg ダウンロードするURL

3. pkgdiffをインストールする

::

   # cd /usr/pkgsrc/pkgtools/pkgdiff
   # pkgvi path to pkg
   # make install
   # make mps

4. 依存するパッケージを表示する

::

   make show-buildlink3
   
このドキュメント
----------------------

以下のURLからこのドキュメントのソースコードをダウンロードできます。
ドキュメントはpy-sphinxを利用しています。

::

 https://github.com/ebijun/NetBSD/tree/master/Guide


* フォーマット: /usr/pkgsrc/textproc/py-sphinx
* 編集: /usr/pkgsrc/editors/gedit
* PDFチェック: /usr/pkgsrc/pring/evince
* bccksで豆本にしたい


