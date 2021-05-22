VER=snapshots
#VER=6.9

DIR=cdn.openbsd.org/pub/OpenBSD/${VER}/luna88k/
VND0=/dev/vnd0
MNT=/mnt
DISK=snapshots.img

check:
	df
	vnconfig -l

update: mount copy umount

copy:
	cp ${DIR}/* ${MNT}
	ls ${MNT}

mount:
	vnconfig ${VND0} ${DISK}
	vnconfig -l
	mount ${VND0}a ${MNT}

umount:
	umount ${MNT}
	vnconfig -u ${VND0}
 
fetch:
	wget --level=1 -r https://cdn.openbsd.org/pub/OpenBSD/${VER}/luna88k
