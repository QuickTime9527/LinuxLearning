#include"my.h"
int arg = 0;
void foo(void *v)

{
	int *pt = (int*)malloc(sizeof(int *));

	int n =(int )v;
	printf("%d:global arg = %d\n",n,arg);
	int arg;
	arg = n*100;
	printf("%d :local arg = %d\n",n,arg);
}
int main()
{
	pthread_t tid[NUM];
	int rev[NUM];
	int i=0;
	for(i = 0;i<NUM;i++)
	{
		rev[i] = pthread_create(&tid[i],NULL,(void *(*)())foo,(void*)i);
		if(rev[i]!=0)
		{
			perror("thread failed!\n");
			exit -1;
		}
		printf("master arg =%d\n",i,arg);
		pthread_join(tid[i],NULL);
	}
}
