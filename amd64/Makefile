RELEASE=/usr/release/images
IMG=${RELEASE}/NetBSD-10.1_STABLE-amd64-202505190540Z-install.img
#IMG=${RELEASE}/NetBSD-10.1-amd64-202412182240Z-install.img
#IMG=${RELEASE}/NetBSD-10.0_STABLE-amd64-202407131640Z-install.img
#IMG=${RELEASE}/NetBSD-10.0_STABLE-amd64-202405070110Z-install.img
#IMG=${RELEASE}/NetBSD-9.99.98-amd64-202207111150Z-install.img
#IMG=${RELEASE}/NetBSD-9.99.93-amd64-202202150800Z-install.img
#IMG=${RELEASE}/NetBSD-9.99.92-amd64-202112060500Z-install.img #R63/P

ARCH=amd64
VND0=vnd0
MNT=/mnt1

DK=`dkctl ${VND0} listwedges|grep ffs |awk -F: '{print $$1}'`

VENDOR=`sysctl machdep.dmi.board-vendor |awk '{print $$3}'`
PRODUCT=`sysctl machdep.dmi.board-product|awk '{print $$3"_"$$4}'|sed -e 's?/??'`
SYSTEM=${VENDOR}_${PRODUCT}


##

DATE=`date +%Y%m%d%H%M`
LIST=`ls -P ${MNT}/${ARCH}/binary/sets |fgrep -vf Pattern`

aaa:
	ls ../dmesg/${ARCH}/${SYSTEM}

gunzip:
	gunzip ${IMG}.gz

all:
	./Update
	echo make etcupdate

etcupdate:
	etcupdate -a -s ${MNT}/${ARCH}/binary/sets/etc.tar.xz

update:
	@for i in ${LIST} ;do echo tar xzpf $$i -C / ;  done

kernel-update:
	cp ${MNT}/${ARCH}/binary/kernel/netbsd-GENERIC.gz /
	gunzip /netbsd-GENERIC.gz
	mv /netbsd /netbsd.1
	mv /netbsd-GENERIC /netbsd
	md5 /netbsd*
	what /netbsd

modules:
	ls ${MNT}/amd64/binary/sets/modules.tar.xz
	tar xzpvf ${MNT}/amd64/binary/sets/modules.tar.xz -C /

backup:
	mkdir ${DATE}
	pkg_chk -g
	cp -p /netbsd ${DATE}
	dmesg -t > ${DATE}/dmesg
	pkg_info |sort > ${DATE}/pkginfo
	sys_info > ${DATE}/sysinfo

mount:
	vndconfig ${VND0} ${IMG}
	mount /dev/${DK} ${MNT}

umount:
	umount ${MNT}
	vndconfig -u vnd0
	df
	vnconfig -l

fetch:
	./NewestISO |sh

update-info:
	pkg_chk -g -C pkgchk.conf
	sys_info |sort > sysinfo
	pkg_info |sort > pkginfo

dmesg:
	dmesg -t > ../dmesg/${ARCH}/${SYSTEM}

delete:
	@rm -i ${RELEASE}/*
