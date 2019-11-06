#include "my.h"
int main()
{
	char *arg[]={"./test1","123","hello","world",NULL};
	printf("caller3 pid = %d,ppid = %d\n",getpid(),getppid());
	execlp("test1","./test1","123","hello","World",NULL);
//	execl("/home/GITSPACE/week9/test1",arg);
	printf("exec1after calling\n");
	return 0;
}
