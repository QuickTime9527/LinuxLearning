#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
static void __attribute__((constructor)) before_main()
{
	printf("Before Test1 Main:");
}
static void callback1(void)
{
	printf("callback1 is running\n");
}
static void callback2(void)
{
        printf("callback1 is running\n");
}
static void callback3(void)
{
        printf("callback1 is running\n");
}
int main(int argc,char *argv[])
{
	int i;
	atexit(callback1);
	atexit(callback2);
	atexit(callback3);
	printf("test1:pid=%d,ppid=%d\n",getpid(),getppid());
	for(i=0;i<argc;i++)
	  printf("test1: %d : %s \n",i,argv[i]);
	printf("test2 Main function finished!\n");
	
	return 0;
}
