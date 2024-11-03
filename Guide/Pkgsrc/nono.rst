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

 DISTNAME=       nono-1.0.0

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

 nono: update to 1.0.0.

 1.0.0 (2024/10/31)

 m68k(New): "Implement data cache."
 vm(Update): "Rewrite whole bus structure."
 m68k(Update): "Implement FTRAPcc instructions."
 m68k(Fix): "Fix problem that MOVE.W ea,CCR instruction was not privileged."
 m68k(Fix): "Fix cache entry clear operation."
 m68k(Fix): "Fix problem that RTE instruction may not be able to recover from a bus error if it occurred on an instruction which accesses the same register's (An)+ or -(An) twice."
 m68k(Fix): "Fix problem that some exception vector was fetched from wrong address space."
 m68k(Fix): "Fix problem that 68030 register monitor displays FPU registers even though no FPU."
 vm(Update): "Fix accessing to Lance's undefined port on LUNA-88K."
 vm(Update): "Fix accessing to CRTC's undefined port on X68030."
 vm(Update): "Implement several DOS calls on Human68k mode. Now you can run fputest.x (0.17.* and later) on it."
 vm(Fix): "Fix a device reset on VirtIO Network device."
 vm(Fix): "Fix a word access to some DMAC registers on X68030."
 vm(Fix): "Fix problem that the third decimal place of configuration item mpu-clock may not be able to specified correctly."
 vm(Fix): "Fix possibility of an abnormal termination on CTRL+OPT.1+DEL input on X68030."
 vm(Fix): "Fix problem that you could not access the floppy again while the motor is on on X68030."
 app(Update): "Make -c optional when -H is specified."
 GUI(Fix): "Support display of 100x speed or more on performance counter."
 util(New): "Implement runx. It can run instructiontest.x and fputest.x (before 0.16.* and after 0.17.*)." 

doc をcommit します
---------------------
 
doc をcommit します。
コメントは、「doc:Updated カテゴリー/パッケージ名 to バージョン」に設定します。

::

 doc: Updated emulators/nono to 0.7.3
 
 cvs diff -u CHANGES-2024
 
        Updated emulators/nono to 0.7.3 [jun 2024-07-09]

