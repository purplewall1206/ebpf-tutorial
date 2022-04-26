CONFIG_MODULE_SIG=n

obj-m := monitor.o

CROSS_COMPILE=''

KDIR := /lib/modules/$(shell uname -r)/build

ins:
	sudo insmod monitor.ko

rm:
	sudo rmmod monitor

mod:
	make -C $(KDIR) M=$(PWD) modules

clean:
	rm -f *.ko *.o *.mod.o *.mod.c .*.cmd *.symvers  modul*