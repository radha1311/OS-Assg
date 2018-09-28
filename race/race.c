#include<stdio.h>
#include<pthread.h>
int count = 0;
void * incthread (void * arg)
{
while(1)
{
    count++;
    printf("Inc: %d\n", count);
}
}
void * decthread (void * arg)
{
   while(1)
{
    count--;
    printf("Dec: %d\n", count);
} 
}
int main()
{
    pthread_t incID, decID;
    pthread_create(&incID, NULL,incthread, NULL );
    pthread_create(&decID, NULL,decthread, NULL );
    pthread_join(incID, NULL);
    pthread_join(incID, NULL);
    return 0;
}