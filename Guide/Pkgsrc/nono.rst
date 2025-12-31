.. 
 Copyright (c) 2022-5 Jun Ebihara All rights reserved.
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


フリーズしているか確認
--------------------------

以下のURLを見て、pkgsrcがフリーズしているか確認します。フリーズしている時はバージョンアップしません。

 https://mail-index.netbsd.org/pkgsrc-changes/index.html
 https://www.pkgsrc.org/is-a-freeze-on/

バージョン指定
---------------------

Makefile 内のバージョンをあげます。

::

 DISTNAME=       nono-1.6.3

チェックサム作成
------------------

::  

 % make makesum
 
 drwxr-xr-x  2 jun  wheel   512 Dec 11 05:47 CVS
 -rw-r--r--  1 jun  wheel    54 May 14  2024 DESCR
 -rw-r--r--  1 jun  wheel  1202 Dec 11 05:55 Makefile
 -rw-r--r--  1 jun  wheel   357 Nov  2 15:01 PLIST
 -rw-r--r--  1 jun  wheel   350 Dec 11 05:56 distinfo

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

 nono: update to 1.6.4.

 1.6.4 (2025/12/08)

 m68k(Fix): "Fix SRP/URP register masks in 68040. This makes NetBSD newpmap kernel bootable."
 m68k(Fix): "Fix an issue where the lower 4 bits of SRP/CRP register in 68030 were cleared."
 m68k(Fix): "Fix memory accesses in PACK/UNPK instructions to a single word access."
 m68k(Update): "Implement several corner cases in 68030 PTEST instruction."
 m68k(Update): "Rewrite whole 68030 MMU and improve performance slightly."
 m68k(Update): "Improve 68030 ATC performance slightly."
 vm(Update): "Implement ESC D and ESC M in serial console emulation."
 host(Fix): "Fix an abnormal termination in usermode network."
 host(Fix): "Fix an issue that the application could not be terminated in usermode network."
 GUI(Update): "Improve the page table monitor."
 GUI(Fix): "Remove incorrect TT hit rate in 68030 ATC monitor since ver 1.6.3."
 debugger(Fix): "Fix an issue where different exceptions occurring consecutively at the same address were not recorded in Exception history."
 debugger(New): "Implement "pe" command." 

doc をcommit します
---------------------
 
doc をcommit します。
コメントは、「doc:Updated カテゴリー/パッケージ名 to バージョン」に設定します。

::

 doc: Updated emulators/nono to 1.6.4
 
 cvs diff -u CHANGES-2025
 
        Updated emulators/nono to 1.6.4 [jun 2025-12-11]

