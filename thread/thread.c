#include<stdio.h>
 #include <sys/types.h>
#include <unistd.h>
#include <pthread.h>

void * helloThread(void *arg)
{
    printf("In hello thread\n");
    write(1,"hello\n",6);
    
}
void * byeThread(void *arg)
{
    printf("In bye thread\n");
    write(1,"bye\n",4);
    
}
int main()
{
    pthread_t tid1,tid2;
    printf("Before thread\n");
    pthread_create(&tid1,NULL,helloThread,NULL);
    pthread_join(tid1,NULL);
    pthread_create(&tid2,NULL,byeThread,NULL);
    pthread_join(tid2,NULL);
    printf("After thread");
    return 0;
}