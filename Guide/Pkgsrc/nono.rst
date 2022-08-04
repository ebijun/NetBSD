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

 DISTNAME=       nono-0.4.2

チェックサム作成
------------------

::  

 % make makesum  
 -rw-r--r--  1 jun  wheel   558 Aug  4 08:24 distinfo
 -rw-r--r--  1 jun  wheel  1164 Aug  4 08:24 Makefile

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

 nono: update to 0.4.2.
 
 0.4.2 (2022-08-03)

 vm(Update):  "Improve a memory map on LUNA-88K."
 vm(Update):  "Improve a keyboard buzzer handling on LUNA. Implement the buzzer indicator on the software keyboard window."
 vm(Update):"Limit maximum ram size to 240MB when using PROM 1.20 on LUNA-88K due to PROM code constraint."
 vm(Update): "Implement behaviors when TVRAM scroll protrudes to the right, probably."
 vm(Fix):  "Fix a horizontal scroll amount of RFCNT to match real machine."
 m88k(Fix): "Fix an address mask when m88200 invalidates cache line."
 m88k(Fix): "Fix cache status when m88200 creates cache entry for writing."
 debugger(Update):  "Add unofficial NetBSD/luna88k system call to the exception history."
 app(Update):  "-X option supports loading symbol tables in NetBSD kernel."
 app(Fix):  "Fix a problem that application may not be able to be terminated when debugger is used."
 app(Fix):  "Fix a silent termination when Ctrl+Q is entered." 
 
doc をcommit します
---------------------
 
doc をcommit します。
コメントは、「doc:Updated カテゴリー/パッケージ名 to バージョン」に設定します。

::

 doc: Updated emulators/nono to  0.4.2
 
 cvs diff -u CHANGES-2022
 Index: CHANGES-2022
 ===================================================================
 RCS file: /cvsroot/pkgsrc/doc/CHANGES-2022,v
 retrieving revision 1.3672
 diff -u -r1.3672 CHANGES-2022
 --- CHANGES-2022        3 Aug 2022 21:54:21 -0000       1.3672
 +++ CHANGES-2022        3 Aug 2022 23:35:09 -0000
 @@ -5470,3 +5470,4 @@
        Updated www/firefox-l10n to 103.0.1 [ryoon 2022-08-03]
        Updated net/nsd to 4.6.0 [ryoon 2022-08-03]
        Updated databases/p5-DBD-SQLite to 1.70 [wiz 2022-08-03]
 +       Updated emulators/nono to 0.4.2 [jun 2022-08-04]

 
