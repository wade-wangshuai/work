#include <common.h>
#include <command.h>

static int do_upgrade(cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[])
{

    char cmd[5][100]={"setenv ipaddr 172.21.53.221;setenv serverip 172.21.53.45\n","tftpboot 0x10000000 bcm947622EAP_nand_cferom_fs_image_128_ubi.w\n","setenv calsize 0x580000;setexpr leftsize $filesize - $calsize;echo $leftsize\n","nand erase 0 0x300000;nand erase 0x580000 0x7A80000","nand write 0x10000000 0x0000 0x200000; nand write 0x10580000 0x580000 $leftsize"};
	int i;
	for (i = 0; i < 5; i++) 
	{
		run_command(cmd[i], 0);
	}

}

U_BOOT_CMD(
			sc_upgrade,	CONFIG_SYS_MAXARGS,	1,	do_upgrade,
			"upgrade the latest code ",
			"\n    - ipaddr 192.168.1.10;serverip 192.168.1.168\n"
			"upgrade code ...\n"
			"    - the latest code"
			);

