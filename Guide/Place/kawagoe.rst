.. 
 Copyright (c) 2013-8 Jun Ebihara All rights reserved.
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

川越よ私は帰ってきたOSC2018NetBSDブースの展望
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

* NetBSD8.0に向けて ... NetBSD7.1.2
* 好きとか嫌いとか最初にUEFIを言い出したのは誰なのかしら
* gcc version 6.4.0 
* OpenSSL 1.1.0g 
* 国内のソフトウェアをpkgsrcで紹介(mikutter/mlterm/..
* RPI & ARM .. OSCごとにイメージファイルリリース
* ftp://ftp.netbsd.org/pub/NetBSD/misc/jun/raspberry-pi/
* RPI3B+ 無線LAN有線LANまだ使えてない
* aarch64... arm64対応

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

 AsiaBSDCon 2018の記録,https://togetter.com/li/1206515,1755
 Raspberry Jam Big Birthday Weekend 2018 in TOKYO NetBSDブース..,https://togetter.com/li/1204795,458
 オープンソースカンファレンス2018 Tokyo/Spring NetBSDブース展示の記録,https://togetter.com/li/1202581,690
 オープンソースカンファレンス2018 Hamanako NetBSDブース展示の記録,https://togetter.com/li/1198246,549
 オープンソースカンファレンス2018 Osaka NetBSDブース展示の記録,https://togetter.com/li/1193730,853
 オープンソースカンファレンス2017 Hiroshima NetBSDブース展示の記録,https://togetter.com/li/1175260,913
 関西オープンソース2017 NetBSDブース展示の記録,https://togetter.com/li/1170068,851
 オープンソースカンファレンス2017 Nagaoka NetBSDブース展示の記録,https://togetter.com/li/1165451,343
 オープンソースカンファレンス2017 Shimane NetBSDブース展示の記録,https://togetter.com/li/1160781,584
 オープンソースカンファレンス2017 Fukuoka NetBSDブース展示の記録,https://togetter.com/li/1158733,424
 オープンソースカンファレンス2017 Tokyo/Fall NetBSDブース展示の記録,https://togetter.com/li/1148810,1259
 オープンソースカンファレンス2017 Chiba NetBSDブース展示の記録,https://togetter.com/li/1146818,509
 セキュリティ・キャンプ全国大会2017「信じて送り出した家庭用ルータがNetBSDにドハマリしてloginプロンプト..,https://togetter.com/li/1140652,2947
 オープンソースカンファレンス2017 Kyoto NetBSDブース展示の記録,https://togetter.com/li/1136708,2214
 オープンソースカンファレンス2017 Hokkaido NetBSDブース展示の記録,https://togetter.com/li/1130009,991
 日本NetBSDユーザーグループ第十九回定期総会 および NetBSD BoF 2017 の記録,https://togetter.com/li/1127726,838
 オープンソースカンファレンス2017 Okinawa NetBSDブース展示の記録,https://togetter.com/li/1120958,990
 オープンソースカンファレンス2017 Nagoya NBUG & NetBSDブース展示の記録,https://togetter.com/li/1114389,1450
 オープンソースカンファレンス2017 Tokyo/Spring NetBSDブース展示の記録,https://togetter.com/li/1089005,1505
 AsiaBSDCon 2017の記録,https://togetter.com/li/1084357,4300

今後のOSC参加予定
~~~~~~~~~~~~~~~~~~
#. OSCの参加者総数77,550人→84,023人 (+6473人)
#. 延べ参加グループ数4,540グループ→5,007グループ (+467グループ)
#. OSC2017東京春までで通算141/155参加  = 90.9%
#. *http://www.jp.NetBSD.org/* を見る
#. イベントページをクリックするとFacebookページへ。

.. csv-table::

 2018年4月14日 - Open Source UN-Conference 2018 Kawagoe
 2018年5月19日 - オープンソースカンファレンス2018 Nagoya
 2018年6月16日 - オープンソースカンファレンス2018 Okinawa
 2018年7月6日 - オープンソースカンファレンス2018 Hokkaido
 2018年7月14日 - 日本NetBSDユーザーグループ第二十回定期総会およびNetBSD BOF 2018
 2018年8月3日 - オープンソースカンファレンス 2018 Kyoto

2018/4/14 川越
~~~~~~~~~~~~~~~~~~~~~~~~~~~~

* 月がきれい: 氷川神社　氷川橋
* OSCのプロが集う何か
* coedo: 香麦(しゃんまい）バス停福田
* coedo: エレバート 埼玉県川越市仲町6-4
* 小川町：麦雑穀工房 小川町 水～土15:00～19:30　日11:00～18:30

2018/5/19 名古屋
~~~~~~~~~~~~~~~~~~~~~~~~~~~~

* 今年も吹上ホール
* OpenBSD/Luna88K+CBUS PC98グラフィックカード2画面
* ワイマーケット＆三八屋&TRUNK

2018/6/16 沖縄
~~~~~~~~~~~~~~

* 場所はコンベンションホール：AKB総選挙とかぶってない
* 新しいネタを入れるときは沖縄から
* 琉球大学枠&やまじゅんさんPCBSD
* 五十嵐さん＆りえしょんのDVDをとらのあなに買いにいかんと
* 麦 baku

2017/7/6 北海道
~~~~~~~~~~~~~~

* LOCALに訊け!
* YK無線,PCNET,毎日自販機,ガード下ジャンク閉店
* ハンズ移転→三谷ビルアダノンキとかも移転
* NoBUGガジェット群
* ジャンク屋:写真店：ハードオフ
* FML深町さん
* さいとさんの店
* さくら石狩データセンター
* クリプトン
* モルトヘッズ(オリジナルラブML元管理人


2018/7/14 定期総会
~~~~~~~~~~~~~~~~~~~~~~~~~~~~

* 日本NetBSDユーザーグループ第二十回定期総会 および NetBSD BoF 2018
* 東大本郷で今日は一日NetBSD三昧
* ねこがいなくなったんです。


2018/8/3-4 京都
~~~~~~~~~~~~~~~~~~

* よしだともこ先生を大いに盛り上げるLunaの会
* mikutterの本場
* だいこん→バンガロー→和知→京都醸造
* グフこそ男のお好み焼きだ！フラウボウ募集中

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


2018/11 KOF
~~~~~~~~~~~~~~~~~~~~

* BSDなひととき(発表者募集
* 「そんな先のことはわからない」(CV:銀河万丈/9話予告)
* 図書販売コーナー推薦本募集：satさん本/NEW GAME!
* 順記で餃子/だまれトリ！/marca/僕とイヌ/カミカゼ

2018/? 広島?
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

* 年間最重要イベント：X68K＆mlterm特集
* XM6i祭り
* X68060祭り
* ビールスタンド重富で重富注ぎ！

2017/? 福岡
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

* 一年の終わり
* PADDY

2019/3 AsiaBSDCon
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

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

* 呼ばれたら行く
* NetBSDで4時間もなんかやるかも。
* 枠30人：対象:友利奈緒
* RPI 20台
* のこり10人は謎マシン枠
* サブタイトル募集：
* 例）「信じて送り出した家電製品がNetBSDのプロンプトを出すわけがない。」

