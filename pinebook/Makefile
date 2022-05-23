DIR=tmp`date +%Y%m%d`

all: check diff copy status
	echo git diff
# make all;make copy; make status;git diff

status:
	@./Status > README

check:
	echo ${DIR}
	mkdir -p ${DIR}
	dmesg -t > ${DIR}/dmesg
	sys_info > ${DIR}/sysinfo
	pkg_info |sort > ${DIR}/pkginfo

diff:
	diff -u Update/sysinfo ${DIR}/sysinfo |more
	diff -u Update/pkginfo ${DIR}/pkginfo|more
	diff -u ../dmesg/aarch64/pinebook ${DIR}/dmesg|more
	diff -u Update/pkgchk.conf /usr/pkgsrc/pkgchk.conf

copy:
	cp ${DIR}/sysinfo Update/sysinfo
	cp ${DIR}/pkginfo Update/pkginfo
	cp ${DIR}/dmesg ../dmesg/aarch64/pinebook

pkgchk:
	pkg_chk -g
	cp /usr/pkgsrc/pkgchk.conf Update/pkgchk.conf

clean:
	rm -r tmp20*
