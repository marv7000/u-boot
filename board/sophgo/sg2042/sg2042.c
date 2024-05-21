// SPDX-License-Identifier: GPL-2.0+
/*
 * Copyright (c) 2020-2021, SiFive Inc
 *
 * Authors:
 *   Pragnesh Patel <pragnesh.patel@sifive.com>
 */

#include <linux/printk.h>
#include <linux/types.h>
#include <cpu_func.h>
#include <dm.h>
#include <asm/sections.h>

void *board_fdt_blob_setup(int *err)
{
	*err = 0;
	if (IS_ENABLED(CONFIG_OF_SEPARATE) || IS_ENABLED(CONFIG_OF_BOARD)) {
		if (gd->arch.firmware_fdt_addr)
		{
			printk("fdt is present at [%p]\n", (void*)gd->arch.firmware_fdt_addr);
			return (ulong *)(uintptr_t)gd->arch.firmware_fdt_addr;
		}
		printk("fdt is not present!\n");
	}

	return (ulong *)&_end;
}

int board_init(void)
{
	/* enable all cache ways */
	enable_caches();

	return 0;
}
