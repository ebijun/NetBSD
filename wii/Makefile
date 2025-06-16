#
# https://mail-index.netbsd.org/port-powerpc/2024/01/27/msg003636.html

BINARY=nycdn.netbsd.org/pub/NetBSD-daily/HEAD/202505102300Z/evbppc/binary/gzimg/wii.img.gz

DIR=tmp`date +%Y%m%d`
MACHINE=wii
DEVICE=rsd0d
BOARD=evbppc
DATE=`date +%Y-%m-%d`

status:
	@./Status > README

check:
	echo ${DIR}
	mkdir -p ${DIR}
	dmesg -t > ${DIR}/dmesg
	sys_info > ${DIR}/sysinfo
	pkg_info |sort > ${DIR}/pkginfo

copy:
	progress -z -f ${BINARY}  dd of=/dev/${DEVICE} bs=4m

fetch:
	./NewestISO |sh
