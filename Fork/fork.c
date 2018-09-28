#include<stdio.h>
#include <unistd.h>

int main()
{
    pid_t id;
    printf("before fork%d\n",getpid());
    id = fork();
    if(0==id)
    printf("child process=%d\t,%d\t,%d\n",getpid(),getppid(),id);
    else
    {
      printf("parent process=%d\t,%d\t,%d\n",getpid(),getppid(),id);  
    }
    return 0;
    }

