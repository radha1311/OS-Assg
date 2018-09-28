#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
int fd[2];
pid_t id;
unsigned char buff[1024];
int main()
{
    
    pipe(fd);
    id=fork();
    if(0==id){
        close(fd[1]);
        read(fd[0],buff,1024);
        printf("read %s from parent%d\n",buff);
        close(fd[0]);
    }
    else{
        close(fd[0]);
        write(fd[1],"hello\n",6);
        close(fd[1]);
    }
    return 0;
}
