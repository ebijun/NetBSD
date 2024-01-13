.. 
 Copyright (c) 2022-3 Jun Ebihara All rights reserved.
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

 DISTNAME=       nono-0.6.2

チェックサム作成
------------------

::  

 % make makesum  
 -rw-r--r--  1 root  wheel  1163 Aug 17 20:25 Makefile
 -rw-r--r--  1 root  wheel   558 Aug 17 20:25 distinfo

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

 nono: update to 0.6.3 .

 0.6.3 (2023/11/30)
 m68k(New): "Implement an instruction cache. Finally X68030 IPL can display corr
ect MPU clock speed."                                                           
 vm(New): "Implement areaset and extended areaset features on X68030."          
 vm(New): "Implement an option whether to cut FC2 or not on X68030."            
 vm(New): "Implement a system port monitor on X68030."                          
 vm(New): "Implement an access status monitor."                          
 vm(Update): "Restrict memory size to 255MB when using PROM image on LUNA-I."  
 vm(Update): "Change memory size limit to 512MB on LUNA-I, LUNA-88K and X68030."
 m68k(Fix): "Fix the problem that an address error while executing bus error han
dler does not cause double bus fault."                                         
 vm(Fix): Issue#131 "Correct interrupt levels from XP Processor on LUNA-88K."   
 GUI(Fix): Issue#133 "Fix the problem that the bitmap plane monitor did not supp
ort 256-color mode."                                                            
 build(Fix): "Make util/mkcgrom buildable on OpenBSD."
doc をcommit します
---------------------
 
doc をcommit します。
コメントは、「doc:Updated カテゴリー/パッケージ名 to バージョン」に設定します。

::

 doc: Updated emulators/nono to  0.6.3
 
 cvs diff -u CHANGES-2023
 
        Updated emulators/nono to 0.6.3 [jun 2023-12-10]


