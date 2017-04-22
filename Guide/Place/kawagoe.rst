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

.. イメージファイルは圧縮すること

川越よ私は帰ってきたOSC2017NetBSDブースの展望
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
　目についたソフトウェアのコンパイル手順をCVSに記録していろんなOS上で動かしてみたい。隣のブースのソフトウェアを、世界中にきちんと動く状態で紹介する。どこがどういいのか説明する。64bit/BigEndian/68Kまであらゆるマシンで動くようなソフトウェアをどう作るか。作ったソフトを20年以上保守するにはどうすればいいか。

::

 # cd /usr
 # ftp ftp://ftp.netbsd.org/pub/NetBSD/NetBSD-current/tar_files/pkgsrc.tar.gz
 # tar xzvf pkgsrc.tar.gz
 # cd /usr/pkgsrc/net/mikutter
 # make install


今年これまで
~~~~~~~~~~~~~~~~~~~~~

* NetBSD8.0に向けて ... NetBSD7.1
* 好きとか嫌いとか最初にUEFIを言い出したのは誰なのかしら
* gcc version 5.4.0
* 国内のソフトウェアをpkgsrcで紹介(mikutter/mlterm/..
* RPI & ARM .. OSCごとにイメージファイルリリース
* ftp://ftp.netbsd.org/pub/NetBSD/misc/jun/raspberry-pi/
* ftp://ftp.netbsd.org/pub/NetBSD/misc/jun/hpcmips
   ニューヨークでなぜかNetBSD/hpcmips on IBM Z50が

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

 オープンソースカンファレンス2017 Tokyo/Spring NetBSDブース展示の記録,https://togetter.com/li/1089005,830
 AsiaBSDCon 2017の記録,https://togetter.com/li/1084357,2654
 オープンソースカンファレンス2017 Hamanako NetBSDブース展示の記録,https://togetter.com/li/1080372,662
 オープンソースカンファレンス2017 Osaka NetBSDブース展示の記録,https://togetter.com/li/1075115,835
 BIG Raspberry JAM Tokyo 2016 NetBSDブース展示の記録,https://togetter.com/li/1058231,916
 オープンソースカンファレンス2016 Hiroshima NetBSDブース展示の記録,https://togetter.com/li/1053125,1333
 オープンソースカンファレンス2016 Fukuoka NetBSDブース展示の記録,https://togetter.com/li/1050258,397
 関西オープンソース2016 NetBSDブース展示の記録,https://togetter.com/li/1047263,1450
 オープンソースカンファレンス2016 Tokyo/Fall NetBSDブース展示の記録,https://togetter.com/li/1044981,1492
 オープンソースカンファレンス2016 Nagaoka NetBSDブース展示の記録,https://togetter.com/li/1031383,476
 オープンソースカンファレンス2016 Shimane NetBSDブース展示の記録,https://togetter.com/li/1028314,934
 オープンソースアンカンファレンス2016 Kanazawa NetBSDブース展示の記録,https://togetter.com/li/1017308,792
 セキュリティ・キャンプ全国大会2016「謎マシンでNetBSDのクロス開発体験」の記録,https://togetter.com/li/1013466,1576
 オープンソースカンファレンス2016 Kyoto NetBSDブース展示の記録,https://togetter.com/li/1005828,2980
 日本NetBSDユーザーグループ第十八回定期総会 および NetBSD BoF 2016 の記録,https://togetter.com/li/997708,1091
 オープンソースカンファレンス2016 Okinawa NetBSDブース展示の記録,https://togetter.com/li/995155,927
 オープンソースカンファレンス2016 Hokkaido NetBSDブース展示の記録,https://togetter.com/li/988853,1026
 オープンソースカンファレンス2016 Nagoya NBUG & NetBSDブース展示の記録,https://togetter.com/li/980383,1297
 オープンソースカンファレンス2016 Gunma NetBSDブース展示の記録,https://togetter.com/li/975036,1034
 AsiaBSDCon 2016の記録,https://togetter.com/li/947029,3405
 オープンソースカンファレンス2016 Tokyo/Spring NetBSDブース展示の記録,https://togetter.com/li/943037,2070
 オープンソースカンファレンス2016 Hamanako NetBSDブース展示の記録,https://togetter.com/li/929091,1270

今後のOSC参加予定
~~~~~~~~~~~~~~~~~~
#. OSCの参加者総数70,585人→77,550人 (+6965人)
#. 延べ参加グループ数4,044グループ→4,540グループ (+496グループ)
#. OSC2017東京春までで通算128/142参加  = 90.1%
#. *http://www.jp.NetBSD.org/* を見る
#. イベントページをクリックするとFacebookページへ。

.. csv-table::

    2017年4月15日 - オープンソースアンカンファレンス2017 川越
    2017年5月27日 - オープンソースカンファレンス2017 Nagoya & Nbug2017/5例会
    2017年6月17日 - オープンソースカンファレンス 2017 Okinawa
    2017年7月8日 - 日本NetBSDユーザーグループ第十九回定期総会およびNetBSD BOF 2017
    2017年7月14日 - オープンソースカンファレンス2017 Hokkaido
    2017年8月4日 - オープンソースカンファレンス2017 Kyoto

2017/4/15 川越
~~~~~~~~~~~~~~~~~~~~~~~~~~~~

* OSCのプロが集う何か
* ハードオフ
* coedo: 香麦(しゃんまい）バス停福田
* coedo: エレバート 埼玉県川越市仲町6-4
* ホワイト餃子
* 小川町：麦雑穀工房 小川町 水～土15:00～19:30　日11:00～18:30

2017/5/27 名古屋
~~~~~~~~~~~~~~~~~~~~~~~~~~~~

* 今年も吹上ホール
* OpenBSD/Luna88K+CBUS PC98グラフィックカード2画面
* ワイマーケット＆三八屋＆23tap&ヒンメル

2017/6/17 沖縄
~~~~~~~~~~~~~~

* 場所は旭橋：AKB総選挙とかぶっている
* 新しいネタを入れるときは沖縄から
* 琉球大学枠&やまじゅんさんPCBSD
* 五十嵐さん＆りえしょんのDVDをとらのあなに買いにいかんと
* 麦 baku

2017/7/8 定期総会
~~~~~~~~~~~~~~~~~~~~~~~~~~~~

* 日本NetBSDユーザーグループ第十九回定期総会 および NetBSD BoF 2017
* 東大本郷で今日は一日NetBSD三昧
* ねこがいなくなったんです。


2017/7/14 北海道
~~~~~~~~~~~~~~

* LOCALに訊け!
* さらばYK無線 - 2017/2月に閉店
* NoBUGガジェット群
* ジャンク屋:写真店：ハードオフ
* FML深町さん
* さいとさんの店
* さくら石狩データセンター
* クリプトン
* モルトヘッズ(オリジナルラブML元管理人


2017/8/4-5 京都
~~~~~~~~~~~~~~~~~~

* よしだともこ先生を大いに盛り上げるLunaの会
* mikutterの本場
* だいこん→バンガロー→和知→京都醸造
* グフこそ男のお好み焼きだ！フラウボウ募集中

2017/8/14-18 セキュリティキャンプ
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

* 8.16 午後府中某所


2017/9 島根？
~~~~~~~~~~~~~~~~~~

* SONY NEWS祭り
* Rubyの郷:発表15分/サンライズ/飛行機/岡山経由か鳥取経由か
* Sony NEWSがたくさんある大学が鳥取にある
* ゼネラルプロダクツ
* 国際宇宙生物研究所＆エスパーク


2017/10　東京秋
~~~~~~~~~~~~~~~~~

* 東京
* 日程未定？
* BSDなひととき


2017/11/10-11 KOF
~~~~~~~~~~~~~~~~~~~~

* BSDなひととき(発表者募集
* 「そんな先のことはわからない」(CV:銀河万丈/9話予告)
* 図書販売コーナー推薦本募集：UNIXUser 藤田さん本
* 順記で餃子/だまれトリ！/marca/僕とイヌ/カミカゼ

2017/? 広島?
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

* 年間最重要イベント：X68K＆mlterm特集
* XM6i祭り
* X68060祭り
* ビールスタンド重富で重富注ぎ！

2017/? 福岡
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

* 一年の終わり
* PADDY

2018/3 AsiaBSDCon
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

* たぶん2018/3/7-10
* BSD関連の国際会議 150人規模
* sendmail作った人とかにシールを渡してみる
* BSD作った人とかにシールを渡してみる
* スポンサーは常に募集中（-毎年100万くらい赤字
* イベント運営を手伝ってくれそうな実直な企業募集
* www.bsdresearch.org
* FreeBSDワークショップ　のとき打ち合わせしてます
* https://www.ospn.jp/press/20170327jnbdug_column.html

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

* 2017/8 幕張
* NetBSDで4時間もなんかやるかも。
* 枠30人：対象:友利奈緒
* RPI 20台
* のこり10人は謎マシン枠
* 「信じて送り出した家電製品がNetBSDのプロンプトを出すわけがない。」

