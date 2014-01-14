ThinkpadX41 を使ってみる
--------------------------
NBUG例会にいく前に寄ったハードオフでThinkpad X41が3150円で売っていたので買ってみました。WZero3（スマホ)と同じ値段！






目標
"""""
艦これを遊ぶためずっと起動しっ放しマシン。

..  image:: ../Picture/2013/12/21/DSC_3000.jpg

主なスペック
"""""""""""""""""
ここではじめてスペックを調べます。

.. csv-table::
 :widths: 20 60

 形式,IBM 252557J (ThinkPad X41)
 CPU, Intel(R) Pentium(R) M processor 1.50GHz id 0x6d8
 メモリ, 758 MB
 ハードディスク, 38154 MB HTC426040G9AT00 1.8インチ日立

USBスティックへインストールイメージ作成
"""""""""""""""""""""""""""""""""""""
NBUG例会(2013/12)会場でおもむろにインストールしてみる。

NetBSDインストールイメージ
"""""""""""""""""""""""""""
NetBSD/i386,amd64には、インストール用イメージファイルがあります。
数週間に一度、i386用イメージファイルを作って、USBメモリにコピーしておくと
ちょっと試せるときにNetBSD-currentがどのくらいブートするか試すことができます。

::

 # cd /usr
 # tar xzvf src.tar.gz
 # tar xzvf xsrc.tar.gz
 # cd /usr/src
 # export BSDOBJDIR=/usr/obj/i386
 # export DESTDIR=/usr/builds/i386
 # export RELEASEDIR=/usr/release
 # export TOOLDIR=/usr/tools/i386
 # export MKX11=yes
 # ./build.sh -U -u -j 3  -m i386 release
 # ./build.sh -U -u -m i386 iso-image
 # ./build.sh -U -u -m i386 live-image
 # ./build.sh -U -u -m i386 install-image
 # ls /usr/release/images/*i386*
 /usr/release/images/NetBSD-6.99.28-i386-install.img.gz
 /usr/release/images/NetBSD-6.99.28-i386-live-sd0root.img.gz
 /usr/release/images/NetBSD-6.99.28-i386-live-wd0root.img.gz
 /usr/release/images/NetBSD-6.99.28-i386.iso
 # gunzip < /usr/release/images/NetBSD-6.99.28-i386-install.img.gz |
  dd of=/dev/rsd3d bs=4m progress=10    ... USBメモリがsd3に見えている

インストールイメージからの起動
"""""""""""""""""""""""""""""
i386用のUSBインストールイメージを作ったものを持っていたので、X41に差して電源を入れます。
USBから起動するために、青いAccessボタンを押してから、F12ボタンを押して、起動ディスクにUSBメモリを選んで、起動します。

NetBSDのインストール
""""""""""""""""""""""
普通にNetBSDをインストールします。たいていリターンキーを押しているとインストールが終わります。

#. タイムゾーンを日本にします
#. ユーザーを作っておきます。rootになれるgroupに追加しておきます。
#. pkgsrcのソースだけインストールしておきます。
#. sshdを起動します。
#. ntpdを起動します。
#. pkgsrc-currentのツリーを展開しておきます。
#. 有線ネットワークをアクセスポイントにつないでdhcp経由でネットワークの設定をしておきます。

..  image:: ../Picture/2013/12/21/DSC_2997.jpg

NetBSDを起動する
"""""""""""""""""
USBメモリを抜いて、NetBSDを起動します。

#. ログインしてログインできるか確認します。
#. dmesgコマンドを実行して、どのデバイスが見えているか／見えていないか確認します。
#. ifconfig -aコマンドを実行して、どのネットワークデバイスが見えているか確認します。有線LANが設定してあればそのまま有線LANが設定されているはずです。

Xの設定
""""""""""""
ルート権限でXの設定ファイルを作ってコピーします。

::

 # X -configure
 # cp /root/xorg.conf.new /etc/X11/xorg.conf
 # startx   ... うまくいけばtwmが表示されます。

..  image:: ../Picture/2013/12/21/DSC_2999.jpg

パッケージのコピー
"""""""""""""""""""""""
普段持ち歩いているNetBSDマシンからパッケージをコピーします。

::

 # scp -r 元マシン:/usr/pkgsrc/packages/All /usr/pkgsrc/packages/

パッケージのインストール
""""""""""""""""""""""""
以下のパッケージをインストールします。

::

　audio/xmix
　devel/fossil
　editors/emacs24
　editors/gedit
　fonts/kochi-ttf
　fonts/vlgothic-ttf
　graphics/gimp
　graphics/shotwell
　graphics/xli
　inputmethod/anthy-elisp
　inputmethod/uim
　multimedia/adobe-flash-plugin11
　net/mikutter
　pkgtools/pkg_rolling-replace
　pkgtools/pkg_tarup
　print/acroread9
　print/evince
　shells/bash
　shells/tcsh
　textproc/py-sphinx
　wm/icewm
　www/seamonkey
　www/seamonkey-l10n
　x11/kterm
　x11/mlterm
　x11/xlockmore-lite


フラッシュプレーヤーの動作確認
"""""""""""""""""""""""""""""""

各種設定
""""""""""""

キーボード設定
""""""""""""""
Aの左はCtrlの日本語配列（Sun Type5+JLEの影響)

X41固有の設定(無線LANカード)
"""""""""""""""""""""""""""""
sysctl でiwiを有効にする。man iwi

X41固有の設定(音)
""""""""""""""""""""""
音設定もしあれば。

追加(メモリ)
""""""""""""""""""
艦これ、ずっと動かしていると760M+120Mくらいメモリ食う。
netbookの余ったメモリを差したらメモリが倍に！

追加(ハードディスク)
"""""""""""""""""""""""""
1,8インチディスクはいろいろめんどくさい。

#. 1.8インチハードディスクに交換。40G→60G。8000円くらい。なんだかのー。
#. X41用SSDに交換。32G 4750円 64G 8000円くらい。やってもいいかな。
#. mSATAに交換。下駄1280円＋128G 10000円くらい。やってみたい。
#. 標準以外のディスクにするとBIOSが文句を言う。(ver2.)

ボリューム調整
""""""""""""""""
xmixとか。

amd64
""""""""""""
たまたまi386で動かしたけどamd64でもたぶん動く。

電源サスペンド
"""""""""""""""""
apmd？
powerd？
両方？

電池
""""""""
icewmで電源表示をつける。1:10くらい持つらしい。

#. 交換：　ロアで6000円くらい。

無線LAN設定
""""""""""""""""
WEP
WEPじゃないの

やること
"""""""""
 github設定、BIOSを1.0にダウングレードするか、それが嫌なら警告が表

http://silentvoice.moe-nifty.com/blog/2013/06/thinkpad-x41win.html
