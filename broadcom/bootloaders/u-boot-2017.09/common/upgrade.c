#include <common.h>
#include <command.h>

static int do_upgrade(cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[])
{

	//char cmd_buf[200];
    char *cmd[]={"setenv ipaddr 172.21.53.221;setenv serverip 172.21.53.45\n","tftpboot 0x10000000 bcm947622EAP_nand_cferom_fs_image_128_ubi.w\n","setenv calsize 0x580000;setexpr leftsize $filesize - $calsize;echo $leftsize\n","nand erase 0 0x300000;nand erase 0x580000 0x7A80000","nand write 0x10000000 0x0000 0x200000; nand write 0x10580000 0x580000 $leftsize"};
	int i;
	for (i = 0; i <= 4; i++) 
	{
	puts(cmd[i]);
	strcpy(cmd_buf,cmd[i])
	run_command(cmd_buf, 0);
	}





/*	
	char cmd_buf[200];
	printf( "setenv ipaddr 172.21.53.221;setenv serverip 172.21.53.45\n");
	strcpy(cmd_buf, "setenv ipaddr 172.21.53.221;setenv serverip 172.21.53.45");
	run_command(cmd_buf, 0);

	printf("tftpboot 0x10000000 bcm947622EAP_nand_cferom_fs_image_128_ubi.w\n");
	strcpy(cmd_buf,"tftpboot 0x10000000 bcm947622EAP_nand_cferom_fs_image_128_ubi.w"); 
	run_command(cmd_buf, 0);

	printf("setenv calsize 0x580000;setexpr leftsize $filesize - $calsize;echo $leftsize\n");
	strcpy(cmd_buf,"setenv calsize 0x580000;setexpr leftsize $filesize - $calsize;echo $leftsize"); 
	run_command(cmd_buf, 0);
	
	printf("nand erase 0 0x300000;nand erase 0x580000 0x7A80000");
	strcpy(cmd_buf,"nand erase 0 0x300000;nand erase 0x580000 0x7A80000\n"); 
	run_command(cmd_buf, 0);
	
	printf("nand write 0x10000000 0x0000 0x200000; nand write 0x10580000 0x580000 $leftsize");
	strcpy(cmd_buf,"nand write 0x10000000 0x0000 0x200000; nand write 0x10580000 0x580000 $leftsize\n"); 
	run_command(cmd_buf, 0);
*/
			return 0;
}

U_BOOT_CMD(
			sc_upgrade,	CONFIG_SYS_MAXARGS,	1,	do_upgrade,
			"upgrade the latest code ",
			"\n    - ipaddr 192.168.1.10;serverip 192.168.1.168\n"
			"upgrade code ...\n"
			"    - the latest code"
			);

