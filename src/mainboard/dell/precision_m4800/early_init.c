/* SPDX-License-Identifier: GPL-2.0-only */

#include <device/pci_ops.h>
#include <ec/dell/mec5035/mec5035.h>
#include <bootblock_common.h>
#include <console/console.h>
#include <option.h>
#include <southbridge/intel/lynxpoint/pch.h>

void bootblock_mainboard_early_init(void)
{
		pci_write_config16(PCH_LPC_DEV, LPC_EN, 0x1c0f);
		pci_write_config16(PCH_LPC_DEV, LPC_IO_DEC, 0x0000);
		mec5035_early_init();
}

// mec5035_mouse_touchpad(TP_PS2_MOUSE);
// 		mec5035_radio_enable(RADIO_WLAN, get_uint_option("wlan", 1));
// 		mec5035_radio_enable(RADIO_WWAN, get_uint_option("wwan", 1));
// 		mec5035_radio_enable(RADIO_WPAN, get_uint_option("bluetooth", 1));