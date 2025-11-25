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
 
 drwxrwxr-x   2 600   125   512 Nov 12 13:59 CVS
 -rw-r--r--   1 root  125    54 Nov 12 13:59 DESCR
 -rw-r--r--   1 root  125  1202 Nov 26 05:16 Makefile
 -rw-r--r--   1 root  125   357 Nov 12 13:59 PLIST
 -rw-r--r--   1 root  125   350 Nov 26 05:16 distinfo

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

 nono: update to 1.6.3.

 1.6.3 (2025/11/25)

 m68k(Fix): "Fix page address mask in several places on 68030 table search."
 m68k(Update): "Revert 68030 ATC to original-compliant behavior (FC-mixed 22-entries). These two fixes make current NetBSD/m68k newpmap kernel bootable (though the actual cause should be a bug in the NetBSD kernel)."
 m68k(Fix): "Fix inverted condition in PFLUSH* for deleting global entries on 68040."
 GUI(New): "Implement 68030 and 68040 page table monitor window."
 GUI(Fix): "Fix an abnormal termination when the log window is stretched."
 debugger(Fix): "Fix an issue where instruction breakpoints might not work."
 debugger(Update): "Show NetBSD/m68k system call number for exception history."
 build(Fix): "Fix a build error on platforms other than x86_64 and i386 after ver 1.6.0."
 vm(Update): "Note: It includes a lot of time axis-related changes that were in the work for the next release, but no functional changes are expected." 

doc をcommit します
---------------------
 
doc をcommit します。
コメントは、「doc:Updated カテゴリー/パッケージ名 to バージョン」に設定します。

::

 doc: Updated emulators/nono to 1.6.3
 
 cvs diff -u CHANGES-2025
 
        Updated emulators/nono to 1.6.3 [jun 2025-11-26]

