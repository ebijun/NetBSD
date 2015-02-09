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

====================================
WZERO3でNetBSDを使ってみる 
====================================

NetBSD/hpcarm 6.1 W-ZERO3 ておくれLive Image
---------------------------------------------

筒井さんによる、ておくれイメージのページも見てください。
 http://www.ceres.dti.ne.jp/tsutsui/netbsd/liveimage/wzero3.html

用意するもの
-----------
#.  WZERO3本体 WS003SH/WS004SH/WS007SH/WS011SH/WS020SH
#.  ディスクイメージコピー用NetBSDマシン
#.  USBカードリーダ
#.  NetBSDインストール用メモリカード

WS003SH/004SH/007SH
 MiniSDカードが必要です。MicroSDカードとMiniSDカードアダプタを組み合わせても利用できます。
 2G以上のSDHCカードを使う場合は、SDHCドライバをインストールするために、2G以下のSDカードが必要です。

WS011SH/WS020SH
 2G以上のMicroSDカード

SDカード用デバイスドライバのインストール
--------------------------------------

WS003SH,WS004SH,WS007SHで、2G以上のSDHCカードを利用するためにはSDカード用デバイスドライバをインストールします。

SDHCドライバ
 http://w-zero3.org/?%A5%B7%A5%B9%A5%C6%A5%E0%B4%D8%B7%B8#wf87e46c

インストール
-----------
  ダウンロードしたSDHCドライバを、2GB以下のMicro/MiniSDカードにコピーします。コピーしたカードをWZEROのカードスロットに差します。

デバイスドライバのインストール
----------------------------
  WZERO3を起動し、ファイルエクスプローラ→mini/microSDカード→コピーしたSDHCドライバをクリック→インストールする場所 デバイスを選んでインストール→再起動 OKを選択→メニューバー右上のXをクリックすると再起動が始まります。

NetBSDディスクイメージのダウンロード
-----------------------------------
NetBSD7.99.4インストール済みのディスクイメージファイルを作りました。

ftp://ftp.netbsd.org/pub/NetBSD/misc/jun/hpcarm/2015-01-24-netbsd-hpcarm.img.gz

ディスクイメージをコンパクトフラッシュにコピーする
-----------------------------------------------
  NetBSDをインストールするMini/MicroSDカードをUSBカードアダプタ経由でNetBSDマシンにつなぎます。

::

 # dmesg    .... sd3に2GBのMicroSDカードがつながっています。
 sd3 at scsibus0 target 0 lun 3: <USB2.0, CardReader SD, 0100> disk removable
 sd3: fabricating a geometry
 sd3: 1947 MB, 1947 cyl, 64 head, 32 sec, 512 bytes/sect x 3987456 sectors
 sd3: fabricating a geometry
 # disklabel sd3　　... sd3のパーティションを確認します。
        :
 5 partitions:
 #        size    offset     fstype  fsize bsize cpg/sgs
 d:   3987456         0     unused      0     0        # (Cyl.      0 -   1946)
 e:   3987209       247      MSDOS                     # (Cyl.      0*-   1946)
 　　　... NetBSDではdパーティションがディスク全体になります。
 # gunzip <　2014-12-06-netbsd6-hpcarm.img.gz |dd of=/dev/rsd3d bs=1m
 USBカードリーダーを差し直します。
 # disklabel sd3
 #        size    offset     fstype  fsize bsize cpg/sgs
 a:   2947392    393216     4.2BSD   2048 16384     0  # (Cyl.     97*-    828*)
 b:    526016   3340608       swap                     # (Cyl.    828*-    958*)
 c:   3473408    393216     unused      0     0        # (Cyl.     97*-    958*)
 d:   3964928         0     unused      0     0        # (Cyl.      0 -    983*)
 e:    393184        32      MSDOS                     # (Cyl.      0*-     97*)

NetBSDの起動
-------------

hpcboot起動
------------
ファイルエクスプローラ→hpcboot.exe を起動すると、ブートローダhpcbootが起動します。

hpcboot内で機種とカーネルを指定
------------------------------
#. mini/microSDカード→カード種別を指定します。
#. netbsd→呼び出すカーネルを指定します。
#. Sharp W-ZERO3(WS004SH)→機種名をプルダウンメニューから選択します。

NetBSD起動
-----------
  Bootボタンを押すと、本当に起動していいか確認メニューが現れます。NetBSDを起動すると、WZERO3のメモリ上にセーブしていたデータは消えてしまうので、必要ならバックアップをとっておいてください。

ログイン
-------
  root でログインできます。

::

  login: root

X起動
-----
  startxコマンドを実行すると、Xサーバが起動します。

::

  # startx

無線LAN (WS003SH/004SH)
-------------------------

 NetBSD起動前にWindowsMobile上で有効（無線LAN LED点灯状態）にしておきます。
 「スタート」→「設定」→「ユーティリティ」→「無線ON/OFF」→「内蔵ワイアレスLANを停止」チェックをはずす→MACアドレスが表示されるか確認する
 [http://www.nazgul.ch/upgt/upgt-firmware-1.1.tar.gz]をダウンロードします。

::

 % tar xzpvf upgt-firmware-1.1.tar.gz
    :
 % ls -l
 total 68
 -rw-r--r--  1 root  wheel     23 Dec 23  2008 Makefile
 -rw-r--r--  1 root  wheel  28976 Dec 23  2008 upgt-gw3887
 -rw-r--r--  1 root  wheel    372 Dec 23  2008 upgt-info
 # dmesg   ... MicroSDカードをUSBカードアダプタ経由でNetBSDマシンにつなぎます。
    :
 sd3 at scsibus0 target 0 lun 3: <USB2.0, CardReader SD, 0100> disk removable
 sd3: fabricating a geometry
 sd3: 1947 MB, 1947 cyl, 64 head, 32 sec, 512 bytes/sect x 3987456 sectors
 sd3: fabricating a geometry
 # fsck /dev/sd3a  ... sd3にメディアがつながっている場合 
 # mount /dev/sd3a /mnt　　... /mntにマウントする。
   無線LANのファームウェアをコピーします。
 # cp upgt-gw3887 /mnt/libdata/firmware/upgt/upgt-gw3887

参考リンク　
---------
より詳細な説明は、以下のリンクを参考にしてください。

*  http://www.ceres.dti.ne.jp/tsutsui/netbsd/liveimage/wzero3.html
*  http://ftp.netbsd.org/pub/NetBSD/misc/tsutsui/wzero3/
*  http://ftp.netbsd.org/pub/NetBSD/misc/tsutsui/wzero3/README.ja
*  NetBSD Guide [http://www.NetBSD.org/docs/guide/download/netbsd-en.pdf.gz
*  Pkgsrc Guide [http://www.NetBSD.org/docs/pkgsrc/pkgsrc.pdf
*  http://www.amazon.co.jp/dp/B000L81AAU/
*  日本NetBSDユーザーグループ http://www.jp.NetBSD.org/

