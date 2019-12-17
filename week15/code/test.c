#include "my.h"
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
static pthread_rwlock_t rwlock;

int g=0;
void *fun(void *param)
{
	int i;
	pthread_rwlock_rdlock(&rwlock);  //readlock
	for(i=0;i<LOOP;i++)
	{
		//pthread_mutex_lock(&mutex);
		g++;
		//pthread_mutex_unlock(&mutex);
	}
	pthread_rwlock_unlock(&rwlock); // unlock
	return NULL;
}


int main()
{
	pthread_t tid[NUM];
	int ret,i;
	for(i=0;i<NUM;i++)
	{
		ret = pthread_create(&tid[i],NULL,fun,NULL);	
		if(ret!=0)  //create thread failed
		{
			printf("create thread fail!\n");
		}
	}
	for(i=0;i<NUM;i++)
		pthread_join(tid[i],NULL);
	
	printf("thread NUM = %d\n",NUM);
	printf("LOOP NUM = %d\n",LOOP);
	printf("expert result = %d\n",LOOP*NUM);
	printf("real result = %d\n",g);
	


	
}
