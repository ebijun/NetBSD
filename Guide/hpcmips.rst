.. 
 Copyright (c) 2013-6 Jun Ebihara All rights reserved.
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

=================================
NetBSD/hpcmipsを使ってみる
=================================

特徴
----

* NetBSD/hpcmipsを利用するために、ディスクイメージを用意しました。
* NetBSDでmatt-nb... がマージされたあと、hpcmipsは不安定です。
* NetBSD7に向けて、バイナリイメージで試せるようにします。
* RPI向けイメージと同じバイナリを作ってみます。

準備するもの
-------------
* NetBSD/hpcmipsをサポートしているマシン (NEC mobilegear,sigmarion)
* 2GB コンパクトフラッシュ
* SigmarionII：FOMA接続ケーブル+USB ネットワークアダプタ
* PCMCIAネットワークカード (カードバス対応でないもの)

起動ディスクの作成
-------------------
* ディスクイメージのダウンロード

::

 # ftp ftp://ftp.netbsd.org/pub/NetBSD/misc/jun/hpcmips/
 2013-08-23-netbsd-hpcmips.img.gz

* 2GB以上のコンパクトフラッシュを準備します。
* ダウンロードしたディスクイメージを、コンパクトフラッシュ上で展開します。

::

	disklabel sd0  ..... 必ずインストールするSDカードか確認してください。
	gunzip < 2013-08-23-netbsd-hpcmips.img.gz|dd of=/dev/rsd0d bs=1m

NetBSD/hpcmipsの起動
------------------
#. コンパクトフラッシュをWindowsCE機に挿して起動します。
#. CF上に見えるhpcboot.exeを実行します。
#. メニューでカーネルを指定して起動します。
#. 少し待つと、NetBSDの起動メッセージが表示されます。

ログイン
---------

 rootでログインできます。

::

	login: root



