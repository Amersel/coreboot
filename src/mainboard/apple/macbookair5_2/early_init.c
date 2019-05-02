/* SPDX-License-Identifier: GPL-2.0-only */

#include <northbridge/intel/sandybridge/raminit_native.h>
#include <southbridge/intel/bd82x6x/pch.h>
#include <cbfs.h>
#include <southbridge/intel/common/gpio.h>

const struct southbridge_usb_port mainboard_usb_ports[] = {
	{ 1, 0,  0 }, /* Ext A (XHCI/EHCI) */
	{ 1, 0,  1 }, /* Ext B (XHCI) */
	{ 1, 0,  2 }, /* Ext C (XHCI/EHCI) */
	{ 1, 0,  3 }, /* Ext D (XHCI) */
	{ 0, 0, -1 }, /* Unused */
	{ 1, 0, -1 }, /* SD */
	{ 1, 0, -1 }, /* Wi-Fi */
	{ 1, 0, -1 }, /* USB Hub (All LS/FS Devices) */
	{ 1, 0, -1 }, /* Camera */
	{ 1, 0,  4 }, /* Ext B (EHCI) */
	{ 1, 0,  5 }, /* Ext D (EHCI) */
	{ 1, 0, -1 }, /* BT */
	{ 0, 0, -1 }, /* Unused */
	{ 0, 0, -1 }, /* Unused */
};

static uint8_t *get_spd_data(int spd_index)
{
	uint8_t *spd_file;
	size_t spd_file_len;
	printk(BIOS_DEBUG, "spd index %d\n", spd_index);
	spd_file = cbfs_map("spd.bin", &spd_file_len);
	if (!spd_file)
		die("SPD data not found.");
	if (spd_file_len < spd_index * 256)
		die("Missing SPD data.");
	return spd_file + spd_index * 256;
}

void mainboard_get_spd(spd_raw_data *spd, bool id_only)
{
	uint8_t *memory;
	const int spd_gpio_vector[] = {71, 70, 69, 68, -1};
	int ramcfg = get_gpios(spd_gpio_vector);
	int spd_index = -1;

	/*
	 * GPIO68 GPIO69 GPIO70 GPIO71 Memory         Supported
	 * 0      0      0      0      4 GiB Hynix    Yes
	 * 0      1      0      0      8 GiB Hynix    No
	 * 0      0      1      0      4 GiB Samsung  Yes
	 * 0      1      1      0      8 GiB Samsung  No
	 * 0      1      1      1      8 GiB Elpida   No
	 * 0      0      1      1      4 GiB Elpida   No
	 */

	switch (ramcfg) {
	case 0:
		spd_index = 0;
		break;
	case 2:
		spd_index = 1;
		break;
	}

	if (spd_index == -1)
		die("Unsupported memory, RAMCFG=%d\n", ramcfg);

	memory = get_spd_data(spd_index);
	memcpy(&spd[0], memory, 256);
	memcpy(&spd[2], memory, 256);
}
