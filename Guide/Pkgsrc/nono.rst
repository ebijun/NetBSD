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


フリーズしているか確認
--------------------------

以下のURLを見て、pkgsrcがフリーズしているか確認します。フリーズしている時はバージョンアップしません。

 https://mail-index.netbsd.org/pkgsrc-changes/index.html
 https://www.pkgsrc.org/is-a-freeze-on/

バージョン指定
---------------------

Makefile 内のバージョンをあげます。

::

 DISTNAME=       nono-1.1.0

チェックサム作成
------------------

::  

 % make makesum
 -rw-r--r--  1 jun   wheel  1148 Dec 29 04:35 Makefile
 -rw-r--r--  1 jun   wheel   357 Nov  4 01:22 PLIST
 -rw-r--r--  1 root  wheel   558 Dec 29 04:36 distinfo

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

 nono: update to 1.1.0.

 1.1.0 (2024/12/25)

 m68k(New): "Start implementing 68040. Currently, it supports some new instructions, MMU and FPU."
 m68k(New): "Implement cpSAVE, cpRESTORE behavior on 68030."
 m68k(Fix): "Fix the order that FSAVE writes to the memory."
 m68k(Fix): "Fix flags on FBcc, FDBcc, FScc, FTRAPcc."
 m68k(Fix): "Fix branch address calculation on FDBcc."
 m68k(Fix): "Fix OVFL, UNFL flags on FMOVE.X FPn,<ea>."
 m68k(Fix): "Improve result of FMOVE.[BW] FPn,<ea> when FPn is out of range."
 m68k(Fix): "Fix a problem that there were cases where F-line exception was not occurred even if the F-line instruction pattern was illegal."
 m68k(Fix): "Implement that initialize FPU registers on the FPU reset."
 m68k(Fix): "Implement a format error exception on RTE and FRESTORE."
 m68k(Update): "Implement the decimal representation of the FPn on the register monitor."
 m68k(Update): "If an instruction has an illegal EA, the debugger now shows it as an illegal instruction."
 m68k(Update): "The debugger now shows branch condition even on FBcc, FDBcc, FScc and FTRAPcc."
 hd64180(Fix): "Fix CPIR, CPDR, INIR, INDR, OTIR, OTDR instructions."
 hd64180(Fix): "Fix contents that is pushed into the stack when the undefined opcode trap."
 hd64180(Update): "Supports disassemble of Z80's undefined opcode as SLL or LD IXr,n."
 hd64180(New): "Add xp-clock configuration."
 vm(New): "Implement a terminal emulation of serial console on virt-m68k (and NEWS)."
 vm(New): "Implement BI_COMMANDLINE on BootInfo. Now you can specify the root device to NetBSD/virt68k."
 vm(Fix): "Clear the SPC's internal queue on the reset."
 vm(Fix): "Implement a reset on virtio-net."
 vm(Fix): "Fix a problem that Goldfish Timer might not work after the reset."
 vm(Fix): "Clear the Goldfish PIC's monitor counter on the reset."
 GUI(Fix): "Fix SPC address label on X68030 SPC monitor."
 GUI(Fix): "Support virt-m68k on the vector table monitor."
 GUI(Fix): "Fix a proiblem where cursor key input was sometimes not possible." 

doc をcommit します
---------------------
 
doc をcommit します。
コメントは、「doc:Updated カテゴリー/パッケージ名 to バージョン」に設定します。

::

 doc: Updated emulators/nono to 1.1.0
 
 cvs diff -u CHANGES-2024
 
        Updated emulators/nono to 1.1.0 [jun 2024-12-29]

