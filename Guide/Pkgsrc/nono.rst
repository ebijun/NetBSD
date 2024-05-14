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

 DISTNAME=       nono-0.7.2

チェックサム作成
------------------

::  

 % make makesum  
 -rw-r--r--  1 jun  wheel  1164 May 14 18:04 Makefile
 -rw-r--r--  1 jun  wheel   306 May 14 18:04 PLIST
 -rw-r--r--  1 jun  wheel   558 May 14 18:05 distinfo

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

 nono: update to 0.7.2. 

 0.7.2 (2024/05/11)

 m68k(Update): "Improve ATC and TT search performance about 10%."
 vm(Update): "Implement a burst transfer on LUNA and virt-m68k. It improves the performance of m68k by about 6-10% and m88
k by about 3%. (X68030 hardware doesn't support the burst transfer)"
 vm(Update): "Improve performance of whole virt-m68k and virtio-block slightly."
 vm(Update): "Minor adjustment for scheduler monitor and 88100 register monitor."
 vm(Update): "Change unit to 2MB/char on X68030 access stat monitor to be consistent with other VMs."
 vm(New): "Implement performance measurement gimic on virt-m68k."
 m68k(Fix): "Fix problem that "Restart VM" sometimes causes app termination since ver 0.6.3."


doc をcommit します
---------------------
 
doc をcommit します。
コメントは、「doc:Updated カテゴリー/パッケージ名 to バージョン」に設定します。

::

 doc: Updated emulators/nono to 0.7.2
 
 cvs diff -u CHANGES-2024
 
        Updated emulators/nono to 0.7.2 [jun 2024-05-14]

