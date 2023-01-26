.. 
 Copyright (c) 2022 Jun Ebihara All rights reserved.
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


=========================
nono のバージョンアップ
=========================

pkgsrc/emulators/nono 以下を更新して、nonoのバージョンアップをしてみます。

バージョン指定
---------------------

Makefile 内のバージョンをあげます。

::

 DISTNAME=       nono-0.5.0

チェックサム作成
------------------

::  

 % make makesum  
-rw-r--r--  1 jun  wheel  1180 Oct 27 23:42 Makefile
-rw-r--r--  1 jun  wheel   558 Oct 27 23:42 distinfo

 make package して動作を確認します。
 
pkglint
----------
 
pkglint をして正しいか確認します。

::
 
 pkg_add pkglint
 pkglint .
 % pkglint .
 Looks fine.

commit 
-------------

バージョンアップ時のアップデート内容をしらべておきます。nonoの場合は、changes.htmlに日英併記された更新内容があるので、英語部分だけを変更点とします。
更新ログの一行目は「パッケージ名: Update to バージョン」の形式にします。

 http://www.pastel-flower.jp/~isaki/nono/doc/changes.html

:: 

 cvs commit 

 nono: update to 0.5.0.
 
 Changes in 0.5.0:
 vm(New): "Start to implement HD647180."
 vm(New): "Implement X68030 extended memory."
 vm(Fix): "Fix an abnormal termination on writing to DREG when buffer full in SPC."
 m68k(Update): "Improve performance of m68030."
 debugger(Fix): "Fix BackSpace input."
 GUI(Update): "Reorganize monitor menu."
 GUI(Update): "Add mainview scale specified in configuration and monitor rate to menu."
 GUI(Fix): "Support 24 dot fonts in memory dump window."
 app(New): "Implement --create-sram option."
 app(New): "Support configuration file ~/.nono.cfg."
 app(Update): "Support configration fast-mode monitor-fontsize mainview-scale"
 app(Update): "Support display format specification in -Mmemdump."
~


doc をcommit します
---------------------
 
doc をcommit します。
コメントは、「doc:Updated カテゴリー/パッケージ名 to バージョン」に設定します。

::

 doc: Updated emulators/nono to  0.5.0
 
 cvs diff -u CHANGES-2023
 Updated emulators/nono to 0.5.0 [jun 2023-01-26]


