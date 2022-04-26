CONFIG_MODULE_SIG=n

obj-m := kprobe_example.o

CROSS_COMPILE=''

KDIR := /lib/modules/$(shell uname -r)/build

ins:
	sudo insmod kprobe_example.ko

rm:
	sudo rmmod kprobe_example

mod:
	make -C $(KDIR) M=$(PWD) modules

clean:
	rm -f *.ko *.o *.mod.o *.mod.c .*.cmd *.symvers  modul*