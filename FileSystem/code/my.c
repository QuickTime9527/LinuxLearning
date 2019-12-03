#include "my.h"

void showMenu()
{
	printf("*********************************\n");
	printf("1.创建新文件\n");
	printf("2.写文件\n");
	printf("3.读文件\n");
	printf("4.修改文件权限\n");
	printf("5.查看当前文件的权限\n");
	printf("6.修改文件权限\n");
	printf("7.退出系统\n");
	printf("*********************************\n");
}
void createFile()
{

    //保存运行次数的文件
    FILE *fileP;
    char *fileName;      //保存在工程目录下
	printf("请输入文件名：");
	scanf("%s",fileName);

    //使用“读入”方式打开文件
    fileP = fopen(fileName, "r");

    //如果文件不存在
    if (fileP == NULL)
    {
        //使用“写入”方式创建文件
        fileP = fopen(fileName, "w");
	   if(fileP!=NULL)
		printf("创建文件成功！\n");
    }else
     {
	printf("创建失败！ 文件已存在\n");
     }
    
    //关闭文件
    fclose(fileP);
}

void writeFile()
{
	FILE *fileP;
	int ch;
      char *fileName;      //保存在工程目录下
	printf("请输入文件名：");
	scanf("%s",fileName);
	fileP = fopen(fileName,"r"); //以read
	if(fileP == NULL)
	{
		printf("该文件不存在！\n");
		while((ch = getchar()) != '\n' && ch != EOF);
	}else{
		fileP = fopen(fileName,"w");
		fprintf(fileP,"yes you are right ！");
	}
}

void run()
{
	int choice;
	int signal = 0;
	showMenu();
	while(signal!=1)
 	{

		printf("请输入你的选择：");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			  createFile();
			  break;
			case 2:
			  writeFile();
			  break;
			case 3:
			  break;
			case 4:
			  break;
			case 5:
			  break;
			case 6:
			  break;
			case 7:
			  signal = 1;
			  break;
			default:
			  printf("你是不是龙鸣啊你？\n");
			  break;
		}
	}	
	printf("Bye!\n");

}






