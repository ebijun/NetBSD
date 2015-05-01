# Update NetWalker NetBSD image on USB memory
# sd0: Netwalker
# sd1: cdimage

MACHINE=evbarm
ARCH=earmv7hf
HARDWARE=NETWALKER

FILE=`date +%Y%m%d`.img
VND_FILE=vnd0
MNT=/mnt

ISO=/usr/release/images/NetBSD-7.99.13-evbarm-earmv7hf-201504280500Z.iso
VND_CD=vnd2
MNT_CD=/mnt2

SETS=${MNT_CD}/${MACHINE}/binary/sets

TARZ=base.tgz comp.tgz games.tgz man.tgz misc.tgz modules.tgz tests.tgz text.tgz xbase.tgz xcomp.tgz xetc.tgz xfont.tgz xserver.tgz

all: mount mountcd image umountcd umount
pkgsrc: mount pkgupdate umount


mount:
	vnconfig ${VND_FILE} ${FILE}
	fsck ${VND_FILE}a
	mount /dev/${VND_FILE}a ${MNT}

umount:
	umount ${MNT}
	vnconfig -u ${VND_FILE}

mountcd:
	vnconfig ${VND_CD} ${ISO}
	mount_cd9660 /dev/${VND_CD}a ${MNT_CD}

umountcd:
	umount ${MNT_CD}
	vnconfig -u ${VND_CD}

image:
	for i in ${TARZ}; do echo $${i};tar xzpf ${SETS}/$${i} -C ${MNT}; done
	tar xzvf ${SETS}/kern-${HARDWARE}.tgz -C ${MNT}
	cp ${SETS}/etc.tgz ${MNT}

pkgupdate:
	(cd ${MNT}/usr/pkgsrc; cvs update -PAd)

backup:
	dd if=/dev/rsd0d of=${FILE} bs=4m progress=10

restore:
	progress -f ${FILE} dd of=/dev/rsd0d bs=4m
