.. 
 Copyright (c) 2013-6 Jun Ebihara All rights reserved.
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

川越よ私は帰ってきたOSC2016NetBSDブースの展望
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

* NetBSD8.0に向けて
* 国内のソフトウェアをpkgsrcで紹介(mikutter/mlterm..
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

 AsiaBSDCon 2016の記録,http://togetter.com/li/947029,2417
 オープンソースカンファレンス2016 Tokyo/Spring NetBSDブース展示の記録,http://togetter.com/li/943037,1375
 オープンソースカンファレンス2016 Hamanako NetBSDブース展示の記録,http://togetter.com/li/929091,719
 NetBSD Advent Calendar 2015の記録,http://togetter.com/li/916444,951
 オープンソースカンファレンス2015 Tokushima NetBSDブース展示の記録,http://togetter.com/li/899923,1076
 関西オープンソース2015 NetBSDブース展示の記録,http://togetter.com/li/896456,1689
 オープンソースカンファレンス2015 Tokyo/Fall NetBSDブース展示の記録,http://togetter.com/li/891107,1137
 オープンソースカンファレンス2015 Fukuoka NetBSDブース展示の記録,http://togetter.com/li/881732,923
 オープンソースカンファレンス2015 Hiroshima NetBSDブース展示の記録,http://togetter.com/li/875487,1593
 オープンソースカンファレンス2015 Niigata NetBSDブース展示の記録,http://togetter.com/li/869752,936
 オープンソースカンファレンス2015 Shimane NetBSDブース展示の記録,http://togetter.com/li/863726,1020
 オープンソースカンファレンス2015 Kansai@Kyoto NetBSDブース展示の記録,http://togetter.com/li/857157,3860
 日本NetBSDユーザーグループ第十七回定期総会 および NetBSD BoF 2015 の記録,http://togetter.com/li/845730,1427
 オープンソースカンファレンス2015 Okinawa　NetBSDブース展示の記録,http://togetter.com/li/842624,953
 オープンソースカンファレンス2015 Hokkaido　NetBSDブース展示の記録,http://togetter.com/li/834148,945
 オープンソースカンファレンス2015 Nagoya&NBUG5月例会 の記録,http://togetter.com/li/824817,2034
 NetBSD博物館,http://togetter.com/li/798599,4794
 AsiaBSDCon 2015の記録,http://togetter.com/li/793444,3930


今後のOSC参加予定
~~~~~~~~~~~~~~~~~~
#. OSCの参加者総数63,230人→70,585人 (+7355人)
#. 延べ参加グループ数3,592グループ→4,044グループ (+452グループ)
#. OSC2015東京春までで通算115/128参加  = 89.8%
#. *http://www.jp.NetBSD.org/* を見る
#. イベントページをクリックするとFacebookページへ。

.. csv-table::

    2016年4月24日 - Open Source UN-Conference 2016 Kawagoe
    2016年4月27日 - 第16回FreeBSDワークショップ（＋懇親会）
    2016年5月14日 - オープンソースカンファレンス2016 Gunma
    2016年5月28日 - オープンソースカンファレンス2016 Nagoya & 名古屋*BSDユーザグループ(NBUG)2016/5月例会
    2016年6月17日 - オープンソースカンファレンス2016 Hokkaido
    2016年7月2日 - オープンソースカンファレンス2016 Okinawa
    2016年7月29日 - オープンソースカンファレンス2016 Kyoto
    2016年11月11日 - 関西オープンフォーラム2016(KOF2016)

2016/5 群馬
~~~~~~~~~~~~~~~~~~~~~~~~~~~~

* 高崎駅ヤマダ電気
* 10分プレゼン大会
* スポンサーたくさんついてる！
* ハードオフ天国

2016/5 名古屋
~~~~~~~~~~~~~~~~~~~~~~~~~~~~

* 今年は吹上ホール
* OpenBSD/Luna88K+CBUS PC98グラフィックカード2画面
* ワイマーケット＆三八屋＆23tap&ヒンメル

2016/6 北海道
~~~~~~~~~~~~~~

* LOCALに訊け!
* YK無線
* NoBUGガジェット群
* ジャンク屋:写真店：ハードオフ
* FML深町さん
* さいとさんの店
* さくら石狩データセンター
* クリプトン
* モルトヘッズ(オリジナルラブML元管理人

2016/7 沖縄
~~~~~~~~~~~~~~

* 海水浴場脇
* 新しいネタを入れるときは沖縄から
* 琉球大学枠&やまじゅんさんPCBSD
* 五十嵐さん＆りえしょんのDVDをとらのあなに買いにいかんと
* アメリカンNo.1
* 麦 baku

2016/7 定期総会
~~~~~~~~~~~~~~~~~~~~~~~~~~~~

* 日本NetBSDユーザーグループ第十八回定期総会 および NetBSD BoF 2016
* 東大本郷で今日は一日NetBSD三昧
* ねこがいなくなったんです。

2016/7 京都
~~~~~~~~~~~~~~~~~~

* よしだともこ先生を大いに盛り上げるLuna68Kの会
* mikutterの本場
* だいこん→バンガロー→和知→京都醸造

2016/9/17か10/1 新潟
~~~~~~~~~~~~~~~~~~~~~~~

* 長岡らしい
* ひさしぶり

2016/9 島根?
~~~~~~~~~~~~~~~~~~

* SONY NEWS祭り
* Rubyの郷:発表15分/サンライズ/飛行機/岡山経由か鳥取経由か
* Sony NEWSがたくさんある大学が鳥取にある
* ゼネラルプロダクツ
* 国際宇宙生物研究所＆エスパーク

2016/10　東京秋
~~~~~~~~~~~~~~~~~

* 東京
* 日程未定？
* BSDなひととき

2016/11/19か26 広島
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

* 年間最重要イベント：X68K＆mlterm特集
* XM6i祭り
* X68060祭り
* ビールスタンド重富で重富注ぎ！

2016/11 KOF
~~~~~~~~~~~~~~~~~~~~

* BSDなひととき(発表者募集
* 「そんな先のことはわからない」(CV:銀河万丈/9話予告)
* 図書販売コーナー推薦本募集：UNIXUser 藤田さん本
* 順記で餃子


2017/3 AsiaBSDCon
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


セキュリティキャンプ
~~~~~~~~~~~~~~~~~

* 2016/8 幕張
* NetBSDで4時間もなんかやります
* 枠30人
* RPI 20台
* のこり10人は謎マシン枠
* どうせそんなに申込ないだろう
