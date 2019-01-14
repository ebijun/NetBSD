RELEASE=/usr/release/images
ISO=${RELEASE}/NetBSD-8.99.30-evbarm-aarch64-201901121310Z.iso

##

DATE=`date +%Y%m%d%H%M`
LIST=`ls -P /mnt/evbarm/binary/sets |fgrep -vf Pattern`

etcupdate:
	etcupdate -a -s /mnt/evbarm/binary/sets/etc.tgz

update:
	for i in ${LIST} ;do tar xzpf $$i -C / ;  done

kernel-update:
	cp /mnt/evbarm/binary/kernel/sun50i-a64-pinebook.dtb.gz /boot/dtb/
	gunzip /boot/dtb/sun50i-a64-pinebook.dtb.gz
	cp /mnt/evbarm/binary/kernel/netbsd-GENERIC64.gz /
	gunzip /netbsd-GENERIC64.gz
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

mount:
	vndconfig vnd0 ${ISO}
	mount_cd9660 /dev/vnd0a /mnt

umount:
	umount /mnt
	vndconfig -u vnd0

fetch:
	./NewestISO |sh
