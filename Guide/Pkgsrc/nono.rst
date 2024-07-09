.. 
 Copyright (c) 2022-4 Jun Ebihara All rights reserved.
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

 DISTNAME=       nono-0.7.3

チェックサム作成
------------------

::  

 % make makesum  
 -rw-r--r--  1 jun  wheel  1164 Jul  9 10:00 Makefile
 -rw-r--r--  1 jun  wheel   304 Jul  9 10:01 distinfo

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

 nono: update to 0.7.3.

 0.7.3 (2024/07/03)

 vm(Fix): "Fix problem that resetting on LUNA-88K sometimes stops the scheduler."
 vm(Fix): "Fix problem that MSX-DOS mode immediately exits since er 0.7.0."
 vm(Fix): "Fix problem that the real PROM image could not access SPC correctly on LUNA-I since ver 0.7.0."
 vm(Fix): "Make an error if the directory specified by windrv-path does not exist on startup."
 vm(Fix): "Fix problem that the renderer runs excessively."
 vm(New): "X68030 Contrast rendering now can use NEON on aarch64."
 vm(New): "Implement SSG (YM2149) registers only (It doesn't work yet)."
 vm(Update): "Mainview scaling is now done by the renderer thread."
 vm(Update): "Display register addresses on the SPC monitor."
 vm(Update): "Change several SCSI internal structures. No functional changes intended."
 vm(Update): "Various internal improvements. No functional changes intended."
 m68k(Update): "Put back the number of ATC lines to 22. It improves the performance about 2%."
 GUI(New): "Make the access status monitor graphical."
 GUI(Update): "Change whole bitmap internal structures. No functional changes intended."
 GUI(Update): "Improve scaling performance at preset magnification by 3-5 times."
 vm(New): "Allow CPU affinity configuration for debugging and evaluation." 

doc をcommit します
---------------------
 
doc をcommit します。
コメントは、「doc:Updated カテゴリー/パッケージ名 to バージョン」に設定します。

::

 doc: Updated emulators/nono to 0.7.3
 
 cvs diff -u CHANGES-2024
 
        Updated emulators/nono to 0.7.3 [jun 2024-07-09]

