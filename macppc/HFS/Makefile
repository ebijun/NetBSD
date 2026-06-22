scp:
#	scp -P 5428 localhost:a.iso .
	scp -P 5428 a.iso localhost:

copy:
#	hcopy netbsd-INSTALL :
	hcopy netbsd-GENERIC :

format:
	hformat -l "Test" a.iso

fetch:
	ftp https://nycdn.netbsd.org/pub/NetBSD-daily/HEAD/latest/macppc/binary/kernel/netbsd-GENERIC.gz
	gunzip netbsd-GENERIC.gz
#	ftp https://nycdn.netbsd.org/pub/NetBSD-daily/HEAD/20251231205729Z/macppc/binary/kernel/netbsd-INSTALL.gz
#	gunzip netbsd-INSTALL.gz
