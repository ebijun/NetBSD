.. 
 Copyright (c) 2014 Jun Ebihara All rights reserved.
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
NetBSDで観光ガイドを作ってみる
=================================

イベントで配る小冊子を作る
--------------------------------

オープンソースカンファレンスではいつもNetBSDブースで「観光ガイド」と
いう小冊子を配っています。この作り方を紹介します。

::

  観光ガイド一覧
  https://github.com/ebijun/osc-demo

観光ガイドを配るまで
--------------------------------
観光ガイドはA4 20ページくらいのPDFファイルです。印刷はセブンイレブンの
コピー機を使っています。USBメモリに入れたPDFファイルを、セブンイレブンに
あるコピー機でカラー1部,白黒15部印刷します。
そのとき「小冊子印刷」を選ぶと、コピー機がページの割付をしてくれて、
A5サイズの小冊子を印刷できます。小冊子印刷で印刷するPDFファイルの
ページ数は4の倍数にしておきます。一回にかかる費用は2800円程度です。

観光ガイドの構造
--------------------------------
観光ガイドは、3つのPDFを組み合わせて作っています。
1. 表紙
2. 本文
3. 裏表紙

PDFを組み合わせる
~~~~~~~~~~~~~~~~~~~~~~~
PDFを組みあわせて、ひとつのPDFファイルにするときには、
pdfshufflerを使っています。

::

 # cd /usr/pkgsrc/print/pdfshuffler
 # make package-install
 % pdfshuffler

表紙
~~~~~~~~~

表紙は、WindowsのIllustratorで作って、PDF出力しています。
ガイドを作りはじめた頃はWindowsで作っていました。
NetBSDならinkscapeが使えます。

::

 # cd /usr/pkgsrc/graphics/inkscape
 # make package-install
 % inkscape

裏表紙
~~~~~~~

裏表紙は、scribusを使っています。これもPDF出力できます。

::

 # cd /usr/pkgsrc/print/scribus-qt4
 # make package-install
 % scribus

本文
-------------
本文部分は、scribusとgithubを組み合わせて使っています。

::

　# pkgsrc/textproc/py-sphinx
  # make package-install


Sphinxでドキュメントを作る
--------------------------
sphinx-quickstartコマンドを実行すると、文書のスケルトンを作ってくれます。

::

  % sphinx-quickstart 
  Welcome to the Sphinx 1.2.2 quickstart utility.
  
  Please enter values for the following settings (just press Enter to
  accept a default value, if one is given in brackets).
  
  Enter the root path for documentation.
  > Root path for the documentation [.]: 
  
  You have two options for placing the build directory for Sphinx output.
  Either, you use a directory "_build" within the root path, or you separate
  "source" and "build" directories within the root path.
  > Separate source and build directories (y/n) [n]: 
  
  Inside the root directory, two more directories will be created; "_templates"
  for custom HTML templates and "_static" for custom stylesheets and other static
  files. You can enter another prefix (such as ".") to replace the underscore.
  > Name prefix for templates and static dir [_]: 
  
  The project name will occur in several places in the built documentation.
  > Project name: Pipe Piper Paper
  > Author name(s): Jun Ebihara
  
  Sphinx has the notion of a "version" and a "release" for the
  software. Each version can have multiple releases. For example, for
  Python the version is something like 2.5 or 3.0, while the release is
  something like 2.5.1 or 3.0a1.  If you don't need this dual structure,
  just set both to the same value.
  > Project version: 1.0
  > Project release [1.0]: 0
  
  The file name suffix for source files. Commonly, this is either ".txt"
  or ".rst".  Only files with this suffix are considered documents.
  > Source file suffix [.rst]: 
  
  One document is special in that it is considered the top node of the
  "contents tree", that is, it is the root of the hierarchical structure
  of the documents. Normally, this is "index", but if your "index"
  document is a custom template, you can also set this to another filename.
  > Name of your master document (without suffix) [index]: [39;49;00m
  
  Sphinx can also add configuration for epub output:
  > Do you want to use the epub builder (y/n) [n]: 
  
  Please indicate if you want to use one of the following Sphinx extensions:
  > autodoc: automatically insert docstrings from modules (y/n) [n]: 
  > doctest: automatically test code snippets in doctest blocks (y/n) [n]: 
  > intersphinx: link between Sphinx documentation of different projects (y/n) [n]: 
  > todo: write "todo" entries that can be shown or hidden on build (y/n) [n]:
  > coverage: checks for documentation coverage (y/n) [n]:
  > pngmath: include math, rendered as PNG images (y/n) [n]: 
  > mathjax: include math, rendered in the browser by MathJax (y/n) [n]: 
  > ifconfig: conditional inclusion of content based on config values (y/n) [n]:
  > viewcode: include links to the source code of documented Python objects (y/n) [n]:
  
  A Makefile and a Windows command file can be generated for you so that you
  only have to run e.g. `make html' instead of invoking sphinx-build
  directly.
  > Create Makefile? (y/n) [y]: 
  > Create Windows command file? (y/n) [y]: 
  
  Creating file ./conf.py.
  Creating file ./index.rst.
  Creating file ./Makefile.
  Creating file ./make.bat.
  
  Finished: An initial directory structure has been created.
  
  You should now populate your master file ./index.rst and create other documentation
  source files. Use the Makefile to build the docs, like so:
     make builder
  where "builder" is one of the supported builders, e.g. html, latex or linkcheck.

html出力をしてみる
------------------
gmake htmlを実行すると、_build/html以下にhtmlファイルを作ってくれます。


::

  % gmake html
  % ls _build/html
  _sources        genindex.html   objects.inv     searchindex.js
  _static         index.html      search.html

テキスト出力をしてみる
------------------------------------
gmake textを実行すると、_build/テキスト以下にtxtファイルを作ってくれます。

::

  % gmake text 
  % ls _build/text
  index.txt

Sphinxのディレクトリをgithubに登録する
------------------------------------------
Sphinxのディレクトリをgithubに登録して、文章の版数管理とプレビューを
githubでやってみます。

::

  https://github.com/ebijun/NetBSD/tree/master/Guide

たとえば、
https://github.com/ebijun/NetBSD/blob/master/Guide/Luna.rst
を見ると、Lunaの薄い本の内容がそれっぽくフォーマットされて出力されます。

観光ガイド本文を作る
------------------------------------------
いろんな文章を、markdownでかいて、どんどんgithubに登録していきます。
観光ガイドを作るときは、イベントに合わせた文章をいくつか選んで、
index.rstに登録します。

::

  https://raw.githubusercontent.com/ebijun/NetBSD/master/Guide/index.rst
     :
   Place/fukuoka     
    https://github.com/ebijun/NetBSD/blob/master/Guide/Place/fukuoka.rst
   Place/intro
    https://github.com/ebijun/NetBSD/blob/master/Guide/Place/intro.rst
   RPI
    https://github.com/ebijun/NetBSD/blob/master/Guide/RPI.rst
   Place/asiabsdcon
    https://github.com/ebijun/NetBSD/blob/master/Guide/Place/asiabsdcon.rst


gmake singlehtmlを実行します。すべての文章が一つのhtmlファイルにまとまります。

::

 % gmake singlehtml
 % ls _build/singlehtml
 _images      _static      index.html   objects.inv

まとまった文章をfirefoxで開きます。全体を20ページにするなら、表紙を裏表紙を抜いた18ページ分になるよう、firefoxの表示縮尺を調整して、PDFで出力します。

 % firefox _build/singlehtml/index.html

PDFを組み合わせる
-------------------------

表紙、裏表紙、本文3つのPDFをpdfshufflerでひとつのPDFファイルにつなぎあわせて、
FTPサーバにアップデートします。アップデートしたらtwitterなりfacebookなりで
報告します。イベント終了後には、URLを配布ドキュメントとして連絡します。


まとめ
-------------------------
イベントごとに配布している小冊子をNetBSD上で作る方法を紹介しました。
おもにAtomのネットブックでいつも作っていますが、
NetBSDであればどのマシンでも手順自体はおなじです。



