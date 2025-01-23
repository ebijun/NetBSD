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

 DISTNAME=       nono-1.1.2

チェックサム作成
------------------

::  

 % make makesum
 -rw-r--r--  1 jun  wheel  1148 Jan  8 20:48 Makefile
 -rw-r--r--  1 jun  wheel   357 Nov  4 01:22 PLIST
 -rw-r--r--  1 jun  wheel   558 Jan  8 20:48 distinfo

 -rw-r--r--  1 jun  wheel  1148 Jan 23 20:02 Makefile
 -rw-r--r--  1 jun  wheel   357 Nov  4 01:22 PLIST
 -rw-r--r--  1 jun  wheel   558 Jan 23 20:03 distinfo

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

 nono: update to 1.1.2.

 m68k(Fix): "Revert FMOVEM.X -(An),<fplist> and FMOVEM.X <fplist>,(An)+ to the illegal instruction because the behavior can no longer be confirmed."
 m68k(Fix): "Fix that illegal instructions around FMOVE.X FPn,<ea> might change FPSR."
 m68k(Fix): "Fix problem that 68030 ATC incorrectly operated Modified bit since ver 0.7.2."
 m68k(Fix): "Fix disassemble of CMP.[WL] An,Dn since ver 1.1.0."
 vm/human68k(Update): "Implement timer work area."
 util/runx(Fix): "Fix several probl"

doc をcommit します
---------------------
 
doc をcommit します。
コメントは、「doc:Updated カテゴリー/パッケージ名 to バージョン」に設定します。

::

 doc: Updated emulators/nono to 1.1.2
 
 cvs diff -u CHANGES-2025
 
        Updated emulators/nono to 1.1.2 [jun 2025-01-23]

