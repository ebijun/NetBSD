# Makefile for NetBSD/hpcmips image.

# set image file name
FILE=`date +%Y-%m-%d`-netbsd7-hpcmips.img

# iso file information
#IMAGE=/usr/release/images/NetBSD-7.99.2-hpcmips-201412110100Z.iso
#IMAGE=/usr/release/images/NetBSD-5.2_STABLE-hpcmips-201412162330Z.iso
#IMAGE=/usr/release/images/NetBSD-6.1.5_PATCH-hpcmips-201412160250Z.iso
IMAGE=/usr/release/images/NetBSD-7.0_BETA-hpcmips-201412182120Z.iso

PKGSRC=../../pkgsrc/pkgsrc-2014-12-13.tar.gz

SETS=/mnt1/hpcmips/binary/sets
INSTALLATION=/mnt1/hpcmips/installation
KERNEL=/mnt1/hpcmips/binary/kernel

# extract sets.
#LIST=man misc modules tests text xbase xcomp xetc xfont xserver
#LIST=base etc comp man modules text xbase xcomp xetc xfont xserver 
LIST=base etc comp man text xbase xcomp xetc xfont xserver 

# mount point
MNT=/mnt
VND=vnd0

# mount cdrom
MNT_CDROM=/mnt1
VND_CDROM=vnd1

all: file newfs cdmount extract bootarea cdunmount

# make image file. 512*3813376=2GB
file: 
	echo Create ${FILE}.
	dd if=/dev/zero of=${FILE} bs=512 count=3813376 progress=50000
	sleep 3

newfs:
	vnconfig ${VND} ${FILE}
	disklabel -R ${VND} DISKLABEL.proto
	newfs_msdos /dev/r${VND}e
	newfs -n 600000 /dev/r${VND}a
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
#	cp msdos/hpcboot.cnf ${MNT}
	
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
