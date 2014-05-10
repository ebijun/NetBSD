.. 
 Copyright (c) 2013-4 Jun Ebihara All rights reserved.
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

川越よ私は帰ってきたOSC後半戦への展望
----------------------------------------------
| 日本NetBSDユーザーグループ
| 蛯原　純
| jun@soum.co.jp

NetBSD
~~~~~~~~
 NetBSDは１個のソースツリーをコンパイルすることで実行イメージを作ることができます。目についたハードウェアの情報をCVSに記録してBSD系UNIX上で動かしてみたい。

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

* NetBSD7.0に向けて
* 国内のソフトウェアをpkgsrcで紹介
* X11 drmkms
* RPI & ARM .. OSCごとにイメージファイルリリース
* ftp://ftp.netbsd.org/pub/NetBSD/misc/jun/raspberry-pi/2014-05-10-earmhf
* http://mail-index.netbsd.org/port-arm/2014/05/09/msg002407.html 

togetterのview数でみるNetBSDブースこの一年
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. csv-table::

 AsiaBSDCon 2014の記録,http://togetter.com/li/641519,1826,参考記録
 オープンソースカンファレンス2013広島　NetBSDブース展示の記録,http://togetter.com/li/573243,1497,X68K&LUNA
 オープンソースカンファレンス2013島根 NetBSDブース展示の記録,http://togetter.com/li/553529,1334,LUNA&NEWS&JavaStation
 オープンソースカンファレンス2014浜名湖　NetBSDブース展示の記録,http://togetter.com/li/645455,1299,Netwalker実験所 
 オープンソースカンファレンス2013北海道　NetBSDブース展示の記録,http://togetter.com/li/563719,1280,クリプトンの方から差し入れが！
 関西オープンソース2013 NetBSDブース展示の記録,http://togetter.com/li/587422,1103,LUNA
 オープンソースカンファレンス2013東京秋　NetBSDブース展示の記録,http://togetter.com/li/578893,1028,Netwinder
 オープンソースアンカンファレンス2014香川　NetBSDブース展示の記録,http://togetter.com/li/654135,720,HP9000/425e
 オープンソースカンファレンス2014東京春　NetBSDブース展示の記録,http://togetter.com/li/635747,687,OSC第1回アワード！
 オープンソースカンファレンス2013福岡　NetBSDブース展示の記録,http://togetter.com/li/590835,654,らこらこシールwith本体 
 オープンソースカンファレンス2013大分　NetBSDブース展示の記録,http://togetter.com/li/593833,616,baserCMS
 関東LibreOfficeオフラインミーティング(#10) の記録,http://togetter.com/li/591904,588,小野寺さん

今後のOSC参加予定
~~~~~~~~~~~~~~~~~~
#. *http://www.jp.NetBSD.org/* を見る
#. イベントページをクリックするとFacebookページへ。

.. csv-table::

 2014年5月10日,Open Source UN-Conference 2014 川越
 2014年5月24日,オープンソースカンファレンス2014 Okinawa
 2014年6月13日,オープンソースカンファレンス2014 Hokkaido
 2014年7月4日,オープンソースカンファレンス2014 Nagoya
 2014年7月12日,日本NetBSDユーザーグループ第十六回定期総会 および NetBSD BoF 2014（仮
 2014年8月1日,オープンソースカンファレンス2014 Kansai@Kyoto
 2014年8月23日,オープンソースカンファレンス2014Shimane
 2014年9月20日,オープンソースカンファレンス2014Hiroshima
 2014年11月8日,関西オープンフォーラム2014（KOF2014）


2014/5 沖縄
~~~~~~~~~~~~~~

* 参加イベント通算150回目! 
* https://github.com/ebijun/NetBSD/blob/master/Guide/allevents.rst
* 海水浴場脇
* 新しいネタを入れるときは沖縄から
* 琉球大学枠&FreeBSD勉強会&Contao神戸さん&PCBSD
* 五十嵐さん＆りえしょんのDVDをとらのあなに買いにいかんと
* アメリカンNo.1
* 麦 baku


2014/6 北海道
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

2014/7 名古屋
~~~~~~~~~~~~~~~~~~~~~~~~~~~~

* NBUG本拠地近くで開催
* Luna68K&88K
* Netwalker実験所 
* 小江戸、尾張に立つ
* ワイマーケット＆三八屋＆菊井かつ

2014/7 定期総会
~~~~~~~~~~~~~~~~~~~~~~~~~~~~

* 日本NetBSDユーザーグループ第十六回定期総会 および NetBSD BoF 2014（仮
* 東大本郷で今日は一日NetBSD三昧

2014/8 京都
~~~~~~~~~~~~~~~~~~

* よしだともこ先生を大いに盛り上げるLuna68Kの会
* mikutterの本場
* 今日現在の参加グループが特濃
* eclipscopeとは何か
* だいこん＆和知

2014/8 島根
~~~~~~~~~~~~~~~~~~

* SONY NEWS祭り
* Rubyの郷:発表15分/サンライズ/飛行機/岡山経由か鳥取経由か
* Sony NEWSがたくさんある大学が鳥取にある
* ゼネラルプロダクツ
* 国際宇宙生物研究所＆エスパーク

2014/9 広島
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

* 年間最重要イベント：X68K＆mlterm特集
* XM6i祭り
* X68060祭り
* ビールスタンド重富で重富注ぎ！

2014/11 KOF
~~~~~~~~~~~~~~~~~~~~

* BSDなひととき(発表者募集
* 「そんな先のことはわからない」(CV:銀河万丈/9話予告)
* 図書販売コーナー推薦本募集
* 順記で餃子

NetBSD関連情報
~~~~~~~~~~~~~~~~~

* http://www.NetBSD.org/
* http://www.jp.NetBSD.org/
* http://www.facebook.com/NetBSD.jp/

詳しくは
~~~~~~~~~~~~~~~~~

* 「なぜNetBSD」で検索
