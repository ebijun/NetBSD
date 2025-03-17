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

 DISTNAME=       nono-1.3.0

チェックサム作成
------------------

::  

 % make makesum
 -rw-r--r--  1 jun  wheel  1192 Jan 28 20:44 Makefile
 -rw-r--r--  1 jun  wheel   357 Nov  4 01:22 PLIST
 -rw-r--r--  1 jun  wheel   626 Jan 28 20:48 distinfo

 -rw-r--r--  1 root  125  1202 Feb 27 17:20 Makefile
 -rw-r--r--  1 root  125   357 Jan  8 20:42 PLIST
 -rw-r--r--  1 root  125   558 Feb 27 17:21 distinfo

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

 nono: update to 1.3.0.

 1.3.0 (2025/02/26)
 
 vm(New): "Implement VirtIO SCSI."
 vm(New): "X68030 MFP timer interrupts now support real-time synchronization."
 vm(New): "NWS-1750 system timer interrupt now supports real-time synchronization."
 vm(Update): "X68030 MFP free-run timer now doesn't use scheduler events."
 vm(Fix): "Fix an issue that specifying 2GB or more of memory would cause an error (on virt-m68k)."
 vm(Fix): "Fix an issue that full speed mode could not be relased by pressing SHIFT key in X68030 JP keyboard mode."
 vm(Fix): "Fix to transition to bus free phase when a SCSI device asserts RST."
 vm(Fix): "Fix an issue that the disk size over 10GB was not displayed correctly on SCSI device monitor."
 m68k(Update): "Make various improvements to 68040 table search processing."
 m68k(Update): "Improve almost 68040 instruction cycles somewhat closer."
 m68k(Fix): "Improve or implement some 68030 instruction cycles."
 m68k(Fix): "Fix an issue that the exception history could not detect the IOCS call on 68040."
 m68k(Update): "The exception history now supports Human68k DOS calls."
 m88k(Fix): "Fix an issue that access to devices other than main memory may fail since ver 0.7.2."
 host(Fix): "Fix an issue dropping ICMPv6 Echo Request packet to router's link local address on the usermode network."
 app(New): "Support --fd0, --fd1 options for X68030."
 GUI(Fix): "Remove incorrect software keyboard window from the menu on NWS-1750 and virt-m68k."
 vm(Update): "Change performance measurement gimic on virt-m68k from VirtIONet to GFTTY." 

doc をcommit します
---------------------
 
doc をcommit します。
コメントは、「doc:Updated カテゴリー/パッケージ名 to バージョン」に設定します。

::

 doc: Updated emulators/nono to 1.3.0
 
 cvs diff -u CHANGES-2025
 
        Updated emulators/nono to 1.3.0 [jun 2025-02-27]

