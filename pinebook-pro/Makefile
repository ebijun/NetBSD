RELEASE=/usr/release/images
ISO=${RELEASE}/NetBSD-9.99.44-evbarm-aarch64-202001291610Z.iso
IMAGE=arm64.img
VND0=/dev/sd2
SD0=/dev/sd2
MNT=/mnt

##

DATE=`date +%Y%m%d%H%M`
LIST=`ls -P /mnt/evbarm/binary/sets |fgrep -vf Pattern`

dtbcopy:
	mount_msdos ${SD0}e ${MNT}
	cp ${MNT}/dtb/rockchip/rk3399-pinebook-pro.dtb ${MNT}
	ls ${MNT}
	umount ${MNT}

unzip:
	gunzip ${IMAGE}.gz

all:
	./Update
	echo make etcupdate

etcupdate:
	etcupdate -a -s /mnt/evbarm/binary/sets/etc.tgz

update:
	for i in ${LIST} ;do tar xzpf $$i -C / ;  done

kernel-update:
	cp /mnt/evbarm/binary/kernel/sun50i-a64-pinebook.dtb.gz /boot/dtb/allwinner
	gunzip /boot/dtb/allwinner/sun50i-a64-pinebook.dtb.gz
	cp /mnt/evbarm/binary/kernel/netbsd-GENERIC64.gz /
	gunzip /netbsd-GENERIC64.gz
	mv /netbsd /netbsd.1
	mv /netbsd-GENERIC64 /netbsd

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
	ls -l /mnt/evbarm/binary/kernel/sun50i-a64-pinebook.dtb.gz
	ls -l /mnt/evbarm/binary/kernel/netbsd-GENERIC64.img.gz

cdmount:
	vndconfig vnd0 ${ISO}
	mount_cd9660 /dev/vnd0a /mnt2

cdumount:
	umount /mnt2
	vndconfig -u vnd0

fetch:
	./NewestISO |sh

pine:
	scp pinebook:/usr/pkg/share/u-boot/pinebook-pro/rksd_loader.img .

brcm-firmware:
#@ebijun For Wi-Fi, copy the files from this URL https://t.co/7Yw7FbDOa5 into /libdata/firmware/if_bwfm/ then reboot -&gt; bwfm0 will appear in ifconfig :)
#https://gitlab.manjaro.org/tsys/pinebook-firmware/tree/master/brcm
	echo https://gitlab.manjaro.org/tsys/pinebook-firmware/tree/master/brcm

