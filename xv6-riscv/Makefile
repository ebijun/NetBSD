NBTOOLS=../usr/src/obj.riscv/tooldir.NetBSD-9.99.92-amd64/bin/

start:
	(cd xv6-riscv;PATH=${NBTOOLS}:${PATH} gmake TOOLPREFIX=riscv64--netbsd- qemu)

clone:
	git clone --depth=1 https://github.com/mit-pdos/xv6-riscv

tools:
	(cd usr/src; ./build.sh -m riscv -u tools)

extract:
	tar xzf src.tgz	
	tar xzf gnusrc.tgz
	tar xzf sharesrc.tgz
	tar xzf syssrc.tgz

fetch:
	ftp https://nycdn.netbsd.org/pub/NetBSD-daily/HEAD/latest/source/sets/src.tgz	
	ftp https://nycdn.netbsd.org/pub/NetBSD-daily/HEAD/latest/source/sets/gnusrc.tgz
	ftp https://nycdn.netbsd.org/pub/NetBSD-daily/HEAD/latest/source/sets/sharesrc.tgz
	ftp https://nycdn.netbsd.org/pub/NetBSD-daily/HEAD/latest/source/sets/syssrc.tgz

qemu:
	sudo pkg_add qemu
git:
	sudo pkg_add git-base
	sudo pkg_add gmake
