.. 
 Copyright (c) 2013-8 Jun Ebihara All rights reserved.
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

観光ガイドを印刷する
---------------------

ダウンロードする
~~~~~~~~~~~~~~~~~

::

 http://www.re.soum.co.jp/~jun/OSC2018hokkaido.pdf

evince PostScript形式で印刷する

output.psができる。

::

 output.ps

両面冊子形式で印刷
~~~~~~~~~~~~~

先頭に両面印刷するPostScriptコマンドを追加したファイルを作って、lpr
で印刷する。これで両面冊子形式で印刷できる。

::

 cat << EOF > a.ps
 %!
 << /Duplex true /Tumble true >> setpagedevice
 EOF
 psbook output.ps |psnup -2 >> a.ps
 lpr a.ps

白黒にする
~~~~~~~~~

ghostscript経由でカラーPDFを白黒PDFに変換する。

::

 gs -sDEVICE=pdfwrite -dProcessColorModel=/DeviceGray -dColorConversionStrategy=/Gray -dPDFUseOldCMS=false -o out.pdf -f in.pdf

白黒PDFファイルからPostScriptに変換する
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#. evince out.pdf →印刷でoutput.psに出力
#. 冊子形式のPostScriptに変換する
#. 15部印刷する

::

 repeat 15 lpr a.ps


hplipのインストール
~~~~~~~~~~~~~~~~~~~~~~

::

 # cd /usr/pkgsrc/print/hplip
 # /etc/mk.confに
 PKG_OPTIONS.hplip=qt追加
 # hpli..

cupsのインストール
~~~~~~~~~~~~~~~~~~~

::

 # cd /usr/pkgsrc/print/cups
 # make package-install
 # /etc/rc.conf に cupsd=YESを追加する
 # ブラウザでhttp://localhost:631にアクセス。
 # Administratorタブを開いて、rootでログイン。


