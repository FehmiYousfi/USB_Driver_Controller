obj-m := Driver.o
KDIR := /lib/modules/$(shell uname -r)/build
default :
	$(MAKE) -C $(KDIR) M=$(shell pwd) modules
install :
	$(MAKE) -C $(KDIR) M=$(shell pwd) module_install
clean :
	$(MAKE) -C $(KDIR) M=$(shell pwd) clean
