#ACTION=replace
ACTION=install

all:
	make scan
	make packages

script:
	sed -e 's/-[0-9].*$$//' packages | awk '{print "(cd /usr/pkgsrc/*/"$$1";make ${ACTION})"}'

packages:
	awk '{print "pkg_info -Fe " $$1}' notfound.list |sh |sort |uniq |tee packages

scan:
	./Ldd |awk '{print $$1}' > notfound.list

clean:
	rm notfound.list packages
