#!/bin/sh
# $Xorg: xinitrc.cpp,v 1.3 2000/08/17 19:54:30 cpqbld Exp $

userresources=$HOME/.Xresources
usermodmap=$HOME/.Xmodmap
sysresources=/etc/X11/xinit/.Xresources
sysmodmap=/etc/X11/xinit/.Xmodmap

# merge in defaults and keymaps

if [ -f $sysresources ]; then
    xrdb -merge $sysresources
fi

if [ -f $sysmodmap ]; then
    xmodmap $sysmodmap
fi

if [ -f $userresources ]; then
    xrdb -merge $userresources
fi

if [ -f $usermodmap ]; then
    xmodmap $usermodmap
fi

# start some nice programs
xset b off

#set keyboard layout
#setxkbmap -layout jp -option ctrl:swapcaps
setxkbmap -model jp106 jp

#uim
export GTK_IM_MODULE=uim
export LANG=ja_JP.UTF-8
#export LANG=en_US.UTF-8

uim-xim &
# To select input method via uim-pref-gtk userinterface.
# uim-pref-gtk 
export XMODIFIERS=@im=uim

#to install: pkg_add xfce4
#startxfce4 ;exit

xsetroot -bg black -grey
#kterm -geometry 80x25+0+0 -fk k14 -fn a14 -fr r14 -km euc&
xsetbg NetBSD.png

#for mikutter , click and start browser.
export BROWSER=dillo

xterm  -geometry 80x25+0+0 &

if [ -f /usr/pkg/bin/icewm ]; then
    icewm
else
    twm
fi
