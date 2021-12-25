DIR=tmp`date +%Y%m%d`
MACHINE=Apple_Mac_mini_M1_2020
DATE=`date +%Y%m%d%H%M`

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
	diff sysinfo ${DIR}/sysinfo 
	diff pkginfo ${DIR}/pkginfo
	diff ../dmesg/aarch64/${MACHINE} ${DIR}/dmesg
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

fetch:
	./NewestISO |sh

backup:
	mkdir ${DIR}
	cp -p /netbsd ${DIR}
	dmesg -t > ${DIR}/dmesg
	pkg_info |sort > ${DIR}/pkginfo
	sys_info > ${DIR}/sysinfo
