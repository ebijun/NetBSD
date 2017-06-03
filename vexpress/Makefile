ISO=/usr/release/images/NetBSD-7.99.75-evbarm-earmv7hf-201706021610Z.iso
FILE=sdcard.img

cdmount:
	vnconfig vnd0 ${ISO}
	mount_cd9660 /dev/vnd0 /mnt
	gunzip < /mnt/evbarm/binary/gzimg/armv7.img.gz |dd of=${FILE} bs=1m conv=notrunc progress=200
	umount /mnt
	vnconfig -u vnd0

fetch:
	./NewestISO |sh
dtb:
	cp /usr/pkg/share/dtb/arm/vexpress-v2p-ca15-tc1.dtb .
kernel:
	cp /usr/obj/kernel/earmv7hf/VEXPRESS_A15/netbsd.ub .
file:
	dd if=/dev/zero of=${FILE} bs=1m count=2048
