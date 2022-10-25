# Makefile for RPI image.

ARCH=aarch64

# set image file name
FILE=`date +%Y-%m-%d`-netbsd-raspi-${ARCH}.img

PKG_PATH=http://cdn.netbsd.org/pub/NetBSD/misc/jun/raspberry-pi/${ARCH}/2022/

BINARY=nycdn.netbsd.org/pub/NetBSD-daily/HEAD/202210240520Z/evbarm-aarch64/binary
SETS=${BINARY}/sets
RPI=${BINARY}/gzimg/arm64.img.gz
#RPI=${BINARY}/gzimg/arm64mbr.img.gz
ORD=a.img

# UEFI
UEFI_VER=v1.33
UEFI_FIRM=RPi4_UEFI_Firmware_${UEFI_VER}.zip
UEFI_URL=https://github.com/pftf/RPi4/releases/download/${UEFI_VER}/${UEFI_FIRM}

PKGSRC=../../../../pkgsrc/pkgsrc-2018-08-04.tar.gz 

VND=vnd0
MNT_BOOT=/mnt1
MNT_ROOT=/mnt2
VND_ORG=vnd1
DK_BOOT=/dev/dk0
DK_ROOT=/dev/dk1
ORG_BOOT=/mnt3
ORG_ROOT=/mnt4
DK_RELEASE=`dkctl ${VND} listwedges|grep ffs |awk -F: '{print $$1}'`

all: file gpt restore boot_config
#all: img boot_config

boot_config:
	vnconfig ${VND} ${FILE}
	dkctl ${VND} listwedges
	mount_msdos ${DK_BOOT} ${MNT_BOOT}
	(cd ${MNT_BOOT};rm  LICENCE.broadcom bootcode.bin cmdline.txt config.txt fixup.dat fixup4.dat fixup4cd.dat fixup_cd.dat start.elf start4.elf start4cd.elf start_cd.elf)
	(cd ${MNT_BOOT};rm -r dtb)	#keep for RPI3
	unzip -d ${MNT_BOOT} ${UEFI_FIRM}
	# Copy RPI_EFI.fd
	mv ${MNT_BOOT}/RPI_EFI.fd ${MNT_BOOT}/RPI_EFI.fd.org
	cp boot/RPI_EFI.fd  ${MNT_BOOT} #disable 3GB barrier
	sync
	umount ${MNT_BOOT}
	vnconfig -u ${VND}

uefi_fetch:
	ftp ${UEFI_URL}

# copy default setupfile
release:
	vnconfig ${VND} ${FILE}
	echo ${DK_RELEASE}
	fsck /dev/${DK_RELEASE}
	mount /dev/${DK_RELEASE} ${MNT_ROOT}
	(cd ../..; tar cf - root ) |(cd ${MNT_ROOT};tar xvf -)
	tar cf - etc |(cd ${MNT_ROOT};tar xvf -)
	echo "PKG_PATH=${PKG_PATH}" >> ${MNT_ROOT}/etc/pkg_install.conf 
	#https://mail-index.netbsd.org/current-users/2020/05/01/msg038495.html
	#rndctl -S var/db/entropy-file #running on amd64
	#cp var/db/entropy-file ${MNT_ROOT}/var/db/entropy-file
	#ls -l ${MNT_ROOT}/var/db/entropy-file
	# RPI4 symbolic link 
	(cd ${MNT_ROOT}/libdata/firmware/if_bwfm/;ln -s brcmfmac43455-sdio.raspberrypi,4-model-b.txt "brcmfmac43455-sdio.Raspberry Pi 4 Model B.txt")
	umount ${MNT_ROOT}
	vnconfig -u ${VND}

restore:
	ls -l    ${RPI}
	gunzip < ${RPI} > ${ORD}
	vnconfig ${VND_ORG} ${ORD}
	mount_msdos /dev/`dkctl ${VND_ORG} listwedges |awk -F: '{print $$1}' |head -2 |tail -1` ${ORG_BOOT}
	### resize
#	gpt resize -i 2 ${VND_ORG}
	resize_ffs -y /dev/`dkctl ${VND_ORG} listwedges |awk -F: '{print $$1}' |tail -1` 
	mount /dev/`dkctl ${VND_ORG} listwedges |awk -F: '{print $$1}' |tail -1` ${ORG_ROOT}
	vnconfig ${VND} ${FILE}
	mount_msdos /dev/`dkctl ${VND} listwedges |awk -F: '{print $$1}' |head -2 |tail -1` ${MNT_BOOT}
	mount /dev/`dkctl ${VND} listwedges |awk -F: '{print $$1}' |tail -1` ${MNT_ROOT}
	(cd ${ORG_BOOT}; cp -r . ${MNT_BOOT})
	dump 0f - ${ORG_ROOT} |(cd ${MNT_ROOT};restore -xf -)
	umount ${ORG_BOOT}
	umount ${ORG_ROOT}
	umount ${MNT_BOOT}
	umount ${MNT_ROOT}
	vnconfig -u ${VND}
	vnconfig -u ${VND_ORG}

gpt:
	vnconfig ${VND} ${FILE}
	gpt create -p 2 ${VND}
	gpt add -i 1 -l "EFI" -s 163840 -t efi ${VND}
	gpt add -i 2 -l "netbsd-root" -s 4751355 -t ffs ${VND}

	newfs_msdos /dev/r`dkctl ${VND} listwedges |awk -F: '{print $$1}' |head -2 |tail -1`
	newfs -n 500000 -b 4096 /dev/r`dkctl ${VND} listwedges |awk -F: '{print $$1}' |tail -1`
	vnconfig -u ${VND}

# make image file. 512*3813376=2GB
file: 
	echo Create ${FILE}.
	dd if=/dev/zero of=${FILE} bs=512 count=4915200 progress=62000
#	 2048*2400
	sleep 3

# stop sshd for package install
pkg:
	vnconfig ${VND} ${FILE}
	echo ${DK_RELEASE}
	fsck /dev/${DK_RELEASE}
	mount /dev/${DK_RELEASE} ${MNT_ROOT}
	echo rc_configured=YES  	>> ${MNT_ROOT}/etc/rc.conf
	echo sshd=NO            	>> ${MNT_ROOT}/etc/rc.conf
	echo syslogd=NO         	>> ${MNT_ROOT}/etc/rc.conf
#	echo dhcpcd=NO          	>> ${MNT_ROOT}/etc/rc.conf
	echo resize_disklabel=NO 	>> ${MNT_ROOT}/etc/rc.conf
	echo resize_gpt=NO             	>> ${MNT_ROOT}/etc/rc.conf
	echo resize_root=NO		>> ${MNT_ROOT}/etc/rc.conf
	echo resize_root_flags=""	>> ${MNT_ROOT}/etc/rc.conf
	echo resize_root_postcmd=""	>> ${MNT_ROOT}/etc/rc.conf
	umount ${MNT_ROOT}
	vnconfig -u ${VND}

pkg-back:
	echo ${DK_RELEASE}
	vnconfig ${VND} ${FILE}
	fsck /dev/${DK_RELEASE}
	mount /dev/${DK_RELEASE} ${MNT_ROOT}
	cp etc/rc.conf ${MNT_ROOT}/etc/rc.conf
	echo "${PKG_PATH}" >> ${MNT_ROOT}/usr/pkg/etc/pkgin/repositories.conf
	umount ${MNT_ROOT}
	vnconfig -u ${VND}
 
# clean logfiles
logclean:
	vnconfig ${VND} ${FILE}
	echo ${DK_RELEASE}
	fsck /dev/${DK_RELEASE}
	mount /dev/${DK_RELEASE} ${MNT_ROOT}
	rm -f ${MNT_ROOT}/var/run/dmesg.boot
	rm -f ${MNT_ROOT}/var/log/lastlogx 
#	rm -f ${MNT_ROOT}/var/log/maillog 
	rm -f ${MNT_ROOT}/var/log/maillog.0.gz 
	rm -f ${MNT_ROOT}/var/log/wtmpx
	rm -f ${MNT_ROOT}/var/log/wtmpx.0.gz
	rm -f ${MNT_ROOT}/var/log/wtmp.0.gz
	rm -f ${MNT_ROOT}/var/mail/root
	rm -f ${MNT_ROOT}/var/db/dhcpcd-usmsc0.lease
	rm -f ${MNT_ROOT}/var/db/dhcpcd-usmsc0.lease6
	rm -f ${MNT_ROOT}/var/db/dhcpcd-url0.lease
	rm -f ${MNT_ROOT}/var/db/dhcpcd-url0.lease6
	rm -f ${MNT_ROOT}/root/dmesg
	rm -f ${MNT_ROOT}/root/pkginfo
	rm -f ${MNT_ROOT}/root/Package/typescript
	rm -rf ${MNT_ROOT}/var/run/dhcpcd
	rm -rf ${MNT_ROOT}/var/run/resolvconf
	umount ${MNT_ROOT}
	vnconfig -u ${VND}

mikutter-key:
	echo mikutter key
	vnconfig ${VND} ${FILE}
	echo ${DK_RELEASE}
	fsck /dev/${DK_RELEASE}
	mount /dev/${DK_RELEASE} ${MNT_ROOT}
	patch -d ${MNT_ROOT}/root/.mikutter/plugin/twitter_api_keys < ../mikutter/twitter_api_keys.rb.patch
	umount ${MNT_ROOT}
	vnconfig -u ${VND}

# fetch newest isofileimage
fetch:
	./NewestISO |tee Fetch
	sh Fetch
	rm Fetch

#Firmware:
#git show HEAD |head
#Author: popcornmix <popcornmix@gmail.com>
#Date:   Tue Nov 17 14:11:58 2020 +0000
#    kernel: Bump to 5.4.77


FIRM=LICENCE.broadcom bootcode.bin fixup.dat fixup_cd.dat start.elf start_cd.elf
FIRMPATH=/usr/local/NetBSD/RPI/Firmware/firmware/boot

firm:
	cp -r ${FIRMPATH}/* Firm
