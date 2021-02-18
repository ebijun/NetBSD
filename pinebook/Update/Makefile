RELEASE=/usr/release/images/
IMG=${RELEASE}/NetBSD-9.99.80-evbarm-aarch64-202102171420Z-install.img
#nycdn.netbsd.org/pub/NetBSD-daily/HEAD/202102061040Z/images/NetBSD-9.99.80-aarch64-install.img.gz
5292800 Feb 18 03:38 

DK=dk1

##

DATE=`date +%Y%m%d%H%M`
LIST=`ls -P /mnt1/evbarm-aarch64/binary/sets/ |fgrep -vf Pattern`

sss:
	echo ${LIST}

all:
	./Update
	echo make etcupdate

etcupdate:
	etcupdate -a -s /mnt1/evbarm-aarch64/binary/sets/etc.tar.xz

update:
	for i in ${LIST} ;do tar xzpf $$i -C / ;  done

kernel-update:
	cp /mnt1/evbarm-aarch64/binary/kernel/netbsd-GENERIC64.gz /
	gunzip /netbsd-GENERIC64.gz
	mv /netbsd /netbsd.1
	mv /netbsd-GENERIC64 /netbsd
	what /netbsd

backup:
	mkdir ${DATE}
	cp -p /netbsd ${DATE}
	cp -p /boot/dtb/allwinner/sun50i-a64-pinebook.dtb ${DATE}
	dmesg -t > ${DATE}/dmesg
	pkg_info |sort > ${DATE}/pkginfo
	sys_info > ${DATE}/sysinfo
	(cd ${DATE};md5 netbsd sun50i-a64-pinebook.dtb dmesg >MD5)

ls:
	ls -l /boot/dtb/allwinner/sun50i-a64-pinebook.dtb
	ls -l /boot/netbsd.img
	ls -l /mnt1/evbarm-aarch64/binary/kernel/netbsd-GENERIC64.img.gz

gunzip:
	gunzip ${IMG}.gz

mount:
	vndconfig vnd0 ${IMG}
	dkctl vnd0
	mount /dev/${DK} /mnt1

umount:
	umount /mnt1
	vndconfig -u vnd0

fetch:
	./NewestISO |sh
