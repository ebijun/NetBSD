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

 DISTNAME=       nono-1.5.0

チェックサム作成
------------------

::  

 % make makesum
 
 -rw-r--r--  1 root  125  1202 Mar 31 10:45 Makefile
 -rw-r--r--  1 root  125   357 Mar  3 21:35 PLIST
 -rw-r--r--  1 root  125   555 Mar 31 10:45 distinfo

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

 nono: update to 1.5.0.

 1.5.0 (2025/09/07)

 vm(New): "Implement 1024x1024 mode of the graphic screen partially on X68030. T
his makes NetBSD/x68k X server work though default configuration only."
 vm(New): "Implement VIRTIO_BLK_T_GET_ID command in VirtIO Block."
 vm(Update): "Limit suppressing full speed mode by key press to LUNA."
 vm(Update): "Create an initialized SRAM.DAT if it doesn't exist on X68030. This
 also obsoletes --create-sram option."
 vm(Fix): "Fix wait state count for Nereid bank memory."
 m88k(Update): "Implement that floating-point instructions raise an exception wh
en SFD1 is set."
 m88k(Fix): "Fix missing exception for rte instruction in user mode."
 GUI(Update): "Display MHz too in the performance counter."
 GUI(Fix): "Fix possible abnormal termination when opening or closeing some moni
tor windows."
 host(Update): Reimplement log."

doc をcommit します
---------------------
 
doc をcommit します。
コメントは、「doc:Updated カテゴリー/パッケージ名 to バージョン」に設定します。

::

 doc: Updated emulators/nono to 1.5.0
 
 cvs diff -u CHANGES-2025
 
        Updated emulators/nono to 1.5.0 [jun 2025-09-08]

