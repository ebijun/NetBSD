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

OSC2016Okinawa
-----------------------
 
ISO:     201606230230Z
NetBSD:  7.99.32
2016-07-02-netbsd-raspi-earmv6hf.img
 
- http://cdn.netbsd.org/
- Kernel for RPI3:
 http://mail-index.netbsd.org/port-arm/2016/06/16/msg003830.html
 http://cdn.netbsd.org/pub/NetBSD/misc/jun/raspberry-pi/2016-07-02-earmv6hf/RPI3/
 
Update:

- NetBSD-current 7.99.32 evbarm-earmv6hf 201606230230Z rpi.img from nyftp.
- git-base-2.9.0
- mlterm-3.7.1
- perl-5.24.0
- mikutter 3.4.1
- XM6i-0.54-netbsd7.0-earmv6hf-2015Q2.tar.gz
- set2pkg: update via pkgsrc.

OSC2016Hokkaido
------------------------

ISO:     201606090220Z
NetBSD:  7.99.30
2016-06-18-netbsd-raspi-earmv6hf.img
 
- NetBSD-current 7.99.30 evbarm-earmv6hf 201606090220Z rpi.img from nyftp.
- GCC 5.4.0
- mikutter 3.4
- security.pax.mprotect.enabled

::

  man security
  man paxctl
  sysctl -a |grep pax
  If application failed, such as omxplayer.
  try to test 
  sysctl -w security.pax.mprotect.enabled=0 
 
OSC2016 Nagoya
------------------------

ISO:     201605191830Z
NetBSD:  7.99.29
2016-05-28-netbsd-raspi-earmv6hf.img
 
Update:

- NetBSD-current 7.99.29 evbarm-earmv6hf 201605191830Z rpi.img from nyftp.
- mikutter 3.3.9
- freetype2:  /usr/X11R7/include/freetype2/freetype
  https://github.com/IIJ-NetBSD/netbsd-src/commit/c792b960afd10ac6a34511f09f7c3b0aa59c8390#diff-e4a2dac7a0572d4d146feafd47940d71
  update x11-links package,if compilation fails depend on freetype.
 
OSC2016 Gunma
------------------------

ISO:     201605051730Z
NetBSD:  7.99.29
2016-05-14-netbsd-raspi-earmv6hf.img
 
Update:

- NetBSD-current 7.99.29 evbarm-earmv6hf 201605051730Z rpi.img from nyftp.
- merge nick-nhusb tree
- openssl 1.0.1t 3 May 2016
- SHARP MZ700 emulator

::

  # npm install -g mz700-js
  # cd /usr/pkg/lib/node_modules/mz700-js
  # npm start
  # mz700-js@0.0.0 start  /usr/pkg/lib/node_modules/mz700-js
  # access http://localhost:3000/MZ-700/client.html

For Happy 23rd Birthday, src!
-----------------------

ISO:     201603211520Z
NetBSD:  7.99.26
2016-03-24-netbsd-raspi-earmv6hf.img 
 
Update:

- https://github.com/ebijun/NetBSD/blob/master/dmesg/earmv6hf/RPI3
- NetBSD-current 7.99.26 evbarm-earmv6hf 201603211520Z rpi.img from nyftp.
- ruby22
- mlterm-3.7.0
 
AsiaBSDCon2016
-----------------------

ISO:     201603090310Z
NetBSD:  7.99.26
2016-03-11-netbsd-raspi-earmv6hf.img
 
Update:

- not tested on RPI3
- NetBSD-current 7.99.26 evbarm-earmv6hf 201603090310Z rpi.img from nyftp.
- mikutter-3.3.8
- OpenSSL 1.0.1s
- XM6i - SHARP X68030 Emulator for NetBSD/x68k (Thanx isaki@)
- XM6i-0.53-netbsd7.0-earmv6hf-2015Q2.tar.gz
- sayaka 
- HDMI Display failure on X ,On-Lap 2501M (reported from @matoken) 
    https://twitter.com/matoken/status/702656906251210753
- mcomix .. Book scanning data viewer
- mpv
- NetBSD GPIO DOC by Marina Brown
-  https://github.com/catskillmarina/netbsd-gpio-doc/blob/master/README.md

Open Source Conference 2016 Tokyo/Spring
-----------------------


ISO:     201602172150Z
NetBSD:  7.99.26
2016-02-27-netbsd-raspi-earmv6hf.img
 
Update:

- NetBSD-current 7.99.26 evbarm-earmv6hf 201602172150Z rpi.img from nyftp.
- mikutter-3.3.6
 
Open Source Conference 2016 Hamanako
-----------------------

ISO:     201601181250Z
NetBSD:  7.99.25

Update:
 
- NetBSD-current 7.99.25 evbarm-earmv6hf 201601181250Z rpi.img from nyftp.
- mikutter-3.3.5
- bind 9.10.3-P3
- OpenSSL 1.0.1r
- musica-0.3.22-netbsd6-evbarm-earmv6hf.tgz for evaluation.
- CVE-2016-0777: get rid of roaming.
- mikutter-3.3.3
- bind
- nodejs
- omxfinder (https://www.npmjs.com/package/omxfinder)
- openjdk
- scribus
- (inkscape)
- gimp
- emacs
- evince
- wordpress
- sphinx
- (shotwell)
- Automatic resize partition: see /etc/rc.conf and /etc/fstab

::

  1. copy image to SD/MicroSD
  2. Boot 
  3. Calculate and resize ld0 partition and automatic reboot
  4. after the reboot,root partition fit for your card.
    http://movapic.com/pic/20150416115108552fa22c4f225
    In this image, ld0a re-created with newfs -b 4096.
 
2015/12
-----------------------
 
ISO:     201512241350Z
NetBSD:  7.99.25
2015-12-27-netbsd-raspi-earmv6hf.img 

Update:

- NetBSD-current 7.99.25 evbarm-earmv6hf 201512241350Z rpi.img from nyftp.
-  https://github.com/ebijun/NetBSD/blob/master/dmesg/earmv6hf/RPI0
- RPI zero support
- bind-9.10.3-P2
- kodi: boot failed on my environment.
- www/otter-browser: compiling.
- omxplayer: sometimes core dumps.
- omxplayer: need /proc/cpuinfo to buy MPEG-2 license key.
 
Open Source Conference 2015 Tokushima
-----------------------

ISO:     201511091610Z
NetBSD:  7.99.21
2015-11-14-netbsd-raspi-earmv6hf.img 
 
Update:
- NetBSD-current 7.99.21 evbarm-earmv6hf 201511091610Z rpi.img from nyftp.

KANSAI OPEN FORUM 2015
-----------------------
 
ISO:     201510310800Z
NetBSD:  7.99.21
2015-11-07-netbsd-raspi-earmv6hf.img
 
Update:

- NetBSD-current 7.99.21 evbarm-earmv6hf 201510310800Z rpi.img from nyftp.
- git-base-2.6.2
- kterm-6.2.0nb24
- mlterm-3.6.0
 
Open Source Conference 2015 Tokyo/Fall
-----------------------

ISO:     201510182130Z
NetBSD:  7.99.21
2015-10-25-netbsd-raspi-earmv6hf.img
 
Update:

- NetBSD-current 7.99.21 evbarm-earmv6hf 201510182130Z rpi.img from nyftp.
- www/firefox
- Testing firefox-41.0.2.tgz and firefox-l10n-41.0.2.tgz (thanx jmcneill)
- XM6i - SHARP X68030 Emulator for NetBSD/x68k (Thanx isaki@)
- XM6i-0.52-netbsd7.0-earmv6hf-2015Q2.tar.gz
 
 
Open Source Conference 2015 Fukuoka
-----------------------

ISO:     201509271300Z
NetBSD:  7.99.21
2015-10-03-netbsd-raspi-earmv6hf.img
 
Update:

- NetBSD-current 7.99.21 evbarm-earmv6hf 201509271300Z rpi.img from nyftp.
- mikutter 3.2.9
- pkg_in/pkg_summary
- Postfix 2.11.6

Open Source Conference 2015 Hiroshima
-----------------------

ISO:     201509101940Z
NetBSD:  7.99.21
2015-09-19-netbsd-raspi-earmv6hf.img
 
Update:

- NetBSD-current 7.99.21 evbarm-earmv6hf 201509101940Z rpi.img from nyftp.
- bind 9.10.2-P4
 

Open Source Conference 2015 Niigata
-----------------------

ISO:     201509012200Z
NetBSD:  7.99.21
2015-09-05-netbsd-raspi-earmv6hf.img
 
Update:

Open Source Conference 2015 Shimane
-----------------------

ISO:     201508181510Z
NetBSD:  7.99.21
2015-08-22-netbsd-raspi-earmv6hf.img
 
Update:

- NetBSD-current 7.99.21 evbarm-earmv6hf 201508181510Z rpi.img from nyftp.
   
Open Source Conference 2015 Kansai@Kyoto
-----------------------

ISO:     201508041420Z
NetBSD:  7.99.20
 
Update:

- RPI2 boot on multi processor: (CPU1-3 enabled!) by  Nick Hudson
- UHS-I support by Jared McNeill
- NetBSD-current 7.99.20 evbarm-earmv6hf 201508041420Z rpi.img from nyftp.
- XM6i - SHARP X68030 Emulator for NetBSD/x68k (Thanx isaki@)
- XM6i-0.51-netbsd7.99-earmv6hf-2015Q2.tar.gz
- www/midori,epiphany
 
