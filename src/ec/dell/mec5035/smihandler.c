/* SPDX-License-Identifier: GPL-2.0-only */

#include <acpi/acpi.h>
#include <console/console.h>
#include <ec/acpi/ec.h>
#include "mec5035.h"

void mec5035_sleep(int slp_type)
{
	switch (slp_type) {
	case ACPI_S3:
		/* System does not yet resume properly if woken by lid */
		mec5035_change_wake(EC_ACPI_WAKE_LID, WAKE_OFF);
		mec5035_sleep_enable();
		break;
	}
}
