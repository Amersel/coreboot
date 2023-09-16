/* SPDX-License-Identifier: GPL-2.0-only */

#include <stdint.h>
#include <northbridge/intel/haswell/haswell.h>
#include <northbridge/intel/haswell/raminit.h>
#include <southbridge/intel/lynxpoint/pch.h>

void mainboard_config_rcba(void)
{
}

// /* FIXME: called after romstage_common, remove it if not used */
// void mb_late_romstage_setup(void)
// {
// }

void mb_get_spd_map(struct spd_info *spdi)
{
	/* FIXME: check this */
	spdi->addresses[0] = 0x50;
	spdi->addresses[1] = 0x51;
	spdi->addresses[2] = 0x52;
	spdi->addresses[3] = 0x53;
}

const struct usb2_port_config mainboard_usb2_ports[MAX_USB2_PORTS] = {
	/* FIXME: Length and Location are computed from IOBP values, may be inaccurate */
	/* Length, Enable, OCn#, Location */
	{ 0x0110, 1, 0, USB_PORT_BACK_PANEL },
	{ 0x0110, 1, 0, USB_PORT_BACK_PANEL },
	{ 0x0040, 1, 1, USB_PORT_BACK_PANEL },
	{ 0x0080, 1, USB_OC_PIN_SKIP, USB_PORT_DOCK },
	{ 0x0110, 1, USB_OC_PIN_SKIP, USB_PORT_BACK_PANEL },
	{ 0x0110, 1, 2, USB_PORT_BACK_PANEL },
	{ 0x0110, 1, 3, USB_PORT_BACK_PANEL },
	{ 0x0110, 1, 3, USB_PORT_BACK_PANEL },
	{ 0x0110, 1, 4, USB_PORT_BACK_PANEL },
	{ 0x0110, 1, 4, USB_PORT_BACK_PANEL },
	{ 0x0110, 1, 5, USB_PORT_BACK_PANEL },
	{ 0x0110, 1, 5, USB_PORT_BACK_PANEL },
	{ 0x0110, 1, 6, USB_PORT_BACK_PANEL },
	{ 0x0110, 1, 6, USB_PORT_BACK_PANEL },
};

const struct usb3_port_config mainboard_usb3_ports[MAX_USB3_PORTS] = {
	{ 1, 0 },
	{ 1, 0 },
	{ 1, 1 },
	{ 1, 1 },
	{ 1, 2 },
	{ 1, 2 },
};
