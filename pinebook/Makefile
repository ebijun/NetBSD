DIR=tmp`date +%Y%m%d`

all: check diff
# make all;make copy; make status;git diff

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
	diff Update/pkgchk.conf /usr/pkgsrc/pkgchk.conf

copy:
	cp ${DIR}/sysinfo Update/sysinfo
	cp ${DIR}/pkginfo Update/pkginfo
	cp ${DIR}/dmesg ../dmesg/aarch64/pinebook

pkgchk:
#	pkg_chk -g
	cp /usr/pkgsrc/pkgchk.conf Update/pkgchk.conf

clean:
	rm -r tmp20*
