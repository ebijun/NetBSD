# Makefile for RPI image.

# set image file name
FILE=`date +%Y-%m-%d`-netbsd-evbarm.img

# iso file information
IMAGE=/usr/release/images/NetBSD-6.99.23-evbarm-arm.iso  
PKGSRC=pkgsrc-2013-09-06.tar.gz

# mount cdrom
MNT_CDROM=/mnt1
VND_CDROM=vnd1

SETS=${MNT_CDROM}/evbarm/binary/sets
RPI=${MNT_CDROM}/evbarm/binary/gzimg/rpi.img

# extract sets.
#LIST=man misc modules tests text xbase xcomp xetc xfont xserver
LIST=man modules text xbase xcomp xetc xfont xserver

# mount point
MNT=/mnt
VND=vnd0



all: file cdmount rpi extract cdunmount

# make image file. 512*3813376=2GB
file: 
	echo Create ${FILE}.
	dd if=/dev/zero of=${FILE} bs=512 count=3813376 progress=50000
	sleep 3

# copy rpi.img.gz to image file and resize partition.
rpi:
	echo Copy rpi.img.gz
	vnconfig ${VND} ${FILE}
	gunzip < ${RPI}.gz |dd of=/dev/r${VND}d bs=1m progress=20
	disklabel -R ${VND} DISKLABEL.proto
	fsck -fy /dev/r${VND}a
	resize_ffs -y /dev/r${VND}a
	fsck -fy /dev/r${VND}a
	vnconfig -u ${VND}

# extract sets to image file.
extract:
	echo extract sets.
	vnconfig ${VND} ${FILE}
	fsck -fy /dev/r${VND}a
	mount /dev/${VND}a ${MNT}
	for i in ${LIST} ; do (tar xzpvf ${SETS}/$${i}.tgz -C ${MNT};); done
	tar xzpvf ${PKGSRC} -C ${MNT}/usr
	umount ${MNT}
	vnconfig -u ${VND}


# stop sshd for package install
pkg:
	vnconfig ${VND} ${FILE}
	fsck -fy /dev/r${VND}a
	mount /dev/${VND}a ${MNT}
	echo rc_configured=YES >> ${MNT}/etc/rc.conf
	echo sshd=NO           >> ${MNT}/etc/rc.conf
	echo syslogd=NO           >> ${MNT}/etc/rc.conf
	echo dhcpcd=NO           >> ${MNT}/etc/rc.conf
	umount ${MNT}
	vnconfig -u ${VND}

# copy default setupfile
release:
	vnconfig ${VND} ${FILE}
	fsck /dev/r${VND}a
	mount /dev/${VND}a ${MNT}
	mount /dev/${VND}e ${MNT}/boot
	(tar cvpf - boot etc root ) |(cd /mnt;tar xvpf -)
	(tar cvpf - Oshimaya) |(cd /mnt/root;tar xvpf -)
	cp u-boot.bin /mnt/boot
	cp kobo.bin  /mnt/boot
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
