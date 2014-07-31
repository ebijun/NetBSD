.. 
 Copyright (c) 2013-4 Jun Ebihara All rights reserved.
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
KOBOでNetBSDを動かしてみる
=================================

目標
----

* KOBOでNetBSDを動かしてみます。
* KOBOにシリアルポート経由で接続します。
* バイナリイメージで試せるようにします。
* RPI向けイメージと同じイメージで起動します。

できることとできないこと
-------------------------

* NetBSDが起動します。
* 外部から電源を供給できるUSBハブ経由で接続したUSB機器を利用できるはずです。
* 電子インクは利用できません。

準備するもの
-------------
* KOBO
* 2GB 以上のmicro SDカード2枚
* シリアル接続ケーブル
* KOBOとシリアルを接続するジャンパ線

::

 秋月:FTDI 3.3V http://akizukidenshi.com/catalo
 TXD: 橙色
 RXD: 黄色
 GND: 黒色

microSDカードの設定
--------------------
 kobo touchには、内蔵microSDスロットと、脇部分にあるmicroSDスロットがあります。内蔵microSDスロットにubootイメージを書き込んだmicroSDを挿します。
脇部分にあるmicroSDスロットには、RPI用に作ったイメージを挿します。
元から刺さっていたmicroSDは大事に保管しておきます。
もしNetBSD起動に飽きた時でも、本来の電子図書として楽しく使えます。
KOBOではmicroSDに書き込んだPDFファイルも読めるので、
PDFビューワとしても便利です。

シリアルケーブル
------------------
 まず裏蓋を開けます。右下の部分にTX,RXと書いた基盤の穴があります。
ここにシリアルポートを接続します。

uboot
-----
 KOBO用ubootイメージは以下の場所にもあります。

::

 http://rappappararin.blogspot.jp/2012/09/kobou-boot.html
 http://rappappararin.blogspot.jp/2012/09/kobonetbsd.html
 https://docs.google.com/open?id=0B-K-8275486qNDk2VFVKS3ZaOHc

以下のコマンドでカーネルをロードして起動します。

::

    mmcinfo 1
    fatload mmc 1 0x70800000 kobo.bin
    go 0x70800000

または、環境変数に引数を設定しておきます。

::

 BR-1A # setenv bootcmd_netbsd 'mmcinfo 1;fatload mmc 1 0x70100000 kobo.bin; go 0x70100000'
 BR-1A # setenv bootcmd 'run bootcmd_netbsd'
 BR-1A # saveenv

