all:
	make scan
	make packages

script:
	awk -F- '{print "(cd /usr/pkgsrc/*/"$$1";make replace)"}' packages

packages:
	awk '{print "pkg_info -Fe " $$1}' notfound.list |sh |sort |uniq |tee packages

scan:
	./Ldd |awk '{print $$1}' > notfound.list

clean:
	rm notfound.list packages
