RELEASE=/usr/release/images
#IMG=${RELEASE}/NetBSD-10.99.10-evbarm-aarch64-202312050520Z-install.img
#IMG=${RELEASE}/NetBSD-10.99.10-evbarm-aarch64-202312050520Z-install.img
#IMG=${RELEASE}/NetBSD-10.99.10-evbarm-aarch64-202401181910Z-install.img
#IMG=${RELEASE}/NetBSD-10.99.10-evbarm-aarch64-202405210700Z-install.img
#IMG=${RELEASE}/NetBSD-10.99.10-evbarm-aarch64-202406251210Z-install.img
#IMG=${RELEASE}/NetBSD-10.99.11-evbarm-aarch64-202407200800Z-install.img
#IMG=${RELEASE}/NetBSD-10.99.12-evbarm-aarch64-202408280900Z-install.img
#IMG=${RELEASE}/NetBSD-10.99.12-evbarm-aarch64-202409211400Z-install.img
IMG=${RELEASE}/NetBSD-10.99.12-evbarm-aarch64-202411251000Z-install.img

DK=dk1

IMAGE=arm64.img
VND0=/dev/sd2
SD0=/dev/sd2
MNT=/mnt1

##

DATE=`date +%Y%m%d%H%M`
LIST=`ls -P ${MNT}/evbarm-aarch64/binary/sets |fgrep -vf Pattern`

aaa:
	echo ${LIST}

gunzip:
	gunzip ${IMG}.gz

all:
	./Update
	echo make etcupdate

etcupdate:
	etcupdate -a -s ${MNT}/evbarm-aarch64/binary/sets/etc.tar.xz

update:
	@for i in ${LIST} ;do echo tar xzpf $$i -C / ;  done

kernel-update:
	cp ${MNT}/evbarm-aarch64/binary/kernel/netbsd-GENERIC64.gz /
	gunzip /netbsd-GENERIC64.gz
	mv /netbsd /netbsd.1
	mv /netbsd-GENERIC64 /netbsd
	md5 /netbsd*
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
	ls -l /boot/netbsd.img
	ls -l /mnt1/evbarm-aarch64/binary/kernel/netbsd-GENERIC64.gz

mount:
	vndconfig vnd0 ${IMG}
	dkctl vnd0
	mount /dev/${DK} ${MNT}

umount:
	umount ${MNT}
	vndconfig -u vnd0

fetch:
	./NewestISO |sh

pine:
	scp pinebook:/usr/pkg/share/u-boot/pinebook-pro/rksd_loader.img .

brcm-firmware:
#@ebijun For Wi-Fi, copy the files from this URL https://t.co/7Yw7FbDOa5 into /libdata/firmware/if_bwfm/ then reboot -&gt; bwfm0 will appear in ifconfig :)
#https://gitlab.manjaro.org/tsys/pinebook-firmware/tree/master/brcm
	echo https://gitlab.manjaro.org/tsys/pinebook-firmware/tree/master/brcm

update-info:
	sys_info |sort > sysinfo
	pkg_info |sort > pkginfo
	dmesg -t > ../dmesg/aarch64/pinebook-pro
