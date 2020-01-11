#include <common.h>
#include <command.h>

static int do_hello(cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[])
{
		printf("Hello World!\n");
			return 0;
}

U_BOOT_CMD(
			hello,	CONFIG_SYS_MAXARGS,	1,	do_hello,
				"echo args to console",
					"[args..]\n"
						"    - echo args to console;"
		);

