# Makefile for NetBSD/zaurus image.

# set image file name
FILE=`date +%Y-%m-%d`-netbsd-zaurus.img

# iso file information
IMAGE=/usr/release/images/NetBSD-7.99.5-zaurus-201502151320Z.iso
PKGSRC=../../pkgsrc/pkgsrc-2015-02-14.tar.gz

SETS=/mnt1/zaurus/binary/sets
INSTALLATION=/mnt1/zaurus/installation
KERNEL=/mnt1/zaurus/binary/kernel
GENERIC=netbsd-GENERIC.gz
C700=netbsd-C700.gz

# extract sets.
LIST=base etc comp man modules xbase xcomp xetc xfont xserver kern-GENERIC

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
	
	cp ${KERNEL}/${GENERIC} ${MNT}
	gunzip < ${MNT}/${GENERIC} > ${MNT}/netbsd
	cp ${KERNEL}/${C700} ${MNT}
	cp ${INSTALLATION}/zboot ${MNT}
	cp ${INSTALLATION}/zbsdmod.o ${MNT}
	echo "insmod -f ./zbsdmod.o" >  ${MNT}/Boot
	echo "./zboot"               >> ${MNT}/Boot
	chmod +x ${MNT}/Boot
	
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

# clean logfiles
logclean:
	vnconfig ${VND} ${FILE}
	fsck /dev/r${VND}a
	mount /dev/${VND}a ${MNT}
	rm -f ${MNT}/var/run/dmesg.boot
	rm -f ${MNT}/var/log/lastlogx 
	rm -f ${MNT}/var/log/wtmpx
	rm -f ${MNT}/var/db/dhcpcd-url0.lease
	rm -f ${MNT}/var/db/dhcpcd-url0.lease6
	rm -f ${MNT}/root/Package/dmesg
	rm -f ${MNT}/root/Package/pkginfo
	rm -rf ${MNT}/var/run/dhcpcd
	rm -rf ${MNT}/var/run/resolvconf
	umount ${MNT}
	vnconfig -u ${VND}

# fetch newest isofileimage
fetch:  
	./NewestISO |tee Fetch
	sh Fetch
	rm Fetch
