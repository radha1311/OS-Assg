#define _GNU_SOURCE
#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

pthread_barrier_t initBar;
 void *netThread (void *arg)
 {
     printf("net started init.....\n");
     sleep(2);
     printf("net finished init ......\n");
     pthread_barrier_wait(&initBar);
     printf("net started execution......\n");

 }

 void *guiThread(void *arg)
 {
     printf("gui started init.....\n");
     sleep(4);
     printf("gui finished init......\n");
     pthread_barrier_wait(&initBar);
     printf("gui started execution.......\n");

 }

 void *fsThread(void *arg)
 {
     printf("file started init......\n");
     sleep(2);
     printf("file finished init.......\n");
     pthread_barrier_wait(&initBar);
     printf("file started execution.......\n");

 }

 int main(){
     pthread_t netId,guiId,fsId;
     pthread_barrier_init(&initBar, NULL, 3);
     

     pthread_create(&netId, NULL, netThread, NULL);
     pthread_create(&guiId, NULL, guiThread, NULL);
     pthread_create(&fsId, NULL, fsThread, NULL);

     pthread_join(netId, NULL);
     pthread_join(guiId, NULL);
     pthread_join(fsId, NULL);

     pthread_barrier_destroy(&initBar);

     return 0;

 }