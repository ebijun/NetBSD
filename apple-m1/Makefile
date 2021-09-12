DIR=tmp`date +%Y%m%d`
MACHINE=Apple_Mac_mini_M1_2020

all: check diff copy status
	echo git diff
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
	diff sysinfo ${DIR}/sysinfo |more
	diff pkginfo ${DIR}/pkginfo|more
	diff ../dmesg/aarch64/${MACHINE} ${DIR}/dmesg|more
	diff pkgchk.conf /usr/pkgsrc/pkgchk.conf

copy:
	cp ${DIR}/sysinfo sysinfo
	cp ${DIR}/pkginfo pkginfo
	cp ${DIR}/dmesg ../dmesg/aarch64/${MACHINE}

pkgchk:
	pkg_chk -g
	cp /usr/pkgsrc/pkgchk.conf Update/pkgchk.conf

clean:
	rm -r tmp20*
