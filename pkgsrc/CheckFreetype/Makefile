#LIBNAME="libfreetype.so.7"
LIBNAME="libfreetype.so.17"

pkg: files
	sh files |grep "Information for " |sort |uniq |awk '{print $$3}' |sed -e 's/-[0-9nb\.]*://'  > pkg
files: list
	ruby200 Pickup ${LIBNAME} > files
list:
	ldd /usr/pkg/bin/* > list
clean:
	rm list files pkg
