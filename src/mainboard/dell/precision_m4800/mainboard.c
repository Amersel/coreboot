/* SPDX-License-Identifier: GPL-2.0-only */

#include <device/device.h>
#include <ec/acpi/ec.h>
#include <drivers/intel/gma/int15.h>
#include <console/console.h>
#include <pc80/keyboard.h>
#include <ec/dell/mec5035/mec5035.h>

static void mainboard_init(struct device *dev)
{
	/* FIXME: trim this down or remove if necessary */
	// {
	// 	int i;
	// 	const u8 dmp[64] = {
	// 		/* 00 */ 0x33, 0x00, 0x04, 0x01, 0x00, 0x07, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	// 		/* 10 */ 0x02, 0x46, 0x34, 0x0a, 0x75, 0x2f, 0x78, 0x0e, 0xa2, 0x0b, 0x88, 0x01, 0x04, 0x00, 0xae, 0x14,
	// 		/* 20 */ 0xc8, 0x19, 0x30, 0x2a, 0x2a, 0x54, 0x29, 0x23, 0x09, 0x02, 0x00, 0x00, 0x00, 0xff, 0x00, 0x03,
	// 		/* 30 */ 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	// 	};

	// 	printk(BIOS_DEBUG, "Replaying EC dump ...");
	// 	for (i = 0; i < 64; i++)
	// 		ec_write (i, dmp[i]);
	// 	printk(BIOS_DEBUG, "done\n");
	// }

	pc_keyboard_init(NO_AUX_DEVICE);
}

static void mainboard_enable(struct device *dev)
{
	install_intel_vga_int15_handler(GMA_INT15_ACTIVE_LFP_INT_LVDS,
					GMA_INT15_PANEL_FIT_CENTERING,
					GMA_INT15_BOOT_DISPLAY_DEFAULT, 2);
	dev->ops->init = mainboard_init;
}

struct chip_operations mainboard_ops = {
	.enable_dev = mainboard_enable,
};
