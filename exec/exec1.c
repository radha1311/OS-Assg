#include<stdio.h>
#include <unistd.h>
#include<stdlib.h>

char *cmd;
char *args[];
int main()
{
    pid_t id;
    printf("before\n");
    id =fork();
    if(id==0){
        printf("child\n");
        execl("cmd/ls","cmd/ls","-a", "-l",NULL);
    }
    else
    {
        printf("parent\n");
    }
    return 0;
}