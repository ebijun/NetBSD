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

.. イメージファイルは圧縮すること

OSC後半戦への展望
----------------------------------------------
| 日本NetBSDユーザーグループ
| 蛯原　純
| jun@soum.co.jp

NetBSD
~~~~~~~~
 NetBSDは１個のソースツリーをコンパイルすることで実行イメージを作ることができます。

ソースコードから作る
""""""""""""""""""""

::

 # ftp ftp://ftp.netbsd.org/pub/NetBSD/NetBSD-current/tar_files/src.tar.gz
 # tar xzvf src.tar.gz
 # ./build.sh -U -m i386 release     .... -U:root以外で作成,i386向け

pkgsrc - ソースコードからソフトウェアを作る
""""""""""""""""""""""""""""""""""""""""""""

::

 # cd /usr
 # ftp://ftp.netbsd.org/pub/NetBSD/NetBSD-current/tar_files/pkgsrc.tar.gz
 # tar xzvf pkgsrc.tar.gz



今年これまでのテーマ
~~~~~~~~~~~~~~~~~~~~~
* 「ワークステーション及びUNIX文化が導入された時代」
* 何ができて何ができていなかったのか
* 今年まとめないともう間に合わない
* mikutter/mlterm...
* RPI & ARM .. OSCごとにイメージファイルリリース
 ftp://ftp.netbsd.org/pub/NetBSD/misc/jun/raspberry-pi/

今後のOSC参加予定
~~~~~~~~~~~~~~~~~~
#. *http://www.jp.NetBSD.org/* を見る
#. イベントページをクリックするとFacebookページへ。

2013/8
~~~~~~~
島根
 Rubyの郷:発表15分/サンライズ/飛行機/岡山経由か鳥取経由か
鳥取
 Sony NEWSがたくさんある大学がある
展示/特集
 NEWS特集?:Ruby:RPI:発表されるものをNetBSDで動かす

#.    2013年8月17日 - Open Source UN-Conference 川越
#.    2013年8月24日 - オープンソースカンファレンス2013 Shimane
#.    2013年8月31日 - 名古屋*BSDユーザグループ(NBUG)2013/8月例会

2013/9
~~~~~~~~
北海道
 LOCAL:ジャンク屋:写真展：深町さん:FML:さいとさん
展示/特集
 深町さん：NetBSDと教育/RPI+α

#.    2013年9月14日 - オープンソースカンファレンス2013Hokkaido
#.    2013年9月21日 - 名古屋*BSDユーザグループ(NBUG)2013/9月例会

2013/10
~~~~~~~~~~
広島
 年間最重要イベント：X68K＆mlterm特集
東京
 BSDなひととき：ARM組み込みボード：発表ネタ募集

#.    2013年10月6日 - オープンソースカンファレンス2013Hiroshima
#.    2013年10月19日 - オープンソースカンファレンス2013 Tokyo/Fall
#.    2013年10月26日 - 名古屋*BSDユーザグループ(NBUG)2013/10月例会

2013/11
~~~~~~~~~
KOF
 BSDなひととき：シャープ特集　X68K,ZAURUS,Netwalker
福岡
 CMS特集：NetBSDでCMSを全部動かす
大分
 組み込みボード：評価ボード特集(K!O!B!O!)

#.    2013年11月8日 - 関西オープンフォーラム2013（KOF2013）
#.    2013年11月16日 - オープンソースカンファレンス2013 Fukuoka
#.    2013年11月23日 - オープンソースカンファレンス2013 Oita


オープンソースカンファレンスこの一年
----------------------------------

.. csv-table::

 OSC2013京都 NetBSDブース展示の記録 ,1381 view , Luna+mlterm-fb+mikutter
 名古屋*BSDユーザグループ(NBUG)2013/7月例会の記録 ,255 view,
 日本NetBSDユーザーグループ第十五回定期総会,546 view,NetBSD BOF
 OSC2013沖縄 NetBSDブース展示の記録 , 546 view,深町さん ちゃんおぷ
 OSC2013名古屋NBUG&NetBSDブース展示の記録 ,1290 view,Luna88K&Luna68K
 名古屋*BSDユーザグループ(NBUG)2013/5月例会の記録 ,277 view,XM6i 画面スクロールでもNetBSD/x68kスライドショー
 NetBSDでuARM, 846 view, uARM
 名古屋*BSDユーザグループ(NBUG)2013/4月例会の記録 ,395 view,send-prしてみた
 名古屋*BSDユーザグループ(NBUG)2013 花見の記録 ,338 view ,BSD鍋
 名古屋*BSDユーザグループ(NBUG)2013/3月例会の記録, 441 view,JAIST合格記念発表
 NetBSD/sparcをQEMUで動かす会の記録, 766 view,QEMU/sparc
 AsiaBSDCon 2013の記録 ,1353 view,KOBO全部くれ攻撃
 OSC2013徳島 NetBSDブース展示の記録 ,837 view,丹下桜様にNetBSDブース&mikutterご紹介
 OSC2013 東京春 NetBSDブース展示の記録 ,804 view,ubootする黄旗ZAURUS
 名古屋*BSDユーザグループ(NBUG)2013/2月例会の記録,393 view,luna68kと88kとbigNEWSが
 OSC2013 浜松 NetBSDブース展示の記録,525 view,NetBSD/RPI
 名古屋*BSDユーザグループ(NBUG)2013/1月例会の記録,474 view,ておくれ6.0.1+mikutter 0.2.1
 名古屋*BSDユーザグループ(NBUG)2012/12月例会の記録,503 view,薩摩で焼肉忘年会
 OSC2012 福岡 NetBSDブース展示の記録,729 view,Doc-Ja&NetWalker+mikutter
 名古屋*BSDユーザグループ(NBUG)2012/11月例会の記録,896 view,NetWalker+mikutter
 関西オープンソース2012 NetBSDブース展示の記録,945 view,XM6i
 OSC2012 会津 NetBSDブース展示の記録,1772 view,mikutterシール評議会開催
 OSC2012 大分秋 NetBSDブース展示の記録,613 view,KOBO&OpenBlocks
 OSC2012 広島 NetBSDブース展示の記録,3076 view,all that X68000!
 名古屋*BSDユーザグループ(NBUG)2012/10月例会の記録,435 view,RPI来る
 名古屋*BSDユーザグループ(NBUG)2012/9 例会の記録,474 view,納屋橋夜イチ
 OSC2012沖縄 NetBSDブース展示の記録,411 view,NetBSD/i386 6.0_RC2ておくれ,XM6iシンセ
 OSC2012 東京秋 NetBSDブース展示の記録,1742 view,OpenBlocksA6&KOBO
 OSC2012 島根 NetBSDブース展示の記録,926 view,ておくれへようこそ 6.0_RC1
 名古屋*BSDユーザグループ(NBUG)2012/8 例会の記録,669 view,XCAST rubyライブラリ
 OSC2012 京都 NetBSDブース展示の記録,2501 view,NetBSD/luna68k LUNAII
 名古屋*BSDユーザグループ(NBUG)2012/7 例会の記録,1369 view,FreeBSD XCAST
 OSC2012 仙台 NetBSDブース展示の記録,634 view,NetBSD/RPI
 日本NetBSDユーザーグループ第十四回定期総会 および NetBSD BoF 2012,951 view,epoc32



