# Makefile for RPI image.

# set image file name
FILE=`date +%Y-%m-%d`-netbsd-raspi.img

# iso file information
#IMAGE=/usr/release/images/NetBSD-6.99.23-evbarm-arm.iso
IMAGE=/usr/release/earm/images/NetBSD-6.99.23-evbarm-earmv6hf.iso  
PKGSRC=pkgsrc-2013-08-21.tar.gz

SETS=binary/sets
RPI=binary/gzimg/rpi.img

# extract sets.
LIST=games man misc modules tests text xbase xcomp xetc xfont xserver

# mount point
MNT=/mnt
VND=vnd0


all: file rpi extract

# extract sets to image file.
extract:
	vnconfig ${VND} ${FILE}
	fsck -fy /dev/r${VND}a
	mount /dev/${VND}a ${MNT}
	for i in ${LIST} ; do (tar xzpvf ${SETS}/$${i}.tgz -C ${MNT};); done
	tar xzpvf ${PKGSRC} -C ${MNT}/usr
	umount ${MNT}
	vnconfig -u ${VND}

# copy rpi.img.gz to image file and resize partition.
rpi:
	vnconfig ${VND} ${FILE}
	gunzip < ${RPI}.gz |dd of=/dev/r${VND}d bs=1m 
	disklabel -R ${VND} DISKLABEL.proto
	fsck -fy /dev/r${VND}a
	resize_ffs -y /dev/r${VND}a
	fsck -fy /dev/r${VND}a
	vnconfig -u ${VND}

# copy rpi.img and sets files to local.
copy:
	echo Copy binary image to local.
	vnconfig ${VND} ${IMAGE}
	mount_cd9660 /dev/${VND}a ${MNT}
	cp -r ${MNT}/evbarm/binary .
	umount ${MNT}
	vnconfig -u ${VND}

# make image file. 512*3813376=2GB
file: 
	echo Create ${FILE}.
	dd if=/dev/zero of=${FILE} bs=512 count=3813376 progress=50000
	sleep 3
