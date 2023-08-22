# Makefile for RPI image.
#Filesystem   512-blocks       Used      Avail %Cap Mounted on
#/dev/ld0a     119457060    4428267  109055940   3% /
#/dev/ld0e        188192      75432     112760  40% /boot
#kernfs                2          2          0 100% /kern
#ptyfs                 2          2          0 100% /dev/pts
#procfs               16         16          0 100% /proc
#tmpfs            485376         16     485360   0% /tmp
#tmpfs            485376         16     485360   0% /var/shm
#/dev/sd0a     465183712   93936240  347988288  21% /mnt

ARCH=earmv7hf

# version information
BINARY=nycdn.netbsd.org/pub/NetBSD-daily/HEAD/202307181140Z/evbarm-earmv7hf/binary

PKG_PATH=http://cdn.netbsd.org/pub/NetBSD/misc/jun/raspberry-pi/${ARCH}/2023/


KERNELDIR=`grep ^IMAGE= Makefile | awk -F- '{print "RPI."$$5}'|sed -e s/.iso//`

PKGSRC=../../../../pkgsrc/pkgsrc-2016Q1.tar.gz 

###

# set image file name
FILE=`date +%Y-%m-%d`-netbsd-armv7-${ARCH}.img
FILE_TMP=a.img

# extract sets.
SETS=${BINARY}/sets
RPI=${BINARY}/gzimg/armv7.img
KERNEL7=${BINARY}/kernel/netbsd-RPI2.gz

#LIST=man misc modules tests text xbase xcomp xetc xfont xserver
LIST=man modules xbase xcomp xetc xfont xserver 

#Firmware: 
#git show HEAD |head
#commit 577aef2bc2f8e9dcd6955a85cf0621cc73b29db7
#Author: Dom Cobley <popcornmix@gmail.com>
#Date:   Wed Feb 9 17:04:38 2022 +0000
#    extra: Update dt-blob.dts to include cm4s
#    See: https://github.com/raspberrypi/firmware/issues/1691

FIRM=LICENCE.broadcom bootcode.bin fixup4cd.dat fixup_cd.dat start.elf start4db.elf start_db.elf fixup.dat fixup4db.dat fixup_db.dat start4.elf start4x.elf start_x.elf fixup4.dat fixup4x.dat  fixup_x.dat  start4cd.elf start_cd.elf
FIRMPATH=/usr/local/NetBSD/RPI/Firmware/firmware/boot

# mount point
MNT=/mnt
VND=vnd0

MNT_CDROM=/mnt1
VND_CDROM=vnd1

MNT_TMP=/mnt2
VND_TMP=vnd2

#all: file rpi extract cdunmount kernel-update bwfm-firmware
all: file rpi extract bwfm-firmware firm 

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
	umount ${MNT}
	vnconfig -u ${VND}

# copy rpi.img.gz to image file and resize partition.
rpi:
	# set disklabel
	vnconfig ${VND} ${FILE}
	fdisk -uf -0 -s 12/32768/163840 ${VND} 
	fdisk -uf -1 -s 169/196608/4964352 ${VND} 
	disklabel -DR ${VND} DISKLABEL.proto
	# newfs dos and ffs
	newfs -n 500000 -b 4096 /dev/r${VND}a
	newfs_msdos  /dev/r${VND}e
	# unzip original image
	gunzip < ${RPI}.gz > ${FILE_TMP}
	vnconfig ${VND_TMP} ${FILE_TMP}
	# restore ffs
	mount /dev/${VND}a ${MNT}
	dump 0uf - /dev/r${VND_TMP}a | ( cd ${MNT} ; restore -xf - )
	umount ${MNT}
	# restore msdos
	mount_msdos /dev/${VND}e ${MNT}
	mount_msdos /dev/${VND_TMP}e ${MNT_TMP}
	(cd ${MNT_TMP}; cp -pr . ${MNT})
	sync
	umount ${MNT}
	umount ${MNT_TMP}
	vnconfig -u ${VND}
	vnconfig -u ${VND_TMP}

# make image file. 512*3813376=2GB
file: 
	echo Create ${FILE}.
#	dd if=/dev/zero of=${FILE} bs=512 count=3813376 progress=50000
	dd if=/dev/zero of=${FILE} bs=512 count=5160960 progress=62000
#	 2048*2520
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

pkg-back:
	vnconfig ${VND} ${FILE}
	fsck /dev/r${VND}a
	mount /dev/${VND}a ${MNT}
	cp etc/rc.conf ${MNT}/etc/rc.conf
	echo "${PKG_PATH}" >> ${MNT}/usr/pkg/etc/pkgin/repositories.conf
	umount ${MNT}
	vnconfig -u ${VND}

# copy default setupfile
release:
	vnconfig ${VND} ${FILE}
	fsck /dev/r${VND}a
	mount /dev/${VND}a ${MNT}
	mount /dev/${VND}e ${MNT}/boot
	(cd ../..; tar cf - etc root ) |(cd ${MNT};tar xvf -)
# earmv7hf: config.txt should contain start address
#	(cd ../../boot;cp * ${MNT}/boot)
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
	touch ${MNT}/var/log/lastlogx 
	chgrp utmp ${MNT}/var/log/lastlogx 
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

# copy newer firmware to /boot on MSDOS partition
# https://github.com/raspberrypi/firmware
firm:
	vnconfig ${VND} ${FILE}
	mount_msdos /dev/${VND}e ${MNT}
	for i in ${FIRM} ; do (cp ${FIRMPATH}/$$i ${MNT}); done
	for i in ${FIRMPATH}/*.dtb ; do (cp  $$i ${MNT}/dtb); done
	# for RPI02W
	cp ${MNT}/dtb/bcm2837-rpi-3-b-plus.dtb ${MNT}/dtb/bcm2710-rpi-zero-2-w.dtb
	umount ${MNT}
	vnconfig -u ${VND}

kernel-update:
	vnconfig ${VND} ${FILE}
	mount /dev/${VND}e ${MNT}
	mv  ${MNT}/kernel7.img ${MNT}/kernel7.img.original
	cp kernel/${KERNELDIR}/netbsd77.img ${MNT}/kernel7.img
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

libssls:
	vnconfig ${VND} ${FILE}
	fsck /dev/r${VND}a
	mount /dev/${VND}a ${MNT}
	(cd ${MNT}/usr/lib;ln -s libssl.so.12 libssl.so.11)
	(cd ${MNT}/usr/lib;ln -s libcrypto.so.12  libcrypto.so.11)
	umount ${MNT}
	vnconfig -u ${VND}

mikutter-key:
	echo mikutter key
	vnconfig ${VND} ${FILE}
	fsck -fy /dev/r${VND}a
	mount /dev/${VND}a ${MNT}
	patch -d ${MNT}/root/.mikutter/plugin/twitter_api_keys < ../mikutter/twitter_api_keys.rb.patch
	umount ${MNT}
	vnconfig -u ${VND}

bwfm-firmware:
	vnconfig ${VND} ${FILE}
	fsck /dev/r${VND}a
	mount /dev/${VND}a ${MNT}
	mkdir -p ${MNT}/libdata/firmware/if_bwfm/
	cp -p ../kernel/Firmware/brcmfmac43* ${MNT}/libdata/firmware/if_bwfm/
	cp -p ../kernel/Firmware/LICENCE.broadcom_bcm43xx ${MNT}/libdata/firmware/if_bwfm/
	umount ${MNT}
	vnconfig -u ${VND}
