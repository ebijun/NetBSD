# Makefile for RPI image.

# set image file name
FILE=`date +%Y-%m-%d`-netbsd-raspi.img

# iso file information
IMAGE=/usr/release/images/NetBSD-6.99.44-evbarm-earmhf-201406231940Z.iso

PKGSRC=pkgsrc-2014-06-21.tar.gz

# extract sets.
SETS=${MNT_CDROM}/evbarm/binary/sets
RPI=${MNT_CDROM}/evbarm/binary/gzimg/rpi.img
NETWALKER=${MNT_CDROM}/evbarm/binary/kernel/netbsd-NETWALKER.gz
NETWALKERBIN=${MNT_CDROM}/evbarm/binary/kernel/netbsd-NETWALKER.bin.gz

#LIST=man misc modules tests text xbase xcomp xetc xfont xserver
#LIST=man modules text xbase xcomp xetc xfont xserver
LIST=man modules tests text xbase xcomp xetc xfont xserver #add test

# mount point
MNT=/mnt
VND=vnd0
MNT_CDROM=/mnt1
VND_CDROM=vnd1

all: file cdmount rpi extract cdunmount

# extract sets to image file.
extract:
	echo extract sets.
	vnconfig ${VND} ${FILE}
	fsck -fy /dev/r${VND}a
	mount /dev/${VND}a ${MNT}
	for i in ${LIST} ; do (tar xzpf ${SETS}/$${i}.tgz -C ${MNT};); done
	echo extract pkgsrc.
	tar xzpf ${PKGSRC} -C ${MNT}/usr
	echo extract netwalker kernel.
	mount_msdos /dev/${VND}e ${MNT}/boot
	cp ${NETWALKER} ${MNT}/boot
	cp ${NETWALKERBIN} ${MNT}/boot
	umount ${MNT}/boot
	umount ${MNT}
	vnconfig -u ${VND}

# copy rpi.img.gz to image file and resize partition.
rpi:
	echo Copy rpi.img.gz
	vnconfig ${VND} ${FILE}
	gunzip < ${RPI}.gz |dd of=/dev/r${VND}d bs=1m 
	disklabel -R ${VND} DISKLABEL.proto
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
pkg-setup:
	vnconfig ${VND} ${FILE}
	fsck -fy /dev/r${VND}a
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
	(cd ..; tar cf - etc root ) |(cd ${MNT};tar xvf -)
	(cd ..; tar cf - Oshimaya) |(cd ${MNT}/root;tar xvf -)
	(cd ../boot;cp * ${MNT}/boot)
	# rm ${MNT}/var/run/dmesg.boot
	# rm ${MNT}/var/log/lastlogx ${MNT}/var/log/wtmpx
	umount ${MNT}/boot
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

# copy newer firmware :XXX copy to /boot on MSDOS
firm:
	vnconfig ${VND} ${FILE}
	fsck -fy /dev/r${VND}a
	mount /dev/${VND}a ${MNT}
	cp /usr/local/NetBSD/RPI/Firmware/firmware/boot/bootcode.bin /mnt
	cp /usr/local/NetBSD/RPI/Firmware/firmware/boot/fixup.dat /mnt
	cp /usr/local/NetBSD/RPI/Firmware/firmware/boot/fixup_cd.dat /mnt
	cp /usr/local/NetBSD/RPI/Firmware/firmware/boot/start.elf /mnt
	cp /usr/local/NetBSD/RPI/Firmware/firmware/boot/start_cd.elf /mnt
	cp /usr/local/NetBSD/RPI/Firmware/firmware/boot/LICENCE.broadcom /mnt
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
