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

 DISTNAME=       nono-1.2.0

チェックサム作成
------------------

::  

 % make makesum
 -rw-r--r--  1 jun  wheel  1192 Jan 28 20:44 Makefile
 -rw-r--r--  1 jun  wheel   357 Nov  4 01:22 PLIST
 -rw-r--r--  1 jun  wheel   626 Jan 28 20:48 distinfo

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

 nono: update to 1.2.0.

 1.2.0 (2025/01/26)

 host(New): "Add a usermode (SLIRP) to host network driver."
 host(Update): "Change the behavior when hostnet-driver value is auto."
 vm(Update): "Even if the CPU goes into STOP state during full speed mode, keep it if DMAC is active on X68030."
 vm(Fix): "Fix problem that polling didn't resume when the drive select signal changed."
 vm(Fix): "Fix virtio_net not receiving multicast packets."
 vm(Fix): "Fix multicast hash on Lance(AM7990)."
 vm(Fix): "Fix RTL8019AS whole receiving algorithm including multicast hash. "
 vm(New): "Implement RSR.PHY bit on RTL8019AS."

doc をcommit します
---------------------
 
doc をcommit します。
コメントは、「doc:Updated カテゴリー/パッケージ名 to バージョン」に設定します。

::

 doc: Updated emulators/nono to 1.2.0
 
 cvs diff -u CHANGES-2025
 
        Updated emulators/nono to 1.2.0 [jun 2025-01-28]

