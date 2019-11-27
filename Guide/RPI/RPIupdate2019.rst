.. 
 Copyright (c) 2013-9 Jun Ebihara All rights reserved.
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

===========================================
RaspberryPIのNetBSDイメージ2019進捗どうですか
===========================================


RaspberryPIのNetBSDイメージについて
---------------------------------

今年もオープンソースカンファレンスごとにRaspberryPI用のNetBSDイメージを作って配布しています。
この一年、どんなことがあったのか表にしてまとめてみました。

.. csv-table::
 :widths: 20 20 20 20 20 80 20 50

 年月,NetBSD,mikutter,mlterm,OpenSSL,ネタ,OSC,URL
 2018/11/10,8.99.25,3.8.2,3.8.7,,gtk3+3.24.1,KOF&OSC新潟,http://mail-index.netbsd.org/port-arm/2018/11/06/msg005153.html
 2018/11/23,8.99.26,3.8.3,3.8.7nb2,,gcc-6.5 RPI0/0W/1ブート不可,OSC島根,http://mail-index.netbsd.org/port-arm/2018/11/19/msg005230.html
 2018/12/8,8.99.26,,,,git-base-2.19.2 RPI3A+ NetBSD SA 2018-009,OSC福岡,http://mail-index.netbsd.org/port-arm/2018/12/03/msg005294.html
 2019/1/26,8.99.30,3.8.4,,1.1.1a,bind-9.13.5W1 sqlite3-3.26 bash-5.0 git-base-2.20.1,OSC大阪,http://mail-index.netbsd.org/port-arm/2019/01/24/msg005415.html
 2019/2/10,8.99.33,,,,gtk3+-3.24.4 NetBSD-SA2019-001,OSC浜名湖,http://mail-index.netbsd.org/port-arm/2019/02/07/msg005450.html
 2019/2/22,8.99.34,3.8.5,,,icu-63.1nb2,OSC東京春,http://mail-index.netbsd.org/port-arm/2019/02/20/msg005506.html
 2019/3/21,8.99.36,3.8.6,3.8.7nb3,1.1.1b,gcc-7.4.0 jemalloc libstdc++,AsiaBSDCon,http://mail-index.netbsd.org/port-arm/2019/03/20/msg005584.html
 2019/4/20,8.99.37,,3.8.8,,libstdc++-9.0 ruby-2.4.6,OSC沖縄,http://mail-index.netbsd.org/port-arm/2019/04/16/msg005599.html
 2019/6/1,8.99.41,3.8.7,,,python37 NetBSD SA 2019-002 2019-003,OSC北海道,http://mail-index.netbsd.org/port-arm/2019/05/23/msg005736.html
 2019/7/13,8.99.50,3.9.0,3.8.8,1.1.1c,libc-12.213 RPI4発売,OSC名古屋,http://mail-index.netbsd.org/port-arm/2019/07/07/msg005875.html
 2019/8/3,8.99.51→9.99.1,3.9.2,,,9.0_BETA,OSC京都,http://mail-index.netbsd.org/port-arm/2019/07/31/msg005994.html
 2019/9/15,9.99.11,3.9.5,,,bwfm,OSC広島,http://mail-index.netbsd.org/port-arm/2019/09/10/msg006129.html
 2019/9/28,9.99.12,,,,RPI4,OSC島根,http://mail-index.netbsd.org/port-arm/2019/09/23/msg006154.html
 2019/10/5,9.99.15,,,,pkgsrc-2019Q3,OSC新潟,http://mail-index.netbsd.org/port-arm/2019/10/03/msg006209.html
 2019/10/19,9.99.17,3.9.6,,,dhcpcd-8.1.1 sudo,OSC徳島,http://mail-index.netbsd.org/port-arm/2019/10/24/msg006265.html
 2019/11/9,9.99.17,,,,bind-9.14.7 glib2-2.6.4,OSC福岡,http://mail-index.netbsd.org/port-arm/2019/11/02/msg006291.html
 2019/11/24,9.99.17,3.9.7,3.8.9,,dhcpcd-8.1.2,OSC東京秋,http://mail-index.netbsd.org/port-arm/2019/11/21/msg006322.html
 2019/11/25,9.99.18,,,,NetBSD-SA-2019-005,,
 年月,NetBSD,mikutter,mlterm,OpenSSL,ネタ,OSC,URL

OSCはほぼ毎月のように日本各地で行われています。
前に、OpenBSDのTheoさんに、自分のノートPCのアップデートをどのくらいの周期でやってるのかきいてみました。
2週間くらいごとかなと答えてくれて、ああだいたいそんなものなのかと思っていました。

NetBSDのイメージを配るとしたとき、どのくらいの周期でアップデートしていけばいいのでしょうか？
イメージを配る理由は、何かソフトウェアが新しくなって新しい機能が入ったとか、ハードウェアのサポート種類が増えたとか、ソフトウェアの脆弱性が出たとか、
理由はいくつかあると思いますが、試しにずっと更新して配りつづけることにしてみました。

イメージのサイズは2GBにしてみました。ダウンロードにかかる時間とか考えると、これ以上でっかくすると使ってもらえません。
2GBのカードのサイズはこんくらいにすればいいよとFreeBSDのワーナーさんに教えてもらってずっとそのサイズにしていましたが、
手狭になったので増やしました。

イメージに入れるソフトを何にするか考えたんですが、mikutterとmltermにしてみました。RubyのGUI環境＋ネットワーク認証を使うソフトと、
基本的なターミナルソフトで、sixelグラフィックも表示できるのでおもしろそうです。

作り方は
 https://github.com/ebijun/NetBSD/blob/master/Guide/RPI/RPIImage.rst
みたいに作って、あらかじめ作っておいたパッケージを組み込んで動作テストをします。mikutterで「あひる焼き」とつぶやいて返事が帰ってくれば
ネットワーク認証と画面表示とRubyまわりと漢字入力がうまくいっています。

新しいハードウェア対応
----------------------

#. RPI4:OSC2019島根から：http://mail-index.netbsd.org/port-arm/2019/10/03/msg006208.html
#. RPI3/RPI0WのBluetooth/無線LAN:OSC2019広島版からテストをはじめました

ソフトウェア配布方法
--------------------
NetBSDのftpサイトはCDN対応のところからダウンロードできるようになりました。漫喫でも楽勝です。
- http://cdn.netbsd.org/
- http://nycdn.netbsd.org/

OSCでやっているデモ
------------------------
RaspberryPIっぽいなにかということで、omxplayerを使ってcrontabで動画を流すデモと、XM6iで
NetBSD/x68kを動かすデモをやっていました。


security.pax.mprotect.enabled
------------------------------------

::

  man security
  man paxctl
  sysctl -a |grep pax
  If application failed, such as omxplayer.
  try to test 
  sysctl -w security.pax.mprotect.enabled=0 
 
GPIOのドキュメント
----------------------
GPIOの使い方をまとめてくれた方が。

* NetBSD GPIO DOC by Marina Brown
  https://github.com/catskillmarina/netbsd-gpio-doc/blob/master/README.md

64bit対応
---------------------

ryo@netbsd さんによる rpi64wip実装が進み、NetBSD/aarch64としてRPI3/4で利用できます。

* https://github.com/ryo/netbsd-src
* http://mail-index.netbsd.org/port-arm/2018/02/20/msg004631.html
* http://mail-index.netbsd.org/port-arm/2018/12/03/msg005297.html

RPI4
-------

- テスト中です。
- USBデバイスはまだ使えません
- 内蔵有線LANポートは使えません
- 無線LANポートは使えます

armv7のいろいろ
--------------------

Jared McNeillさんによるNetBSD ARM Bootable Imagesがあります。

* http://www.invisible.ca/arm/


ご注文はなんとかですか（弱点）
-----------------------------
- RPI3の無線はつかえませんか？→使えるようになりました！
- ラズビアンでは動くんですが
- 9.0版はないんですか→9.0BETAから。

まとめ
----------
OSCごとにイメージをつくっていると、だいたいBINDとOpenSSLの脆弱性に対応できていい感じです。なんでOSCの直前になると脆弱性がみつかるんでしょうか。
たまにBSD自体の10年もののバグとかも発掘されて楽しいです。
リリース間隔があけばあくほど、ひとりで対応できる作業量を越えてしまう気がするので、いまんとここれでいいのかほんとうに。
