#https://twitter.com/tsutsuii/status/1262429647364427783
#1) nono-0.0.3 をダウンロード
#https://twitter.com/isaki68k/status/1261646479816404992
#2) 展開して doc/index.html を読んでビルド
#3) liveimage をダウンロードして gunzip
#4) nono.cfg を作って置く
#https://gist.github.com/tsutsui/340546bdc064cee786ed2473fb510463
#
#5) wx/nono で実行
#6) Emulated ROM上で以下のコマンドを実行
#k
#[enter]
#[enter]
#d
#boot
#g
#x
#
VERSION=20251114071131Z

TEO=http://teokurebsd.org/netbsd/liveimage/20200518-luna68k
IMAGE=liveimage-luna68k-raw-2025-03-04.img
IMAGE_CURRENT=liveimage-luna68k-raw-`date +%Y-%m-%d`.img
IMAGE_KERNEL=liveimage-luna68k-raw.img
ISO=/usr/release/images/NetBSD-11.99.4-luna68k-20251114071131Z.iso
VND0=vnd0
VND1=vnd1
MNT=/mnt
SETS=/cdrom/luna68k/binary/sets

#https://gist.github.com/tsutsui/340546bdc064cee786ed2473fb510463
CONFIG=https://gist.githubusercontent.com/tsutsui/340546bdc064cee786ed2473fb510463/raw/24f6f3312ea89509044792d3b5a915aaac971a06/nono.cfg

nono.cfg:
	ftp ${CONFIG}

fetch:
#	ftp ${TEO}/${IMAGE}.gz
#	gunzip ${IMAGE}.gz
	./NewestISO |sh

pkgsrc:
	ftp http://www.pastel-flower.jp/~isaki/NetBSD/patch/pkgsrc-nono-20201013.diff
	ftp http://www.pastel-flower.jp/~isaki/NetBSD/patch/nono-20201013.diff

cdmount:
	#ftp -4 http://cdn.netbsd.org/pub/NetBSD/NetBSD-9.1/images/NetBSD-9.1-luna68k.iso
	vnconfig vnd1 ${ISO}
	mount_cd9660 /dev/vnd1 /cdrom

update:
	vnconfig ${VND0} ${IMAGE_CURRENT}
	fsck /dev/${VND0}a
	mount /dev/${VND0}a ${MNT}
	tar xzpf /cdrom/luna68k/binary/sets/base.tgz -C /mnt
	tar xzpf /cdrom/luna68k/binary/sets/kern-GENERIC.tgz -C /mnt
	tar xzpf /cdrom/luna68k/binary/sets/modules.tgz -C /mnt
	tar xzpf /cdrom/luna68k/binary/sets/rescue.tgz -C /mnt
	cp ${SETS}/etc.tgz ${MNT}

last:
	find nycdn.netbsd.org -name sets |tail -1

echo:
	for i in ${SETS}/* ; do (echo "tar xzpf $${i} -C ${MNT}") done |fgrep -f Pattern

dmesg:
	vnconfig ${VND0} ${IMAGE_CURRENT}
	fsck /dev/${VND0}a
	mount /dev/${VND0}a ${MNT}
	cp /mnt/root/dmesg ../dmesg/luna68k/nono
	umount ${MNT}
	vnconfig -u ${VND0}

replace:
	@echo cp -p `ls -t liveimage-luna68k-raw-*.img |head -1` "liveimage-luna68k-raw-`date +%Y-%m-%d`.img" 

kernel:
	vnconfig vnd0 ${IMAGE_KERNEL}
	fsck /dev/vnd0a
	mount /dev/vnd0a /mnt
	what /mnt/netbsd
	cp /usr/src/sys/arch/luna68k/compile/GENERIC/netbsd /mnt/netbsd
	what /mnt/netbsd
	umount /mnt
	vnconfig -u vnd0
