.. 
 Copyright (c) 2013-2022 Jun Ebihara All rights reserved.
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

ルナ式練習帳、またはLunaの薄い本2022　[1]_
===========================================

  「私が誰かは わかっているはずだ。」その声は天使の声だった。
       --- さまよえる天使 [2]_ [3]_ バーナード マラマッド [4]_

.. image:: Picture/2011/07/16/P1000588.JPG
 :height: 230

.. image:: Picture/2013/06/22/DSC_2130.jpg
 :height: 230

.. image:: Picture/2013/01/27/DSC_1584.jpg
 :height: 230

.. image:: Picture/2014/07/05/DSC_0230.jpg
 :height: 230

History and Background of LUNA
-------------------------------------

The LUNA hardware had two different operating systems; a 4.3BSD derivative and a SVR3 variant. The first one, named UNIOS-B, was was a port of Integrated Solution Inc. UNIX product. ISI manufactured m68k based VME UNIX boxes. Their OS had an interesting feature of TRFS (Translucent Remote File System) as well as the popular SMI's NFS. The paper of TRFS was published at USENIX Technical Conference (late '80, details unknown in this moment). [174]_

nono - LUNA-I emulator
-------------------------------------

「nono は NetBSD とかで動作する LUNA-I とかのエミュレータです。 でもまだ動きません。」 [167]_

::

 nono 0.0.3 (2020/05/16) 置いときますね。
 http://pastel-flower.jp/~isaki/nono/
 なんちゃってROM用意したので、実機ROMなくても一応起動はすると思う。けど起動しかできないのと、こっからどうしたもんかは追々…。

「nonoさんが実機ROMなしでも起動するようなのでとりあえず最小インストールイメージを置きました」　[168]_

::

 NetBSD/luna68k 9.0 minimam liveimage 20200518版
 http://teokurebsd.org/netbsd/liveimage/20200518-luna68k/

* pkgsrc経由でのnonoインストール

::

 pkgsrc/emulators/nono
 make package-install
 https://gnats.netbsd.org/55761
 https://twitter.com/isaki68k/status/1315996525919518724
 http://www.pastel-flower.jp/~isaki/NetBSD/patch/pkgsrc-nono-20201013.diff
 http://www.pastel-flower.jp/~isaki/NetBSD/patch/nono-20201013.diff
 add /etc/mk.conf
  ACCEPTABLE_LICENSES+= nono-license
 cd /usr/pkgsrc/emulators/nono;make ;make package-install

* nonoからのNetBSD/luna68k liveimage起動 [169]_ 

::

 1) nono-0.1.1 をダウンロード
 https://twitter.com/isaki68k/status/1261646479816404992
 2) 展開して doc/index.html を読んでビルド
 3) liveimage をダウンロードして gunzip
 4) nono.cfg を作って置く
 https://gist.github.com/tsutsui/340546bdc064cee786ed2473fb510463
 5) wx/nono で実行
 6) Emulated ROM上で以下のコマンドを実行
 k
 [enter]
 [enter]
 d
 boot
 g
 x

::

 vmtype=luna
 #ethernet-hostdriver=tap
 #prom-use-rom=0  #外部ROMを指定しなければ内蔵なんちゃってROMで上がるので指定しなくても動く
 #spc0-id6-writeprotect=1 #ディスクライトプロテクト。デモとかで^Cで落とす用。
 spc0-id6-image=hd,liveimage-luna68k-raw-20200518.img


* Luna88Kの起動

 「設定ファイルでvmtype=luna88kにして、O/luna88kのリリースセットの中のboot を-Aオプションで指定とかまでは出来ます。」　[170]_

 「it was made from scratch.」　[171]_

 #OpenBSD/luna88k 6.8-current runs on nono-0.1.4 on #OpenBSD/amd64. Now I can login to virtual luna88k machine! Great! [178]_

 For anyone interested in nono and luna88k, I put OpenBSD/luna88k live image. (990MB gzip'ed, 2.0G uncompressed) Set this image as spc0-id6-image in nono.cfg, and start nono with OpenBSD/luna88k bootloader, i.e. "nono (other options) -A boot" [179]_

::

 #VER=6.8
 VER=snapshots
 ftp https://cdn.openbsd.org/pub/OpenBSD/${VER}/luna88k/miniroot68.fs
 ftp https://cdn.openbsd.org/pub/OpenBSD/${VER}/luna88k/bsd
 ftp https://cdn.openbsd.org/pub/OpenBSD/${VER}/luna88k/bsd.rd
 nono -A bsd.rd

::

 vmtype=luna88k
 #luna-dipsw1=11111111  #ディップスイッチの初期値設定
 #ethernet-hostdriver=tap
 #prom-use-rom=0
 ram-size=64
 spc0-id6-image=hd,spc0-id6-image


 うぇーい、進んだーーー(゜∀゜)ーーー!! [173]_
 MFP通過した。 [175]_
 ROMやっと動いたー( ´Д｀) [180]_

* library_aslr [181]_

 /etc/rc.conf.local に library_aslr=NO と書いておくと reordering libraries をスキップします。 
 起動後であれば、 # rcctl disable library_aslr でも良いです。
 man.openbsd.org/rc.conf

LUNA前夜 - 誕生と再生のためのテーマ
-------------------------------------
 オムロン株式会社が1990年代初めに発売していたワークステーションLUNA。

 「オムロンはインターネットの基礎となるＵＮＩＸにパイオニアとして取り組んできました。最初のマシンは１９８４年に出荷を開始した「スーパーメイト」と言うモトローラ社の６８０００をＣＰＵとして使ったワークステーションでした。、当時サンマイクロシステムズが設立されたばかりで、１０ＭＨｚのチップを使っていましたが、我々は国産の最新の１２．５ＭＨｚのチップを使い、当時の最高速マシンとして登場しました。

 当然ＵＮＩＸを使うと自然にインターネットを使う事になるのですが、ＵＮＩＸそのものが技術者しか使えないものだったため、技術者同士の通信手段として細々と使われていたに過ぎません。 しかし、それでもＵＮＩＸの将来性に気づいていた我々は草の根的にオムロンの中でネットワークを拡大していきました。シグマワークステーション、ＬＵＮＡワークステーションとマシンは進化していきましたが、その一方で「オムロン・インターネット」が着々と規模を拡大していました。 最終的には全国３０個所以上、２０００人が使うネットワークにまで成長しました。 当時はだれもこれが「イントラネット」だと言う意識は無く、ひたすら便利なネットワークとして整備を続けました。もちろん今ではこれが典型的なイントラネットである事は間違いありません。 しかし、この段階では依然として技術者専用の情報インフラでありました。 草の根的な従って統率の無いものでした。」 [50]_

スーパーメイト
~~~~~~~~~~~~~~~~~~~~~~~~~~

LUNAは、SX-9100以降の愛称なんですが、その前のSX-8700 の時代は、スーパーメイトという愛称でした。 [149]_

そしてソースリーディングを開始して約半年後、いよいよオムロン標準の16ビットボード（68000MPU）を改造して68451MMUを追加したボードコンピュータに、UNIXを移植する作業がスタートしました。開発環境は、EXORmacs上のIdrisを用い、移植中のOSのロードモジュールは、RS-232C接続で、実機にダウンロードしました。

そして、AH（アドバンストハード）プロジェクトと合流して開発したのが、68000搭載のUNIXワークステーションSX-8700でした。当時はUNIX System III注19であり、開発環境としてVAX-780上のSystem IIIを使いました。VAXと68000のバイトオーダーが逆だったので苦労しました。このマシンがスーパーメイトという商品名で、1984年春のマイコンショーで、オムロンのコンピュータとして華やかにデビューしたのです。そして間もなく発表されたUNIX System Vを移植し直し、その年の秋に出荷が開始されました。 [150]_

トラック一台分
~~~~~~~~~~~~~~
 引越しのため、収集していた古いワークステーションを廃棄している（しようとしている）ところです。そんななか、希少マシン？はNetBSDの移植に使用されていることを知り、事務局様を通じて、junk-jaへのポストをお願いしました。 [11]_

1985年12月20日
~~~~~~~~~~~~~~~
 SEA設立総会の夜。「1985年12月20日という日付は、日本のソフトウェアの歴史に永久に記録されよう。」(c)岸田さん　「詳しくはシグマせんとのこと」 [54]_

1986年10月
~~~~~~~~~~
 「SIGMA サイドで作っていたオムロンのLUNA マシンは、そのころ，まだ影も形もなかった．わたしがソニーにアドバイスしたマーケティング戦略は，とりあえず最初のロットでできた何十台かのマシンを日本全国の大学の研究者に無料で配って使ってもらうというもの．これもみごとに図にあたったと思います．」 [53]_

1982年
~~~~~~~~
「一九八二(昭和五七)年頃の話。ワークステーション開発部長をしていた市原達朗は、その利用法を考えているうちに、ワークステーションを使った産学連携を思いついた。数学のノーベル賞とも言われるフィールズ賞の受賞者・広中平祐をトップに、全国から一○○人の教授を選んで、一人一○大、合計一○○○台のワークステーションを寄付し、それをネットワークで結んで研究成果を無償解法してもらう。そしてそれを企業が事業に活用するというのがその趣旨だった。協力してもらうのは立石電機のほかに、東芝、日立製作所、IBMといった企業四社を想定していた。」 [156]_

LUNAシリーズ概要
----------------
SX-9100
~~~~~~~~~
 1987年発表 for Σプロジェクト [36]_ [51]_ [86]_
 「札幌Σサブセンターに設置されて、地場企業によるΣ CAI ソフトウエアの開発に利用されていた。」 [52]_

LUNA [13]_ 
~~~~~~~~~~~~~~~~~~
#. 1989年発表 MC68030 20MHz
#. 起動動画 [45]_ [46]_  [38]_

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
~~~~~~~~~~~~

#. ビットマップボード:モノクロ:2048x1024,1プレーン
#. ビットマップボード:カラー:2048x1024,4プレーン,4096色中16色/16階調同時表示
#. 増設メモリボード:最大4MBx2枚
#. LANボード:イーサネット,チーパネット(DT20/25)
#. PC-98インターフェースボード
#. GPXボード: X.25,GP-1B

UNI-OS [37]_
~~~~~~~~~~~~~~~~~

UniOS-B 
    Unix4.3BSDを移植したもの。Lunaで稼動。
UniOS-U 
    UnixAT&TSystemV R2.1をベースに4.2BSDの機能等を付加し、移植したもの。Luna、Luna-IIで稼動。
UniOS-Σ 
    ΣOS-VOR1準拠したもの。Luna-Σで稼動。(要出典:Luna-Σという呼び方)　[83]_
UniOS-Mach 
    Machをベースに移植したもの。Luna-II、Luna-88Kで稼動。 

----

 本校のワークステーションはオムロン株式会社の「ＬＵＮＡ」（DT65及びFS180）というもので、ＣＰＵに「MC68030」（メインメモリー１６ＭＢ）を、基本ソフトウェアに統合化ＯＳ（後述します）である「Unios-U」を採用した高性能なものです。（注釈：ここの部分を読めば、最近のコンピュータの進化が実感できますね） [66]_

LUNAII
~~~~~~~
#. 1991/6 MC68040 25MHz
#. 68040を搭載したワークステーションLUNA‐IIのハードウェア
#. 互換性を重視し,CISC CPUを採用したワークステーションについて [21]_
#. カーネル起動問題

.. csv-table:: シリーズ構成 [73]_

 DT2460    ,DT2465 , DT2660 , DT2665
 8/16MB    ,8/16MB , 8/16MB , 8/16MB
 250MB     ,250MB  , 250MB  , 250MB

* PC98インターフェースを2スロット装備
* DT2465,2665は、フロッピーの代わりにテープストリーマ付き
* イーサネット/チーパネット(標準)+イーサネット(オプション)

#. ビットマップボード:モノクロ:2048x1024,1プレーン
#. ビットマップボード:カラー:2048x1024,4プレーン,4096色中16色同時表示
#. ビットマップボード:カラー:2048x1024,8プレーン,1670万色中256色同時表示

 88Kでも88K2でも、hwplanebits(=ROMモニタのワークエリアの値)は、 PW7131(8bpp) → 8 PW7102(4bpp) → 1 となる。 [101]_ [102]_  [103]_


LUNA88k　[10]_ 
~~~~~~~~~~~~~~~~~

#. モトローラRISC CPU MC88100(m88k)を採用
#. マルチCPU対応(最大4つ) 1CPU時25Mips ,4CPU時100Mips
#. Mach2.5,X11.4/X11R5(Luna88K2),Wnn4.1,Motif1.1.4
#. PC-98用バス対応
#. OpenBSDはm88kの実機とtoolchainがメンテナンスされている唯一のBSD
#. 1992/9 「マルチRISCワークステーションLUNA‐88K2 - 33MHz MC88100 CPUを最大4個搭載したマルチRISCワークステーションについて」 [16]_
#. 88Kと88K2ではNVRAM/Timekeeperが違う。 [84]_
#. 起動動画 [30]_ [48]_ [49]_
#. ユニマガ紹介記事 [74]_ と、製品仕様 [75]_ と、まとめ [71]_
#. miod@openbsd.org さんのOpenBSD/luna88k ページ [90]_
#. LUNA-88K2 姉妹生存報告。10月にリリースされた #OpenBSD 6.8 [176]_
#. MC88100 バグ対応の一部 [177]_

.. csv-table:: シリーズ構成 [73]_

 DT8840    ,DT8860
 8/16MB    ,32/64MB
 250MB     ,250MB 
 270万円     ,350万円

* 


omron3
~~~~~~~
 omron3.sp.cs.cmu.edu (オムロン製 LUNA88k) は 1990年から1997年の間 CMU の日本語コンピュータ環境を提供するべくボランティア達によって運用されてきた計算機です。1997年5月をもって komachi.sp.cs.cmu.edu (Intel Pentium 120Mhz FreeBSD) に役目を引き継ぎ引退しました。  [68]_

OEM版
~~~~~
 「LUNAのシグマOSのやつで日本無線からでていたOEMのワークステーションというやつを使っていたことがあります。なんか日本語フォントがX-Window立ち上げなくても使えたようなおぼろげな記憶。銀座にあったオムロンのセミナー会場で講習をうけたのだけど、そこではOEMでなくて普通のLUNAだったからなんかちがってとまどったような...」 [64]_

LUNA2010 [78]_
~~~~~~~~~~~~~~~~~
 Introduces Omron Electronic BV's Luna 2010, a multiprocessor Unix workstation that supports configurations of up to four 88110 CPUs. Compatibility with Data General's DG/UX 5.4 Release 2.10 operating system; Other features; Prices. [79]_

 そして、新しいワークステーション用のチップセットのコードネームにAsteroidという名前をつけました。火星と木星の間にある無数にある小惑星群のことです。今から考えると、何でこんな名前を付けたのだろうを反省してしまいますが、とにかくそういう名前をつけてしまいました。 [77]_

* 88110
* 1993/9ごろ 
* DC/UX5.4.X

OSCを中心とするイベント駆動開発
---------------------------------
#. 動きそうなLUNAを探す
#. ハードウェアを整備する
#. ソフトウェアを書くために必要な情報を交換する
#. 行き詰ったらツイッターで相談する
#. 定期的にイベントで展示する
#. 昔使っていた人に直接話を聞く
#. 集めた情報を整理して、公開する

OSC2011Kansai＠kyoto - LUNA復活 
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
NetBSD/m68k will never die!
 当日いきなりSun/NEWS/Luna展示 [31]_

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

なぜNetBSD/luna68kなのか
~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 LUNAを使っていたわけでもないのになぜNetBSD/luna68kにこだわるのか。それはNetBSDのyamt-kmemブランチマージ作業の際の話にまで遡る。 [91]_ [92]_
違った yamt-km のほうだった orz  [93]_ [94]_
yamt-km では hp300由来の m68k pmap でカーネルKVA用のセグメントテーブルをKVAの最上位に移動する必要があった。大部分のm68kではKVA空間上位は空いていたが luna68kだけは 0x40000000以降のデバイスアクセスにTTレジスタを使っていた。 [95]_
で、hp300由来のpmapのセグメントテーブルとページテーブルの初期化は壮絶に何をやっているのかさっぱりわからない記述になっていて、かつ030と040は別の初期化が必要で、yamt-kmマージ当初はyamtさんがそれなりに書き換えたけれど誰もテストしていなかったわけですよ [96]_
その後 NetBSD 4.0 が出る前に yamt-km マージで動かなくなっていた atari を修正して、そのあとをm68k全部のpmap初期化をすべて読み解いてそれぞれのpmap_bootstrap.cを初期化意図が読み取れるようにゴリゴリ書きなおしたわけなんですよ [97]_
実機テストできない機種のソースを4つも5つも書きなおして、1年後に見直すと致命的なtypoがあったりして、誰も持ってないマシンのコードなんか何の意味があるのか消してしまえなどと言われて、でもOSC2011京都で入手したluna68k実機ではそのままのソースで起動した、というお話 [98]_

OSC2011Kansai＠kyotoの波紋
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
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

KOF2011 - LUNAII展示
~~~~~~~~~~~~~~~~~~~~~~
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

OSC2012Kansai＠Kyoto
~~~~~~~~~~~~~~~~~~~~~~~~
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

OSC2013Tokushima
~~~~~~~~~~~~~~~~~~~
#. NetBSDこの20年 [55]_
#. NetBSD/luna68kブートローダー起動展示 [8]_

::

 Module Name:    src
 Committed By:   tsutsui
 Date:           Sat Jan  5 17:44:25 UTC 2013
 
 Added Files:
        src/sys/arch/luna68k/include: loadfile_machdep.h
        src/sys/arch/luna68k/stand/boot: Makefile autoconf.c bmc.c bmd.c boot.c
            boot.ldscript conf.c cons.c device.h devopen.c disklabel.c font.c
            getline.c init_main.c ioconf.c kbd.c kbdreg.h locore.S machdep.c
            omron_disklabel.h parse.c preset.h prf.c rcvbuf.h romcons.c
            romvec.h samachdep.h sc.c screen.c scsi.c scsireg.h scsivar.h sd.c
            sio.c sioreg.h status.h stinger.h trap.c ufs_disksubr.c vectors.h
            version

 Log Message:
 First cut at NetBSD/luna68k native bootloader.
 
 Based on 4.4BSD-Lite2/luna68k "Stinger" loader revision "Phase-31"
 http://svnweb.freebsd.org/csrg/sys/luna68k/stand/
 and MI libsa glue stuff are taken from hp300 etc.
 
 Tested on LUNA-I and old DK315C SCSI disk drive.
 
 LUNA's monitor PROM can load only an a.out binary in 4.3BSD FFS partition
 (i.e. created by "newfs -O 0") on disks with OMRON's UniOS disklabel,
 but now we can load an ELF kernel in root partition via this bootloader.
 (See luna68k/disksubr.c for details of UniOS label)
 
 TODO:
 - LUNA-II support (check 68040 to adjust cpuspeed for DELAY())
 - secondary SCSI support for LUNA-II
 - netboot via le(4) (should be trivial)
 - support boot options on bootloader prompt
 - bootinfo (passing info about booted device and kernel symbols)
 - support "press return to boot now, any other key for boot menu" method
   like x86 bootloader (needs cnscan() like functions)
 - tapeboot (anyone wants it?)

OSC2013Nagoya - Luna88K&Luna68K
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* あおやまさんと江富さんによるLuna88K/Luna68K完全動態展示 [57]_
* Luna88K2 & Luna68K プロトタイプ7号機
* OpenBSD/luna88k開発者あおやまさんによるプレゼンテーション [10]_

OSC2013 Kansai@Kyoto
~~~~~~~~~~~~~~~~~~~~~~~~~
 非力なマシンで最新のOSを動かすためには、大変な努力と工夫が必要です。その展示を実現させた方は、その努力と工夫を楽しんでおられたというわけです。 [100]_

NBUG 2013/9
~~~~~~~~~~~~~~~~~~~~~~~~~
* OpenBSD/luna88k 近況報告

KOF2013
~~~~~~~~~~
* 関西オープンソース2013NetBSDブースの記録 [117]_

OSC2014 Kansai@kyoto
~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* OSC2014京都 NetBSDブース展示への道 [134]_
* OSC2014京都 NetBSDブースの記録 [135]_


LUNAグッズ
~~~~~~~~~~~
* LUNAグッズ持参でブースに遊びに来てくれる元関係者の方が！
* シールとフロッピー [59]_
* たれまく
* ペンセット [60]_
* ペンケースとバンダナ  [76]_  [121]_  [130]_
* dpNote - 図形グッズ：シール・定規
* ホッチキス [133]_
* トレーナー [144]_
* LUNAII ボールペン

LUNA関連書籍
~~~~~~~~~~~~~
LUNAユーザーグループとは何か - mikutterの薄い本 [81]_ を会場に忘れたら、なぜか一緒に送られてくる
 UNIXワークステーションがわかる本 [61]_

　@tsutsuii LUNAの薄い本2013作れってことすね [7]_


LUNAについて私が知っている二、三の事柄
-----------------------------------------

Project Mach 
~~~~~~~~~~~~~~
 Project Mach was an operating systems research project of the Carnegie Mellon University School of Computer Science from 1985 to 1994.

 *"It's never too late. When it's over, you get to tell the story"* -- Garrison Keillor [67]_

* luna88kカーネルソース [72]_

LUNAインストール方法 
~~~~~~~~~~~~~~~~~~~~~
* インストールマニュアル [27]_
* NetBSD/luna68kの起動ディスク作り方メモ [28]_

NetBSD/luna68Kのブート方法 [13]_
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
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
#. native bootloader update for NetBSD/luna68k [116]_

LUNA88Kのブートローダー
~~~~~~~~~~~~~~~~~~~~~~~~~~
#. OpenBSD/luna88k standalone bootloader by @MiodVallat works fine on my LUNA-88K2! [107]_


BSD広告条項
~~~~~~~~~~~
 4.4BSD-Lite2由来のコードに含まれる3項目(All advertising materials ..)、広告条項削除OKについて、文書で許可を出してくれるOMRONの方がいらっしゃると2-clause BSDで配布できる。

電源問題
~~~~~~~~
#. OMRONワークステーション LUNA-II 電源ユニット修理記 [25]_
#. 「KOF本番週の日曜日に電源が不調になり急遽部品手配して展示直前に修理していた」
#. OSC2012京都前に再度補修 [26]_
#. LUNA-II, LUNA-88K 電源ユニット(PTD573-51) 四級塩電解コンデンサ一覧 [88]_
#. 88K2は88Kより分解しやすいような気がする。 [127]_


LUNAII
~~~~~~~
#. 1MB SIMM/4MB SIMM切替→SIMM脇に謎ジャンパが
#. 4bppフレームバッファのX11R5ソースは？ [85]_

PC98-Cバス
~~~~~~~~~~~
#. 86音源ボード on LUNA [138]_
#. C-bus拡張ボード on LUNA-88K2 [146]_
   
UniOS-Machと西暦2000年問題
~~~~~~~~~~~~~~~~~~~~~~~~~~~
 でも、同じマシンでUniOS-Mach立ち上げると時刻が変になる。昔調べたとおりdate(8)コマンドでは2000年以降の日付は設定できないので、OS内部で元々Y2K対応が甘いだけかもしれない。 [82]_ [84]_


質問日時:2009/10/28 17:51:08 
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 会社でワークステーション（オムロン製LUNAII）を使用していますが、プリンターが不良となりました。エプソンVP-4000です。中古をさがしていますが、これと互換性のあるプリンターはないでしょうか？ [14]_

----

 もう捨てようかと思う...が、未練があり捨てられず [10]_

----

 *Sometimes you get so lonely / Sometimes you get nowhere / I've lived all over the world / I've left every place / Please be mine / Share my life / Stay with me / Be my wife* [5]_

LUNA年表　- 月の刃
-----------------------
 「次の日からオレとルナ先生の生活がはじまったんだ」 [62]_

 青：あおやまさん,江：江富さん,オ：オムロン,筒：筒井さん,菅：菅原さん,モ:モトローラ

.. csv-table:: 
 :widths: 7 3 60

 1986/10, , いけない！ルナ先生連載開始
 1987,Σ,SX-9100 オムロンから発表 [47]_
 1988,オ,グッドデザイン賞受賞 [15]_
 1988/7, , いけない!ルナ先生連載終了
 1989,オ,SX-9100/DT LUNA MC68030 20MHz
 1989/3,オ,LUNAのハードウエア Omron Tech No.29 p.8-15 [19]_
 1990/7,オ,Luna88k Omron Tech p.81-92 [20]_
 1991/6,オ,LUNA‐II Omron Tech No.31 p. 91-9 [21]_
 1991/10/11, ,春奈るなさんの誕生日
 1991/11,モ,MC88110の存在が明らかになる [17]_
 1992/12,オ,LUNA‐88K2 Omron Tech No.32 p.336-344 [16]_
 1992/12,オ,MC88110ワークステーション Omron Tech No.32 p.345-350 [18]_
 1993/9,オ,LUNA2010
 1994, , いけない!ルナ先生 復刻版
 1994, , 4.4BSD Lite luna68K 
 1994,オ,LUNA-IIの生産終了
 1994/3,オ,LUNA2010用システム診断プログラムの開発について [80]_
 1998/6, ,NetBSD/luna68k　やってるひと、いますよ。[netbsd 02006] [23]_
 1999/12, ,NetBSD/news68kマージ
 2000/1/6, ,NetBSD/luna68kマージ
 2000, , いけない!ルナ先生 復刻版
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
 2013/06/22,青, Luna88K OSC 2013 Nagoyaで初展示。江富さんのLuna68kも初展示。 [119]_
 2013/08/2,筒, OSC2013京都でLuna/LunaII tw/mikutter展示。 [120]_
 2013/08/24,筒, OSC2013島根でLunaII+mlterm-fb+mikutterd展示 [118]_
 2013/09/21,青, OpenBSD/luna88k近況報告 無印/4bpp/リリース [109]_
 2013/11/8-9,筒, KOF2013 NetBSDブースでLuna+mikutter展示 [117]_
 2013/12/21,青, OpenBSD/luna88k近況報告 PC98バス 音源ボード [110]_
 2014/01/11,筒, native bootloader update for NetBSD/luna68k [129]_
 2014/03/05,,いけない！ルナ先生 DVD全6巻発売開始 [114]_  [115]_
 2014/04/19,青,NBUG2014/4例会 OpenBSD/luna88k 2014/4近況報告 [125]_
 2014/07/05,青,OSC 2014 NagoyaでLuna88K+PC98 86音源ボード展示 [122]_  [123]_  [124]_
 2014/07/13,筒,LunaII+8bpp ボードでカラー表示 [126]_
 2014/07/20,筒,LUNA's keyboard driver changes from OpenBSD/luna88k [131]_
 2014/07/21,筒,luna68k 4/8bpp framebuffers as a monochrome server [132]_
 2014/08/01,筒,lunaII+mikutterd今年はカラーだ展示 [134]_
 2014/08/13,筒,LUNA framebuffer mod for LCDs without Sync on Green support [142]_
 2014/11/07-08,筒,関西オープンソース2014 NetBSDブース展示の記録 [143]_
 2014/11/29,青,yaft × LUNA [140]_
 2014/12/20,青,86音源ボード on LUNA [138]_
 2014/12/29,青,86音源ボードコードコミット [139]_
 2015/02/21,青,LUNA-88K2はPCカードの夢を見るか？ [141]_
 2015/03/21,青,LUNA-88K2はPCカードの夢を見るか？ <補遺> [145]_
 2015/05/01,青,OpenBSD 5.7リリース  [148]_
 2015/05/22,青,C-bus拡張ボード on LUNA-88K2 [146]_
 2015/07/06,,「いけない！ルナ先生」コラボ読切で復活  [147]_
 2015,青,OpenBSD/luna88k移植物語 [152]_
 2015/10,青, FM音源の調べ on LUNA http://www.slideshare.net/ao_kenji/nbug201510
 2016/3,江,Luna68K AsiaBSDCon2016ブース展示
 2016/7,筒,Luna68K PSG Z80 sound driver for PC6001 to NetBSD/luna68k OSC京都 [164]_
 2016/11,藤, Implimentation of 4.4BSD luna68k by Akito Fujita KOF
 2016/11,筒,Luna68K PSG Z80 sound driver for PC6001 to NetBSD/luna68k OSC広島
 2017/3,青江,Luna88K&Luna68K AsiaBSDCon2017ブース展示
 2018/5,筒,RaSCSI + OMROM 初代LUNA 起動
 2018/5,青,LUNA-88K2 OSC2018Nagoya ブース展示
 2018/8,菅,LUNA68K OSC2018Kyoto ブース展示 LUNAのPSG音源でPCM再生
 2018/8,筒,LUNA68K OSC2018Kyoto ブース展示 sayaka+mlterm-fb
 2018/7,青,LUNA-88K2 OSC2018Nagoya ブース展示 [165]_
 2020/4,,オムロン元社長・立石義雄氏逝去 [172]_
 2020/5,井,nono-0.0.3リリース [167]_
 2020/7,井,nono-0.1.0リリース  
 2021/5,青,Here come LUNA-88K emulators! [182]_
 2021/6,井,nono-0.2.0リリース [181]_
 2022/4,井,nono-0.3.0リリース 
 2022/5,筒,psgpam(4)マージ [183]_
 2022/6,井,nono-0.4.0リリース NetBSD/x68kブート
 2022/7,井,nono-0.4.1リリース [185]_
 2022/7,筒,NetBSD/luna88k シングルユーザブート [184]_
 2022/9,井,lunafb(4) improvement [186]_
 2022/10,井,nono-0.4.4リリース [187]_
 2023/1,井,nono-0.5.0リリース [188]_
  
最近のLUNA
----------------

メモリ64M
~~~~~~~~~
 というわけで LUNA-IIの64MB設定でも NetBSD/luna68kカーネル起動した。これでしばらく耐久テストするか… [12]_ [34]_

mlterm-fb & tw
~~~~~~~~~~~~~~~~~
 ツイッタークライアント！ [39]_ [40]_ [41]_ [42]_ [43]_ [44]_ [111]_

mlterm-fb + mikutterd
~~~~~~~~~~~~~~~~~~~~~~~~~~~
 LunaIIならmlterm-fbとmikutterdを組み合わせてタイムラインを展示できます。

画像の2値化
~~~~~~~~~~~
 モノクロ画面で効率的にデモ画面を作る方法：（サーベイする）

LUNA-88K:NVRAM and Timekeeper registers
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 On 'original' LUNA-88K, NVRAM contents and Timekeeper registers are
mapped on the most significant byte of each 32bit word. (i.e. 4-bytes
stride)
Also, add small 'Wrong year set by UniOS-Mach after Y2K' hack. [89]_

LUNA88K謎ボード
~~~~~~~~~~~~~~~~~
* PWB7183 [99]_
* 専用チップが載っている　[102]_

KOF2014におけるLUNA展示
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 LUNAフォントとSONYフォント [137]_ 


yaft X LUNA
~~~~~~~~~~~~~~~~~
 yet another frame buffer terminal [136]_


老ハード介護問題
~~~~~~~~~~~~~~~~
* 電源修理
* SCSI HDD確保
* ブラウン管を知らない子どもたち
* 3ボタンマウスを知らない子どもたち [128]_
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
.. [4] バーナード・マラマッドに関する研究 http://www.ishikawa-nct.ac.jp/lab/G/koguma/www/ehp/suzukihp.pdf
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
.. [36] Σプロジェクト http://ja.wikipedia.org/wiki/Σプロジェクト
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
.. [61] UNIXワークステーションがわかる本 (LUNAの本シリーズ) http://www.amazon.co.jp/dp/4526029963
.. [62] いけない!ルナ先生 全５巻 http://www.comicpark.net/readcomic/index.asp?content_id=COMC_AKC01155_SET
.. [63] PS2Linux Kit(Sync on Green)対応モニタ一覧 http://www.ps2linux.dev.jp/monitor.html
.. [64] かやまさん https://www.facebook.com/jun.ebihara.18/posts/692735874076690?comment_id=30643585&offset=0&total_comments=1
.. [65] LUNAのカタログ Holonic Workstation LUNA[マニュアル・データーシート類] http://www.h2.dion.ne.jp/~dogs/collect/ds/luna.html
.. [66] ワークステーション操作入門 http://www.kumamotokokufu-h.ed.jp/kokufu/comp/ws_tx1.html
.. [67] "It's never too late. When it's over, you get to tell the story" -- Garrison Keillor  http://www.cs.cmu.edu/afs/cs/project/mach/public/www/mach.html
.. [68] ピッツバーグ便利帳 サーバーの歴史 http://komachi.sp.cs.cmu.edu/benricho/Komachi#.E3.82.B5.E3.83.BC.E3.83.90.E3.83.BC.E3.81.AE.E6.AD.B4.E5.8F.B2 「1993年、オムロンのワークステーション業務撤退に伴い藤田さんと作業マシン達に突然の引き上げ命令が下りました。」
.. [69] OpenBSD/luna88k「network bootでIPアドレス取得」(2002/06/05)の頃のページ http://t.co/VRxXgWWpTO
.. [70] 同じく「Miod Vallatさんに見つかる」(2004/03/21)の頃のページ http://t.co/3QmzWm7reR
.. [71] OMRON Luna88Kについてのまとめ http://t.co/rt5kUB74VG 作者も忘れている説
.. [72] http://www.cs.cmu.edu/afs/cs/project/mach/public/src/mkernel/src/kernel/luna88k/
.. [73] LUNA-II スペック表というサーベイ漏れ https://t.co/KV9f6XS8bU
.. [74] ユニマガのluna88k発売の記事。 https://twitter.com/a1kawa/status/360427576717611008
.. [75] LUNA-88K2 の製品仕様 プロセッサ以外は同じという見方もある https://twitter.com/tsutsuii/status/361463750982778880/photo/1
.. [76] もうひとつあった。2011年OSC京都 わざわざ2日目に持ってきていただいた超重要LUNAグッズ ペンケースとバンダナ http://movapic.com/ebijun/pic/3812352 たしか、来場者の方の奥様の所有で、「持って行くのはいいけれど絶対に持って返ってくるように」と申し渡された、というお話だったような
.. [77]  名は体を表す http://ameblo.jp/hirokun39/entry-11345138649.html
.. [78] LUNA2010 Good Design Award http://www.g-mark.org/award/describe/20641
.. [79] Omron spins four 88110s at Data General Aviion line http://connection.ebscohost.com/c/articles/9402180800/omron-spins-four-88110s-data-general-aviion-line
.. [80] システム診断プログラムの開発 LUNA2010用システム診断プログラムの開発について http://jglobal.jst.go.jp/public/20090422/200902172571690192
.. [81] mikutterの薄い本製作委員会 http://home1.tigers-net.com/brsywe/mikutter.html
.. [82] https://twitter.com/ao_kenji/status/360775880198459394/photo/1
.. [83] Wikipediaの「LUNA-Σ」という呼称は果てしなく要出典という感想。 https://twitter.com/tsutsuii/status/360430992638492672
.. [84] "RTC" の stamp のオフセットをそれぞれ x4してやればいいような気がします https://twitter.com/tsutsuii/status/360418015600312320
.. [85] まずはDIP SW操作してみて変わるかどうか https://twitter.com/tsutsuii/status/360416804876722177
.. [86] マンガソフトウェア革命―Σプロジェクトの全貌 http://www.amazon.co.jp/dp/4339022543
.. [87] 仁和寺 http://randen.keifuku.co.jp/map/17.html
.. [88] https://gist.github.com/tsutsui/6203477 OMRON LUNA-II および LUNA-88K の電源ユニットに使用されている要交換な四級塩電解コンデンサのリスト。
.. [89] http://marc.info/?l=openbsd-cvs&m=137617369920936
.. [90] miod@openbsd.org さんのOpenBSD/luna88k resource page http://gentiane.org/~miod/software/openbsd/luna88k/
.. [91] https://twitter.com/tsutsuii/status/365121355001237505
.. [92] http://nxr.netbsd.org/xref/src/doc/BRANCHES?r=1.330#623 
.. [93] https://twitter.com/tsutsuii/status/365121528309891072
.. [94] http://nxr.netbsd.org/xref/src/doc/BRANCHES?r=1.330#1611 
.. [95] https://twitter.com/tsutsuii/status/365121928526184448
.. [96] https://twitter.com/tsutsuii/status/365122443951616001
.. [97] https://twitter.com/tsutsuii/status/365122859305140225
.. [98] https://twitter.com/tsutsuii/status/365123833402896384
.. [99] https://twitter.com/ao_kenji/status/366154076565680128/photo/1
.. [100] 20年前のコンピュータで最新のOSを動かす意味とは？ http://notredameningen.kyo2.jp/e422862.html
.. [101] 88Kと88K2のグラフィックボードを交換して調査。 https://twitter.com/ao_kenji/status/366066990093303809
.. [102] 専用のゲートアレイでしょうか。https://twitter.com/ao_kenji/status/366056571609939968
.. [103] PWB7102  https://twitter.com/ao_kenji/status/366009479285854208
.. [104]  UniOS-Machを参考に1bpp/4bpp/8bppを自前で識別するようにした。 https://twitter.com/ao_kenji/status/368294458996948992
.. [105] Luna88k マニュアル https://twitter.com/ao_kenji/status/395857381818519552
.. [106] Luna88k FaceBook ページ　https://www.facebook.com/Luna88k
.. [107] OpenBSD/luna88k standalone bootloader by @MiodVallat works fine on my LUNA-88K2! https://twitter.com/ao_kenji/status/395551245563219969
.. [108] LUNA-88KのPC-98拡張バス(Cバス)についてのメモ https://gist.github.com/ao-kenji/7843096
.. [109] OpenBSD/luna88k近況報告 NBUG 2013/9  http://www.slideshare.net/ao_kenji/openbsdluna88k-news-at-nbug-meeting-2013
.. [110] OpenBSD/luna88k近況報告 NBUG 2013/12 http://www.slideshare.net/ao_kenji/nbug201312
.. [111] test tweet from OpenBSD/luna88k https://twitter.com/ao_kenji/status/482151248502591488
.. [112] OMRONワークステーションLUNA 工作日記 http://togetter.com/li/535307
.. [113] OMRONワークステーション LUNA-II 電源ユニット修理記 その3 http://togetter.com/li/548989
.. [114] 「いけない！ルナ先生」実写化！6人のアイドルが先生に http://natalie.mu/comic/news/105048
.. [115]  http://www.cinemart.co.jp/ikenai-runa/
.. [116]  native bootloader update for NetBSD/luna68k http://mail-index.netbsd.org/port-luna68k/2014/01/11/msg000038.html
.. [117] 関西オープンソース2013NetBSDブース展示の記録  http://togetter.com/li/587422
.. [118] オープンソースカンファレンス2013島根 NetBSDブース展示の記録 http://togetter.com/li/553529
.. [119] OSC2013名古屋 NBUG&NetBSDブース展示の記録 http://togetter.com/li/522396
.. [120] オープンソースカンファレンス2013関西＠京都　NetBSDブース展示記録 http://togetter.com/li/542885
.. [121] 泣いて喜びそうなもの発掘 https://twitter.com/goinkyo_hacker/status/482528142930620416
.. [122] OpenBSD/luna88kのご紹介 http://www.slideshare.net/ao_kenji/osc2014-nagoya
.. [123] OpenBSD/luna88kのご紹介 パンフレット http://www.nk-home.net/~aoyama/osc2014nagoya/obsd-luna88k-leaflet.pdf
.. [124] オープンソースカンファレンス2014 Nagoya&NBUG7月例会 の記録 http://togetter.com/li/688742
.. [125] OpenBSD/luna88k 2014/4近況報告 http://www.slideshare.net/ao_kenji/nbug201404
.. [126] Setup Bt458 color palette to support ANSI color text on 8bpp framebuffer. http://mail-index.netbsd.org/source-changes/2014/07/13/msg056309.html
.. [127] 88K2電源交換 https://twitter.com/ao_kenji/status/485393846314872832 
.. [128] どうしてこのマウスにはボタンが３つもあるのか https://twitter.com/ao_kenji/status/485275421768814592
.. [129] native bootloader update for NetBSD/luna68k http://mail-index.netbsd.org/port-luna68k/2014/01/11/msg000038.html
.. [130] 泣いて喜びそうなバンダナ https://twitter.com/goinkyo_hacker/status/482528142930620416/photo/1
.. [131] LUNA's keyboard driver changes from OpenBSD/luna88k http://mail-index.netbsd.org/source-changes/2014/07/20/msg056548.html
.. [132] luna68k 4/8bpp framebuffers as a monochrome server http://mail-index.netbsd.org/source-changes/2014/07/21/msg056590.html
.. [133] LUNAホッチキス https://twitter.com/goinkyo_hacker/status/497392417478156288/photo/1
.. [134] OSC2014京都NetBSDブース展示への道 http://togetter.com/li/703494
.. [135] OSC2014 Kansai@Kyoto NetBSDブース展示の記録 http://togetter.com/li/700617
.. [136] yaft×Laan http://www.slideshare.net/ao_kenji/nbug201411-yaft-42177561
.. [137] KOFにおけるLUNA展示 https://speakerdeck.com/tsutsui/kof-and-luna-at-netbsd-booth
.. [138] PC-9801-86 sound board on LUNA http://www.slideshare.net/ao_kenji/nbug201412
.. [139] OpenBSD/luna88k用の86音源ボードドライバを整理してcommit。 https://twitter.com/ao_kenji/status/549203137001553921
.. [140] yaft×LUNA http://www.slideshare.net/ao_kenji/nbug201411-yaft-42177561
.. [141] LUNA-88K2はPCカードの夢を見るか http://www.slideshare.net/ao_kenji/nbug201502
.. [142] LUNA framebuffer mod for LCDs without Sync on Green support http://mail-index.netbsd.org/port-luna68k/2014/08/13/msg000043.html
.. [143] 関西オープンソース2014 NetBSDブース展示の記録 http://togetter.com/li/742243
.. [144] Lunaトレーナー http://movapic.com/ebijun/pic/5232493
.. [145] LUNA-88K2はPCカードの夢を見るか <補遺> http://www.slideshare.net/ao_kenji/nbug201503
.. [146] C-bus拡張ボード on LUNA-88K2 http://www.slideshare.net/ao_kenji/osc2015-nagoya/
.. [147] 伝説のHコメディ「Oh！透明人間」×「いけない！ルナ先生」コラボ読切で復活 http://natalie.mu/comic/news/152961
.. [148] INSTALLATION NOTES for OpenBSD 5.7 http://ftp.openbsd.org/pub/OpenBSD/5.7/luna88k/INSTALL.luna88k
.. [149] LUNAは、SX-9100以降の愛称なんですが、その前のSX-8700 の時代は、スーパーメイトという愛称でした。 https://www.facebook.com/events/1062729970410808/permalink/1153405211343283/
.. [150] このマシンがスーパーメイトという商品名で http://www.tomo.gr.jp/root/new/root82.html
.. [151] LUNA88Kに付属しているxzoomというデモの画像です。 http://moon.hanya-n.org/comp/luna/luna88k.html
.. [152] OpenBSD/luna88k移植物語 http://www.slideshare.net/ao_kenji/a-story-of-porting-openbsdluna88k
.. [153] FM音源の調べ on LUNA http://www.slideshare.net/ao_kenji/nbug201510
.. [154] PSG音源の調べ  https://speakerdeck.com/tsutsui/osc2016-kyoto-psg-tunes-on-netbsd-luna68k
.. [155] LUNAのPSGというか647180実装  https://twitter.com/tsutsuii/status/759793635898515456
.. [156] 「できません」と云うな―オムロン創業者 立石一真　https://www.amazon.co.jp/dp/4478006334/
.. [157] http://www.ustream.tv/recorded/90107872
.. [158] https://speakerdeck.com/tsutsui/osc2016-hiroshima-psg-tunes-on-netbsd-luna68k-again
.. [159] https://speakerdeck.com/tsutsui/osc2016-kyoto-psg-tunes-on-netbsd-luna68k
.. [160] https://speakerdeck.com/tsutsui/osc2014-kansai-at-kyoto-netbsd-luna68k-report
.. [161] http://www.ceres.dti.ne.jp/tsutsui/kof2013/NetBSD_bootloader.html
.. [162] http://www.ceres.dti.ne.jp/tsutsui/osc2013kyoto/NetBSD-luna68k_mlterm-fb_Twitter.html
.. [163] https://twitter.com/tsutsuii/status/991191717050118144
.. [164] https://speakerdeck.com/tsutsui/osc2016-kyoto-psg-tunes-on-netbsd-luna68k
.. [165] https://www.slideshare.net/ao_kenji/osc2019-nagoya
.. [166] http://www.pastel-flower.jp/~isaki/nono/
.. [167] https://twitter.com/isaki68k/status/1261646479816404992
.. [168] https://twitter.com/tsutsuii/status/1262429647364427783
.. [169] https://twitter.com/tsutsuii/status/1262430960718508033
.. [170] https://twitter.com/isaki68k/status/1262375954883772418
.. [171] https://twitter.com/isaki68k/status/1262949576362930180
.. [172] https://ja.wikipedia.org/wiki/%E7%AB%8B%E7%9F%B3%E7%BE%A9%E9%9B%84
.. [173] https://twitter.com/isaki68k/status/1317441952107827201
.. [174] http://wiki.netbsd.org/ports/luna68k/luna68k_info/#behindthescene
.. [175] https://twitter.com/isaki68k/status/1322807313741148160
.. [176] https://twitter.com/ao_kenji/status/1324952816884985857
.. [177] https://twitter.com/ao_kenji/status/1324990436390268928
.. [178] https://twitter.com/ao_kenji/status/1330473862686003202
.. [179] https://twitter.com/ao_kenji/status/1330504720516063235
.. [180] https://twitter.com/isaki68k/status/1330124516333412361
.. [180] https://twitter.com/ao_kenji/status/1330019763775365120
.. [181] https://twitter.com/isaki68k/status/1406522668321366022
.. [182] Here come LUNA-88K emulators!  https://www.slideshare.net/ao_kenji/osc2021-nagoya-248742459
.. [183] http://mail-index.netbsd.org/source-changes/2022/06/10/msg139155.html
.. [184] https://twitter.com/tsutsuii/status/1551955355101691904
.. [185] https://twitter.com/isaki68k/status/1551020192037097473
.. [186] http://mail-index.netbsd.org/source-changes/2022/09/25/msg141239.html
.. [187] https://twitter.com/isaki68k/status/1585612735932674049
.. [188] https://twitter.com/isaki68k/status/1618215457722617856

このページ
~~~~~~~~~~~
* https://github.com/ebijun/NetBSD/blob/master/Guide/Luna.rst にあります。
* /usr/pkgsrc/textproc/py-sphinx をインストールして、make htmlとか。
