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

 DISTNAME=       nono-0.7.0

チェックサム作成
------------------

::  

 % make makesum  
 -rw-r--r--  1 jun  wheel  1163 Feb 26 05:30 Makefile
 -rw-r--r--  1 jun  wheel   558 Feb 26 05:30 distinfo

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

 nono: update to 0.7.0. 

 0.7.0 (2024-02-21)

 vm(New): "Start to support virt68k."
 vm(Fix): "Fix problem that the interrupt acknowledge didn't handle correctly when two Nereid boards are installed simul
taneously."
 vm(Fix): "Fix several spurious interrupts on resetting on various devices."
 vm(Fix): "Implement MIE on X68030 SCC."
 vm(Fix): "Fix not to update TxDR on starting the timer on X68030 MFP."
 vm(Fix): "Fix several accesses to CRTC on X68030."
 vm(Update): "Fix and rearrange whole bus access. Some device wait may be changed intentionally or unintentionally."
 vm(Update): "Rearrange the power devices on all architecture."
 app(New): "Graphic rendering now can use AVX2 on amd64."
 app(Update): "-X option is changed to accept only one argument if -H is not specified."
 app(Update): "Configuration item exec-file and exec-arg are added."
 app(Update): "--initrd option and configuration item exec-initrd are added."
 app(Update): "Path beginning of '~' in the configuration file is replaced to the home directory."
 app(Fix): "-Lhelp can be displayed even if -X is specified."

doc をcommit します
---------------------
 
doc をcommit します。
コメントは、「doc:Updated カテゴリー/パッケージ名 to バージョン」に設定します。

::

 doc: Updated emulators/nono to  0.7.0
 
 cvs diff -u CHANGES-2024
 
        Updated emulators/nono to 0.7.0 [jun 2024-02-26]

