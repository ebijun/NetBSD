# Makefile for NetBSD/hpcmips image.

# set image file name
FILE=`date +%Y-%m-%d`-netbsd-hpcmips.img

# iso file information
IMAGE=/usr/release/images/NetBSD-7.99.1-hpcmips-201408111550Z.iso
PKGSRC=../../pkgsrc/pkgsrc-2014-08-09.tar.gz

SETS=/mnt1/hpcmips/binary/sets
KERNELPATH=/mnt1/hpcmips/binary/kernel
INSTALLATION=/mnt1/hpcmips/installation

KERNEL=netbsd-GENERIC.gz
KERNEL-TX=netbsd-TX3912.gz
INSTALLKERNEL=netbsd-install.gz

# extract sets.
LIST=base etc comp man modules tests text xbase xcomp xetc xfont xserver kern-GENERIC

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
	vnconfig -u ${VND}
	fdisk -ufF -0 -s 6/32/122848 ${FILE} #DOS partition:DISKLABEL.proto

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
	tar xzpf ${PKGSRC} -C ${MNT}/usr
	mkdir ${MNT}/kern
	mkdir ${MNT}/proc
	mkdir ${MNT}/msdos
	umount ${MNT}
	vnconfig -u ${VND}

bootarea:
	echo boot area.
	vnconfig ${VND} ${FILE}
	fsck_msdos -fy /dev/r${VND}e
	mount /dev/${VND}e ${MNT}
	
	cp ${INSTALLATION}/hpcboot.exe ${MNT}
	cp ${INSTALLATION}/pbsdboot.exe ${MNT}
	cp ${INSTALLATION}/pbsdboot1.exe ${MNT}
	cp ${KERNELPATH}/${KERNEL} ${MNT}
	cp ${KERNELPATH}/${KERNEL-TX} ${MNT}
	cp ${KERNELPATH}/${KERNEL} .
	cp ${KERNELPATH}/${KERNEL-TX} .
	
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
	(cd /mnt/dev;./MAKEDEV all)
	umount ${MNT}
	vnconfig -u ${VND}

# fetch newest isofileimage
fetch:  
	./NewestISO |tee Fetch
	sh Fetch
	rm Fetch

# Setup via gxemul
boot:
	gxemul -e mobilepro770 -M 256 -I 800000000  -d ${FILE} ${KERNEL}

bootinstall:
        gxemul -e mobilepro770 -d ${FILE} -d c:${IMAGE} ${INSTALLKERNEL}

