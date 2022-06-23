.. 
 Copyright (c) 2013-2022 Jun Ebihara All rights reserved.
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
RaspberryPIのNetBSDイメージ2022進捗どうですか
===========================================


RaspberryPIのNetBSDイメージについて
---------------------------------

今年もオープンソースカンファレンスごとにRaspberryPI用のNetBSDイメージを作って配布しています。
この一年、どんなことがあったのか表にしてまとめてみました。

.. csv-table::
 :widths: 20 20 20 20 20 80 20 50

 年月,NetBSD,mikutter,mlterm,OpenSSL,ネタ,OSC,URL
 2019/8/3,8.99.51→9.99.1,3.9.2,,,9.0_BETA,OSC京都,http://mail-index.netbsd.org/port-arm/2019/07/31/msg005994.html
 2021/2/27,9.99.80,,,1.1.1j,sudo,OSC東京春, http://mail-index.netbsd.org/port-arm/2021/02/27/msg007187.html
 2021/4/2,9.99.81,,,1.1.1k,openssh8.5,NBUG2021/4,http://mail-index.netbsd.org/port-arm/2021/04/02/msg007213.html
 2021/5/26,9.99.82,4.1.5,3.9.1nb1,,NetBSD9.2,OSC名古屋,http://mail-index.netbsd.org/port-arm/2021/05/26/msg007290.html
 2021/6/26,9.99.85,,,,次はgcc10,OSC北海道,http://mail-index.netbsd.org/port-arm/2021/06/17/msg007309.html
 2021/7/31,9.99.87,,,,gcc10/ruby27,OSC京都,http://mail-index.netbsd.org/port-arm/2021/07/28/msg007381.html
 2021/8/26,9.99.88,,,,bind-9.16.20,ODC,http://mail-index.netbsd.org/port-arm/2021/08/23/msg007421.html
 2021/9/18,9.99.88,4.1.6,,,openssh8.6,OSC広島,http://mail-index.netbsd.org/port-arm/2021/09/17/msg007439.html
 2021/10/2,9.99.90,,,,,OSC新潟,http://mail-index.netbsd.org/port-arm/2021/09/25/msg007444.html
 2021/10/23,(9.99.92),4.1.7,,,(openssh8.8),OSC東京秋,http://mail-index.netbsd.org/port-arm/2021/10/18/msg007452.html
 2021/11/13,9.99.92,,,,openssh8.8 Zero2,KOF2021,http://mail-index.netbsd.org/port-arm/2021/11/05/msg007482.html
 2021/11/20,9.99.92,,,,ファーム更新,OSC福岡,http://mail-index.netbsd.org/port-arm/2021/11/17/msg007495.html
  2022/1/29,9.99.92,5.0.2,3.9.2,1.1.1m,drm大改修,OSC大阪,http://mail-index.netbsd.org/port-arm/2022/01/10/msg007542.html
 2022/3/12,9.99.94,5.0.4,,,tor,OSC東京春,http://mail-index.netbsd.org/port-arm/2022/03/05/msg007597.html
 2022/4/09,9.99.96,,,1.1.1n,,,http://mail-index.netbsd.org/port-arm/2022/03/05/msg007628.html
 2022/5/28,9.99.96,,3.9.2nb1,,OpenSSH9.0,OSC名古屋,http://mail-index.netbsd.org/port-arm/2022/03/05/msg007674.html
 2022/6/25,9.99.98,,,, icu-71.1 ,OSC北海道,http://mail-index.netbsd.org/port-arm/2022/06/22/msg007697.html
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
  https://github.com/ebijun/NetBSD/blob/master/RPI/RPIimage/Image/aarch64/README
#. RPI3/RPI0WのBluetooth/無線LAN:OSC2019広島版からテストをはじめました
#. Raspberry PI zero 2 W earmv7hf版で動きます。
 https://github.com/ebijun/NetBSD/blob/master/RPI/RPIimage/Image/earmv7hf/README
 
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

- pinebookとpkgsrcを共用しています。
* http://mail-index.netbsd.org/port-arm/2020/11/18/msg007066.html
* https://github.com/ebijun/NetBSD/blob/master/RPI/RPIimage/Image/aarch64/README

armv7のいろいろ
--------------------

NetBSD ARM Bootable Imagesがあります。

* https://nycdn.netbsd.org/pub/arm/


ご注文はなんとかですか（弱点）
-----------------------------
- RPI4のGPUとか

まとめ
----------
OSCごとにイメージをつくっていると、だいたいBINDとOpenSSLの脆弱性に対応できていい感じです。なんでOSCの直前になると脆弱性がみつかるんでしょうか。
たまにBSD自体の10年もののバグとかも発掘されて楽しいです。
リリース間隔があけばあくほど、ひとりで対応できる作業量を越えてしまう気がするので、いまんとここれでいいのかほんとうに。
