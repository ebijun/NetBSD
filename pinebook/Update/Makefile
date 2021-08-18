RELEASE=/usr/release/images/
IMG=${RELEASE}/NetBSD-9.99.88-evbarm-aarch64-202108160550Z-install.img
#IMG=${RELEASE}/NetBSD-9.99.85-evbarm-aarch64-202106200030Z-install.img
#-rw-r--r--  1 root  wheel  1625292800 Jul 14 22:26 /usr/release/images/NetBSD-9.99.86-evbarm-aarch64-202107140840Z-install.img

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
