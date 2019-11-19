#include "my.h"
int g=10;

int main()
{
	int l=20;
	static int s=30;
	pid_t pid;
	pid = fork();
	if(pid < 0)
	{
		perror("failed to fork!\n");
		return -1;
	}
	else if(pid==1)
	{
		int p = 99;
		printf("-------address of var-------\n");
		printf("%g=%16p\n&l=%16p\n&s=%16p\n",&g,&l,&s);
		
	}
}
