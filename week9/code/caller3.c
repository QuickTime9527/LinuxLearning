#include "my.h"
int main()
{
	printf("caller3 pid = %d,ppid = %d\n",getpid(),getppid());
	execl("/home/zhaoxihe/GITSPACE/week9/code/test1","./test1","123","hello","world",NULL);
	printf("exec1after calling\n");
	return 0;
}
