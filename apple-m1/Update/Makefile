RELEASE=/usr/release/images
IMG=${RELEASE}/NetBSD-10.99.10-evbarm-aarch64-202402190640Z-install.img
#IMG=${RELEASE}/NetBSD-10.99.10-evbarm-aarch64-202401141100Z-install.img
#IMG=${RELEASE}/NetBSD-10.99.10-evbarm-aarch64-202312041140Z-install.img
#IMG=${RELEASE}/NetBSD-10.99.10-evbarm-aarch64-202311051250Z-install.img
#IMG=${RELEASE}/NetBSD-10.99.10-evbarm-aarch64-202310150750Z-install.img
#IMG=${RELEASE}/NetBSD-10.99.8-evbarm-aarch64-202309121100Z-install.img
#IMG=${RELEASE}/NetBSD-10.99.7-evbarm-aarch64-202308231240Z-install.img
#IMG=${RELEASE}/NetBSD-10.99.7-evbarm-aarch64-202308211510Z-install.img
#IMG=${RELEASE}/NetBSD-10.99.7-evbarm-aarch64-202308170210Z-install.img
#IMG=${RELEASE}/NetBSD-10.99.7-evbarm-aarch64-202307311120Z-install.img
#IMG=${RELEASE}/NetBSD-10.99.5-evbarm-aarch64-202307151840Z-install.img
#IMG=${RELEASE}/NetBSD-10.99.4-evbarm-aarch64-202306091110Z-install.img
#IMG=${RELEASE}/NetBSD-10.99.4-evbarm-aarch64-202305080450Z-install.img

IMAGE=arm64.img
VND0=/dev/sd0
SD0=/dev/sd0
MNT=/mnt1
M1=/
# 
VND-C=/dev/sd1
MNT-C=/

DK=`dkctl vnd0 listwedges |grep ffs |awk -F: '{print $$1}'`
DK-C=`dkctl ${VND-C} listwedges |grep ffs |awk -F: '{print $$1}'`

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
	@for i in ${LIST} ;do echo tar xzpf $$i -C ${M1} ;  done

kernel-mount:
	mount /dev/${DK-C} ${MNT-C}

kernel-umount:
	umount ${MNT-C}

kernel-update:
	cp ${MNT}/evbarm-aarch64/binary/kernel/netbsd-GENERIC64.gz ${MNT-C}
	gunzip ${MNT-C}/netbsd-GENERIC64.gz
	mv ${MNT-C}/netbsd ${MNT-C}/netbsd.1
	mv ${MNT-C}/netbsd-GENERIC64 ${MNT-C}/netbsd
	md5 ${MNT-C}/netbsd*
	what ${MNT-C}/netbsd

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
	dmesg -t > ../../dmesg/aarch64/Apple_Mac_mini_M1_2020
