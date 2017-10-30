.. 
 Copyright (c) 2013-7 Jun Ebihara All rights reserved.
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
RaspberryPIのNetBSDイメージ2017進捗どうですか
===========================================


RaspberryPIのNetBSDイメージについて
---------------------------------

今年もオープンソースカンファレンスごとにRaspberryPI用のNetBSDイメージを作って配布しています。
この一年、どんなことがあったのか表にしてまとめてみました。

.. csv-table::

 年月,NetBSD,mikutter,mlterm,OpenSSL,ネタ,OSC,URL
 2016/1,7.99.25,3.3.3,3.6.1,,CVE-2016-0777: get rid of roaming,OSC浜名湖,http://mail-index.netbsd.org/port-arm/2016/01/22/msg003635.html
 2016/2,7.99.26,3.3.7,3.6.3,1.0.1r,BIND-9.10.3-P3,OSC東京春,http://mail-index.netbsd.org/port-arm/2016/02/24/msg003689.html
 2016/3,7.99.26,3.3.8,,1.0.1s,,AsiaBSDCon,http://mail-index.netbsd.org/port-arm/2016/03/10/msg003709.html
 2016/5,7.99.29,,3.7.0,1.0.1t,RPI3サポート/merge nick-nhusb tree,OSC群馬,http://mail-index.netbsd.org/port-arm/2016/05/07/msg003771.html
 2016/6,7.99.29,3.3.9,,,freetype2ディレクトリ変更,OSC名古屋,http://mail-index.netbsd.org/port-arm/2016/05/25/msg003797.html
 ,7.99.30,3.4.0,,,GCC5.4.0 security.pax.mprotect,OSC北海道,http://mail-index.netbsd.org/port-arm/2016/06/13/msg003821.html
 ,7.99.31,,,,RPI3 machdep.cpu.frequency.current = 1200,,http://mail-index.netbsd.org/port-arm/2016/06/17/msg003833.html
 2016/7,7.99.32,3.4.1,3.7.1,,git-base-2.9.0 perl-5.24,OSC沖縄,http://mail-index.netbsd.org/port-arm/2016/06/29/msg003846.html
 2016/8,7.99.34,,,,SA 2016-006: Race condition in mail.local(8),OSC京都,http://mail-index.netbsd.org/port-arm/2016/07/27/msg003884.html
 2016/9,7.99.36,3.4.2,,,,OSuC金沢,http://mail-index.netbsd.org/port-arm/2016/08/23/msg003918.html
 ,7.99.38,3.4.3,3.7.2,,git-base-2.10.0,OSC島根,http://mail-index.netbsd.org/port-arm/2016/09/22/msg003920.html
 ,7.99.39,,,,,OSC長岡,http://mail-index.netbsd.org/port-arm/2016/09/29/msg003921.html
 2016/11,7.99.41,3.4.6,,1.0.2j,RPI2 Ver1.2サポート libssl.12/libcrypt.12 NetBSD2017-SA01,OSC東京秋,http://mail-index.netbsd.org/port-arm/2016/11/02/msg003954.html
 ,7.99.42,,,,BIND-9.10.4-P4 Raspberrypi-userland-2016-1101,KOF2016,http://mail-index.netbsd.org/port-arm/2016/11/10/msg003958.html
 ,7.99.42,3.4.7,,,NTP-4.2.8p9,OSC広島,http://mail-index.netbsd.org/port-arm/2016/11/23/msg003970.html
 2016/12,7.99.44,3.4.8,,,CWE-120 libc git-base-2.11.0,BIG RPI Jam,http://mail-index.netbsd.org/port-arm/2016/12/10/msg004002.html
 2017/1,7.99.59,3.5.1,,,HardwareRNG BIND-9.10.4-P5 raspberrypi-userland-20170109,OSC大阪,http://mail-index.netbsd.org/port-arm/2017/01/25/msg004087.html
 2017/2,7.99.59,3.5.2,3.8.0,1.0.2k,,OSC浜名湖,https://github.com/ebijun/osc-demo/blob/master/2017/OSC2017hamanako.txt
 2017/3,7.99.64,3.5.3,,,tcpdump-4.9.0 BIND-9.10.4-P6 postfix-3.1.4 NetBSD-SA02 git-base-2.12.0,OSC東京春,http://mail-index.netbsd.org/netbsd-advocacy/2017/03/13/msg000728.html
 2017/4,7.99.69,3.5.7,,,NetBSD7.1 ruby-2.3,OSuC川越,http://mail-index.netbsd.org/port-arm/2017/04/14/msg004130.html
 2017/5,7.99.72(→7.99.75),,3.8.1,,BIND-9.10.4-P8 fossil-2.2 git-base-2.13.0,OSC名古屋,http://mail-index.netbsd.org/port-arm/2017/05/24/msg004150.html
 2017/6,8.99.1,3.5.8,,,perl-5.26 qemu/VEXPRESS_A15カーネルからの起動 (BIND-9.10.5-P1),OSC沖縄,http://mail-index.netbsd.org/port-arm/2017/06/12/msg004179.html
 2017/7,8.99.1,,,,RPI3起動タイミング修正 microSD認識エラー修正 BIND-9.10.5-P2,JNUG2017,http://mail-index.netbsd.org/port-arm/2017/07/07/msg004286.html
 2017/7,8.99.1,3.5.9,,,,OSC北海道,http://mail-index.netbsd.org/port-arm/2017/07/13/msg004307.html
 2017/8,8.99.1,,,,,OSC京都,http://mail-index.netbsd.org/port-arm/2017/07/13/msg004307.html
 ,8.99.1,,3.8.2,,git-base-2.14.1 Bluetoothサポート,ODC2017Tokyo,http://mail-index.netbsd.org/port-arm/2017/08/18/msg004375.html
 2017/9,8.99.2,3.5.10,,,ruby23-base-2.3.4nb1,OSC千葉 NanoPi,http://mail-index.netbsd.org/port-arm/2017/09/01/msg004383.html
 ,8.99.2,3.5.11,,,,OSC東京秋,
 2017/10,8.99.3,,,,ruby23-base-2.3.5,OSC福岡,http://mail-index.netbsd.org/port-arm/2017/10/03/msg004402.html
 ,8.99.4,,,,,OSC島根,
 ,8.99.5,3.5.12,3.8.3,,https://w1.fi/security/2017-1/ B.ROOT-SERVERS.NET,OSC長岡,http://mail-index.netbsd.org/port-arm/2017/10/22/msg004416.html
 2017/11,8.99.5,3.5.13,,,,KOF2017,

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

RPI3/RPI0WのBluetooth/無線LANへの対応準備をしています。

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


ご注文はなんとかですか（弱点）
-----------------------------
- RPI3の無線はつかえませんか？
- ラズビアンでは動くんですが
- 8.0版はないんですか

まとめ
----------
OSCごとにイメージをつくっていると、だいたいBINDとOpenSSLの脆弱性に対応できていい感じです。なんでOSCの直前になると脆弱性がみつかるんでしょうか。
たまにBSD自体の10年もののバグとかも発掘されて楽しいです。
リリース間隔があけばあくほど、ひとりで対応できる作業量を越えてしまう気がするので、いまんとここれでいいのかほんとうに。
