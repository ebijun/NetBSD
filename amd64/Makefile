RELEASE=/usr/release/images
IMG=${RELEASE}/NetBSD-9.99.90-amd64-202110052120Z-install.img

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
	dmesg -t > ../dmesg/${ARCH}/${SYSTEM}

delete:
	@rm -i ${RELEASE}/*
