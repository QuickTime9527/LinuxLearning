#include <stdio.h>


#define CLEAR_BUF \
    {\
    int ch; \
while ((ch = getchar()) != EOF && ch != '\n')\
        {\
        ; \
        }\
    }


void run();  //程序运行
void showMenu();    //显示菜单
void createFile();  //创建文件

void writeFile(); //写文件
