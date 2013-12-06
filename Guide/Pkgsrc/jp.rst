.. 
 Copyright (c) 2013 Jun Ebihara All rights reserved.
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

firefox
""""""""""

::

 # cd /usr/pkgsrc/www/firefox
 # make package-install
 # cd /usr/pkgsrc/www/firefox-l10n
 # make package-install
 # cd /usr/pkgsrc/multimedia/adobe-flash-plugin11
 # make package-install

gedit
""""""""

::

 # cd /usr/pkgsrc/editors/gedit
 # make package-install

icewm
"""""""""

::

 # cd /usr/pkgsrc/wm/icewm
 # make package-install

漢字入力
""""""""""

::

 # cd /usr/pkgsrc/inputmethod/mozc-server
 # make package-install
 # cd /usr/pkgsrc/inputmethod/ibus-mozc
 # make package-install
 
 % ls -l ~/.xinitrc
 .xinitrcが存在しない場合はコピーする  !! 上書きしないよう注意！ 
 % cp /etc/X11/xinit/xinitrc ~/.xinitrc
 % vi .xinitrc                     ... 以下の行を追加
 export LANG=ja_JP.UTF-8
 ibus-daemon --xim &
 export GTK_IM_MODULE="ibus"
 export XMODIFIERS="@im=ibus"
 export QT_IM_MODULE="ibus"

emacs
"""""""""

::

 # cd /usr/pkgsrc/editors/emacs
 # make package-install
 # cd /usr/pkgsrc/inputmethod/mozc-elisp/
 # make package-install
 # emacs ~/.emacs
 (set-language-environment "Japanese")
 (require 'mozc)
 (setq default-input-method "japanese-mozc")

pdfビューワ
""""""""""""""""

::

 # cd /usr/pkgsrc/print/evince
 # make package-install

gnome/xfce
""""""""""""

::

 # cd /usr/pkgsrc/meta-pkgs/gnome
 # make package-install
 # cd /usr/pkgsrc/meta-pkgs/xfce4
 # make package-install


