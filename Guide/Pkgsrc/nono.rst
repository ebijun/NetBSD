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

 DISTNAME=       nono-0.6.4

チェックサム作成
------------------

::  

 % make makesum  
 -rw-r--r--  1 jun  wheel  1163 Jan  8 11:33 Makefile
 -rw-r--r--  1 jun  wheel   558 Jan  8 11:33 distinfo



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

 nono: update to 0.6.4. 

 0.6.4 (2023/12/28)
 
 vm(New): "Implement a Windrv compatible device on X68030. You can access a host d
 irectory via the device on Human68k."
 vm(New): "Implement a contrast feature on X68030."
 vm(Update): "Implement that writing to the SPC is made to wait if the internal qu
 eue is full. You can write a SCSI media on Human68k."
 vm(Update): "DMAC now uses FC (Function Code) to access on X68030."
 vm(Update): "Connect the host's [PageUp], [PageDown] and [End] key to guest's [ROLL UP], [ROLL DOWN] and [UNDO] key respectively on X68030. "
 vm(Fix): "Fix the problem that SCC, FDC, SPC and Nereid are not reset correctly on X68030."
 vm(Fix): "Fix a CIIN condition on X68030."
 vm(Fix): "Fix $ED0000..$EDFFFF was user-accessible on X68030."
 vm(Fix): "Fix timing that mouse sends its data on X68030. It should not affect anything."
 GUI(New): "Rearrange menus. A part of "Device > Operation" and old "File" menus are integrated into"VM"."
 GUI(New): "Add "Send CTRL+OPT.1+DEL" menu on X68030."
 GUI(Fix): "Fix an abnormal termination when open the loglevel setting window since 0.6.3."
 debugger(Fix): "Fix an abnormal termination when the argument of command line option -b cannot be parsed as a hexadecimal number."
 debugger(New): "--bi-exg option."

doc をcommit します
---------------------
 
doc をcommit します。
コメントは、「doc:Updated カテゴリー/パッケージ名 to バージョン」に設定します。

::

 doc: Updated emulators/nono to  0.6.4
 
 cvs diff -u CHANGES-2024
 
        Updated emulators/nono to 0.6.4 [jun 2024-01-08]

