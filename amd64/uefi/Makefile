nbmake:
	(cd /usr/src/distrib/amd64;/usr/obj/tooldir.NetBSD-7.99.32-amd64/bin/nbmake-amd64 install_image)

release:
	(cd /usr/src;./build.sh -m amd64 release)

extract:
	tar xzvf nbsd-uefi-installimage.tar.bz2 -C /usr/src/distrib/amd64

tools:
	mkdir -p /usr/obj
	(cd /usr/src;./build.sh tools)

patch:
	patch -p1 -d /usr/src < nbsd-install_image.diff
	patch -p1 -d /usr/src < nbsd-msdosfs-fix-filename-lookup.diff

extractsrc:
	tar xzvf src.tar.gz -C /usr
	tar xzvf xsrc.tar.gz -C /usr

fetchsrc:
	ftp http://cdn.netbsd.org/pub/NetBSD/NetBSD-current/tar_files/src.tar.gz
	ftp http://cdn.netbsd.org/pub/NetBSD/NetBSD-current/tar_files/xsrc.tar.gz

fetch:
	ftp http://cdn.netbsd.org/pub/NetBSD/misc/nonaka/tmp/uefi/nbsd-uefi-installimage.tar.bz2
	ftp http://cdn.netbsd.org/pub/NetBSD/misc/nonaka/tmp/uefi/nbsd-install_image.diff
