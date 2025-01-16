RELEASE=/usr/release/images/

IMG=${RELEASE}/NetBSD-10.99.12-evbarm-aarch64-202501150610Z-install.img
#IMG=${RELEASE}/NetBSD-10.99.12-evbarm-aarch64-202411251000Z-install.img
#IMG=${RELEASE}/NetBSD-10.99.12-evbarm-aarch64-202410141310Z-install.img
#IMG=${RELEASE}/NetBSD-10.99.12-evbarm-aarch64-202409211400Z-install.img
#IMG=${RELEASE}/NetBSD-10.99.12-evbarm-aarch64-202408280900Z-install.img
#IMG=${RELEASE}/NetBSD-10.99.11-evbarm-aarch64-202407200800Z-install.img
#IMG=${RELEASE}/NetBSD-10.99.10-evbarm-aarch64-202406251210Z-install.img
#IMG=${RELEASE}/NetBSD-10.99.10-evbarm-aarch64-202405210700Z-install.img
#IMG=${RELEASE}/NetBSD-10.99.10-evbarm-aarch64-202402270000Z-install.img
#IMG=${RELEASE}/NetBSD-10.99.10-evbarm-aarch64-202401181910Z-install.img

# X works well
#IMG=${RELEASE}/NetBSD-9.99.106-evbarm-aarch64-202211072300Z-install.img

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
	for i in ${LIST} ;do echo tar xzpf $$i -C / ;  done

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
