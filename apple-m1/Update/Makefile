RELEASE=/usr/release/images
IMG=${RELEASE}/NetBSD-9.99.88-evbarm-aarch64-202109151600Z-install.img

#-rw-r--r--  1 root  wheel  1625292800 Aug 16 19:51 /usr/release/images/NetBSD-9.99.88-evbarm-aarch64-202108160550Z-install.img
#-rw-r--r--  1 root  wheel  1625292800 Jul 18 09:48 /usr/release/images/NetBSD-9.99.86-evbarm-aarch64-202107171950Z-install.img
#-rw-r--r--  1 root  wheel  1625292800 Jun 20 23:32 /usr/release/images/NetBSD-9.99.85-evbarm-aarch64-202106200930Z-install.img
DK=dk1

IMAGE=arm64.img
VND0=/dev/sd0
SD0=/dev/sd0
MNT=/mnt1
M1=/mnt

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

kernel-update:
	cp ${MNT}/evbarm-aarch64/binary/kernel/netbsd-GENERIC64.gz ${M1}
	gunzip ${M1}/netbsd-GENERIC64.gz
	mv ${M1}/netbsd ${M1}/netbsd.1
	mv ${M1}/netbsd-GENERIC64 ${M1}/netbsd
	md5 ${M1}/netbsd*
	what ${M1}/netbsd

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