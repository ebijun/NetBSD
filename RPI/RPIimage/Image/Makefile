# Makefile for RPI image.

ARCH=earmv6hf
#ARCH=earm

PKG_PATH=http://cdn.netbsd.org/pub/NetBSD/misc/jun/raspberry-pi/${ARCH}/2017-04-15/

# iso file information
IMAGE=/usr/release/images/NetBSD-7.99.71-evbarm-${ARCH}-201705160910Z.iso


PKGSRC=../../../pkgsrc/pkgsrc-2016Q1.tar.gz 

###

# set image file name
FILE=`date +%Y-%m-%d`-netbsd-raspi-${ARCH}.img
FILE_TMP=a.img

# extract sets.
SETS=${MNT_CDROM}/evbarm/binary/sets
RPI=${MNT_CDROM}/evbarm/binary/gzimg/rpi.img
KERNELBIN=${MNT_CDROM}/evbarm/binary/kernel/netbsd-RPI.bin.gz
KERNELBIN7=${MNT_CDROM}/evbarm/binary/kernel/netbsd-RPI2.bin.gz
KERNEL=${MNT_CDROM}/evbarm/binary/kernel/netbsd-RPI.gz
KERNEL7=${MNT_CDROM}/evbarm/binary/kernel/netbsd-RPI2.gz

#LIST=man misc modules tests text xbase xcomp xetc xfont xserver
LIST=man modules xbase xcomp xetc xfont xserver 

#Firmware: 
#git show HEAD |grep commit
# Date:   Fri Mar 3 13:50:35 2017 +0000
# commit 78c4983379de0537f49a97fb37ceaaf42632b28c
FIRM=LICENCE.broadcom bootcode.bin fixup.dat fixup_cd.dat start.elf start_cd.elf
FIRMPATH=/usr/local/NetBSD/RPI/Firmware/firmware/boot

# mount point
MNT=/mnt
VND=vnd0
MNT_CDROM=/mnt1
VND_CDROM=vnd1
VND_TMP=vnd2

all: file cdmount rpi extract cdunmount fit

#update: cdmount update-extract cdunmount

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
	umount ${MNT}/boot
	umount ${MNT}
	vnconfig -u ${VND}

# copy rpi.img.gz to image file and resize partition.
rpi:
	echo Copy rpi.img.gz
	vnconfig ${VND} ${FILE}
	gunzip < ${RPI}.gz |dd of=/dev/r${VND}d bs=1m 
	disklabel -R ${VND} DISKLABEL.proto
	fdisk -uf -0 -s 6/8192/180224 ${VND} #DOS id6 partition:DISKLABEL.proto
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
	echo rc_configured=YES  >> ${MNT}/etc/rc.conf
	echo sshd=NO            >> ${MNT}/etc/rc.conf
	echo syslogd=NO         >> ${MNT}/etc/rc.conf
#	echo dhcpcd=NO          >> ${MNT}/etc/rc.conf
	echo resize_disklabel=NO 	>> ${MNT}/etc/rc.conf
	echo resize_disklabel_disk=""	>> ${MNT}/etc/rc.conf
	echo resize_disklabel_part=""	>> ${MNT}/etc/rc.conf
	echo resize_root=NO		>> ${MNT}/etc/rc.conf
	echo resize_root_flags=""	>> ${MNT}/etc/rc.conf
	echo resize_root_postcmd=""	>> ${MNT}/etc/rc.conf
	umount ${MNT}
	vnconfig -u ${VND}

# copy default setupfile
release:
	vnconfig ${VND} ${FILE}
	fsck /dev/r${VND}a
	mount /dev/${VND}a ${MNT}
	mount /dev/${VND}e ${MNT}/boot
	(cd ..; tar cf - etc root ) |(cd ${MNT};tar xvf -)
#	(cd ..; tar cf - Oshimaya) |(cd ${MNT}/root;tar xvf -)
	(cd ../boot;cp * ${MNT}/boot)
	echo "PKG_PATH=${PKG_PATH}" >> ${MNT}/etc/pkg_install.conf 
	umount ${MNT}/boot
	umount ${MNT}
	vnconfig -u ${VND}

# clean logfiles
logclean:
	vnconfig ${VND} ${FILE}
	fsck /dev/r${VND}a
	mount /dev/${VND}a ${MNT}
	rm -f ${MNT}/var/run/dmesg.boot
	rm -f ${MNT}/var/log/lastlogx 
#	rm -f ${MNT}/var/log/maillog 
	rm -f ${MNT}/var/log/maillog.0.gz 
	rm -f ${MNT}/var/log/wtmpx
	rm -f ${MNT}/var/log/wtmpx.0.gz
	rm -f ${MNT}/var/log/wtmp.0.gz
	rm -f ${MNT}/var/mail/root
	rm -f ${MNT}/var/db/dhcpcd-usmsc0.lease
	rm -f ${MNT}/var/db/dhcpcd-usmsc0.lease6
	rm -f ${MNT}/var/db/dhcpcd-url0.lease
	rm -f ${MNT}/var/db/dhcpcd-url0.lease6
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

# copy newer firmware to /boot on MSDOS partition
# https://github.com/raspberrypi/firmware
firm:
	vnconfig ${VND} ${FILE}
	mount_msdos /dev/${VND}e ${MNT}
	for i in ${FIRM} ; do (cp ${FIRMPATH}/$$i /mnt); done
	umount ${MNT}
	vnconfig -u ${VND}

kernel:
	vnconfig ${VND} ${FILE}
	mount_msdos /dev/${VND}e ${MNT}
#	gunzip < ${KERNELBIN}  > ${MNT}/kernel.img
	gunzip < ${KERNELBIN7} > ${MNT}/kernel7.img
	umount ${MNT}
#	mount /dev/${VND}a ${MNT}
#	gunzip < ${KERNEL}  > ${MNT}/netbsd.earmv6hf
#	gunzip < ${KERNEL7} > ${MNT}/netbsd.earmv7hf
#	umount ${MNT}
	vnconfig -u ${VND}

kernel-update:
	vnconfig ${VND} ${FILE}
	mount /dev/${VND}e ${MNT}
#	mv  ${MNT}/kernel.img ${MNT}/kernel.img.original
#	cp /usr/obj/kernel/earmv6hf/RPI/netbsd.bin ${MNT}/kernel.img
	mv  ${MNT}/kernel7.img ${MNT}/kernel7.img.original
	cp /usr/obj/kernel/earmv6hf/RPI2/netbsd.bin ${MNT}/kernel7.img
	umount ${MNT}
	vnconfig -u ${VND} 

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

libssls:
	vnconfig ${VND} ${FILE}
	fsck /dev/r${VND}a
	mount /dev/${VND}a ${MNT}
	(cd ${MNT}/usr/lib;ln -s libssl.so.12 libssl.so.11)
	(cd ${MNT}/usr/lib;ln -s libcrypto.so.12  libcrypto.so.11)
	umount ${MNT}
	vnconfig -u ${VND}
