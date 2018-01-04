#pkgsrc/sysutils/* are:
#BOARD=a10-olinuxino-lime
#BOARD=bananapi
#BOARD=bananapi-m3
#BOARD=beagleboard
#BOARD=beagleboneblack
#BOARD=beaglebonewhite
#BOARD=chip
#BOARD=chip-pro
#BOARD=cubieboard2
#BOARD=cubieboard4
#BOARD=cubietruck
#BOARD=hummingbird-a31
#BOARD=jetson-tk1
#BOARD=jetson-tx1
#BOARD=nanopi-m1
#BOARD=nanopi-neo
#BOARD=nanopi-neo2
#BOARD=orangepi-2
BOARD=orangepi-one
#BOARD=orangepi-plus2e
#BOARD=pine64
#BOARD=pinebook
#BOARD=pocketchip

PKG=/usr/pkg
DEVICE=sd0
MOUNT=/mnt

all: spl mount setconsole mkubootimage umount

spl:
	dd if=${PKG}/share/u-boot/${BOARD}/u-boot-sunxi-with-spl.bin of=/dev/r${DEVICE}d bs=1k seek=8 conv=sync

mkubootimage:
	mkubootimage -A arm -C none -O linux -T script -a 0 -n "NetBSD sunxi boot" ${MOUNT}/boot.cmd ${MOUNT}/boot.scr

setconsole:
	ed ${MOUNT}/boot.cmd < Command

mount:
	mount_msdos /dev/${DEVICE}e ${MOUNT}

umount:
	umount ${MOUNT}
