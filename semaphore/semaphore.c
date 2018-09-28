#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
int a, b;
int sum;
sem_t semIP2Proc, semProc2IP;

void *inputThread (void *arg)
{
	while(1)
	{
	sem_wait(&semProc2IP);
	scanf("%d", &a);
	scanf("%d", &b);
	sem_post(&semIP2Proc);
	}
}

void *processingThread (void *arg)
{
  	while(1)
	{
	sem_wait(&semIP2Proc);
	sum= a+b;
	printf("sum=%d", sum);
	sem_post(&semProc2IP);
	}
}

int main()
{
pthread_t input_id, process_id;
sem_init(&semIP2Proc,0,0);
sem_init(&semProc2IP,0,1);
pthread_create(&input_id,NULL,inputThread,NULL);
pthread_create(&process_id,NULL,processingThread,NULL);
pthread_join(input_id,NULL);
pthread_join(process_id,NULL);
sem_destroy(&semIP2Proc);
sem_destroy(&semProc2IP);
return 0;
}
