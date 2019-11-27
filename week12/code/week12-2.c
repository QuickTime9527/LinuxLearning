#include "my.h"

int main()
{
	pid_t p;
	int fd[2],rn,wn,i;
	char rbuf[1],wbuf[30];
	memset(rbuf,0,sizeof(rbuf));
	memset(wbuf,0,sizeof(wbuf));
	pipe(fd);
	p = fork();
	if(p<0)
	{
		perror("fork failed!\n");
		return -1;
	}
	else if(p==0)
	{
		close(fd[0]);
		sprintf(rbuf,"[child %d] is running!\n",getpid());
		for(i=0;i<65536;i++)
		{
			write(fd[1],wbuf,sizeof(wbuf));
		}
		close(fd[1]);
		exit(0);
	}
	else{
		wait(NULL);
		close(fd[1]);

		while(1)
		{
			rn = read(fd[0],rbuf,sizeof(rbuf));
			printf("[parent] read from pipe %d byte.Conten of pipe is %s\n",rn,rbuf);
			if(rn==0)
			{
				printf("[parent] write error.\n");
				break;
			}
		}
		close(fd[0]);
		return 0;
	}
}
