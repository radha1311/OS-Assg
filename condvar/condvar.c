#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>
int  event = 0;
pthread_mutex_t eventMutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t eventCount;

void *threadt1(void *arg)
{
  pthread_mutex_lock(&eventMutex);
   	 while (!event)
	{
	printf("waiting before cond var\n");
	pthread_cond_wait(&eventCount, &eventMutex);
	printf("waiting after cond var\n"); 
	}
 printf("Event became true\n");   
pthread_mutex_unlock(&eventMutex);
}


void *threadt2(void *arg)
{
   pthread_mutex_lock(&eventMutex);
   event=1;
   printf("Made event true\n");
   pthread_mutex_unlock(&eventMutex);
   pthread_cond_signal(&eventCount);

    
}
int main()
{
    pthread_t tid1,tid2;
    pthread_cond_init(&eventCount, NULL);
    pthread_create(&tid1, NULL, threadt1, NULL);
    pthread_join(tid1, NULL);
    pthread_create(&tid2, NULL, threadt2, NULL);
    pthread_join(tid2, NULL);
   
    return 0;
}
