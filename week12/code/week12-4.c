
//  week12-4.c
//  Linux
//
//  Created by 赵锡赫 on 2019/11/26.
//  Copyright © 2019 tz. All rights reserved.
//

#include "my.h"


int main()
{
    char bufs[4];
    char *str = "I am a test";
    int *nums;
    pid_t p1,p2,p3;
    int s1,s2,s3,i;
    int fd[2];
    int r_num;
    srand((unsigned)time(NULL));
    bzero(bufs, sizeof(bufs));
    pipe(fd);
    p1 = fork();
    if(p1<0)
    {
        perror("fork failed.\n");
        return -1;
    }
    else if(p1==0)   // 子进程执行
    {
	  close(fd[0]);   //关闭fd0 写入数据
        printf("[child %d] \t[parent %d]\n",getpid(),getppid());
	for(i=0;i<65535;i++)
		nums[i] = rand() % 51 + 13;
	  
	if(write(fd[1], nums, 65535))
       	 printf("parent write over\n");
        close(fd[1]);
	 wait(NULL);
        exit(9);
    }
    else{
        p2 = fork();
        if(p2<0)  
        {
            perror("fork failed.\n");
            return -1;
        }
        else if(p2==0)//第二个子进程 读出数字 ，并将数字打印 ，再次将数字写入p2 管道
        {
		sleep(1);// 等待父进程向管道写入数据
            printf("[child %d]\t[parent %d] wait to read data\n",getpid(),getppid());
		close(fd[1]);
		//读数据
		  read(fd[0],nums,65535);
		
		 write(STDOUT_FILENO, bufs, strlen(bufs));
     	       bzero(bufs, sizeof(bufs));
	
		
		
		

  		write(STDOUT_FILENO, "\n", 1);

		close(fd[0]);
            exit(19);
        }
        else{
            p3 = fork();
            if(p3<0)
            {
                perror("fork failed.\n");
                return -1;
            }
            else if(p3==0)
            {
                printf("[child %d]\t[parent %d]\n",getpid(),getppid());
                exit(99);
            }
            else{
                p1 = wait(&s1);
                p2 = wait(&s2);
                p3 = wait(&s3);
                printf("%d exit code %d\n%d exit code %d\n%d exit code %d",p1,WEXITSTATUS(s1),p2,WEXITSTATUS(s2),p3,WEXITSTATUS(s3));
                return 0;
            }
        }
    }
}

