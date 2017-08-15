UBOOT=u-boot-2017.07
BOARD=orangepi_one
CROSS_COMPILE=arm-none-eabi-

build:
	(cd ${UBOOT};make )

defconfig:
	(cd ${UBOOT};make ${BOARD}_defconfig)

gcc:
	apt-get install binutils-arm-none-eabi
	apt-get install gcc-arm-none-eabi
	apt-get install swig libpython-dev

list:
	ls ${UBOOT}/configs

extract:
	tar -jxvf ${UBOOT}.tar.bz2

fetch:
	wget ftp://ftp.denx.de/pub/u-boot/${UBOOT}.tar.bz2
