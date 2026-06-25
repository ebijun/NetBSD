#INST=./nycdn.netbsd.org/pub/NetBSD-daily/netbsd-11/1214114847Z/virt68k/installation/ramdisks/inst-ramdisk.fs
INST=./nycdn.netbsd.org/pub/NetBSD-daily/netbsd-11/20251214114847Z/virt68k/installation/ramdisks/inst-ramdisk.fs
KERNEL=nycdn.netbsd.org/pub/NetBSD-daily/HEAD/20260523140238Z/virt68k/binary/kernel/netbsd-GENERIC.gz


install:
	nono --initrd ${INST}

fetch:
	./NewestISO|sh -v
file:
	dd if=/dev/zero of=virt68k.img bs=1m count=2048

update:
	cp -p liveimage-virt68k-raw-2026-04-09.img liveimage-virt68k-raw-`date +%Y-%m-%d`.img

kernel:
	#scp -P 10069 localhost:/netbsd .
	scp -P 10069 localhost:/usr/INSTALL/kern-GENERIC.tgz .

gunzip:
	cp ${KERNEL} .
	gunzip `basename ${KERNEL}`
