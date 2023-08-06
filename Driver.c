
//Linux Usb Device Driver

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/usb.h>  

#define USB_VENDOR_ID 0x1209
#define USB_PRODUCT_ID 0x5741

static int usb_drv_probe(struct usb_interface *interface, const struct usb_deviceid *id)
{
	struct usb_host_interface *interface_desc;
	struct usb_end_descriptor * endpoint;
	int ret;

	interface_desc = interface->cur_altersetting;
	printk(KERN_INFO "USBinfo %d now probed: (%04X: %04)\n", intface_desc->desc.bIntfaceNumber, id->idVendor, id->idProduct);
	printk(KERN_INFO "ID->bNumberEndpoints : %02X\n",intface_desc->desc.bNumEndpoints);
	printk(KERN_INFO "ID-> bIntrefaceClass: %02X\n", intface_desc.desc.bInterfaceClass);
	ret = usb_register_dev(interface,&usb_cd);
	if(ret)
	{
		printk(KERN_INFO "Not able yo get the minor number..\n");
	}
	else
	{
		printk(KERN_INFO "Minor Number = %d\n", interface->minor);
	}
}

static struct usb_device_disconnect(struct usb_interface *interface)
{
	printk(KERN_INFO "Disconnect and Release the Minor Number %d\n", intreface->minor);
	usb_deregister_dev(interface,&usb_cd);
}

static struct usd_device_id usb_drv_table[] = {
{	
	USB_DEVICE(USB_VENDOR_ID,USB_PRODUCT_ID)},{}
};

MODULE_DEVICE_TABLE(usb,usb_drv_table);

static struct usb_driver usb_drv_struct = {
	.name		= "Custom USB Driver",
	.probe		= usb_drv_probe,
	.disconnect	= usb_drv_disconnect,
	.id_table	= usb_drv_table,
};

static int __init usb_test_init(void)
{
	printk(KERN_INFO "Rgister the usb driver with the usb subsystem\n");
	usb_register(&usb_drv_struct);
}

static void __exit usb_test_exit(void)
{
	printk(KERN_INFO "Dergister the usb driver From the usb subsystem\n");
	usb_deregister(&usb_drv_struct);
}
module_init(usb_test_init);
module_exit(usb_test_exit);

MODULE_LICENCE("GPL");
MODULE_AUTHOR("Luceor Labs <fehmi.yousfi@Luceor.com>");
MODULE_DISCRIPTION("USB_test_Driver")





