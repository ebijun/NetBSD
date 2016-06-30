tools:
	mkdir -p /usr/obj
	(cd /usr/src;./build.sh tools)

patch:
	patch -p1 -d /usr/src < nbsd-install_image.diff
	patch -p1 -d /usr/src < nbsd-msdosfs-fix-filename-lookup.diff

extract:
	tar xzvf src.tar.gz -C /usr
#	tar xzvf nbsd-uefi-installimage.tar.bz2 -C /usr

fetchsrc:
	ftp http://cdn.netbsd.org/pub/NetBSD/NetBSD-current/tar_files/src.tar.gz
	ftp http://cdn.netbsd.org/pub/NetBSD/NetBSD-current/tar_files/xsrc.tar.gz

fetch:
	ftp http://cdn.netbsd.org/pub/NetBSD/misc/nonaka/tmp/uefi/nbsd-uefi-installimage.tar.bz2
	ftp http://cdn.netbsd.org/pub/NetBSD/misc/nonaka/tmp/uefi/nbsd-install_image.diff
	ftp http://cdn.netbsd.org/pub/NetBSD/misc/nonaka/tmp/uefi/nbsd-msdosfs-fix-filename-lookup.diff
