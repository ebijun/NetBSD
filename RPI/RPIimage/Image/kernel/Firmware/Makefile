FIRM=firmware-brcm80211_20190717-2_all.deb

from_debian:
	ftp http://ftp.jp.debian.org/debian/pool/non-free/f/firmware-nonfree/${FIRM}
	ar -p ${FIRM} data.tar.xz > data.tar.xz
	tar xzvf data.tar.xz ./lib/firmware/brcm/brcmfmac43455-sdio.bin
	cp ./lib/firmware/brcm/brcmfmac43455-sdio.bin .

fetch:
	ftp https://github.com/RPi-Distro/firmware-nonfree/raw/master/brcm/brcmfmac43430-sdio.bin
	ftp https://github.com/RPi-Distro/firmware-nonfree/raw/master/brcm/brcmfmac43430-sdio.txt
#	ftp https://github.com/RPi-Distro/firmware-nonfree/raw/master/brcm/brcmfmac43455-sdio.bin
	ftp https://github.com/RPi-Distro/firmware-nonfree/raw/master/brcm/brcmfmac43455-sdio.txt
	ftp https://github.com/RPi-Distro/firmware-nonfree/blob/master/LICENCE.broadcom_bcm43xx

