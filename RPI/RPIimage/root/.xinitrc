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
xset +fp /usr/pkg/lib/X11/fonts/TTF
xset +fp rehash
xset b off
#setxkbmap -layout jp -option ctrl:swapcaps
setxkbmap -layout jp

#uim
export GTK_IM_MODULE=uim
export LANG=ja_JP.UTF-8
uim-xim &
export XMODIFIERS=@im=uim

xsetroot -bg black -grey
kterm -geometry 80x25+0+0 -fk k14 -fn a14 -fr r14 -km euc&
xsetbg Oshimaya/proudly_1280x800.jpg
xterm &

if [ -f /usr/pkg/bin/icewm ]; then
    icewm
else
    twm
fi
