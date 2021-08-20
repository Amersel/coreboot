/* SPDX-License-Identifier: GPL-2.0-only */

#include <northbridge/intel/haswell/haswell.h>
#include <northbridge/intel/haswell/raminit.h>
#include <southbridge/intel/lynxpoint/pch.h>

void mainboard_config_rcba(void)
{
	
	RCBA16(D31IR) = DIR_ROUTE(PIRQA, PIRQD, PIRQC, PIRQA);
	RCBA16(D29IR) = DIR_ROUTE(PIRQH, PIRQD, PIRQA, PIRQC);
	RCBA16(D28IR) = DIR_ROUTE(PIRQA, PIRQA, PIRQA, PIRQA);
	RCBA16(D27IR) = DIR_ROUTE(PIRQG, PIRQB, PIRQC, PIRQD);
	RCBA16(D26IR) = DIR_ROUTE(PIRQA, PIRQF, PIRQC, PIRQD);
	RCBA16(D25IR) = DIR_ROUTE(PIRQE, PIRQF, PIRQG, PIRQH);
	RCBA16(D22IR) = DIR_ROUTE(PIRQA, PIRQD, PIRQC, PIRQB);
	RCBA16(D20IR) = DIR_ROUTE(PIRQA, PIRQB, PIRQC, PIRQD);

	//RCBA_RMW_REG_32(FD, ~0, PCH_DISABLE_ALWAYS),
};

void mb_get_spd_map(struct spd_info *spdi)
{
	spdi->addresses[0] = 0x50;
	spdi->addresses[1] = 0x51;
	spdi->addresses[2] = 0x52;
	spdi->addresses[3] = 0x53;
}

const struct usb2_port_config mainboard_usb2_ports[MAX_USB2_PORTS] = {
	/* Length, Enable, OCn#, Location */
	{ 0x0040, 1, USB_OC_PIN_SKIP, USB_PORT_BACK_PANEL },
	{ 0x0040, 1, USB_OC_PIN_SKIP, USB_PORT_BACK_PANEL },
	{ 0x0040, 1, 1, USB_PORT_BACK_PANEL },
	{ 0x0040, 1, 2, USB_PORT_BACK_PANEL },
	{ 0x0040, 1, 3, USB_PORT_BACK_PANEL },
	{ 0x0040, 1, 3, USB_PORT_BACK_PANEL },
	{ 0x0040, 1, 0, USB_PORT_BACK_PANEL },
	{ 0x0040, 1, 0, USB_PORT_BACK_PANEL },
	{ 0x0040, 1, 4, USB_PORT_BACK_PANEL },
	{ 0x0040, 1, 4, USB_PORT_BACK_PANEL },
	{ 0x0040, 1, 5, USB_PORT_BACK_PANEL },
	{ 0x0040, 1, 5, USB_PORT_BACK_PANEL },
	{ 0x0040, 1, 6, USB_PORT_BACK_PANEL },
	{ 0x0040, 1, 7, USB_PORT_BACK_PANEL },
};

const struct usb3_port_config mainboard_usb3_ports[MAX_USB3_PORTS] = {
	/* Enable, OCn# */
	{ 1, 6 },
	{ 1, 7 },
	{ 1, USB_OC_PIN_SKIP },
	{ 1, USB_OC_PIN_SKIP },
	{ 1, 1 },
	{ 1, 2 },
};

// void mainboard_romstage_entry(unsigned long bist)
// {
// 	struct pei_data pei_data = {
// 		.pei_version = PEI_VERSION,
// 		.mchbar = (uintptr_t)DEFAULT_MCHBAR,
// 		.dmibar = (uintptr_t)DEFAULT_DMIBAR,
// 		.epbar = DEFAULT_EPBAR,
// 		.pciexbar = DEFAULT_PCIEXBAR,
// 		.smbusbar = SMBUS_IO_BASE,
// 		.wdbbar = 0x4000000,
// 		.wdbsize = 0x1000,
// 		.hpet_address = HPET_ADDR,
// 		.rcba = (uintptr_t)DEFAULT_RCBA,
// 		.pmbase = DEFAULT_PMBASE,
// 		.gpiobase = DEFAULT_GPIOBASE,
// 		.temp_mmio_base = 0xfed08000,
// 		.system_type = 1, /* desktop/server, FIXME: check this */
// 		.tseg_size = CONFIG_SMM_TSEG_SIZE,
// 		.spd_addresses = { 0xa0, 0xa2, 0xa4, 0xa6 }, /* FIXME: check this */
// 		.ec_present = 0,
// 		.dimm_channel0_disabled = 0, /* FIXME: leave channel 0 enabled */
// 		.dimm_channel1_disabled = 0, /* FIXME: leave channel 1 enabled */
// 		.max_ddr3_freq = 1600,
// 		.usb2_ports = {
// 			/* Length, Enable, OCn#, Location */
// 			{ 0x0040, 1, USB_OC_PIN_SKIP, USB_PORT_BACK_PANEL },
// 			{ 0x0040, 1, USB_OC_PIN_SKIP, USB_PORT_BACK_PANEL },
// 			{ 0x0040, 1, 1, USB_PORT_BACK_PANEL },
// 			{ 0x0040, 1, 2, USB_PORT_BACK_PANEL },
// 			{ 0x0040, 1, 3, USB_PORT_BACK_PANEL },
// 			{ 0x0040, 1, 3, USB_PORT_BACK_PANEL },
// 			{ 0x0040, 1, 0, USB_PORT_BACK_PANEL },
// 			{ 0x0040, 1, 0, USB_PORT_BACK_PANEL },
// 			{ 0x0040, 1, 4, USB_PORT_BACK_PANEL },
// 			{ 0x0040, 1, 4, USB_PORT_BACK_PANEL },
// 			{ 0x0040, 1, 5, USB_PORT_BACK_PANEL },
// 			{ 0x0040, 1, 5, USB_PORT_BACK_PANEL },
// 			{ 0x0040, 1, 6, USB_PORT_BACK_PANEL },
// 			{ 0x0040, 1, 7, USB_PORT_BACK_PANEL },
// 		},
// 		.usb3_ports = {
// 			{ 1, 6 },
// 			{ 1, 7 },
// 			{ 1, USB_OC_PIN_SKIP },
// 			{ 1, USB_OC_PIN_SKIP },
// 			{ 1, 1 },
// 			{ 1, 2 },
// 		},
// 	};

// 	struct romstage_params romstage_params = {
// 		.pei_data = &pei_data,
// 		.gpio_map = &mainboard_gpio_map,
// 		.rcba_config = rcba_config,
// 		.bist = bist,
// 	};

// 	romstage_common(&romstage_params);
// }
