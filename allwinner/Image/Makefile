# Makefile for Allwinner image.

ARCH=earmv7hf
#ARCH=earm

PKG_PATH=ftp://ftp.netbsd.org/pub/NetBSD/misc/jun/allwinner/${ARCH}/2016-02-27;ftp://ftp.netbsd.org/pub/pkgsrc/packages/NetBSD/earmv7hf/7.0/All
 
   
# iso file information
IMAGE=/usr/release/images/NetBSD-7.99.26-evbarm-${ARCH}-201602040320Z.iso

# set image file name
FILE=`date +%Y-%m-%d`-netbsd-cubieboard2-${ARCH}.img


PKGSRC=../../pkgsrc/pkgsrc-2015Q4.tar.gz

# UBOOT
BOARD=cubieboard2
UBOOTURL=http://dl.linux-sunxi.org/nightly/u-boot-sunxi/u-boot-sunxi/u-boot-sunxi-latest/
UBOOTDIR=u-boot-sunxi-${BOARD}-20150127T173720-ea1ac32

# FEX : for Board Configration
FEX=cubieboard2
FEXURL=http://ftp.netbsd.org/pub/NetBSD/misc/jmcneill/allwinner/fex

# kernels
TYPE=CUBIEBOARD
KERNEL=${MNT_CDROM}/evbarm/binary/kernel/netbsd-${TYPE}.gz
KERNELBIN=${MNT_CDROM}/evbarm/binary/kernel/netbsd-${TYPE}.ub.gz

NETWALKER=${MNT_CDROM}/evbarm/binary/kernel/netbsd-NETWALKER.gz
NETWALKERBIN=${MNT_CDROM}/evbarm/binary/kernel/netbsd-NETWALKER.bin.gz

KOBO=${MNT_CDROM}/evbarm/binary/kernel/netbsd-ld0-KOBO.gz
KOBOBIN=${MNT_CDROM}/evbarm/binary/kernel/netbsd-ld0-KOBO.bin.gz
KOBOUBOOT=${MNT_CDROM}/evbarm/binary/kernel/netbsd-ld0-KOBO.ub.gz

# extract sets.
SETS=${MNT_CDROM}/evbarm/binary/sets
beagleboard=${MNT_CDROM}/evbarm/binary/gzimg/armv7.img

#LIST=man misc modules tests text xbase xcomp xetc xfont xserver
LIST=man modules xbase xcomp xetc xfont xserver 

# mount point
MNT=/mnt
VND=vnd0
MNT_CDROM=/mnt1
VND_CDROM=vnd1
FILE_TMP=a.img
VND_TMP=vnd2

all: file cdmount beagleboard extract cdunmount fit uboot-copy

# extract sets to image file.
extract:
	echo extract sets.
	vnconfig ${VND} ${FILE}
	fsck -fy /dev/r${VND}a
	mount /dev/${VND}a ${MNT}
	for i in ${LIST} ; do (tar xzpf ${SETS}/$${i}.tgz -C ${MNT};); done
#	echo extract pkgsrc.
#	tar xzpf ${PKGSRC} -C ${MNT}/usr
	mount_msdos /dev/${VND}e ${MNT}/boot
#	gunzip < ${KERNELBIN} > ${MNT}/boot/netbsd.ub
	mv ${MNT}/boot/netbsd-CUBIEBOARD.ub ${MNT}/boot/netbsd.ub
#	cp ${NETWALKER}    ${MNT}/boot
#	cp ${NETWALKERBIN} ${MNT}/boot
#	cp ${KOBO}         ${MNT}/boot
#	cp ${KOBOBIN}      ${MNT}/boot
#	cp ${KOBOUBOOT}    ${MNT}/boot
	umount ${MNT}/boot
	umount ${MNT}
	vnconfig -u ${VND}

# copy beagleboard.img.gz to image file and resize partition.
beagleboard:
	echo Copy beagleboard.img.gz
	vnconfig ${VND} ${FILE}
	gunzip < ${beagleboard}.gz |dd of=/dev/r${VND}d bs=1m 
	disklabel -R ${VND} DISKLABEL.proto
	fdisk -uf -0 -s 6/8192/114688 ${VND} #DOS id6 partition:DISKLABEL.proto
	fsck -fy /dev/r${VND}a
	resize_ffs -y /dev/r${VND}a
	fsck -fy /dev/r${VND}a
	vnconfig -u ${VND}

# make image file. 512*3813376=2GB
file: 
	echo Create ${FILE}.
	dd if=/dev/zero of=${FILE} bs=512 count=3813376 progress=50000
	sleep 3

# stop sshd for package install
pkg:
	vnconfig ${VND} ${FILE}
	fsck /dev/r${VND}a
	mount /dev/${VND}a ${MNT}
	echo rc_configured=YES >> ${MNT}/etc/rc.conf
	echo sshd=NO           >> ${MNT}/etc/rc.conf
	echo syslogd=NO        >> ${MNT}/etc/rc.conf
#	echo dhcpcd=NO         >> ${MNT}/etc/rc.conf
	echo resize_disklabel=NO        >> ${MNT}/etc/rc.conf
	echo resize_disklabel_disk=""   >> ${MNT}/etc/rc.conf
	echo resize_disklabel_part=""   >> ${MNT}/etc/rc.conf
	echo resize_root=NO             >> ${MNT}/etc/rc.conf
	echo resize_root_flags=""       >> ${MNT}/etc/rc.conf
	echo resize_root_postcmd=""     >> ${MNT}/etc/rc.conf
	umount ${MNT}
	vnconfig -u ${VND}

# copy default setupfile
release:
	vnconfig ${VND} ${FILE}
	sleep 5
	fsck /dev/r${VND}a
	mount /dev/${VND}a ${MNT}
	mount /dev/${VND}e ${MNT}/boot
	tar cf - etc root |(cd ${MNT};tar xvf -)
	cp boot/* ${MNT}/boot
	sed -i -e 's/cubieboard2/${FEX}/' ${MNT}/boot/uEnv.txt
	echo "PKG_PATH=${PKG_PATH}" >> ${MNT}/etc/pkg_install.conf
	umount ${MNT}/boot
	umount ${MNT}
	vnconfig -u ${VND}

# clean logfiles
logclean:
	vnconfig ${VND} ${FILE}
	sleep 5
	fsck /dev/r${VND}a
	mount /dev/${VND}a ${MNT}
	rm -f ${MNT}/var/run/dmesg.boot
	rm -f ${MNT}/var/log/lastlogx 
#	rm -f ${MNT}/var/log/maillog 
	rm -f ${MNT}/var/log/maillog.0.gz 
	rm -f ${MNT}/var/log/wtmpx
	rm -f ${MNT}/var/log/wtmpx.0.gz
	rm -f ${MNT}/var/log/wtmp.0.gz
	rm -f ${MNT}/var/db/dhcpcd-awge0.lease
	rm -f ${MNT}/var/db/dhcpcd-awge0.lease6
	rm -f ${MNT}/root/dmesg
	rm -f ${MNT}/root/pkginfo
	rm -f ${MNT}/root/Package/typescript
	rm -rf ${MNT}/var/run/dhcpcd
	rm -rf ${MNT}/var/run/resolvconf
	umount ${MNT}
	vnconfig -u ${VND}

# mount cdrom image
cdmount:
	echo mount cdrom image.
	vnconfig ${VND_CDROM} ${IMAGE}
	mount_cd9660 /dev/${VND_CDROM}a ${MNT_CDROM}

# unmount cdrom image
cdunmount:
	echo mount cdrom image.
	umount ${MNT_CDROM}
	vnconfig -u ${VND_CDROM}

# update pkgsrc
pkgsrc-update:
	vnconfig ${VND} ${FILE}
	fsck /dev/r${VND}a
	mount /dev/${VND}a ${MNT}
	(cd ${MNT}/usr/pkgsrc;cvs update -PAd)
	umount ${MNT}
	vnconfig -u ${VND}

# fetch newest isofileimage
fetch:
	./NewestISO |tee Fetch
	sh Fetch
	rm Fetch

# uboot
uboot-update:
	(cd u-boot;ftp  ${UBOOTURL}/u-boot-sunxi-${BOARD}.tar.xz)
	(cd u-boot;tar xzvf u-boot-sunxi-${BOARD}.tar.xz)

uboot-copy:
	dd if=u-boot/${UBOOTDIR}/u-boot-sunxi-with-spl.bin of=${FILE} bs=1k seek=8 conv=notrunc

# FEX : for Board Configration, copy into /boot and set uEnv.txt
fex-update:
	(cd fex;ftp ${FEXURL}/${FEX}.bin)

fex-copy:
	cp fex/${FEX}.bin boot/

fit:
	cp ${FILE} ${FILE_TMP}
	vnconfig ${VND_TMP} ${FILE_TMP}
	newfs -n 500000 -b 4096 /dev/r${VND_TMP}a
	mount /dev/${VND_TMP}a ${MNT}
	vnconfig ${VND} ${FILE}
	dump 0uf - /dev/r${VND}a | ( cd ${MNT} ; restore -xf - )
	umount ${MNT}
	vnconfig -u ${VND}
	vnconfig -u ${VND_TMP}
	cp ${FILE_TMP} ${FILE}
