.. 
 Copyright (c) 2022-6 Jun Ebihara All rights reserved.
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

 DISTNAME=       nono-1.8.3

チェックサム作成
------------------

::  

 % make makesum

 drwxr-xr-x  2 jun  wheel   512 Jul 26 00:04 CVS
 -rw-r--r--  1 jun  wheel    54 May 14  2024 DESCR
 -rw-r--r--  1 jun  wheel  1202 Jul 26 00:04 Makefile
 -rw-r--r--  1 jun  wheel   357 Nov  2  2025 PLIST
 -rw-r--r--  1 jun  wheel   350 Jul 26 00:04 distinfo

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

 nono: update to 1.8.3.

 add options.mk for alsa and pulseaudio 
  https://gist.github.com/tsutsui/4d2f78d001871479e7e5a68695606952
 
 1.8.3 (2026/08/29)
 
 build(New): "Migrated to C++17."
 m68030(Fix): "Fix access to the cache-inhibited area. This fixes the issue where 4.4BSD failed to boot since ver 1.6.6."
 vm(Fix): "Fix and adjust "out of tune" mark on SSG monitor."
 vm(Update): "In CLI app, power-off sequence on the system port also makes power button off on X68030."
 debugger(Fix): "Fix branch information for DJNZ on HD64180."
 debugger(Fix): "Fix mnemonic of LD r,(IX+d) / LD (IX+d),r where r is H/L on HD64180."
 debugger(New): "Implement bt command."
 vm(Update): "MSX-DOS mode now can pass command line arguments to the guest command." 

doc をcommit します
---------------------
 
doc をcommit します。
コメントは、「doc:Updated カテゴリー/パッケージ名 to バージョン」に設定します。

::

 doc: Updated emulators/nono to 1.8.3
 
 cvs diff -u CHANGES-2026
 
        Updated emulators/nono to 1.8.3 [jun 2026-08-31]

