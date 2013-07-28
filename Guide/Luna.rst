.. 
 Copyright (c) 2013 Jun Ebihara All rights reserved.
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

ルナ式練習帳、またはLunaの薄い本2013　[1]_
===========================================

  「私が誰かは わかっているはずだ。」その声は天使の声だった。
       --- さまよえる天使 [2]_ [3]_ バーナード マラマッド [4]_

.. image:: Picture/2011/07/16/P1000588.JPG
 :height: 230

.. image:: Picture/2013/06/22/DSC_2130.jpg
 :height: 230

OMRON LUNA
------------
 オムロン株式会社が1990年代初めに発売していたワークステーション。

 「オムロンはインターネットの基礎となるＵＮＩＸにパイオニアとして取り組んできました。最初のマシンは１９８４年に出荷を開始した「スーパーメイト」と言うモトローラ社の６８０００をＣＰＵとして使ったワークステーションでした。、当時サンマイクロシステムズが設立されたばかりで、１０ＭＨｚのチップを使っていましたが、我々は国産の最新の１２．５ＭＨｚのチップを使い、当時の最高速マシンとして登場しました。

 当然ＵＮＩＸを使うと自然にインターネットを使う事になるのですが、ＵＮＩＸそのものが技術者しか使えないものだったため、技術者同士の通信手段として細々と使われていたに過ぎません。 しかし、それでもＵＮＩＸの将来性に気づいていた我々は草の根的にオムロンの中でネットワークを拡大していきました。シグマワークステーション、ＬＵＮＡワークステーションとマシンは進化していきましたが、その一方で「オムロン・インターネット」が着々と規模を拡大していました。 最終的には全国３０個所以上、２０００人が使うネットワークにまで成長しました。 当時はだれもこれが「イントラネット」だと言う意識は無く、ひたすら便利なネットワークとして整備を続けました。もちろん今ではこれが典型的なイントラネットである事は間違いありません。 しかし、この段階では依然として技術者専用の情報インフラでありました。 草の根的な従って統率の無いものでした。」 [50]_

トラック一台分
~~~~~~~~~~~~~~
 引越しのため、収集していた古いワークステーションを廃棄している（しようとしている）ところです。そんななか、希少マシン？はNetBSDの移植に使用されていることを知り、事務局様を通じて、junk-jaへのポストをお願いしました。 [11]_

1985年12月20日
~~~~~~~~~~~~~~~
 SEA設立総会の夜。「1985年12月20日という日付は、日本のソフトウェアの歴史に永久に記録されよう。」(c)岸田さん　「詳しくはシグマせんとのこと」 [54]_

1986年10月
~~~~~~~~~~
 「SIGMA サイドで作っていたオムロンのLUNA マシンは、そのころ，まだ影も形もなかった．わたしがソニーにアドバイスしたマーケティング戦略は，とりあえず最初のロットでできた何十台かのマシンを日本全国の大学の研究者に無料で配って使ってもらうというもの．これもみごとに図にあたったと思います．」 [53]_

SX-9100
~~~~~~~~~
 1987年発表 for ∑プロジェクト [36]_ [51]_
 「札幌Σサブセンターに設置されて、地場企業によるΣ CAI ソフトウエアの開発に利用されていた。」 [52]_

LUNA [13]_ 
~~~~~~~~~~~~~~~~~~
#. 1989年発表 MC68030 20MHz

.. csv-table:: シリーズ構成 [65]_

 ディスクレス,ベーシック,スタンダード,スタンダード,ファイルサーバ,ハイエンド
 DT10      ,DT20/25, DT30/35 , DT32/37 ,DT40/45 ,DT50/55
 4MB       ,4MB    , 4MB     , 8MB     ,4MB     ,8MB
 -         ,70MB   , 100MB   , 100MB   ,172MB   ,172MB
 LAN       ,-      , LAN     , LAN     ,LAN     ,LAN
 ブラック    ,ブラック ,　ホワイト , ホワイト  ,ホワイト  ,ホワイト
 55万円    , 88/103万,115/135万円,140/160万円,165/185万円,190/210万円

* PC98インターフェースはホワイトタイプに装備,DT20/25はオプション
* DT25,35,37は、フロッピーの代わりにテープストリーマ付き

オプション
"""""""""

#. ビットマップボード:モノクロ:2048x1024,1プレーン
#. ビットマップボード:カラー:2048x1024,4プレーン,4096色中16色/16階調同時表示
#. 増設メモリボード:最大4MBx2枚
#. LANボード:イーサネット,チーパネット(DT20/25)
#. PC-98インターフェースボード
#. GPXボード: X.25,GP-1B

UNI-OS [37]_
~~~~~~~~~~~~~~~

UniOS-B 
    Unix4.3BSDを移植したもの。Lunaで稼動。
UniOS-U 
    UnixAT&TSystemV R2.1をベースに4.2BSDの機能等を付加し、移植したもの。Luna、Luna-IIで稼動。
UniOS-Σ 
    ΣOS-VOR1準拠したもの。Luna-Σで稼動。(XXX:Luna-∑という呼び方)
UniOS-Mach 
    Machをベースに移植したもの。Luna-II、Luna-88Kで稼動。 

----
 本校のワークステーションはオムロン株式会社の「ＬＵＮＡ」（DT65及びFS180）というもので、ＣＰＵに「MC68030」（メインメモリー１６ＭＢ）を、基本ソフトウェアに統合化ＯＳ（後述します）である「Unios-U」を採用した高性能なものです。（注釈：ここの部分を読めば、最近のコンピュータの進化が実感できますね） [66]_

LUNAII
~~~~~~~
#. 1991/6
#. 68040を搭載したワークステーションLUNA‐IIのハードウェア
#. 互換性を重視し,CISC CPUを採用したワークステーションについて [21]_
#. カーネル起動問題

LUNA88k　[10]_ 
~~~~~~~~~~~~~~~~~

#. モトローラRISC CPU MC88100(m88k)を採用
#. マルチCPU対応(最大4つ)
#. PC-98用バス対応
#. OpenBSDはm88kの実機とtoolchainがメンテナンスされている唯一のBSD
#. 1992/9 「マルチRISCワークステーションLUNA‐88K2 - 33MHz MC88100 CPUを最大4個搭載したマルチRISCワークステーションについて」 [16]_

omron3
~~~~~~~
 omron3.sp.cs.cmu.edu (オムロン製 LUNA-88k) は 1990年から1997年の間 CMU の日本語コンピュータ環境を提供するべくボランティア達によって運用されてきた計算機です。1997年5月をもって komachi.sp.cs.cmu.edu (Intel Pentium 120Mhz FreeBSD) に役目を引き継ぎ引退しました。  [68]_

OEM版
~~~~~
 「LUNAのシグマOSのやつで日本無線からでていたOEMのワークステーションというやつを使っていたことがあります。なんか日本語フォントがX-Window立ち上げなくても使えたようなおぼろげな記憶。銀座にあったオムロンのセミナー会場で講習をうけたのだけど、そこではOEMでなくて普通のLUNAだったからなんかちがってとまどったような...」 [64]_

21世紀のイベント駆動開発
-----------------------
#. 動きそうなLUNAを探す
#. ハードウェアを整備する
#. ソフトウェアを書くために必要な情報を交換する
#. 行き詰ったらツイッターで相談する
#. 定期的にイベントで展示する
#. 昔使っていた人に直接話を聞く
#. 集めた情報を整理して、公開する

OSC2011Kansai@kyoto 
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
NetBSD/m68k will never die!
 当日いきなりSun/NEWS/Luna展示 [30]_

 2011/7/16のコミットメッセージ [35]_

::

 Revive NetBSD/luna68k.

 Even after almost a lost decade since NetBSD/luna68k was
 switched to using ELF format by default back in 2001,
 actually only one fix (bus.h) is required for a GENERIC kernel itself
 to get multiuser login: prompt on a real hardware.  Hurrahhh!!!
 
 Demonstrated with a working Xorg mono server on the NetBSD booth
 at Open Source Conference 2011 Kansai @ Kyoto:
 http://www.ospn.jp/osc2011-kyoto/
 
 "Very impressed," commented by Tomoko YOSHIDA,
 Program Committee Chair of the Conference,
 and some other OMRON guys.
 
 Special Thanks to Tadashi Okamura, for providing
 a working SX-9100/DT "LUNA" for this mission.

LunaII,Luna88Kが発見される
~~~~~~~~~~~~~~~~~~~~~~~~~~~
* 「オムロンからLUNA88Kが発掘された」from よしだともこ先生 [29]_
* 「LUNA88KはOpenBSD開発者の方へ」→あおやまさんと連絡がとれる
* 「ツイッターで『LUNA-IIはありませんか』とつぶやくと」
* 「ふと、横を見ると『LUNA II』と書いたマシンが。。。」

LunaII対応
~~~~~~~~~~~
#. 同じオペランドで68030と68040で違う命令の罠
#. %tt1 (PA/VA透過変換レジスタ)設定値修正
#. M68040共通部分の修正適用
#. 外付けSCSIアタッチ追加
#. LCD表示を「SX-9100/DT2」に変更

KOF2011
~~~~~~~
* 「NetBSDが謎マシンを動かす理由＝そこに山があるからｗ 」 [24]_
* 「明日11日(金)からのKOFのNetBSDブースで OSC京都のOMRON LUNA展示の後に発見された LUNA-IIで動くNetBSD/luna68k を展示します。」
* 「LUNA資料は手書きだ」
* 「NetBSD/luna68k画面表示の裏でひっそりと活躍する自作LUNA-II内蔵型B/WビデオtoVGA変換。」
* 「「そんなことよりそれはなんだ」と言われそうなLUNAならぬ初代SX-9100 Mr.文具セット。裏によしだ先生サイン(?)入りの貴重品。」

isibootd(8)
~~~~~~~~~~~
 LUNA専用ネットブートサーバープログラムisibootd(8)をNetBSDツリーにコミット。

FPU判別ルーチン
~~~~~~~~~~~~~~~
#. ローエンド、ベーシックタイプは68881
#. サーバータイプは68882

OSC2012Kansai@Kyoto
~~~~~~~~~~~~~~~~~~~~~~
#. NetBSD/luna68k近況 [58]_
#. wsconsコンソールフレームバッファ修正 (OpenBSD/luna88kから)
#. オムロンフォントで表示
#. 電源トラブル：電解コンデンサ全交換
#. PROM起動仕様 HDDから起動する条件調査
#. bootarg問題
#. SSD on LUNA
#. Xorgサーバー

円頓寺LUNAエンカウント
~~~~~~~~~~~~~~~~~~~~~~~
 NBUG2013/2月例会。いきなりLuna68K/Luna88k/BigNEWSがNBUG例会にタクシーで持ち込まれる。「掲示板でLUNA88kをNBUG例会に持ち込もうか聞いている人がいる」と噂になっていたその人だった。 [56]_

OSC2013tokushima
~~~~~~~~~~~~~~~~~~~
#. NetBSDこの20年 [5]_
#. NetBSD/luna68kブートローダー起動展示 [8]_

::

 Modified Files:
        src/sys/arch/luna68k/stand/boot: Makefile conf.c devopen.c init_main.c
            ioconf.c locore.S samachdep.h version
 Added Files:
        src/sys/arch/luna68k/stand/boot: getsecs.c if_le.c lance.c lance.h
 Log Message:
 Add netboot support.
 Based on ews4800mips, mvme68k, and x68k standalone drivers.
 Also bump version.
 Tested on LUNA-I.
 XXX: We really need proper documents about libsa APIs.

OSC2013nagoya
~~~~~~~~~~~~~~~
* あおやまさんと江富さんによるLuna88K/Luna68K完全動態展示 [57]_
* OpenBSD/luna88k開発者あおやまさんによるプレゼンテーション [10]_

LUNAグッズ
----------
* シールとフロッピー [59]_
* たれまく
* ペンセット [60]_

LUNA関連書籍
------------
 UNIXワークステーションがわかる本 [61]_


Project Mach 
--------------
 Project Mach was an operating systems research project of the Carnegie Mellon University School of Computer Science from 1985 to 1994.
 "It's never too late. When it's over, you get to tell the story" -- Garrison Keillor [67]_

* luna88kカーネルソース [71]_

LUNAインストール方法 
~~~~~~~~~~~~~~~~~~~~~
* インストールマニュアル [27]_
* NetBSD/luna68kの起動ディスク作り方メモ [28]_

NetBSD/luna68Kの課題 [13]_
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
2種類のブート方法： [27]_

 #. PROMがUNIOS-B /a.outをロードする
 #. PROMが独自プロトコルでサーバからカーネルロード

* NetBSD1.5以降 m68kはELFフォーマット移行：どうやって起動するか
* 実機がないままソースツリーはメンテされ続ける

PROMモニタ
~~~~~~~~~~
#. newfs -O o で作った4.3BSD形式のFFS上のa.outカーネルは読める。
#. LUNAIIでのネットブートは無理？
#. HDD起動時の制約は？(SCSI ID,カーネルサイズ,ファイルシステム)
#. LUNAIIは外部SCSI HDDから起動できるか

LUNA68Kのブートローダー
~~~~~~~~~~~~~~~~~~~~~~~
#. NetBSD/luna68k の起動ディスクの作り方メモ [28]_
#. なんか出た。これでデバッグできる [8]_

BSD広告条項
~~~~~~~~~~~
 4.4BSD-Lite2由来のコードに含まれる3項目(All advertising materials ..)、広告条項削除OKについて、文書で許可を出してくれるOMRONの方がいらっしゃると2-cluse BSDで配布できる。

電源問題
~~~~~~~~
#. OMRONワークステーション LUNA-II 電源ユニット修理記 [25]_
#. 「KOF本番週の日曜日に電源が不調になり急遽部品手配して展示直前に修理していた」
#. OSC2012京都前に再度補修 [26]_

LUNAII
~~~~~~~
#. 1MB SIMM/4MB SIMM切替→SIMM脇に謎ジャンパが
#. 4bppフレームバッファのX11R5ソースは？
 
----

　@tsutsuii LUNAの薄い本2013作れってことすね [7]_

----

 Sometimes you get so lonely / Sometimes you get nowhere / I've lived all over the world / I've left every place / Please be mine / Share my life / Stay with me / Be my wife [5]_

質問日時:2009/10/28 17:51:08 
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 会社でワークステーション（オムロン製LUNAⅡ）を使用していますが、プリンターが不良となりました。エプソンVP-4000です。中古をさがしていますが、これと互換性のあるプリンターはないでしょうか？ [14]_

LUNA年表
--------
 「次の日からオレとルナ先生の生活がはじまったんだ」 [62]_
青：あおやまさん,江：江富さん,オ：オムロン,筒：筒井さん,モ:モトローラ

.. csv-table:: 
 :widths: 7 3 60

 1987,∑,SX-9100 オムロンから発表
 1988,オ,グッドデザイン賞受賞 [15]_
 1989,オ,SX-9100/DT LUNA MC68030 20MHz
 1989/3,オ,LUNAのハードウエア Omron Tech No.29 p.8-15 [19]_
 1990/7,オ,Luna88k Omron Tech p.81-92 [20]_
 1991/6,オ,LUNA‐II Omron Tech No.31 p. 91-9 [21]_
 1991/11,モ,MC88110の存在が明らかになる [17]_
 1992/12,オ,LUNA‐88K2 Omron Tech No.32 p.336-344 [16]_
 1992/12,オ,MC88110ワークステーション Omron Tech No.32 p.345-350
 1994, , 4.4BSD Lite luna68K [18]_
 1994,オ,LUNA-IIの生産終了
 1998/6, ,NetBSD/luna68k　やってるひと、いますよ。[netbsd 02006] [23]_
 1999/12, ,NetBSD/news68kマージ
 2000/1/6, ,NetBSD/luna68kマージ
 2000/2/18, ,桝田さんluna68k起動成功 [netbsd 05132] [22]_
 2000/08,青,LUNA-88K2入手
 2001/12,青,LUNAにOpenBSD移植決意
 2002/01/27,青,OpenBSD/sparc上でm88kクロス環境構築
 2002/03/29,青,シリアルコンソールでカーネルCopyright表示
 2002/06/05,青,network bootでIPアドレス取得 [69]_
 2003/08,青,コンパイラのバグがなおったようなので再開
 2003/09/20,青,tarのオプションを間違えてソース消去、CVS導入
 2003/10/05,青,なんとかもとの状態に戻る
 2003/12/10,青,NFS rootでシングルユーザ＆マルチユーザ
 2003/12/10,青,NFS rootでシングルユーザ＆マルチユーザ
 2004/02/17,青,SCSI動作
 2004/03/21,青,Miod Vallatさん(OpenBSD/mvme88kのport maintainer)に見つかる [70]_
 2004/04/21,青, OpenBSD本家treeにcommit
 2004/11/01,青, OpenBSD 3.6: 初の正式リリース
 2007/08/31,青, LUNA-88K2の電源ユニット故障により起動できなくなる
 2007/9/5,青, Luna88K捜索願い [nbug:10540]
 2009/10/28, ,Yahoo知恵袋にLUNAIIに関する]質問が [14]_
 2011/07,筒,OSC2011Kansai@KyotoでLUNA/NEWS/Sun3展示 [31]_
 2011/7,筒, NetBSD/luna68k on OMRON LUNA - Bootstrap [37]_
 2011/07,オ, LUNA88Kオムロンにて発掘される！
 2011/08,青,ご好意により、オムロンで発掘されたLUNA-88Kが届く
 2011/08/15,青, 上記LUNA-88Kの電源ユニットを移植して復活
 2011,筒,KOFでLUNA-II展示 [9]_
 2012/05/01,青, OpenBSD 5.1: 久しぶりの正式リリース
 2012/02/28,青,10年目にして一応マルチプロセッサ対応
 2012/08/03,筒,OSC2012関西@京都でLuna&LunaII展示 [32]_
 2013/01,青, OpenBSD m88k portのELF化&共有ライブラリ化
 2013/01/27, ,Luna88k(白と黒) Luna88K2Luna2010を青山さんに送る
 2013/02/16,江, Luna88K&Luna68k&BigNEWSをNBUG例会に持ち込む
 2013/03/09,江,Luna88kをあおやまさんに送る
 2013/03/09,筒,OSC2013徳島でLuna68K展示 [33]_
 2013/03/19,筒,筒井さんから江富さんにLuna68k起動ディスクが送られる
 2013/04/13,青, Monochrome X serverが動作
 2013/06/22,青, Luna88K OSC 2013 Nagoyaで初展示。江富さんのLuna68kも初展示。

それから
--------

メモリ64M
~~~~~~~~~
 というわけで LUNA-IIの64MB設定でも NetBSD/luna68kカーネル起動した。これでしばらく耐久テストするか… [12]_ [34]_

mlterm-fb & tw
~~~~~~~~~~~~~~
 ツイッタークライアント！ [39]_ [40]_ [41]_ [42]_ [43]_ [44]_

老ハード介護問題
~~~~~~~~~~~~~~~~
* 電源修理
* SCSI HDD確保
* ブラウン管を知らない子どもたち
* 液晶接続問題 [63]_
* ハード保守
* 詳しい人がいなくなる

----

 「それなら、なぜ、先祖代々の墓を守って山間に生活したがる農民を、ダム工事のためにおいだすんだね？それぞれの人間にそれぞれの幸福がある。それなら、なぜ、彼らを一般化の中に投げ込むんだ。君はなぜ、そういう役割をひきうけるんだ？」 [6]_

----

脚注
----
 Luna関連コメントは筒井さんに紹介してもらったものです。
.. rubic:: 

.. [1] カフカ式練習帳 http://www.bunshun.co.jp/cgi-bin/book_db/book_detail.cgi?isbn=9784163813301
.. [2] The Angel Levine: http://www.blackmovie-jp.com/movie/angellevine.php?act=a#.Uei7I9f75z0
.. [3] Look Back in Anger: http://en.wikipedia.org/wiki/Look_Back_in_Anger_%28song%29
.. [4] バーナード・マラマッドに関する研究 http://www.ishikawa-nct.ac.jp/tech/guide/suzukihp.pdf
.. [5] Be My Wife: http://en.wikipedia.org/wiki/Be_My_Wife
.. [6] 高橋和巳『散華』論 -生活人としての大家- ,東口昌央,1988, http://ir.lib.osaka-kyoiku.ac.jp/dspace/handle/123456789/15270
.. [7] https://twitter.com/ebijun/status/231983148118970368
.. [8] NetBSD/luna68kブートローダー実装作業日記,2013/1/4 http://togetter.com/li/433650
.. [9] NetBSDブース @ 関西オープンソース 2011,2011/11/13 http://togetter.com/li/213724
.. [10] OpenBSD/luna88k on LUNA-88K2 http://www.nk-home.net/~aoyama/osc2013nagoya/OpenBSD-luna88k.pdf
.. [11] トラック一台分? http://www.jp.netbsd.org/ja/JP/ml/junk-ja/201301/msg00005.html
.. [12] というわけで https://twitter.com/tsutsuii/status/357219819289985024/photo/1
.. [13] 展示マシン紹介(3) http://www.ceres.dti.ne.jp/tsutsui/osc2011kyoto/
.. [14] Yahoo!知恵袋 http://detail.chiebukuro.yahoo.co.jp/qa/question_detail/q1132299146 まだ動いていたのか！人々に勇気を与えた質問。
.. [15] GOOD DESIGN AWARD http://www.g-mark.org/award/describe/15097 … 価格にマルが一つ足りない
.. [16] 「マルチRISCワークステーションLUNA‐88K2 - 33MHz MC88100 CPUを最大4個搭載したマルチRISCワークステーションについて」 http://jglobal.jst.go.jp/detail.php?JGLOBAL_ID=200902066730130379 … これも1992年12月でさっきのと同じだから同時進行だったのかな
.. [17] MC88110とは http://en.wikipedia.org/wiki/MC88110  "... the MC88110 was ultimately unsuccessful and was used in few systems." 諸行無常
.. [18] 「MC88110を搭載したワークステーションのハードウェア - 64bits,Superscalerを採用したMC88110 CPUを搭載したワークステーションのハードウェアについて」 http://jglobal.jst.go.jp/detail.php?JGLOBAL_ID=200902068908677809 … 幻のLUNA88K3計画なのだろうか
.. [19] 「LUNA(デスクトップWS)のハードウエア 従来機に比べて小形化,低価格化を実現したハードウエアについて」 http://jglobal.jst.go.jp/detail.php?JGLOBAL_ID=200902088071486407 
.. [20] 「マルチプロセッサワークステーションのハードウエア - RISCマルチプロセッサのワークステーションへのインプリメンテーション技術について」http://jglobal.jst.go.jp/detail.php?JGLOBAL_ID=200902066853173587 実はLUNA88Kの設計のほうがLUNA-IIより先なんですよね
.. [21] 「68040を搭載したワークステーションLUNA‐IIのハードウェア」 http://jglobal.jst.go.jp/detail.php?JGLOBAL_ID=200902048488142806 … , Omron Tech 31巻 2号 91-97頁, 1991年06月
.. [22] 古文書に見る現実逃避パワー http://www.re.soum.co.jp/~fukaumi/ml/netbsd/200002/msg00122.html …
.. [23] 古文書に見る謎の痕跡 http://www.re.soum.co.jp/~fukaumi/ml/netbsd/199806/msg00068.html 
.. [24] なぜ山に登るのか http://www.ceres.dti.ne.jp/tsutsui/kof2011/Why-enigmatic-machines.html 
.. [25] OMRONワークステーション LUNA-II 電源ユニット修理記 http://togetter.com/li/215988
.. [26] OMRONワークステーション LUNA-II 電源ユニット修理記 その2 http://togetter.com/li/354562 
.. [27] インストール方法 http://www.jp.netbsd.org/ports/luna68k/install.html
.. [28] NetBSD/luna68k の起動ディスクの作り方メモ https://gist.github.com/tsutsui/5196134  とかですが netboot の説明を isibootd(8) に合わせて更新するのをさぼっている（ブーメラン）
.. [29] LUNA88K,オムロンにて発掘される！ http://www.jp.netbsd.org/ja/JP/ml/port-mac68k-ja/201107/msg00011.html
.. [30] Luna88k起動動画 https://twitter.com/ao_kenji/status/353469599871799296 https://twitter.com/ao_kenji/status/353476705521905664
.. [31] "NetBSD/m68k will never die!" http://www.ceres.dti.ne.jp/tsutsui/osc2011kyoto/NetBSD-m68k-will-never-die.html
.. [32] OSC2012京都NetBSDブース展示の記録 http://togetter.com/li/350035
.. [33] OSC2013徳島 NetBSDブース展示の記録 http://togetter.com/li/468577
.. [34] OMRONワークステーションLUNA 工作日記  http://togetter.com/li/535307
.. [35] コミットメッセージ http://mail-index.netbsd.org/source-changes/2011/07/16/msg024675.html
.. [36] ∑プロジェクト http://ja.wikipedia.org/wiki/Σプロジェクト
.. [37] http://ja.wikipedia.org/wiki/Luna_(ワークステーション)
.. [38] NetBSD/luna68k on OMRON LUNA - Bootstrap http://www.youtube.com/watch?v=c1_e-A9Osr0
.. [39]  Twitter timeline on NetBSD/luna68k and mlterm-fb (final) http://www.youtube.com/watch?v=djbEw0G_LMI 2013/5/24
.. [40] mlterm-fb demonstration on NetBSD/luna68k (revised) http://www.youtube.com/watch?v=BP8AIceWgxA 2013/5/18
.. [41] Twitter timeline on NetBSD/luna68k and mlterm-fb (take 4) http://www.youtube.com/watch?v=yKKT_Z1P9Xo 2013/05/04
.. [42] Twitter timeline on NetBSD/luna68k and mlterm-fb (take 3) http://www.youtube.com/watch?v=Cl1CaO5scHY 2013/05/01
.. [43] Twitter timeline on NetBSD/luna68k and mlterm-fb (take 2) http://www.youtube.com/watch?v=8sC5XpK-Hxs 2013/04/29
.. [44] Twitter timeline on NetBSD/luna68k and mlterm-fb http://www.youtube.com/watch?v=nzD0A279mcg 2013/04/27
.. [45] NetBSD/luna68k on OMRON LUNA - Start X.Org http://www.youtube.com/watch?v=NRh60c420Mc 2011/07/30
.. [46] mlterm-fb demonstration on NetBSD/luna68k wsfb console http://www.youtube.com/watch?v=jHU876RexCo 2013/04/25
.. [47] Σワークステーション(SX‐9100)の概要
 http://jglobal.jst.go.jp/public/20090422/200902068890346915 1987/9/30 Omron Tech p.207-213
.. [48] OpenBSD/luna88k on OMRON LUNA-88K2 - bootstrap screen http://www.youtube.com/watch?v=btwiiZw3B2s 2013/07/06
.. [49] OpenBSD/luna88k on OMRON LUNA-88K2 - starting X.org http://www.youtube.com/watch?v=_EUpSpUD0Qw 2013/07/06
.. [50] オムロンのイントラネットの歴史 http://www.masuda.org/intra/rekisi.html
.. [51] 【IT】日本のITの歴史―SONY『NEWS』の戦略(3)（1989-03-20 http://www.miraikeikaku-shimbun.com/article/13282000.html
.. [52] さっぽろコンピュータ博物館 http://www.sec.or.jp/elecen/museum/
.. [53] 歴史的コンピュータとソフトウェアプロジェクトに関する昔話(社外公開版) http://katsu.watanabe.name/doc/comphist/
.. [54] SEA Mail Vol.1 No.1 http://www.sea.jp/office/seamail/1986/1986_1_honan.pdf
.. [55] NetBSDこの20年 http://www.slideshare.net/tsutsuii/osc2013tokushima-net-bsd20th
.. [56] 名古屋*BSDユーザグループ(NBUG)2013/2月例会の記録 http://togetter.com/li/456972
.. [57] OSC2013名古屋 NBUG&NetBSDブース展示の記録 http://togetter.com/li/522396
.. [58] NetBSD/luna68k 近況 http://www.ceres.dti.ne.jp/tsutsui/osc2012kyoto/NetBSD-luna68k-updates.html
.. [59] LUNAシールとフロッピー http://movapic.com/pic/2013062214270151c535a5bd627
.. [60] LUNAペンセットと本 https://twitter.com/tsutsuii/status/135565130372104192
.. [61] UNIXワークステーションがわかる本 (LUNAの本シリーズ) http://www.amazon.co.jp/UNIX%E3%83%AF%E3%83%BC%E3%82%AF%E3%82%B9%E3%83%86%E3%83%BC%E3%82%B7%E3%83%A7%E3%83%B3%E3%81%8C%E3%82%8F%E3%81%8B%E3%82%8B%E6%9C%AC-LUNA%E3%81%AE%E6%9C%AC%E3%82%B7%E3%83%AA%E3%83%BC%E3%82%BA-LUNA%E3%83%A6%E3%83%BC%E3%82%B6%E3%82%B0%E3%83%AB%E3%83%BC%E3%83%97/dp/4526029963
.. [62] いけない!ルナ先生 全５巻 http://www.comicpark.net/readcomic/index.asp?content_id=COMC_AKC01155_SET
.. [63] PS2Linux Kit(Sync on Green)対応モニタ一覧 http://www.ps2linux.dev.jp/monitor.html
.. [64] かやまさん https://www.facebook.com/jun.ebihara.18/posts/692735874076690?comment_id=30643585&offset=0&total_comments=1
.. [65] LUNAのカタログ Holonic Workstation LUNA[マニュアル・データーシート類] http://www.h2.dion.ne.jp/~dogs/collect/ds/luna.html
.. [66] ワークステーション操作入門 http://www.kumamotokokufu-h.ed.jp/kokufu/comp/ws_tx1.html
.. [67] "It's never too late. When it's over, you get to tell the story" -- Garrison Keillor  http://www.cs.cmu.edu/afs/cs/project/mach/public/www/mach.html
.. [68] ピッツバーグ便利帳 サーバーの歴史 http://komachi.sp.cs.cmu.edu/benricho/Komachi#.E3.82.B5.E3.83.BC.E3.83.90.E3.83.BC.E3.81.AE.E6.AD.B4.E5.8F.B2 「1993年、オムロンのワークステーション業務撤退に伴い藤田さんと作業マシン達に突然の引き上げ命令が下りました。」
.. [69] OpenBSD/luna88k「network bootでIPアドレス取得」(2002/06/05)の頃のページ http://t.co/VRxXgWWpTO
.. [70] @ebijun 同じく「Miod Vallatさんに見つかる」(2004/03/21)の頃のページ http://t.co/3QmzWm7reR
.. [71] OMRON Luna88Kについてのまとめ http://t.co/rt5kUB74VG 作者も忘れている説
.. [72] http://www.cs.cmu.edu/afs/cs/project/mach/public/src/mkernel/src/kernel/luna88k/

このページ
~~~~~~~~~~~
 https://github.com/ebijun/NetBSD/blob/master/Guide/Luna.rst にあります。
