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

 DISTNAME=       nono-1.4.0

チェックサム作成
------------------

::  

 % make makesum
 
 -rw-r--r--  1 root  125  1202 Mar 31 10:45 Makefile
 -rw-r--r--  1 root  125   357 Mar  3 21:35 PLIST
 -rw-r--r--  1 root  125   555 Mar 31 10:45 distinfo

make package して動作を確認します。
 
Patch /usr/pkgsrc/emulators/nono/patches/patch-cli_Makefile failed

1 out of 1 hunks failed--saving rejects to po/Makefile.rej
1 out of 1 hunks failed--saving rejects to wx/Makefile.rej

ERROR: Patching failed due to modified or broken patch file(s):
ERROR: 	/usr/pkgsrc/emulators/nono/patches/patch-cli_Makefile
ERROR: 	/usr/pkgsrc/emulators/nono/patches/patch-po_Makefile
ERROR: 	/usr/pkgsrc/emulators/nono/patches/patch-wx_Makefile

 
 
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

 nono: update to 1.4.0.

 pkgsrc:
  

 1.4.0 (2025/03/30)
 
 vm(New): "Implement HD647180 ASCI (Asynchronous Serial Communication Interface)."
 vm(Fix): "Fix an issue that keyboard LED changes may not be reflected in the software keyboard window on X68030."
 host(New): "Implement run-time switching of the network and serial host driver."
 app(Update): "Change hostcom-driver=cons to hostcom-driver=console (cons is still available)."
 GUI(Fix): "Fix an issue that the title might not change after leaving mouse mode."
 GUI(Fix): "Fix abnormal terminations caused by status panel width."
 GUI(Fix): "Fix an issue that changing the font size while the log monitor is displayed might cause an abnormal termination."
 GUI(Fix): "Fix an issue that changing the font size might break layout on the log monitor and LCD monitor."
 GUI(Fix): "Fix several issues that drawing window might cause abnormal termination."
 GUI(Fix): "Adjust button size on the memory monitor."
 GUI(Update): "Adjust main window layout when the window is shrunk."
 GUI(Update): "Adjust initial size of memory monitorand bitmap monitor."
 GUI(Update): "Adjust window stretch of memory monitor, log monitor, history monitor and vector monitor."

doc をcommit します
---------------------
 
doc をcommit します。
コメントは、「doc:Updated カテゴリー/パッケージ名 to バージョン」に設定します。

::

 doc: Updated emulators/nono to 1.4.0
 
 cvs diff -u CHANGES-2025
 
        Updated emulators/nono to 1.4.0 [jun 2025-03-31]

