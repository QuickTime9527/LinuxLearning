#include <stdio.h>

// 创建文件
void CreateFile()
{
    //文件指针
    FILE *fileP;
    char fileName[] = "hello.txt";      //保存在工程目录下

    //使用“读入”方式打开文件
    fileP = fopen(fileName, "r");

    //如果文件不存在
    if (fileP == NULL)
    {
        //使用“写入”方式创建文件
        fileP = fopen(fileName, "w");
    }
    
    //关闭文件
    fclose(fileP);
}

void main()
{
    CreateFile();

   // system("pause");
}

