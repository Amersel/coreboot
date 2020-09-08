/* SPDX-License-Identifier: GPL-2.0-only */

#include <program_loading.h>

/* For each segment of a program loaded this function is called*/
void prog_segment_loaded(uintptr_t start, size_t size, int flags)
{
	platform_segment_loaded(start, size, flags);
	arch_segment_loaded(start, size, flags);
}

void __weak platform_segment_loaded(uintptr_t start,
							size_t size, int flags)
{
	/* do nothing */
}

void __weak arch_segment_loaded(uintptr_t start, size_t size,
						int flags)
{
	/* do nothing */
}

void prog_run(struct prog *prog)
{
	//printk(BIOS_DEBUG, "MANUAL DEBUG: enter prog_run."
	//		"platform_prog_run()\n");
	platform_prog_run(prog);
	//printk(BIOS_DEBUG, "MANUAL DEBUG: platform_prog_run finished."
	//		"arch_prog_run.\n");
	arch_prog_run(prog);
	//printk(BIOS_DEBUG, "MANUAL DEBUG: arch_prog_run finished."
	//		"prog_run end.\n");
}

void __weak platform_prog_run(struct prog *prog)
{
	/* do nothing */
}
