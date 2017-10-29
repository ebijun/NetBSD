all:
	make scan
	make packages

packages:
	awk '{print "pkg_info -Fe " $$1}' notfound.list |sh |sort |uniq > packages

scan:
	./Ldd |awk '{print $$1}' > notfound.list

clean:
	rm notfound.list packages
