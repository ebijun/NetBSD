# Makefile for ODROID-C1 image.

# set image file name
FILE=`date +%Y-%m-%d`-netbsd-odroid_c1.img

# iso file information
IMAGE=/usr/release/images/NetBSD-7.99.20-evbarm-earmv7hf-201508082350Z.iso

PKGSRC=../../pkgsrc/pkgsrc-2015-04-25.tar.gz

# UBOOT
UBOOTURL=http://ftp.netbsd.org/pub/NetBSD/misc/jmcneill/odroidc1
UBOOTTAR=u-boot-odroidc-v2011.03-20150308.tar.gz

# kernels
TYPE=ODROID-C1
KERNEL=${MNT_CDROM}/evbarm/binary/kernel/netbsd-${TYPE}.gz
KERNELBIN=${MNT_CDROM}/evbarm/binary/kernel/netbsd-${TYPE}.ub.gz


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

all: file cdmount beagleboard extract cdunmount release uboot-copy resetfdisk

# extract sets to image file.
extract:
	echo extract sets.
	vnconfig ${VND} ${FILE}
	fsck -fy /dev/r${VND}a
	mount /dev/${VND}a ${MNT}
	for i in ${LIST} ; do (tar xzpf ${SETS}/$${i}.tgz -C ${MNT};); done
	#echo extract pkgsrc.
	#tar xzpf ${PKGSRC} -C ${MNT}/usr
	mount_msdos /dev/${VND}e ${MNT}/boot
	gunzip < ${KERNELBIN} > ${MNT}/boot/netbsd.ub
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
	umount ${MNT}
	vnconfig -u ${VND}

# copy default setupfile
release:
	vnconfig ${VND} ${FILE}
	fsck /dev/r${VND}a
	mount /dev/${VND}a ${MNT}
	mount /dev/${VND}e ${MNT}/boot
	tar cf - etc root |(cd ${MNT};tar xvf -)
	cp boot/* ${MNT}/boot
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
	rm -f ${MNT}/var/db/dhcpcd-awge0.lease
	rm -f ${MNT}/var/db/dhcpcd-awge0.lease6
	rm -f ${MNT}/root/dmesg
	rm -f ${MNT}/root/pkginfo
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
	(cd u-boot;ftp  ${UBOOTURL}/${UBOOTTAR})
	(cd u-boot;tar xzvf ${UBOOTTAR})

uboot-copy:
	dd if=u-boot/bl1.bin.hardkernel of=${FILE} bs=1 count=442 conv=notrunc
	dd if=u-boot/bl1.bin.hardkernel of=${FILE} bs=512 skip=1 seek=1 conv=notrunc
	dd if=u-boot/u-boot.bin of=${FILE} bs=512 seek=64 conv=notrunc

resetfdisk:
	fdisk -ufF -1 -s 169/393216/3420160 ${FILE}
