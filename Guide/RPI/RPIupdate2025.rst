.. 
 Copyright (c) 2013-2025 Jun Ebihara All rights reserved.
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
RaspberryPIのNetBSDイメージ2025進捗どうですか
===========================================


RaspberryPIのNetBSDイメージについて
---------------------------------

今年もオープンソースカンファレンスごとにRaspberryPI用のNetBSDイメージを作って配布しています。
この一年、どんなことがあったのか表にしてまとめてみました。

.. csv-table::
 :widths: 20 20 20 20 20 80 20 50

 年月,NetBSD,mikutter,mlterm,OpenSSL,ネタ,OSC,URL
 2019/8/3,8.99.51→9.99.1,3.9.2,,,9.0_BETA,OSC京都,http://mail-index.netbsd.org/port-arm/2019/07/31/msg005994.html
 2023/1/28,10.99.2,5.0.4nb2,3.9.2,,10ブランチ,OSC大阪,http://mail-index.netbsd.org/port-arm/2023/01/19/msg008093.html
 2023/12/9,10.99.10,,,,,OSC福岡,http://mail-index.netbsd.org/port-arm/2023/12/05/msg008449.html
 2024/1/27,10.99.10,,3.9.3nb6,,10RC3,OSC大阪,http://mail-index.netbsd.org/port-arm/2024/01/18/msg008522.html
 2024/3/2,10.99.10,,3.9.3nb7,,10RC5 ruby3.2,OSC東京,http://mail-index.netbsd.org/port-arm/2024/02/22/msg008586.html
 2024/5/25,10.99.10,5.0.7nb2,3.9.3nb9,,NetBSD10 ,OSC名古屋,http://mail-index.netbsd.org/port-arm/2024/05/21/msg008716.html
 2024/6/29,10.99.10,,3.9.3nb10,,gcc12,OSC北海道,http://mail-index.netbsd.org/port-arm/2024/06/24/msg008778.html
 2024/7/27,10.99.11,,3.9.3nb11,,openssh9.8,OSC京都,http://mail-index.netbsd.org/port-arm/2024/07/17/msg008829.html
 2024/9/7,10.99.12,,,,,ODC,http://mail-index.netbsd.org/port-arm/2024/08/22/msg008875.html
 2024/9/29,10.99.12,,,3.0.15,sayaka 3.8.1,OSC広島,http://mail-index.netbsd.org/port-arm/2024/09/20/msg008918.html
 2024/10/26,10.99.12,,3.9.3nb13,,nanotodon,OSC東京,http://mail-index.netbsd.org/port-arm/2024/10/16/msg009010.html
 2024/12/7,10.99.12,,3.9.3nb16,,,OSC福岡,http://mail-index.netbsd.org/port-arm/2024/11/23/msg009037.html
 2025/1/25,10.99.12,5.0.8,3.9.3nb18,,,OSC大阪,https://mail-index.netbsd.org/port-arm/2025/01/13/msg009100.html
 2025/2/21,10.99.12,5.1.1nb1,,,dillo,OSC東京春,https://mail-index.netbsd.org/port-arm/2025/02/18/msg009133.html
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

#. RPI5:2023/10末出荷開始 Broadcom BCM2712 64-bit quad-core Arm Cortex-A76  2.4GHz
#. https://github.com/worproject/rpi5-uefi http://mail-index.netbsd.org/port-arm/2024/01/19/msg008524.html
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
RaspberryPIっぽいなにかということで、omxplayerを使って動画を流すデモと、nonoで
NetBSD/x68k,OpenBSD/luna88k,NetBSD/luna68kを動かすデモをやっています。


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

RPI5
-----------------

* https://github.com/worproject/rpi5-uefi

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
