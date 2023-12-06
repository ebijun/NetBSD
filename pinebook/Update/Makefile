RELEASE=/usr/release/images/
IMG=${RELEASE}/NetBSD-10.99.10-evbarm-aarch64-202312050520Z-install.img
#IMG=${RELEASE}/NetBSD-10.99.10-evbarm-aarch64-202311231700Z-install.img
#IMG=${RELEASE}/NetBSD-10.99.9-evbarm-aarch64-202309271910Z-install.img
#IMG=${RELEASE}/NetBSD-10.99.7-evbarm-aarch64-202308231240Z-install.img
#IMG=${RELEASE}/NetBSD-10.99.6-evbarm-aarch64-202307201330Z-install.img
#IMG=${RELEASE}/NetBSD-10.99.4-evbarm-aarch64-202306110050Z-install.img
#IMG=${RELEASE}/NetBSD-10.99.4-evbarm-aarch64-202305160840Z-install.img
#IMG=${RELEASE}/NetBSD-10.99.2-evbarm-aarch64-202303041720Z-install.img

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
