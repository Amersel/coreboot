/* SPDX-License-Identifier: GPL-2.0-only */

#ifndef AMD_PICASSO_PCI_DEVS_H
#define AMD_PICASSO_PCI_DEVS_H

#include <device/pci_def.h>
#include <amdblocks/pci_devs.h>

/* GNB Root Complex */
#define GNB_DEV			0x0
#define GNB_FUNC		0
#define GNB_DEVFN		PCI_DEVFN(GNB_DEV, GNB_FUNC)
#define SOC_GNB_DEV		_SOC_DEV(GNB_DEV, GNB_FUNC)

/* IOMMU */
#define IOMMU_DEV		0x0
#define IOMMU_FUNC		2
#define IOMMU_DEVFN		PCI_DEVFN(IOMMU_DEV, IOMMU_FUNC)
#define SOC_IOMMU_DEV		_SOC_DEV(IOMMU_DEV, IOMMU_FUNC)

/* PCIe GPP Bridges 0 - 6 */
#define PCIE_HOST_BRIDGE_06_DEV	0x1

#define PCIE_GPP_0_FUNC		1
#define PCIE_GPP_0_DEVFN	PCI_DEVFN(PCIE_HOST_BRIDGE_06_DEV, PCIE_GPP_0_FUNC)
#define SOC_GPP_0_DEV		_SOC_DEV(PCIE_HOST_BRIDGE_06_DEV, PCIE_GPP_0_FUNC)

#define PCIE_GPP_1_FUNC		2
#define PCIE_GPP_1_DEVFN	PCI_DEVFN(PCIE_HOST_BRIDGE_06_DEV, PCIE_GPP_1_FUNC)
#define SOC_GPP_1_DEV		_SOC_DEV(PCIE_HOST_BRIDGE_06_DEV, PCIE_GPP_1_FUNC)

#define PCIE_GPP_2_FUNC		3
#define PCIE_GPP_2_DEVFN	PCI_DEVFN(PCIE_HOST_BRIDGE_06_DEV, PCIE_GPP_2_FUNC)
#define SOC_GPP_2_DEV		_SOC_DEV(PCIE_HOST_BRIDGE_06_DEV, PCIE_GPP_2_FUNC)

#define PCIE_GPP_3_FUNC		4
#define PCIE_GPP_3_DEVFN	PCI_DEVFN(PCIE_HOST_BRIDGE_06_DEV, PCIE_GPP_3_FUNC)
#define SOC_GPP_3_DEV		_SOC_DEV(PCIE_HOST_BRIDGE_06_DEV, PCIE_GPP_3_FUNC)

#define PCIE_GPP_4_FUNC		5
#define PCIE_GPP_4_DEVFN	PCI_DEVFN(PCIE_HOST_BRIDGE_06_DEV, PCIE_GPP_4_FUNC)
#define SOC_GPP_4_DEV		_SOC_DEV(PCIE_HOST_BRIDGE_06_DEV, PCIE_GPP_4_FUNC)

#define PCIE_GPP_5_FUNC		6
#define PCIE_GPP_5_DEVFN	PCI_DEVFN(PCIE_HOST_BRIDGE_06_DEV, PCIE_GPP_5_FUNC)
#define SOC_GPP_5_DEV		_SOC_DEV(PCIE_HOST_BRIDGE_06_DEV, PCIE_GPP_5_FUNC)

#define PCIE_GPP_6_FUNC		7
#define PCIE_GPP_6_DEVFN	PCI_DEVFN(PCIE_HOST_BRIDGE_06_DEV, PCIE_GPP_6_FUNC)
#define SOC_GPP_6_DEV		_SOC_DEV(PCIE_HOST_BRIDGE_06_DEV, PCIE_GPP_6_FUNC)

/* PCIe GPP Bridges to Bus A and Bus B devices */
#define PCIE_HOST_BRIDGE_AB_DEV	0x8

#define PCIE_GPP_A_FUNC		1
#define PCIE_GPP_A_DEVFN	PCI_DEVFN(PCIE_HOST_BRIDGE_AB_DEV, PCIE_GPP_A_FUNC)
#define SOC_PCIE_GPP_A_DEV	_SOC_DEV(PCIE_HOST_BRIDGE_AB_DEV, PCIE_GPP_A_FUNC)
#define   GFX_DEV		0x0
#define   GFX_FUNC		0
#define   GFX_DEVFN		PCI_DEVFN(GFX_DEV, GFX_FUNC)

#define   XHCI0_DEV		0x0
#define   XHCI0_FUNC		3
#define   XHCI0_DEVFN		PCI_DEVFN(XHCI0_DEV, XHCI0_FUNC)

#define   XHCI1_DEV		0x0
#define   XHCI1_FUNC		4
#define   XHCI1_DEVFN		PCI_DEVFN(XHCI1_DEV, XHCI1_FUNC)

#define   AUDIO_DEV		0x0
#define   AUDIO_FUNC		5
#define   AUDIO_DEVFN		PCI_DEVFN(AUDIO_DEV, AUDIO_FUNC)

#define   HD_AUDIO_DEV		0x0
#define   HD_AUDIO_FUNC		6
#define   HD_AUDIO_DEVFN	PCI_DEVFN(HD_AUDIO_DEV, HD_AUDIO_FUNC)

#define PCIE_GPP_B_FUNC		2
#define PCIE_GPP_B_DEVFN	PCI_DEVFN(PCIE_HOST_BRIDGE_AB_DEV, PCIE_GPP_B_FUNC)
#define SOC_PCIE_GPP_B_DEV	_SOC_DEV(PCIE_HOST_BRIDGE_AB_DEV, PCIE_GPP_B_FUNC)
#define   SATA_DEV		0x0
#define   SATA_FUNC		0
#define   SATA_DEVFN		PCI_DEVFN(SATA_DEV, SATA_FUNC)

/* Data Fabric functions */
#define DF_DEV			0x18

#define DF_F0_DEVFN		PCI_DEVFN(DF_DEV, 0)
#define SOC_DF_F0_DEV		_SOC_DEV(DF_DEV, 0)

#define DF_F1_DEVFN		PCI_DEVFN(DF_DEV, 1)
#define SOC_DF_F1_DEV		_SOC_DEV(DF_DEV, 1)

#define DF_F2_DEVFN		PCI_DEVFN(DF_DEV, 2)
#define SOC_DF_F2_DEV		_SOC_DEV(DF_DEV, 2)

#define DF_F3_DEVFN		PCI_DEVFN(DF_DEV, 3)
#define SOC_DF_F3_DEV		_SOC_DEV(DF_DEV, 3)

#define DF_F4_DEVFN		PCI_DEVFN(DF_DEV, 4)
#define SOC_DF_F4_DEV		_SOC_DEV(DF_DEV, 4)

#define DF_F5_DEVFN		PCI_DEVFN(DF_DEV, 5)
#define SOC_DF_F5_DEV		_SOC_DEV(DF_DEV, 5)

#define DF_F6_DEVFN		PCI_DEVFN(DF_DEV, 6)
#define SOC_DF_F6_DEV		_SOC_DEV(DF_DEV, 6)

/* SMBUS */
#define SMBUS_DEV		0x14
#define SMBUS_FUNC		0
#define SMBUS_DEVFN		PCI_DEVFN(SMBUS_DEV, SMBUS_FUNC)
#define SOC_SMBUS_DEV		_SOC_DEV(SMBUS_DEV, SMBUS_FUNC)

/* LPC BUS */
#define PCU_DEV			0x14
#define LPC_FUNC		3
#define LPC_DEVFN		PCI_DEVFN(PCU_DEV, LPC_FUNC)
#define SOC_LPC_DEV		_SOC_DEV(PCU_DEV, LPC_FUNC)

#endif /* AMD_PICASSO_PCI_DEVS_H */
