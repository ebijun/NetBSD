tar:
	(cd rpi4boot;chown -R root.wheel .;tar cvf ../boot.tar .)

extract:
	tar xzvf rpi4boot.tgz

fetch:
#	ftp http://cdn.netbsd.org/pub/NetBSD/misc/mlelstv/rpi4boot.tgz
#acpi mode
	ftp http://www.netbsd.org/~jmcneill/rpi4-acpi.tgz
#UEFI Firmware
	ftp https://github.com/pftf/RPi4/releases/download/v1.9/RPi4_UEFI_Firmware_v1.9.zip

