CONFIG_MODULE_SIG=n

obj-m := ext4_monitor.o
ext4_monitor-objs := monitor_handlers.o ext4_monitor.o

CROSS_COMPILE=''

KDIR := /lib/modules/$(shell uname -r)/build

ins:
	sudo insmod monitor.ko

rm:
	sudo rmmod monitor

mod:  
	make -C $(KDIR) M=$(PWD) modules

clean:
	rm -f *.ko *.o *.mod.o *.mod.c .*.cmd *.symvers  modul* *.mod