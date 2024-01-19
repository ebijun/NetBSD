#http://www.nagoya.bug.gr.jp/~hamajima/fs-uae/
FS-UAE_config=/home/jun/.config/fs-uae
FS-UAE=/home/jun/FS-UAE
AMIGAROM=/usr/local/NetBSD/amiga/amiga-os-310-a1200.rom

#8
cyberstorm:
	ls -l ${FS-UAE}/Configurations/cyberstorm.fs-uae
	cat ${FS-UAE}/Configurations/cyberstorm.fs-uae
	fs-uae ${FS-UAE}/Configurations/cyberstorm.fs-uae

#7
copy:
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
