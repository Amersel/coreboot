/* SPDX-License-Identifier: GPL-2.0-only */

// #include <southbridge/intel/lynxpoint/pch.h>
#include <device/pci_ops.h>
#include <ec/dell/mec5035/mec5035.h>
#include <bootblock_common.h>
#include <console/console.h>
#include <southbridge/intel/lynxpoint/pch.h>

// void bootblock_mainboard_early_init(void)
// {
// 	mec5035_early_init();
// }
/* FIXME: remove this if not needed */
void mainboard_config_superio(void)
{
		printk(BIOS_DEBUG, "Beginning mainboard_config_superio\n");
		pci_write_config32(PCH_LPC_DEV, LPC_GEN2_DEC, 0x007c0901);
		mec5035_early_init();
		mec5035_mouse_touchpad(TP_PS2_MOUSE);
		pci_write_config32(PCH_LPC_DEV, LPC_GEN2_DEC, 0x005c0921);
		printk(BIOS_DEBUG, "Ending mainboard_config_superio\n");

}
