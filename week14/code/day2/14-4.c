#include <stdio.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
void *thread_	function(void *arg);
int run_now=1;
void *thread_function(void *arg){
	int printf_count2 = 0;
	while(printf_count2++<5){
		if(run_now==2){
			printf("function thread is run!\n");
			run_now=1;
		}
		else{
			printf("function thread is sleep\n");
			sleep(1);
		}
	}
	pthread_exit(NULL);
}
int main()
{
	int print_count1=0;
	pthread_t a_thread;
	//创建一个进程
	if(pthread_create(&a_thread,NULL,thread_function,NULL)!=0){
		perror("Thread creation failed");
		exit(1);
	}
	while(print_count1++<5){
		if(run_now==1){
			printf("main thread is run\n");
			run_now=2;
		}
		else{
			printf("main thread is sleep\n");
			sleep(1);
		}
	}
	pthread_join(a_thread,NULL);
	exit(0);
}
