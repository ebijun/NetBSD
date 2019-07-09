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
 2018/5/19,8.99.15,3.6.7 APIKey,,,git-base-2.17.0 NetBSD SA 2018-007,OSC名古屋,http://mail-index.netbsd.org/port-arm/2018/05/18/msg004789.html
 2018/6/16,8.99.19,3.7.1,,,PR53283 git-base-2.17.1,OSC沖縄,http://mail-index.netbsd.org/port-arm/2018/06/11/msg004851.html
 2018/7/07,8.99.21,3.7.2,3.8.6,,git-base-2.18,OSC北海道,http://mail-index.netbsd.org/port-arm/2018/07/01/msg004913.html
 2018/7/21,8.0,,,,,NBUG2018/7,http://mail-index.netbsd.org/port-arm/2018/07/22/msg004963.html
 2018/8/4,8.99.22,3.7.4,,,omxplayer,OSC京都,http://mail-index.netbsd.org/port-arm/2018/07/29/msg004969.html
 2018/8/25,8.99.24,,,1.1.0i,RPI3B+Ether,ODC,http://mail-index.netbsd.org/port-arm/2018/08/24/msg004993.html
 2018/9/23,8.99.25,3.8.0,,,OpenSSH7.8 git-base-2.19.0 libssh33,OSC広島,http://mail-index.netbsd.org/port-arm/2018/09/17/msg005023.html
 2018/10/06,8.99.25,,,1.1.1,,OSC香川,http://mail-index.netbsd.org/port-arm/2018/10/01/msg005059.html
 2018/10/28,8.99.25,3.8.1,,,git-base-2.19.1 ruby-2.4.5,OSC東京秋,http://mail-index.netbsd.org/port-arm/2018/10/25/msg005097.html
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

RPI4/RPI3/RPI0WのBluetooth/無線LANへの対応準備をしています。

::

 http://mail-index.netbsd.org/port-arm/2017/07/30/msg004328.html

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

ryo@netbsd さんによる rpi64wip実装が進み、NetBSD/aarch64としてRPI3で利用できます。

* https://github.com/ryo/netbsd-src
* http://mail-index.netbsd.org/port-arm/2018/02/20/msg004631.html
* http://mail-index.netbsd.org/port-arm/2018/12/03/msg005297.html

armv7のいろいろ
--------------------

Jared McNeillさんによるNetBSD ARM Bootable Imagesがあります。

* http://www.invisible.ca/arm/


ご注文はなんとかですか（弱点）
-----------------------------
- RPI3の無線はつかえませんか？
- ラズビアンでは動くんですが
- 8.0版はないんですか→リリースしました。

まとめ
----------
OSCごとにイメージをつくっていると、だいたいBINDとOpenSSLの脆弱性に対応できていい感じです。なんでOSCの直前になると脆弱性がみつかるんでしょうか。
たまにBSD自体の10年もののバグとかも発掘されて楽しいです。
リリース間隔があけばあくほど、ひとりで対応できる作業量を越えてしまう気がするので、いまんとここれでいいのかほんとうに。
