#
# https://mail-index.netbsd.org/port-powerpc/2024/01/27/msg003636.html

MNT=/mnt
VND=/dev/vnd0

BINARY=nycdn.netbsd.org/pub/NetBSD-daily/HEAD/20251004215608Z/evbppc/binary
IMG=${BINARY}/gzimg/wii.img
SETS=${BINARY}/sets
LIST=base comp debug games gpufw kern-WII man manhtml misc modules rescue tests text xbase xcomp xdebug xetc xfont xserver

DIR=tmp`date +%Y%m%d`
MACHINE=wii
DEVICE=rsd0d
BOARD=evbppc
DATE=`date +%Y-%m-%d`

status:
	@./Status > README

mount:
	vnconfig ${VND} ${BINARY}
	fsck ${VND}a
	mount ${VND}a ${MNT}
	ls ${MNT}

umount:
	umount ${MNT}
	vnconfig -u ${VND}
	vnconfig -l

gunzip:
	gunzip ${BINARY}.gz

check:
	echo ${DIR}
	mkdir -p ${DIR}
	dmesg -t > ${DIR}/dmesg
	sys_info > ${DIR}/sysinfo
	pkg_info |sort > ${DIR}/pkginfo

copy:
	progress -f ${IMG}  dd of=/dev/${DEVICE} bs=4m

fetch:
	./NewestISO |sh

sets:
	@for i in ${LIST} ; do (echo tar xzpf ${SETS}/$${i}.tgz -C ${MNT};); done
	@echo cp ${SETS}/etc.tgz ${MNT}

