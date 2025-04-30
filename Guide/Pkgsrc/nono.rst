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

 DISTNAME=       nono-1.4.1

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

 nono: update to 1.4.1.

 1.4.1 (2025/04/30)
 
 m88k: "Fix several exception priorities."
 m88k: "Implement the illegal instruction exception."
 m88k: "Fix several DMx registers upon a data access exception."
 m88k: "Fix the behavior of the ld.d instruction when an exception occurred on the second word."
 m88k: "Fix that PID and SXIP registers were writeable."
 m88k: "Revert the search method inside the BATC/PATC to that of ver 0.6.1."
 vm: "Implement an interrupt handler in the builtin emulated PROM on LUNA-88K. This fixes the issue where the hexdump command on the OpenBSD/luna88k boot loader was hanging when accessing the bus error region."
 vm: "Modify and adjust the memory map on LUNA-88K."
 vm: "Implement the SCSI bus transition from the selection phase to the message out phase. This fixes the abnormal termination while booting UniOS Mach. (But it doesn't work yet.)"
 vm: "Change the handling of write-protected SCSI image files."
 vm: "Support the LUNA-88K software keyboard(?). As a result of this, several internal keycodes on LUNA-I and X68030 are also moved."
 debugger: "The breakpoint monitor now supports m88k."
 debugger: "The breakpoint monitor now supports 1-byte instructions like HD64180."
 debugger: "Fix the abnormal termination when a breakpoint has an invalid CPU name."
 debugger: "The vector table now supports LUNA-88K."
 debugger: "Change the syntax of the bv command."
 debugger: "The bi command supports some mnemonics."
 debugger: "Implement --bi and --bv options."
 util/nvramedit: "Fix the file size of NVRAM.DAT." 

doc をcommit します
---------------------
 
doc をcommit します。
コメントは、「doc:Updated カテゴリー/パッケージ名 to バージョン」に設定します。

::

 doc: Updated emulators/nono to 1.4.1
 
 cvs diff -u CHANGES-2025
 
        Updated emulators/nono to 1.4.1 [jun 2025-04-30]

