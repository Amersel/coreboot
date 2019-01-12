package main

type haswellmc struct {
	variant string
}

func (i haswellmc) Scan(ctx Context, addr PCIDevData) {
	inteltool := ctx.InfoSource.GetInteltool()

	/* FIXME:XX Move this somewhere else.  */
	MainboardIncludes = append(MainboardIncludes, "drivers/intel/gma/int15.h")
	MainboardEnable += (`	/* FIXME: fix those values*/
	install_intel_vga_int15_handler(GMA_INT15_ACTIVE_LFP_INT_LVDS, GMA_INT15_PANEL_FIT_DEFAULT, GMA_INT15_BOOT_DISPLAY_DEFAULT, 0);
`)

	DevTree = DevTreeNode{
		Chip:          "northbridge/intel/haswell",
		MissingParent: "northbridge",
		Comment:       "FIXME: check gfx.ndid and gfx.did",
		Registers: map[string]string{
			"gpu_dp_b_hotplug":                    FormatInt32((inteltool.IGD[0xc4030] >> 2) & 7),
			"gpu_dp_c_hotplug":                    FormatInt32((inteltool.IGD[0xc4030] >> 10) & 7),
			"gpu_dp_d_hotplug":                    FormatInt32((inteltool.IGD[0xc4030] >> 18) & 7),
			"gpu_panel_port_select":               FormatInt32((inteltool.IGD[0xc7208] >> 30) & 3),
			"gpu_panel_power_up_delay":            FormatInt32((inteltool.IGD[0xc7208] >> 16) & 0x1fff),
			"gpu_panel_power_backlight_on_delay":  FormatInt32(inteltool.IGD[0xc7208] & 0x1fff),
			"gpu_panel_power_down_delay":          FormatInt32((inteltool.IGD[0xc720c] >> 16) & 0x1fff),
			"gpu_panel_power_backlight_off_delay": FormatInt32(inteltool.IGD[0xc720c] & 0x1fff),
			"gpu_panel_power_cycle_delay":         FormatInt32(inteltool.IGD[0xc7210] & 0xff),
			"gpu_cpu_backlight":                   FormatHex32(inteltool.IGD[0x48254]),
			"gpu_pch_backlight":                   FormatHex32((inteltool.IGD[0xc8254] >> 16) * 0x10001),
			"gpu_ddi_e_connected":                 FormatBool(((inteltool.IGD[0x64000] >> 4) & 1) == 0),
			/* FIXME:XX hardcoded.  */
			"gfx.ndid": "3",
			"gfx.did":  "{ 0x80000100, 0x80000240, 0x80000410, 0x80000410, 0x00000005 }",
		},
		Children: []DevTreeNode{
			{
				Chip: "cpu_cluster",
				Dev:  0,
				Children: []DevTreeNode{
					{
						Chip: "cpu/intel/haswell",
						Children: []DevTreeNode{
							{
								Chip: "lapic",
								Dev:  0,
							},
							{
								Chip: "lapic",
								Dev:  0xacac,
								Disabled: true,
							},
						},
						Registers: map[string]string{
							/* FIXME:XX hardcoded.  */
							"c1_acpower": "1",
							"c2_acpower": "3",
							"c3_acpower": "5",
							"c1_battery": "1",
							"c2_battery": "3",
							"c3_battery": "5",
						},
					},
				},
			},

			{
				Chip:          "domain",
				Dev:           0,
				PCIController: true,
				ChildPCIBus:   0,
				PCISlots: []PCISlot{
					PCISlot{PCIAddr: PCIAddr{Dev: 0x0, Func: 0}, writeEmpty: true, additionalComment: "Host bridge"},
					PCISlot{PCIAddr: PCIAddr{Dev: 0x1, Func: 0}, writeEmpty: true, additionalComment: "PCIe Bridge for discrete graphics"},
					PCISlot{PCIAddr: PCIAddr{Dev: 0x2, Func: 0}, writeEmpty: true, additionalComment: "Internal graphics"},
					PCISlot{PCIAddr: PCIAddr{Dev: 0x3, Func: 0}, writeEmpty: true, additionalComment: "Mini-HD audio"},
				},
			},
		},
	}

	PutPCIDev(addr, "Host bridge")

	/* FIXME:XX some configs are unsupported.  */

	KconfigBool["CPU_INTEL_HASWELL"] = true
	KconfigBool["NORTHBRIDGE_INTEL_HASWELL"] = true
	KconfigBool["INTEL_INT15"] = true
	KconfigBool["HAVE_ACPI_TABLES"] = true
	KconfigBool["HAVE_ACPI_RESUME"] = true

	if i.variant != "ULT" {
		KconfigBool["TSC_MONOTONIC_TIMER"] = true
		KconfigString["GFX_GMA_CPU_VARIANT"] = "Normal"
	}

	KconfigInt["MAX_CPUS"] = 8

	DSDTIncludes = append(DSDTIncludes, DSDTInclude{
		File: "cpu/intel/common/acpi/cpu.asl",
	})

	DSDTPCI0Includes = append(DSDTPCI0Includes, DSDTInclude{
		File: "northbridge/intel/haswell/acpi/haswell.asl",
	}, DSDTInclude{
		File: "drivers/intel/gma/acpi/default_brightness_levels.asl",
	})
}

func init() {
	RegisterPCI(0x8086, 0x0c00, haswellmc{variant: "Desktop"})
	RegisterPCI(0x8086, 0x0c04, haswellmc{variant: "Mobile"})
	RegisterPCI(0x8086, 0x0a04, haswellmc{variant: "ULT"})
	RegisterPCI(0x8086, 0x0c08, haswellmc{variant: "Server"})
	for _, id := range []uint16{
		0x0402, 0x0412, 0x0422,
		0x0406, 0x0416, 0x0426,
		0x0d16, 0x0d26, 0x0d36,
		0x0a06, 0x0a16, 0x0a26,
	} {
		RegisterPCI(0x8086, id, GenericVGA{GenericPCI{Comment: "VGA controller"}})
	}
}
