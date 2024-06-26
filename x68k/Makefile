VM=liveimage-x68k-with-packages-20210613

extract:
	7z e ${VM}.zip

download:
	ftp http://teokurebsd.org/netbsd/liveimage/20210613-x68k/${VM}.zip

#### make nono.cfg
init:
	echo "vmtype = x68030" > nono.cfg

add_diskimage:
	echo "spc0-id0-image = hd,${VM}.hds" >> nono.cfg

fetch:
	./NewestISO |sh

replace:
	@cp -p `ls -t liveimage-x68k-with-packages-*.hds |head -1` "liveimage-x68k-with-packages-`date +%Y%m%d`.hds" 
