#include<stdio.h>
#include<pthread.h>
#include <sys/types.h>
#include <unistd.h>


int count= 0;
pthread_mutex_t countMutex= PTHREAD_MUTEX_RECURSIVE_INITIALIZER_NP;
void * incThread(void *arg)
{
while (1)
{
pthread_mutex_lock(&countMutex);
pthread_mutex_lock(&countMutex);
count++;
printf("Inc: %d\n", count);
pthread_mutex_unlock(&countMutex);
pthread_mutex_unlock(&countMutex);
}
}
void * decThread(void *arg)
{
while (1)
{
pthread_mutex_lock(&countMutex);
pthread_mutex_lock(&countMutex);
count--;
printf("Dec: %d\n",count);
pthread_mutex_unlock(&countMutex);
pthread_mutex_unlock(&countMutex);
}
}
int main()
{
pthread_t inc,dec;
pthread_mutex_init(&countMutex,NULL);
pthread_create(&inc,NULL,incThread,NULL);
pthread_create(&dec,NULL,decThread,NULL);
pthread_join(&inc,NULL);
pthread_join(&dec,NULL);
pthread_mutex_destroy(&countMutex);
return 0;

}
