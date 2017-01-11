# Makefile for NetBSD/hpcmips image.

# set image file name
FILE=`date +%Y-%m-%d`-netbsd-hpcmips.img

# iso file information
IMAGE=/usr/release/images/NetBSD-7.1_RC1-hpcmips-201701071950Z.iso

PKGSRC=../../pkgsrc/pkgsrc-2017-01-07.tar.gz

SETS=/mnt1/hpcmips/binary/sets
INSTALLATION=/mnt1/hpcmips/installation
KERNEL=/mnt1/hpcmips/binary/kernel

# extract sets.
LIST=base etc comp man text tests xbase xcomp xetc xfont xserver 

# mount point
MNT=/mnt
VND=vnd0

# mount cdrom
MNT_CDROM=/mnt1
VND_CDROM=vnd1

all: file newfs cdmount extract bootarea cdunmount
#all: cdmount extract bootarea cdunmount

# make image file. 512*3813376=2GB
file: 
	echo Create ${FILE}.
	dd if=/dev/zero of=${FILE} bs=512 count=3813376 progress=50000
#	dd if=/dev/zero of=${FILE} bs=256 count=3813376 progress=50000
	sleep 3

newfs:
	vnconfig ${VND} ${FILE}
	disklabel -R ${VND} DISKLABEL.proto
	newfs_msdos /dev/r${VND}e
	newfs -n 600000 -b 4096 /dev/r${VND}a
	fdisk -ufF -0 -s 6/32/122848 ${FILE} #DOS partition:DISKLABEL.proto
	vnconfig -u ${VND}

cdmount:
	echo mount cdrom image.
	vnconfig ${VND_CDROM} ${IMAGE}
	mount_cd9660 /dev/${VND_CDROM}a ${MNT_CDROM}

cdunmount:
	echo mount cdrom image.
	umount ${MNT_CDROM}
	vnconfig -u ${VND_CDROM}

extract:
	echo extract sets.
	vnconfig ${VND} ${FILE}
	fsck -fy /dev/r${VND}a
	mount /dev/${VND}a ${MNT}
	for i in ${LIST} ; do (tar xzpf ${SETS}/$${i}.tgz -C ${MNT};); done
	(cd ${MNT}/dev;./MAKEDEV all)
	tar xzpf ${PKGSRC} -C ${MNT}/usr
	mkdir ${MNT}/msdos
	mkdir ${MNT}/kern
	mkdir ${MNT}/proc
	umount ${MNT}
	vnconfig -u ${VND}

bootarea:
	echo boot area.
	vnconfig ${VND} ${FILE}
	fsck_msdos -fy /dev/r${VND}e
	mount /dev/${VND}e ${MNT}
	
	cp ${INSTALLATION}/hpcboot.exe ${MNT}
	cp ${KERNEL}/netbsd-GENERIC.gz ${MNT}
	cp ${KERNEL}/netbsd-TX3912.gz ${MNT}
	gunzip < ${KERNEL}/netbsd-GENERIC.gz > ${MNT}/netbsd
	cp msdos/hpcboot.cnf ${MNT}
	
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
	echo copy default files and make device nodes.
	vnconfig ${VND} ${FILE}
	fsck /dev/r${VND}a
	mount /dev/${VND}a ${MNT}
	tar cvpf - etc root  |(cd /mnt;tar xvpf -)
	umount ${MNT}
	vnconfig -u ${VND}

# fetch newest isofileimage
fetch:
	./NewestISO |tee Fetch
	sh Fetch
	rm Fetch
