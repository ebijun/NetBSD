IMG=armv7.img
FIRM=rpi-firmware.zip
VND0=vnd0
MNT0=/mnt0
DEVICE=sd0

dtb:
	(cd ${MNT0};cp bcm2837-rpi-3-b-plus.dtb bcm2710-rpi-zero-2-w.dtb)

fixup:
	cp  Firmware/start* ${MNT0}/
	cp  Firmware/fixup* ${MNT0}/
	cp  Firmware/bootcode.bin ${MNT0}/

mount:
	vnconfig ${VND0} ${IMG}
	vnconfig -l
	mount_msdos /dev/${VND0}e ${MNT0}
	ls ${MNT0}

umount:
	umount ${MNT0}
	vnconfig -u ${VND0}

gunzip:
	gunzip ${IMG}.gz
	mkdir -p Firmware
	(cd Firmware;7z e ../${FIRM})
	
fetch:
	ftp https://nycdn.netbsd.org/pub/NetBSD-daily/netbsd-9/latest/evbarm-earmv7hf/binary/gzimg/armv7.img.gz
	ftp http://ftp.netbsd.org/pub/NetBSD/misc/mlelstv/rpi-firmware.zip

copy:
	@echo progress -f ${IMG} dd of=/dev/r${DEVICE} bs=4m
