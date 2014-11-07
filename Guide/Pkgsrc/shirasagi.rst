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

::

 # cd /usr/pkgsrc/pkgtools/url2pkg
 # make package-install
 # which url2pkg
 /usr/pkg/bin/url2pkg
 # cd /usr/pkgsrc/www
 # mkdir shirasagi
 # cd shirasagi
 # url2pkg https://github.com/shirasagi/shirasagi/archive/v0.3.0.tar.gz
 # cd /usr/pkgsrc/www/shirasagi/work/shirasagi-0.3.0/doc
 # cat install.txt
 # cd /usr/pkgsrc/www/ruby-rails32
 # make package-install
 # cd /usr/pkgsrc/devel/git-base
 # make package-install
 # cd /usr/pkgsrc/security/mozilla-rootcerts
 # mozilla-rootcerts install
 # cd /usr/pkgsrc/lang/python27
 # make package-install
 # ln -s /usr/pkg/bin/python27 /usr/pkg/bin/python
 # cd /usr/pkgsrc/graphics/ruby-RMagick
 # make package-install
 # ftp http://pkgsrc-wip.sourceforge.net/snapshots/pkgsrc-wip-2014????-snapshot.tar.gz
 # tar xzvf pkgsrc-wip-2014????-snapshot.tar.gz -C /usr/pkgsrc
 # cd /usr/pkgsrc/wip/ruby-therubyracer
 check http://inoao.hatenablog.com/entry/2014/03/27/183523
 # gem200 install --version '=3.3.10.4' libv8
 # pkg-wip : rubyracer
 # cp /var/www/shirasagi
 # cp config/samples/* config
 # bundle install

