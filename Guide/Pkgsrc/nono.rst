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

 DISTNAME=       nono-1.6.0

チェックサム作成
------------------

::  

 % make makesum
 
-rw-r--r--  1 jun  wheel    54 May 14  2024 DESCR
-rw-r--r--  1 jun  wheel  1202 Nov  2 14:42 Makefile
-rw-r--r--  1 jun  wheel   357 Nov  2 14:43 PLIST
-rw-r--r--  1 jun  wheel   350 Nov  2 14:44 distinfo

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

 nono: update to 1.6.0.

 1.6.0 (2025/10/29)

 host(New): "Implement sound output."
 vm(New): "Implement ADPCM (playback only) on X68030."
 vm(Update): "Implement external request transfer on X68030 DMAC."
 vm(Update): "Implement link array chain mode on X68030 DMAC."
 vm(Update): "Separate loglevel per channel."
 vm(Update): "Implement FPACK __LTOS on Human68k mode."
 GUI(New): "Implement thread monitor."
 app(New): "Support specifying cores for heterogeneous CPU (formally)."
 vm(Fix): "Revert to suppressing full speed mode on key press on X68030. It was removed in ver 1.5.0, but was reintroduced to address unintended side effects."
 host(Update): "host-avx2, host-neon are renamed to hostcpu-avx2, hostcpu-neon."
 app(Fix): "Fix possible abnormal termination if the configuration file contains non-ASCII characters on NetBSD 11.0_BETA."


doc をcommit します
---------------------
 
doc をcommit します。
コメントは、「doc:Updated カテゴリー/パッケージ名 to バージョン」に設定します。

::

 doc: Updated emulators/nono to 1.6.0
 
 cvs diff -u CHANGES-2025
 
        Updated emulators/nono to 1.6.0 [jun 2025-11-02]

