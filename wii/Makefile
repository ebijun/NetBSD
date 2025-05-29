#
# https://mail-index.netbsd.org/port-powerpc/2024/01/27/msg003636.html

BINARY=nycdn.netbsd.org/pub/NetBSD-daily/HEAD/202505102300Z/evbppc/binary/gzimg/wii.img.gz

DEVICE=rsd0d
BOARD=evbppc
DATE=`date +%Y-%m-%d`

copy:
	progress -z -f ${BINARY}  dd of=/dev/${DEVICE} bs=4m

fetch:
	./NewestISO |sh
