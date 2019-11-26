#include "my.h"

void showMenu()
{
	printf("this is menu\n");
	printf("*********************************\n");
	printf("1.创建新文件\n");
	printf("2.写文件\n");
	printf("3.读文件\n");
	printf("4.修改文件权限\n");
	printf("5.查看当前文件的权限\n");
	printf("6.修改文件权限\n");
	printf("*********************************\n");
}
void createFile()
{
	FILE *fpWrite = fopen("data.txt","w");
	
}
