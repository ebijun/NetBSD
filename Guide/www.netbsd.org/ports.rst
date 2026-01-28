NetBSDがサポートするプラットフォーム (Ports)
-------------------------------------------------------

NetBSDでは、サポート対象のアーキテクチャを「,ポート (Port),」と呼んでいます。ほとんどのポートは汎用ハードウェアやエミュレータ上で動作しますが、一部の商用ハードウェアも含まれます。

ポートは、その重要性やコミュニティの活動レベルに基づき、以下の3つの「,ティア (Tier),」に分類されます。このティアは、`core@NetBSD.org` の決定により、時間の経過とともに変更されることがあります。

ティア分類の概要
^^^^^^^^^^^^^^^^^

.. csv-table::

 ティア,名称, サポートの焦点 , 状態                     ,
 I,Focus (重点),NetBSDの戦略の一部としてサポート  , 現代のサーバー、組み込み、デスクトップアーキテクチャが対象。MI (Machine Independent) な変更は、これらのポートでテストされ、MD (Machine Dependent) なサポートも確実に行われる必要があります。
 II,Organic (有機的),コミュニティのペースで進化        , 一般的に、ハードウェアは産業的な関連性を失っているか、コミュニティ活動がTier Iほど活発でないポートが対象。通常は動作していますが、維持管理はユーザーコミュニティの責任です。リリース時に動作しない場合は、Tier IIIに降格します。
 III,Life Support (生命維持),動作しない、または深刻な問題を抱えている , コミュニティの関心の欠如やハードウェアの希少性などにより、機能しなくなったポートが対象。合理的な期間内に修正が示されない場合、Attic（非サポート）に移動します。                       

-----

ティア I: Focus (重点ポート)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

現在、9つのポートがTier Iステータスです。

.. csv-table::

 Port        , CPU           , 対応マシン                                  , 最新リリース
 aarch64 , aarch64       , 64-bit ARM CPUs                        , 10.1
 amd64   , x86\_64       , 64-bit x86-family machines (AMD/Intel) , 10.1
 evbarm  , arm           , ARM評価ボード                               , 10.1
 evbmips , mips          , MIPSベース評価ボード                           , 10.1
 evbppc  , powerpc       , PowerPCベース評価ボード                        , 10.1
 hpcarm  , arm           , StrongARMベース Windows CE PDA            , 10.1
 i386    , i386          , 32-bit x86-family汎用マシン ("PC clones")   , 10.1 
 sparc64 , sparc         , Sun UltraSPARC (64-bit)                , 10.1
 xen     , i386 x86\_64 , Xen Virtual Machine Monitor            , 10.1

ティア II: Organic (有機的ポート)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

現在、49のポートがTier IIステータスです。

（例：alpha amiga atari macppc pmax sparc vax zaurus など）

ティア III: Life Support (生命維持ポート)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

現在、Tier IIIステータスのポートは,ありません,。

-----

CPUアーキテクチャ別ポート一覧
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

同じ `MACHINE_ARCH` (uname -p ) を持つマシンは、通常同じユーザーランドバイナリを共有します。

.. csv-table::

 CPUティア該当ポート
 aarch64,I,aarch64
 amd64,I,amd64 xen
 arm,I II,acorn32 cats epoc32 evbarm hpcarm iyonix netwinder shark zaurus
 i386,I,i386  xen
 m68k,II,amiga atari cesfic hp300 luna68k mac68k mvme68k news68k next68k sun3 x68k
 mipseb,I II , emips evbmips ews4800mips mipsco newsmips sbmips sgimips
 mipsel,I II , algor arc cobalt evbmips hpcmips pmax sbmips
 powerpc,I II , amigappc bebox evbppc ibmnws macppc mvmeppc ofppc prep rs6000 sandpoint
 sparc64,I,sparc64
 vax,II, vax
 alpha,II, alpha
 hppa,II,hppa
 sh3eb/el,II,dreamcast evbsh3 hpcsh landisk mmeye
 m68010,II,sun2
 riscv,II, riscv (最新リリースなし)                                                                    ,
 itanium,II, ia64 (最新リリースなし) 

-----

用語の対照表
^^^^^^^^^^^^^^^^

.. csv-table::

 コンセプト, `/usr/share/mk`, 変数`uname`, コマンド`build.sh` コマンド 
 ポート,`MACHINE`,`uname -m`,`build.sh -m`
 CPU,`MACHINE_ARCH`,`uname -p`,`build.sh -a`

-------------

出典:[Platforms supported by NetBSD](https://wiki.netbsd.org/ports/)


