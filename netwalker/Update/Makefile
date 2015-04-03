# Update NetWalker NetBSD image on USB memory
# sd0: Netwalker
# sd1: cdimage

MACHINE=evbarm
ARCH=earmv7hf
HARDWARE=NETWALKER

USB=/dev/sd0
MNT=/mnt
USB_ISO=/dev/sd1
MNT_ISO=/mnt1

VND_CD=vnd2
MNT_CD=/mnt2
SETS=${MNT_CD}/${MACHINE}/binary/sets

TARZ=base.tgz comp.tgz games.tgz man.tgz misc.tgz modules.tgz tests.tgz text.tgz xbase.tgz xcomp.tgz xetc.tgz xfont.tgz xserver.tgz

all: mount image umount

mount:
	fsck ${USB}a
	mount ${USB}a ${MNT}
	mount_msdos ${USB_ISO}e ${MNT_ISO}
	vnconfig ${VND_CD} `ls -t ${MNT_ISO}/*${ARCH}*.iso|head`
	mount_cd9660 /dev/${VND_CD}a ${MNT_CD}

umount:
	umount ${MNT_CD}
	vnconfig -u ${VND_CD}
	umount ${MNT}
	umount ${MNT_ISO}

image:
	for i in ${TARZ}; do echo $${i};tar xzpf ${SETS}/$${i} -C ${MNT}; done
	tar xzvf ${SETS}/kern-${HARDWARE}.tgz -C ${MNT}
	cp ${SETS}/etc.tgz ${MNT}
