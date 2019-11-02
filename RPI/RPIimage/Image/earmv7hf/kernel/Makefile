DIR=`grep IMAGE=/ ../Makefile | awk -F- '{print "RPI."$$5}'|sed -e s/.iso//`

mkdir:
	@echo mkdir ${DIR}
	@echo mv netbsd77.img ${DIR}

