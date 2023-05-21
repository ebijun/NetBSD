MACHINE=`sysctl -n hw.machine` #= amd64
VENDOR=`sysctl -n machdep.dmi.system-vendor` # ASUSTeK COMPUTER INC.
PRODUCT=`sysctl -n machdep.dmi.system-product`  # X200MA
DISK=wd0

#MACHINE=`sysctl -n hw.machine_arch` #= apple-m1
#VENDOR =`sysctl -n hw.model|awk -F, '{print $$1}'` 
#PRODUCT=`sysctl -n hw.model|awk -F, '{print $$2}'` 
#DISK=sd0

DIR="${MACHINE}/${VENDOR}/${PRODUCT}/${DISK}"

echo:
	echo ${DIR}

smart:
	mkdir -p ${DIR}
	sudo atactl ${DISK} smart status	> ${DIR}/status
	sudo atactl ${DISK} identify		> ${DIR}/identify
