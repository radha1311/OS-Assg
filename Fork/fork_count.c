#include<stdio.h>
#include <unistd.h>
int count=0;
   
int main()
{
    pid_t id;
    printf("before fork%d\n",getpid());
    id = fork();
    if(0==id)
    {
    printf("child process=%d\t,%d\t,%d\n",getpid(),getppid(),id);
    printf("child count%d \n",count);
    }
    
    else
    {
    printf("parent process=%d\t,%d\t,%d\n",getpid(),getppid(),id); 
    count++;
    printf("parent count%d \n",count); 
    }
    return 0;
    }
