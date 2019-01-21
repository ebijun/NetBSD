DIR=tmp`date +%Y%m%d`

all: check diff

status:
	@./Status > README

check:
	echo ${DIR}
	mkdir ${DIR}
	dmesg -t > ${DIR}/dmesg
	sys_info > ${DIR}/sysinfo
	pkg_info |sort > ${DIR}/pkginfo

diff:
	diff Update/sysinfo ${DIR}/sysinfo |more
	diff Update/pkginfo ${DIR}/pkginfo|more
	diff ../dmesg/aarch64/pinebook ${DIR}/dmesg|more

copy:
	cp ${DIR}/sysinfo Update/sysinfo
	cp ${DIR}/pkginfo Update/pkginfo

clean:
	rm -r tmp20*
