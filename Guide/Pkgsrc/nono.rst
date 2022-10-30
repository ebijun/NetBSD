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

 DISTNAME=       nono-0.4.4

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

 nono: update to 0.4.4.
 
 0.4.4 (2022-10-27)
 
Changes in 0.4.4:

 vm(New):  "Support 8bpp board on LUNA provisionally."
 vm(Fix):  "Change configuration item name from xxx-new-sci-ignore to xxx-new-sic-ignore."
 vm(Fix): "Fix a problem that RAM is not placed correctly."
 vm(Fix): "Fix an access to X68030 palette registers."
 m88k(Update):  "Improve m88k core performance about 3%."
 debugger(Fix):  "Memory break point now works even on address 0."
 host(Fix): "Fix a queue overflow when many characters are pasted to the host serial console at a time."
 GUI(New): "Implement x1.5 and x2.0 scale on the main window."
 GUI(New): "Add fontsize 24."
 GUI(New): "Link the front LCD window size and LCD charactor monitor size to font size."
 GUI(New): "Split the Bt454/458 monitor from video monitor."
 GUI(New): "Implement a palette monitor."
 GUI(New): "Implement DIPSW setting window."
 GUI(New):  "Implement memory edit."
 GUI(New): "Implement disassemble monitor."
 GUI(Update): "Implement output format selector on the memory dump monitor, and support MMU descriptor."
 GUI(Update): "Implement one line up/down button on the memory dump monitor."
 GUI(Update): "Support mouse wheel on the memory dump monitor."
 GUI(Update): "Place a GTK control on the GTK panel correctly."
 GUI(Update): "Don't load the default catalog. Because it contains unintended translation."
 build(New): "Support wxWidgets 3.2 series." 

doc をcommit します
---------------------
 
doc をcommit します。
コメントは、「doc:Updated カテゴリー/パッケージ名 to バージョン」に設定します。

::

 doc: Updated emulators/nono to  0.4.4
 
 cvs diff -u CHANGES-2022
 Updated emulators/nono to 0.4.4 [jun 2022-10-27]


