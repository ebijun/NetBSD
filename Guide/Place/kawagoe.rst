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

.. イメージファイルは圧縮すること

川越よ私は帰ってきたOSC2015NetBSDブースの展望
----------------------------------------------
| 日本NetBSDユーザーグループ
| 蛯原　純
| jun@soum.co.jp

NetBSD
~~~~~~~~
 NetBSDは１個のソースツリーをコンパイルすることで実行イメージを作ることができます。目についたハードウェアの情報を全部CVSに記録してBSD系UNIX上で動かしてみたい。

ソースコードから作る
""""""""""""""""""""

::

 # ftp ftp://ftp.netbsd.org/pub/NetBSD/NetBSD-current/tar_files/src.tar.gz
 # tar xzvf src.tar.gz
 # ./build.sh -U -m i386 release     .... -U:root以外で作成,i386向け
 # ./build.sh -U -m i386 iso-image

pkgsrc - ソースコードからソフトウェアを作る
""""""""""""""""""""""""""""""""""""""""""""
　目についたソフトウェアのコンパイル手順をCVSに記録していろんなOS上で動かしてみたい。

::

 # cd /usr
 # ftp ftp://ftp.netbsd.org/pub/NetBSD/NetBSD-current/tar_files/pkgsrc.tar.gz
 # tar xzvf pkgsrc.tar.gz
 # cd /usr/pkgsrc/net/mikutter
 # make install


今年これまで
~~~~~~~~~~~~~~~~~~~~~

* NetBSD7.0に向けて(通算二回目
* 国内のソフトウェアをpkgsrcで紹介(mikutter/mlterm..
* X11 drmkms
* RPI & ARM .. OSCごとにイメージファイルリリース
* ftp://ftp.netbsd.org/pub/NetBSD/misc/jun/raspberry-pi/
* ftp://ftp.netbsd.org/pub/NetBSD/misc/jun/allwinner/
* ftp://ftp.netbsd.org/pub/NetBSD/misc/jun/odroid_c1
* ftp://ftp.netbsd.org/pub/NetBSD/misc/jun/hpcarm
* ftp://ftp.netbsd.org/pub/NetBSD/misc/jun/zaurus

イメージファイル
~~~~~~~~~~~~~~~~~~~~~~~~~

* 2GBのイメージ
* ddでコピー
* 差してブートするとNetBSDが起動
* rootでログイン：パスワードなし
* startxでicewm起動
* mikutterが起動
* mltermとか、良いプロダクトを全世界の人に見てもらいたい
* いろんな国の人から本当に反応がある！楽しい！

togetterのview数でみるNetBSDブースこの一年
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. csv-table::

 http://togetter.com/li/798599, NetBSD博物館,1699
 http://togetter.com/li/793444, AsiaBSDCon 2015の記録,2811
 http://togetter.com/li/788681, オープンソースカンファレンス2015 Tokyo/Spring　NetBSDブース展示の記録,1145
 http://togetter.com/li/781556, オープンソースカンファレンス2015 Hamanako　NetBSDブース展示の記録,587
 http://togetter.com/li/779725, オープンソースカンファレンス2015 Oita　NetBSDブース展示の記録,604
 http://togetter.com/li/762067, NetBSD Advent Calendar 2014の記録,777
 http://togetter.com/li/748237, オープンソースカンファレンス2014 Fukuoka　NetBSDブース展示の記録,1812
 http://togetter.com/li/742243, 関西オープンソース2014 NetBSDブース展示の記録,1864
 http://togetter.com/li/733588, オープンソースカンファレンス2014 Tokyo/Fall　NetBSDブース展示の記録,1888
 http://togetter.com/li/721414, オープンソースカンファレンス2014 Hiroshima　NetBSDブース展示の記録,2113
 http://togetter.com/li/709947, オープンソースカンファレンス2014 Shimane　NetBSDブース展示の記録,1647
 http://togetter.com/li/691775, 日本NetBSDユーザーグループ第十六回定期総会 および NetBSD BoF 2014,2352
 http://togetter.com/li/688742, オープンソースカンファレンス2014 Nagoya&NBUG7月例会 の記録,1517
 http://togetter.com/li/680053, オープンソースカンファレンス2014北海道　NetBSDブース展示の記録,2002
 http://togetter.com/li/671580, オープンソースカンファレンス2014沖縄　NetBSDブース展示の記録,582


今後のOSC参加予定
~~~~~~~~~~~~~~~~~~
#. OSCの参加者総数63,230人　延べ参加グループ数3,592グループ
#. OSC2015東京春までで通算103/114参加=90.3%
#. *http://www.jp.NetBSD.org/* を見る
#. イベントページをクリックするとFacebookページへ。

.. csv-table::

 2015年5月9日 - Open Source UN-Conference 2015 Kawagoe
 2015年5月22日 - オープンソースカンファレンス2015 Nagoya & 名古屋*BSDユーザーグループ2015/5例会
 2015年6月12日 - オープンソースカンファレンス2015 Hokkaido
 2015年7月4日 - オープンソースカンファレンス2015 Okinawa
 2015年7月11日 - 日本NetBSDユーザーグループ第十七回定期総会 および NetBSD BoF 2015
 2015年8月7日 - オープンソースカンファレンス2015 Kansai@Kyoto
 2015年8月22日 - オープンソースカンファレンス2015 Shimane
 2015年11月6日 - 関西オープンフォーラム2015（KOF2015）
 2016年3月10日 - AsiaBSDCon 2016

2015/5 名古屋
~~~~~~~~~~~~~~~~~~~~~~~~~~~~

* NBUG本拠地近くで開催
* OpenBSD/Luna88K+CBUS PC98グラフィックカード2画面
* ワイマーケット＆三八屋＆23tap&(菊井かつ)
* OSuCあるんでしたっけ？


2015/6 北海道
~~~~~~~~~~~~~~

* LOCALに訊け!
* YK無線
* NoBUGガジェット群
* ジャンク屋:写真店：ハードオフ
* FML深町さん
* さいとさんの店
* さくら石狩データセンター
* クリプトン
* モルトヘッズ

2015/7 沖縄
~~~~~~~~~~~~~~

* 海水浴場脇
* 新しいネタを入れるときは沖縄から
* 琉球大学枠&FreeBSD勉強会&Contao神戸さん&やまじゅんさんPCBSD
* 五十嵐さん＆りえしょんのDVDをとらのあなに買いにいかんと
* アメリカンNo.1
* 麦 baku

2015/7 定期総会
~~~~~~~~~~~~~~~~~~~~~~~~~~~~

* 日本NetBSDユーザーグループ第十六回定期総会 および NetBSD BoF 2014（仮
* 東大本郷で今日は一日NetBSD三昧

2015/8 京都
~~~~~~~~~~~~~~~~~~

* よしだともこ先生を大いに盛り上げるLuna68Kの会
* mikutterの本場
* だいこん→バンガロー→和知

2015/8 島根
~~~~~~~~~~~~~~~~~~

* SONY NEWS祭り
* Rubyの郷:発表15分/サンライズ/飛行機/岡山経由か鳥取経由か
* Sony NEWSがたくさんある大学が鳥取にある
* ゼネラルプロダクツ
* 国際宇宙生物研究所＆エスパーク

2015/?? 広島
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

* 年間最重要イベント：X68K＆mlterm特集
* XM6i祭り
* X68060祭り
* ビールスタンド重富で重富注ぎ！

2015/11 KOF
~~~~~~~~~~~~~~~~~~~~

* BSDなひととき(発表者募集
* 「そんな先のことはわからない」(CV:銀河万丈/9話予告)
* 図書販売コーナー推薦本募集：CPU黒歴史本？
* 順記で餃子

2015/11? 徳島？
~~~~~~~~~~~~~~~~~~~~~

* 動きがあるらしいぞ？
* シラサギ動くようにしなきゃ

2016/4 AsiaBSDCon
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

* BSD関連の国際会議 150人規模
* sendmail作った人とかにシールを渡してみる
* BSD作った人とかにシールを渡してみる
* スポンサーは常に募集中（-毎年100万くらい赤字
* イベント運営を手伝ってくれそうな実直な企業募集
* www.bsdresearch.org
* FreeBSDワークショップ　のとき打ち合わせしてます

観光ガイド
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

* なんか地元の情報:行ったら行くようなとこリスト
* そのへんではやっているハードでNetBSDを動かす方法
* A4 20P→小冊子印刷でA4両面4Px5枚
* Sphinx+scribus→セブンイレブンで15部印刷
* 毎回2000円くらい
* https://github.com/ebijun/osc-demo

NetBSD関連情報
~~~~~~~~~~~~~~~~~

* http://www.NetBSD.org/
* http://www.jp.NetBSD.org/
* http://www.facebook.com/NetBSD.jp/

詳しくは
~~~~~~~~~~~~~~~~~

* 「なぜNetBSD」で検索
