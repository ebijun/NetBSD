DIR=tmp`date +%Y%m%d`

all: check diff

status:
	./Status 

check:
	echo ${DIR}
	mkdir ${DIR}
	sys_info > ${DIR}/sysinfo
	pkg_info |sort > ${DIR}/pkginfo

diff:
	diff Update/sysinfo ${DIR}/sysinfo
	diff Update/pkginfo ${DIR}/pkginfo

copy:
	cp ${DIR}/sysinfo Update/sysinfo
	cp ${DIR}/pkginfo Update/pkginfo

clean:
	rm -r tmp20*
