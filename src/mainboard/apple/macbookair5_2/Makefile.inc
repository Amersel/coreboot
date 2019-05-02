bootblock-y += gpio.c
bootblock-y += early_init.c

romstage-y += gpio.c
romstage-y += early_init.c

ramstage-$(CONFIG_MAINBOARD_USE_LIBGFXINIT) += gma-mainboard.ads

subdirs-y += spd
