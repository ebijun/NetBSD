ルナ式練習帳、またはLunaの薄い本2013　
======================================

  「私が誰かは わかっているはずだ。」その声は天使の声だった。
       --- さまよえる天使 [#ma1]_ [#ma2]_ バーナード マラマッド [#ma3]_

OMRON LUNA
~~~~~~~~~~
 オムロン株式会社が1990年代初めに発売していたワークステーション。

トラック一台分
~~~~~~~~~~~~~~
 引越しのため、収集していた古いワークステーションを廃棄している（しようとしている）ところです。そんななか、希少マシン？はNetBSDの移植に使用されていることを知り、事務局様を通じて、junk-jaへのポストをお願いしました。 [#lu4]_

SX-9100
~~~~~~~~~
 1987年発表 for ∑プロジェクト

LUNA68K [#lu6]_
~~~~~~~~~~~~~~~~~~
#. 1989年発表 MC68030 20MHz
#. UNIOS-B - 4.3BSD
#. UNIOS-U - SVR2+4.3BSD統合
#. UNIOS-∑ - ∑


LUNA88k　[#lu3]_
~~~~~~~~~~~~~~~~~

#. モトローラRISC CPU MC88100(m88k)を採用
#. マルチCPU対応(最大4つ)
#. PC-98用バス対応
#. OpenBSDはm88kの実機とtoolchainがメンテナンスされている唯一のBSD

NetBSD/luna68Kの課題 [#lu6]_
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
2種類のブート方法：
#. PROMがUNIOS-B /a.outをロードする
#. PROMが独自プロトコルでサーバからカーネルロード

* NetBSD1.5以降 m68kはELFフォーマット移行：どうやって起動するか
* 実機がないままソースツリーはメンテされ続ける

LUNA68Kのブートローダー
~~~~~~~~~~~~~~~~~~~~~~~
 なんか出た。これでデバッグできる [#lu1]_

電源問題
~~~~~~~~
 壊れる電源は壊れる。



LUNA年表
~~~~~~~~~
青：
　あおやまさん

.. csv-table::
 :widths: 7 3 60

 1987,∑,SX-9100 オムロンから発表
 1989,オ,SX-9100/DT LUNA MC68030 20MHz
 1994, , 4.4BSD Lite luna68K
 1999/12, ,NetBSD/news68kマージ
 2000/1/6, ,NetBSD/luna68kマージ
 2000/08,青,LUNA-88K2入手
 2001/12,青,LUNAにOpenBSD移植決意
 2002/01/27,青,OpenBSD/sparc上でm88kクロス環境構築
 2002/03/29,青,シリアルコンソールでカーネルCopyright表示
 2002/06/05,青,network bootでIPアドレス取得
 2003/08,青,コンパイラのバグがなおったようなので再開
 2003/09/20,青,tarのオプションを間違えてソース消去、CVS導入
 2003/10/05,青,なんとかもとの状態に戻る
 2003/12/10,青,NFS rootでシングルユーザ＆マルチユーザ
 2003/12/10,青,NFS rootでシングルユーザ＆マルチユーザ
 2004/02/17,青,SCSI動作
 2004/03/21,青,Miod Vallatさん(OpenBSD/mvme88kのport maintainer)に見つかる
 2004/04/21,青, OpenBSD本家treeにcommit
 2004/11/01,青, OpenBSD 3.6: 初の正式リリース
 2007/08/31,青, LUNA-88K2の電源ユニット故障により起動できなくなる
 2011/7,筒,OSC2011Kansai@KyotoでLUNA展示
 2011/08,青,ご好意により、オムロンで発掘されたLUNA-88Kが届く
 2011/08/15,青, 上記LUNA-88Kの電源ユニットを移植して復活
 2012/05/01,青, OpenBSD 5.1: 久しぶりの正式リリース
 2012/02/28,青,10年目にして一応マルチプロセッサ対応
 2013/01,青, OpenBSD m88k portのELF化&共有ライブラリ化
 2013/04/13,青, Monochrome X serverが動作
 2013/06/22,青, OSC 2013 Nagoyaで初展示


----

　@tsutsuii LUNAの薄い本2013作れってことすね [#lu0]_

----

 Sometimes you get so lonely / Sometimes you get nowhere / I've lived all over the world / I've left every place / Please be mine / Share my life / Stay with me / Be my wife [#be]_

----

メモリ64M
~~~~~~~~~
 というわけで LUNA-IIの64MB設定でも NetBSD/luna68kカーネル起動した。これでしばらく耐久テストするか… [#lu5]_

----

 「それなら、なぜ、先祖代々の墓を守って山間に生活したがる農民を、ダム工事のためにおいだすんだね？それぞれの人間にそれぞれの幸福がある。それなら、なぜ、彼らを一般化の中に投げ込むんだ。君はなぜ、そういう役割をひきうけるんだ？」 [#san]_

----

.. rubic:: 脚注

.. [#ka] カフカ式練習帳 http://www.bunshun.co.jp/cgi-bin/book_db/book_detail.cgi?isbn=9784163813301
.. [#ma1] The Angel Levine: http://www.blackmovie-jp.com/movie/angellevine.php?act=a#.Uei7I9f75z0
.. [#ma2] Look Back in Anger: http://en.wikipedia.org/wiki/Look_Back_in_Anger_%28song%29
.. [#ma3] バーナード・マラマッドに関する研究 http://www.ishikawa-nct.ac.jp/tech/guide/suzukihp.pdf
.. [#be] Be My Wife: http://en.wikipedia.org/wiki/Be_My_Wife
.. [#san] 高橋和巳『散華』論 -生活人としての大家- ,東口昌央,1988, http://ir.lib.osaka-kyoiku.ac.jp/dspace/handle/123456789/15270
.. [#lu0] https://twitter.com/ebijun/status/231983148118970368
.. [#lu1] NetBSD/luna68kブートローダー実装作業日記,2013/1/4 http://togetter.com/li/433650
.. [#lu2] NetBSDブース @ 関西オープンソース 2011,2011/11/13 http://togetter.com/li/213724
.. [#lu3] OpenBSD/luna88k on LUNA-88K2 http://www.nk-home.net/~aoyama/osc2013nagoya/OpenBSD-luna88k.pdf
.. [#lu4] トラック一台分? http://www.jp.netbsd.org/ja/JP/ml/junk-ja/201301/msg00005.html
.. [#lu5] というわけで https://twitter.com/tsutsuii/status/357219819289985024/photo/1
.. [#lu6] 展示マシン紹介(3) http://www.ceres.dti.ne.jp/tsutsui/osc2011kyoto/
    これだけサーベイ結果を投稿すればLUNAの薄い本も充実するであろう（投げっぱなし作戦）
    @toshi_a LUNA展示の「1989年発売」を見て「まだ生まれてない」と言われるのには動揺せず説明を続けられるようになりました……
    実際問題として 2011年のOSCでは「Windows95より年下です」というネタを発表する中学生がいてですね……
    （LUNA-IIの生産終了は1996年です）
    個人的に知恵袋パソコンカテゴリ最強の質問 http://detail.chiebukuro.yahoo.co.jp/qa/question_detail/q1132299146 … まだ稼働しているのかがとても気になる
    GOOD DESIGN AWARD http://www.g-mark.org/award/describe/15097 … 価格にマルが一つ足りない
    「マルチRISCワークステーションLUNA‐88K2 - 33MHz MC88100 CPUを最大4個搭載したマルチRISCワークステーションについて」 http://jglobal.jst.go.jp/detail.php?JGLOBAL_ID=200902066730130379 … これも1992年12月でさっきのと同じだから同時進行だったのかな
    MC88110とは http://en.wikipedia.org/wiki/MC88110  "... the MC88110 was ultimately unsuccessful and was used in few systems." 諸行無常
    「MC88110を搭載したワークステーションのハードウェア - 64bits,Superscalerを採用したMC88110 CPUを搭載したワークステーションのハードウェアについて」 http://jglobal.jst.go.jp/detail.php?JGLOBAL_ID=200902068908677809 … 幻のLUNA88K3計画なのだろうか
    @hkloverq 初代LUNAは68030 http://jglobal.jst.go.jp/detail.php?JGLOBAL_ID=200902088071486407 … LUNA-IIが68040ですね
    「マルチプロセッサワークステーションのハードウエア - RISCマルチプロセッサのワークステーションへのインプリメンテーション技術について」 OMRON TECHNICS 1990年07月 実はLUNA88Kの設計のほうがLUNA-IIより先なんですよね
    「68040を搭載したワークステーションLUNA‐IIのハードウェア」 http://jglobal.jst.go.jp/detail.php?JGLOBAL_ID=200902048488142806 … , Omron Tech 31巻 2号 91-97頁, 1991年06月
    古文書に見る現実逃避パワー http://www.re.soum.co.jp/~fukaumi/ml/netbsd/200002/msg00122.html …
    古文書に見る謎の痕跡 http://www.re.soum.co.jp/~fukaumi/ml/netbsd/199806/msg00068.html …
    なぜ山に登るのか http://www.ceres.dti.ne.jp/tsutsui/kof2011/Why-enigmatic-machines.html …
    @ebijun 電源シリーズ http://togetter.com/li/215988  http://togetter.com/li/354562 
    @ebijun http://www.jp.netbsd.org/ports/luna68k/install.html … とか https://gist.github.com/tsutsui/5196134  とかですが netboot の説明を isibootd(8) に合わせて更新するのをさぼっている（ブーメラン）

