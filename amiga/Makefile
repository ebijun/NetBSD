#http://www.nagoya.bug.gr.jp/~hamajima/fs-uae/
FS-UAE_config=/home/jun/.config/fs-uae
FS-UAE=/home/jun/FS-UAE
AMIGAROM=/usr/local/NetBSD/amiga/amiga-os-310-a1200.rom

#11
start:
	fs-uae

#10
copy-netbsd:
	cp NetBSD-install.fs-uae ${FS-UAE}/Configurations/
	cat ${FS-UAE}/Configurations/NetBSD-install.fs-uae
	cp NetBSD-root+swap.hdf.xz ${FS-UAE}/Hard\ Drives/
	gunzip ${FS-UAE}/Hard\ Drives/NetBSD-root+swap.hdf.xz

#10
copy:
	cp Default.fs-uae ${FS-UAE}/Configurations/
	cat ${FS-UAE}/Configurations/Default.fs-uae

#9
fetch:
	ftp http://www.nagoya.bug.gr.jp/~hamajima/fs-uae/Default.fs-uae
	ftp http://www.nagoya.bug.gr.jp/~hamajima/fs-uae/NetBSD-root+swap.hdf.xz

#8
cyberstorm:
	ls -l ${FS-UAE}/Configurations/cyberstorm.fs-uae
	cat ${FS-UAE}/Configurations/cyberstorm.fs-uae
	fs-uae ${FS-UAE}/Configurations/cyberstorm.fs-uae

#7
copy-cyberstorm:
	cp cyberstorm.fs-uae ${FS-UAE}/Configurations/

#6
lha:
	ftp http://aminet.net/util/arc/lha.run
	cp lha.run ${FS-UAE}/Hard\ Drives/AmigaOS/AmiNet
	ftp http://aminet.net/driver/other/FlashUpdates-26042002.lha
	cp FlashUpdates-26042002.lha ${FS-UAE}/Hard\ Drives/AmigaOS/AmiNet

#5
CyberStormPPC-ROM:
	touch ${FS-UAE}/Kickstarts/cyberstormppc.rom
	mkdir -p ${FS-UAE}/Hard\ Drives/AmigaOS/AmiNet
	mkdir ${FS-UAE}/Hard\ Drives/ENV

#4
copy_kickstart:
	cp ${AMIGAROM} ${FS-UAE}/Kickstarts/A1200_3.1.rom

#3
start_fs-uae:
	echo "Push F12 & move cursor to X & Return to EXIT."
	fs-uae

#2
plugin_path:
	mkdir -p ${FS-UAE_config}
	echo "/usr/pkg/share/fs-uae/plugins" >> ${FS-UAE_config}/plugins-dir

#1
pkg_add:
	pkg_add fs-uae
	pkg_add fs-uae-qemu-uae

log:
	more  /home/jun/FS-UAE/Cache/Logs/fs-uae.log.txt

#-11
netbsd:
	ls -l ${FS-UAE}/Configurations/NetBSD-install.fs-uae
	cat ${FS-UAE}/Configurations/NetBSD-install.fs-uae
	fs-uae ${FS-UAE}/Configurations/NetBSD-install.fs-uae

#-09
mkdisk:
	echo -n "rdsk" > ${FS-UAE}/Hard\ Drives/NetBSD-usr.hdf
	dd if=/dev/zero of=${FS-UAE}/Hard\ Drives/NetBSD-usr.hdf oseek=4 bs=1m count=8000

