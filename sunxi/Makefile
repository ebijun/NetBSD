#UBOOT=/usr/pkg/share/u-boot/nanopi-neo/u-boot-sunxi-with-spl.bin
#DTB=sun8i-h3-nanopi-neo.dtb

UBOOT=/usr/pkg/share/u-boot/nanopi-neo2/u-boot-sunxi-with-spl.bin
DTB=sun50i-h5-nanopi-neo2.dts

KERNEL=netbsd-SUNXI.ub

write:
	@echo sunxi-fel -p -v uboot ${UBOOT} write 0x42000000 ${KERNEL} write 0x43000000 ${DTB} write 0x43100000 boot.scr

boot.scr:
	mkubootimage -A arm -C none -O linux -T script -a 0 -n "NetBSD sunxi boot" boot.cmd boot.scr

copy:
	mount_msdos /dev/sd0e /mnt
	cp /mnt/${KERNEL} .
	umount /mnt
