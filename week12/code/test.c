#include <stdio.h>
#include <unistd.h>
#include <strings.h>
#include <string.h>
#include <stdlib.h>



int main()
{
    char* str = "i am parent";
    char buf[4];
    bzero(buf, sizeof(buf));
    pid_t pid;
    int fd[2];

    pipe(fd);

    pid = fork();
    if(0 == pid)//child read
    {
        sleep(1);//等待父进程向管道写入数据
        printf("i am child, read to read\n");
        close(fd[1]);

        while(read(fd[0], buf, sizeof(buf)-1) > 0)
        {
            //printf("len=%d, %s\n", strlen(buf), buf);
            write(STDOUT_FILENO, buf, strlen(buf));
            bzero(buf, sizeof(buf));
        }

        write(STDOUT_FILENO, "\n", 1);
        close(fd[0]);
        
        exit(0);
        

    }
    else//parent write
    {
        printf("i am parent, read to read\n");
        close(fd[0]);
        
        write(fd[1], str, strlen(str));

        close(fd[1]);

        wait(NULL);//

        exit(0);

    }
    
}
