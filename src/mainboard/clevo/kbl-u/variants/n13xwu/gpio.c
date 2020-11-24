/* SPDX-License-Identifier: GPL-2.0-only */

#include <mainboard/gpio.h>
#include <soc/gpio.h>

static const struct pad_config gpio_table[] = {
	// RCIN#
	_PAD_CFG_STRUCT(GPP_A0,		0x44000502,	0x0),

	// LAD0
	_PAD_CFG_STRUCT(GPP_A1,		0x44000402,	0x0),

	// LAD1
	_PAD_CFG_STRUCT(GPP_A2,		0x44000402,	0x0),

	// LAD2
	_PAD_CFG_STRUCT(GPP_A3,		0x44000402,	0x0),

	// LAD3
	_PAD_CFG_STRUCT(GPP_A4,		0x44000402,	0x0),

	// LFRAME#
	_PAD_CFG_STRUCT(GPP_A5,		0x44000600,	0x0),

	// SERIRQ
	_PAD_CFG_STRUCT(GPP_A6,		0x44000402,	0x0),

	// PIRQA#
	_PAD_CFG_STRUCT(GPP_A7,		0x44000102,	0x0),

	// CLKRUN#
	_PAD_CFG_STRUCT(GPP_A8,		0x44000700,	0x0),

	// CLKOUT_LPC0
	_PAD_CFG_STRUCT(GPP_A9,		0x44000600,	0x0),

	// CLKOUT_LPC1
	_PAD_CFG_STRUCT(GPP_A10,	0x44000600,	0x1000),

	// PME#
	_PAD_CFG_STRUCT(GPP_A11,	0x44000200,	0x0),

	// BM_BUSY#
	_PAD_CFG_STRUCT(GPP_A12,	0x44000200,	0x0),

	// SUSWARN#/SUSPWRDNACK
	_PAD_CFG_STRUCT(GPP_A13,	0x44000200,	0x0),

	// SUS_STAT#/ESPI_RESET#
	_PAD_CFG_STRUCT(GPP_A14,	0x44000600,	0x0),

	// SUS_ACK#
	_PAD_CFG_STRUCT(GPP_A15,	0x44000502,	0x0),

	// SD_1P8_SEL
	_PAD_CFG_STRUCT(GPP_A16,	0x44000200,	0x0),

	// SD_PWR_EN#
	_PAD_CFG_STRUCT(GPP_A17,	0x44000200,	0x0),

	// ISH_GP0
	_PAD_CFG_STRUCT(GPP_A18,	0x44000201,	0x0),

	// ISH_GP1
	_PAD_CFG_STRUCT(GPP_A19,	0x44000603,	0x0),

	// ISH_GP2
	_PAD_CFG_STRUCT(GPP_A20,	0x44000200,	0x0),

	// ISH_GP3
	_PAD_CFG_STRUCT(GPP_A21,	0x84000200,	0x1000),

	// ISH_GP4
	_PAD_CFG_STRUCT(GPP_A22,	0x4000200,	0x0),

	// ISH_GP5
	_PAD_CFG_STRUCT(GPP_A23,	0x4000200,	0x0),

	// CORE_VID0
	_PAD_CFG_STRUCT(GPP_B0,		0x44000700,	0x0),

	// CORE_VID1
	_PAD_CFG_STRUCT(GPP_B1,		0x44000700,	0x0),

	// VRALERT#
	_PAD_CFG_STRUCT(GPP_B2,		0x44000200,	0x0),

	// CPU_GP2
	_PAD_CFG_STRUCT(GPP_B3,		0x44000200,	0x0),

	// CPU_GP3
	_PAD_CFG_STRUCT(GPP_B4,		0x44000200,	0x0),

	// SRCCLKREQ0#
	_PAD_CFG_STRUCT(GPP_B5,		0x44000200,	0x0),

	// SRCCLKREQ1#
	_PAD_CFG_STRUCT(GPP_B6,		0x44000200,	0x0),

	// SRCCLKREQ2#
	_PAD_CFG_STRUCT(GPP_B7,		0x44000700,	0x0),

	// SRCCLKREQ3#
	_PAD_CFG_STRUCT(GPP_B8,		0x44000700,	0x0),

	// SRCCLKREQ4#
	_PAD_CFG_STRUCT(GPP_B9,		0x44000702,	0x0),

	// SRCCLKREQ5#
	_PAD_CFG_STRUCT(GPP_B10,	0x44000702,	0x0),

	// EXT_PWR_GATE#
	_PAD_CFG_STRUCT(GPP_B11,	0x44000700,	0x0),

	// SLP_S0#
	_PAD_CFG_STRUCT(GPP_B12,	0x44000200,	0x0),

	// PLTRST#
	_PAD_CFG_STRUCT(GPP_B13,	0x44000700,	0x0),

	// SPKR
	_PAD_CFG_STRUCT(GPP_B14,	0x44000600,	0x1000),

	// GSPI0_CS#
	_PAD_CFG_STRUCT(GPP_B15,	0x44000200,	0x0),

	// GSPI0_CLK
	_PAD_CFG_STRUCT(GPP_B16,	0x44000200,	0x0),

	// GSPI0_MISO
	_PAD_CFG_STRUCT(GPP_B17,	0x44000200,	0x0),

	// GSPI0_MOSI
	_PAD_CFG_STRUCT(GPP_B18,	0x44000600,	0x3000),

	// GSPI1_CS#
	_PAD_CFG_STRUCT(GPP_B19,	0x44000200,	0x0),

	// GSPI1_CLK
	_PAD_CFG_STRUCT(GPP_B20,	0x44000200,	0x0),

	// GSPI1_MISO
	_PAD_CFG_STRUCT(GPP_B21,	0x44000200,	0x0),

	// GSPI1_MOSI
	_PAD_CFG_STRUCT(GPP_B22,	0x44000700,	0x1000),

	// SML1ALERT#/PCHHOT#
	_PAD_CFG_STRUCT(GPP_B23,	0x44000200,	0x0),

	// SMBCLK
	_PAD_CFG_STRUCT(GPP_C0,		0x44000702,	0x0),

	// SMBDATA
	_PAD_CFG_STRUCT(GPP_C1,		0x44000702,	0x1000),

	// SMBALERT#
	_PAD_CFG_STRUCT(GPP_C2,		0x44000201,	0x1000),

	// SML0CLK
	_PAD_CFG_STRUCT(GPP_C3,		0x44000200,	0x0),

	// SML0DATA
	_PAD_CFG_STRUCT(GPP_C4,		0x44000200,	0x0),

	// SML0ALERT#
	_PAD_CFG_STRUCT(GPP_C5,		0x44000200,	0x0),

	// SML1CLK
//	_PAD_CFG_STRUCT(GPP_C6,		0xffffffff,	0xffffff00),

	// SML1DATA
//	_PAD_CFG_STRUCT(GPP_C7,		0xffffffff,	0xffffff00),

	// UART0_RXD
	_PAD_CFG_STRUCT(GPP_C8,		0x44000700,	0x0),

	// UART0_TXD
	_PAD_CFG_STRUCT(GPP_C9,		0x44000700,	0x0),

	// UART0_RTS#
	_PAD_CFG_STRUCT(GPP_C10,	0x44000700,	0x0),

	// UART0_CTS#
	_PAD_CFG_STRUCT(GPP_C11,	0x44000700,	0x0),

	// UART1_RXD
	_PAD_CFG_STRUCT(GPP_C12,	0x44000702,	0x0),

	// UART1_TXD
	_PAD_CFG_STRUCT(GPP_C13,	0x82880102,	0x0),

	// UART1_RTS#
	_PAD_CFG_STRUCT(GPP_C14,	0x44000700,	0x0),

	// UART1_CTS#
	_PAD_CFG_STRUCT(GPP_C15,	0x44000700,	0x0),

	// I2C0_SDA
	_PAD_CFG_STRUCT(GPP_C16,	0x44000200,	0x0),

	// I2C0_SCL
	_PAD_CFG_STRUCT(GPP_C17,	0x44000200,	0x0),

	// I2C1_SDA
	_PAD_CFG_STRUCT(GPP_C18,	0x44000200,	0x0),

	// I2C1_SCL
	_PAD_CFG_STRUCT(GPP_C19,	0x40880102,	0x0),

	// UART2_RXD
	_PAD_CFG_STRUCT(GPP_C20,	0x44000702,	0x0),

	// UART2_TXD
	_PAD_CFG_STRUCT(GPP_C21,	0x44000700,	0x0),

	// UART2_RTS#
	_PAD_CFG_STRUCT(GPP_C22,	0x44000700,	0x0),

	// UART2_CTS#
	_PAD_CFG_STRUCT(GPP_C23,	0x44000700,	0x0),

	// SPI1_CS#
	_PAD_CFG_STRUCT(GPP_D0,		0x44000200,	0x0),

	// SPI1_CLK
	_PAD_CFG_STRUCT(GPP_D1,		0x44000200,	0x0),

	// SPI1_MISO
	_PAD_CFG_STRUCT(GPP_D2,		0x44000200,	0x0),

	// SPI1_MOSI
	_PAD_CFG_STRUCT(GPP_D3,		0x44000200,	0x0),

	// FLASHTRIG
	_PAD_CFG_STRUCT(GPP_D4,		0x44000200,	0x0),

	// ISH_I2C0_SDA
	_PAD_CFG_STRUCT(GPP_D5,		0x44000700,	0x0),

	// ISH_I2C0_SCL
	_PAD_CFG_STRUCT(GPP_D6,		0x44000700,	0x0),

	// ISH_I2C1_SDA
	_PAD_CFG_STRUCT(GPP_D7,		0x44000700,	0x0),

	// ISH_I2C1_SCL
	_PAD_CFG_STRUCT(GPP_D8,		0x44000201,	0x0),

	// GPIO
	_PAD_CFG_STRUCT(GPP_D9,		0x44000200,	0x0),

	// GPIO
	_PAD_CFG_STRUCT(GPP_D10,	0x44000200,	0x0),

	// GPIO
	_PAD_CFG_STRUCT(GPP_D11,	0x44000200,	0x0),

	// GPIO
	_PAD_CFG_STRUCT(GPP_D12,	0x44000200,	0x0),

	// ISH_UART0_RXD
	_PAD_CFG_STRUCT(GPP_D13,	0x44000200,	0x0),

	// ISH_UART0_TXD
	_PAD_CFG_STRUCT(GPP_D14,	0x44000200,	0x0),

	// ISH_UART0_RTS#
	_PAD_CFG_STRUCT(GPP_D15,	0x44000700,	0x0),

	// ISH_UART0_CTS#
	_PAD_CFG_STRUCT(GPP_D16,	0x44000700,	0x0),

	// DMIC_CLK1
	_PAD_CFG_STRUCT(GPP_D17,	0x44000700,	0x0),

	// DMIC_DATA1
	_PAD_CFG_STRUCT(GPP_D18,	0x44000700,	0x0),

	// DMIC_CLK0
	_PAD_CFG_STRUCT(GPP_D19,	0x44000700,	0x0),

	// DMIC_DATA0
	_PAD_CFG_STRUCT(GPP_D20,	0x44000700,	0x0),

	// SPI1_IO2
	_PAD_CFG_STRUCT(GPP_D21,	0x44000102,	0x0),

	// SPI1_IO3
	_PAD_CFG_STRUCT(GPP_D22,	0x44000700,	0x0),

	// I2S_MCLK
	_PAD_CFG_STRUCT(GPP_D23,	0x44000700,	0x0),

	// SATAXPCIE0/SATAGP0
	_PAD_CFG_STRUCT(GPP_E0,		0x42100100,	0x1000),

	// SATAXPCIE1/SATAGP1
	_PAD_CFG_STRUCT(GPP_E1,		0x44000702,	0x0),

	// SATAXPCIE2/SATAGP2
	_PAD_CFG_STRUCT(GPP_E2,		0x44000502,	0x0),

	// CPU_GP0
	_PAD_CFG_STRUCT(GPP_E3,		0x40000000,	0x0),

	// DEVSLP0
	_PAD_CFG_STRUCT(GPP_E4,		0x4000700,	0x0),

	// DEVSLP1
	_PAD_CFG_STRUCT(GPP_E5,		0x4000700,	0x0),

	// DEVSLP2
	_PAD_CFG_STRUCT(GPP_E6,		0x44000200,	0x0),

	// CPU_GP1
	_PAD_CFG_STRUCT(GPP_E7,		0x44000100,	0x0),

	// SATALED#
	_PAD_CFG_STRUCT(GPP_E8,		0x44000700,	0x0),

	// USB2_OC0#
	_PAD_CFG_STRUCT(GPP_E9,		0x44000200,	0x0),

	// USB2_OC1#
	_PAD_CFG_STRUCT(GPP_E10,	0x44000200,	0x0),

	// USB2_OC2#
	_PAD_CFG_STRUCT(GPP_E11,	0x44000200,	0x0),

	// USB2_OC3#
	_PAD_CFG_STRUCT(GPP_E12,	0x44000200,	0x0),

	// DDPB_HPD0
	_PAD_CFG_STRUCT(GPP_E13,	0x44000700,	0x0),

	// DDPC_HPD1
	_PAD_CFG_STRUCT(GPP_E14,	0x44000700,	0x0),

	// DDPD_HPD2
	_PAD_CFG_STRUCT(GPP_E15,	0x42840102,	0x0),

	// DDPE_HPD3
	_PAD_CFG_STRUCT(GPP_E16,	0x80880102,	0x0),

	// EDP_HPD
	_PAD_CFG_STRUCT(GPP_E17,	0x44000702,	0x0),

	// DDPB_CTRLCLK
	_PAD_CFG_STRUCT(GPP_E18,	0x44000700,	0x0),

	// DDPB_CTRLDATA
	_PAD_CFG_STRUCT(GPP_E19,	0x44000700,	0x1000),

	// DDPC_CTRLCLK
	_PAD_CFG_STRUCT(GPP_E20,	0x44000702,	0x0),

	// DDPC_CTRLDATA
	_PAD_CFG_STRUCT(GPP_E21,	0x44000702,	0x1000),

	// DDPD_CTRLCLK
	_PAD_CFG_STRUCT(GPP_E22,	0x40100000,	0x0),

	// DDPD_CTRLDATA
	_PAD_CFG_STRUCT(GPP_E23,	0x44000201,	0x1000),

	// BATLOW#
	_PAD_CFG_STRUCT(GPD0,		0x4000702,	0x0),

	// LANPHYPC
	_PAD_CFG_STRUCT(GPD1,		0x4000700,	0x0),

	// LAN_WAKE#
	_PAD_CFG_STRUCT(GPD2,		0x880502,	0x0),

	// PWRBTN#
	_PAD_CFG_STRUCT(GPD3,		0x4000702,	0x3000),

	// SLP_S3#
	_PAD_CFG_STRUCT(GPD4,		0x4000700,	0x0),

	// SLP_S4#
	_PAD_CFG_STRUCT(GPD5,		0x4000700,	0x0),

	// SLP_A#
	_PAD_CFG_STRUCT(GPD6,		0x4000700,	0x0),

	// RSVD
	_PAD_CFG_STRUCT(GPD7,		0x4000301,	0x0),

	// SUSCLK
	_PAD_CFG_STRUCT(GPD8,		0x4000700,	0x0),

	// SLP_WLAN#
	_PAD_CFG_STRUCT(GPD9,		0x4000700,	0x0),

	// SLP_S5#
	_PAD_CFG_STRUCT(GPD10,		0x4000700,	0x0),

	// LANPHYPC
	_PAD_CFG_STRUCT(GPD11,		0x4000500,	0x0),

	// I2S2_SCLK
	_PAD_CFG_STRUCT(GPP_F0,		0x44000702,	0x0),

	// I2S2_SFRM
	_PAD_CFG_STRUCT(GPP_F1,		0x44000702,	0x0),

	// I2S2_TXD
	_PAD_CFG_STRUCT(GPP_F2,		0x44000700,	0x0),

	// I2S2_RXD
	_PAD_CFG_STRUCT(GPP_F3,		0x44000702,	0x0),

	// I2C2_SDA
	_PAD_CFG_STRUCT(GPP_F4,		0x44000702,	0x2000000),

	// I2C2_SCL
	_PAD_CFG_STRUCT(GPP_F5,		0x44000702,	0x2000000),

	// I2C3_SDA
	_PAD_CFG_STRUCT(GPP_F6,		0x44000702,	0x2000000),

	// I2C3_SCL
	_PAD_CFG_STRUCT(GPP_F7,		0x44000702,	0x2000000),

	// I2C4_SDA
	_PAD_CFG_STRUCT(GPP_F8,		0x44000702,	0x2000000),

	// I2C4_SCL
	_PAD_CFG_STRUCT(GPP_F9,		0x44000702,	0x2000000),

	// I2C5_SDA/ISH_I2C2_SDA
	_PAD_CFG_STRUCT(GPP_F10,	0x44000b02,	0x2000000),

	// I2C5_SCL/ISH_I2C2_SCL
	_PAD_CFG_STRUCT(GPP_F11,	0x44000b02,	0x2000000),

	// EMMC_CMD
	_PAD_CFG_STRUCT(GPP_F12,	0x44000702,	0x0),

	// EMMC_DATA0
	_PAD_CFG_STRUCT(GPP_F13,	0x44000702,	0x0),

	// EMMC_DATA1
	_PAD_CFG_STRUCT(GPP_F14,	0x44000702,	0x0),

	// EMMC_DATA2
	_PAD_CFG_STRUCT(GPP_F15,	0x44000702,	0x0),

	// EMMC_DATA3
	_PAD_CFG_STRUCT(GPP_F16,	0x44000702,	0x0),

	// EMMC_DATA4
	_PAD_CFG_STRUCT(GPP_F17,	0x44000702,	0x0),

	// EMMC_DATA5
	_PAD_CFG_STRUCT(GPP_F18,	0x44000702,	0x0),

	// EMMC_DATA6
	_PAD_CFG_STRUCT(GPP_F19,	0x44000702,	0x0),

	// EMMC_DATA7
	_PAD_CFG_STRUCT(GPP_F20,	0x44000702,	0x0),

	// EMMC_RCLK
	_PAD_CFG_STRUCT(GPP_F21,	0x44000702,	0x0),

	// EMMC_CLK
	_PAD_CFG_STRUCT(GPP_F22,	0x44000700,	0x0),

	// GPIO
	_PAD_CFG_STRUCT(GPP_F23,	0x40100100,	0x0),

	// SD_CMD
	_PAD_CFG_STRUCT(GPP_G0,		0x44000700,	0x0),

	// SD_DATA0
	_PAD_CFG_STRUCT(GPP_G1,		0x44000102,	0x0),

	// SD_DATA1
	_PAD_CFG_STRUCT(GPP_G2,		0x44000700,	0x0),

	// SD_DATA2
	_PAD_CFG_STRUCT(GPP_G3,		0x44000700,	0x0),

	// SD_DATA3
	_PAD_CFG_STRUCT(GPP_G4,		0x44000700,	0x0),

	// SD_CD#
	_PAD_CFG_STRUCT(GPP_G5,		0x44000702,	0x0),

	// SD_CLK
	_PAD_CFG_STRUCT(GPP_G6,		0x44000700,	0x0),

	// SD_WP
	_PAD_CFG_STRUCT(GPP_G7,		0x44000702,	0x0)
};

void mainboard_configure_gpios(void)
{
	gpio_configure_pads(gpio_table, ARRAY_SIZE(gpio_table));
}
