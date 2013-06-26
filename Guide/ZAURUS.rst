===========================
ザウルスでNetBSDを使ってみる
===========================

用意するもの
-----------
#. ザウルス本体
#. 1G以上のSDカードまたはMicroSDカード＋SDカードアダプタ
#. 2G以上のSDカードを使う場合、SD+SDHCドライバインストール用に、1G以下のSDカードまたはコンパクトフラッシュ。
#. ディスクイメージコピー用NetBSDマシン
#. USBカードリーダ

SDカード用デバイスドライバのインストール
--------------------------------------
ザウルスSL-Cシリーズでは、2G以上のSDカードを利用できません。
「SL-A300、SL-Cシリーズ、SL-6000用のSD＋SDHCドライバ」(
[http://petit-noise.net/download/sdhc-driver])を利用すると2G以上のSDカードを利用できます。

ダウンロード
------------
SL-Cxx00用 
 http://petit-noise.net/system/files/zaurus-sd-driver-update_2.1-for-Cxx00_arm.ipk
SL-C750/760/860用 
 http://petit-noise.net/system/files/zaurus-sd-driver-update_2.1-for-Cxx0_arm.ipk
SL-C700用 
 http://petit-noise.net/system/files/zaurus-sd-driver-update_2.0-for-C700_arm.ipk

インストール
------------
  ダウンロードしたzaurus-sd-driver-update_2.1-for-C..._arm.ipkを、CFカードまたは、1GB以下のSDカードにコピーします。コピーしたカードをザウルスのカードスロットに差します。

デバイスドライバのインストール
----------------------------
  ザウルスを起動し、ファイル→CFカード→zaurus-sd-driver-update_2.1-for-C..._arm.ipkをクリック→インストール先 本体メモリーを選ぶ→再起動 OKを選択→メニューバー右上のXをクリックすると再起動が始まります。

NetBSDディスクイメージのダウンロード
-----------------------------------
  http://ftp.netbsd.org/pub/NetBSD/misc/tsutsui/zaurus/
  ftp ftp://ftp.netbsd.org/pub/NetBSD/misc/tsutsui/zaurus/netbsd-zaurus-20120204-1GB-SD.img.gz

ディスクイメージをコンパクトフラッシュにコピーする
-----------------------------------------------
NetBSDをインストールするSDカードをUSBカードアダプタ経由でNetBSDマシンにつなぎます。

::

 # dmesg    .... sd3に2GBのMicroSDカードがつながっています。
 sd3 at scsibus0 target 0 lun 3: <USB2.0, CardReader SD, 0100> disk removable
 sd3: fabricating a geometry
 sd3: 1936 MB, 1936 cyl, 64 head, 32 sec, 512 bytes/sect x 3964928 sectors
 sd3: fabricating a geometry
 # disklabel sd3　　... sd3のパーティションを確認します。
        :
 4 partitions:
 #        size    offset     fstype 　fsize bsize cpg/sgs
 a:   2030112         0      MSDOS                     # (Cyl.      0 -    991*)
 d:   2030112         0     unused      0     0        # (Cyl.      0 -    991*)
 　　　　... NetBSDではdパーティションがディスク全体になります。
 # gunzip < netbsd-zaurus-20120204-1GB-SD.img.gz|dd of=/dev/rsd3d bs=1m
 0+14144 records in
 0+14144 records out
 926941184 bytes transferred in 158.240 secs (5857818 bytes/sec)
 　　USBカードリーダーを差し直します。
 # disklabel sd3
 8 partitions:
 #        size    offset     fstype  fsize bsize cpg/sgs
 a:   1742848     67584     4.2BSD   2048 16384   128  # (Cyl.     33 -    883)
 b:    131072   1810432       swap                     # (Cyl.    884 -    947)
 c:   1742848     67584     unused      0     0        # (Cyl.     33 -    883)
 d:   1941504         0     unused      0     0        # (Cyl.      0 -    947)
 e:     65536      2048      MSDOS                     # (Cyl.      1 -     32)

ターミナルソフトのインストール
#. ターミナルソフトのダウンロード
----------------------  
  ftp http://kimux.org/liza/arc/qpe-embeddedkonsole-ja_1.6.0-wide3_arm.ipk
----------------------
#. ターミナルソフトのコピー
----------------------
<pre>
# mount_msdos /dev/sd3e /mnt
# cp qpe-embeddedkonsole-ja_1.6.0-wide3_arm.ipk /mnt
# umount /mnt
</pre>
----------------------
#. ターミナルソフトのインストール
----------------------
  ターミナルソフトをインストールするために、ファイル→SDカード→qpe-embeddedkonsole-ja_1.6.0-wide3_arm.ipkをクリックして、インストーラ経由でターミナルソフトをインストールします。
----------------------
#. ターミナルソフトの起動
----------------------
アプリケーションメニュー内に端末ウィンドウアイコンがあることを確認します。端末ウィンドウアイコンを長押しして離すと、プロパティメニューを表示します。チェックボックス 「アプリケーションをVGA(480x640ドット)の画面に最適化して実行する」のチェックを外して、「OK」ボタンを押してアイコン画面に戻ります。
----------------------
端末ウィンドウアイコンをクリックして、ターミナルを起動します。フォントの大きさは、Fn+Qで現れるメニューで変更できます。

NetBSDの起動

<h4>SL-C700以外</h4>
<pre>
bash-2.05$ cd /mnt/card
bash-2.05$ su
# insmod -f zbsdmod.o
# ./zboot
  :
NetBSD/zaurus (Amnesiac) (console)
 
login:
</pre>
<h4>SL-C700の場合</h4>
----------------------
#. メンテナンスカーネルからLinuxを起動
----------------------
BとDを押しながら、電池ぶたロックをロック、解除、ロックと動かして電源ボタンを押すと、メンテナンスカーネルが起動します。メンテナンスカーネルでは、1GB以上のSDカードは認識しないため、差しておくとキーボード入力を受け付けません。
<pre>
rootでログインします。
# zaurus login: root
# cd /mnt/card
# insmod -f zbsdmod.o
# ./zboot
  スペースキーを押して中断します。
> boot netbsd.c700
  :
</pre>
  * ログイン
rootでログインします。
X起動
----------------------startxコマンドを実行すると、Xサーバが起動します。
<pre>
cp /etc/X11/xinit/xinitrc ~/.xinitrc
chmod +w ~/.xinitrc
vi ~/.xinitrc
</pre>
<pre>
/etc/X11/xorg.conf:
Section "Device"
      :
#    Option  "Rotate"   "CW"   ... この行をコメントアウトしてください。
EndSection
</pre>
参考リンク　より詳細な説明は、以下のリンクを参考にしてください。
#. NetBSD/zaurus installation tips [http://mail-index.netbsd.org/port-zaurus/2011/05/20/msg000045.html]
#. ↑日本語訳 [http://www.na.rim.or.jp/~kano/tmp/msg000045ja.html]
#. [http://ftp.jp.NetBSD.org/pub/NetBSD/misc/tsutsui/zaurus/]
#. ザウルス SL-C700 シリアルケーブル作成 [http://togetter.com/li/237198]
#. NetBSDでザウルス SL-C700 サポートするぞ [http://togetter.com/li/242873]
#. NetBSD/zaurus お試し用 1GB SDイメージ [http://togetter.com/li/243703]
#. SDHCドライバ [http://petit-noise.net/download/sdhc-driver]
#. SL-C700でNetBSD/zaurus [http://qml.610t.org/FreeBSD/mutoh_20120212.html]
#. NetBSD/zaurus [http://www.NetBSD.org/ports/zaurus/]
#. NetBSD Guide [http://www.NetBSD.org/docs/guide/download/netbsd-en.pdf.gz]
#. Pkgsrc Guide [http://www.NetBSD.org/docs/pkgsrc/pkgsrc.pdf]
#. 日本NetBSDユーザーグループ [http://www.jp.NetBSD.org/]
#. 日本NetBSDユーザーグループfacebookページ [http://www.facebook.com/NetBSD.jp]
