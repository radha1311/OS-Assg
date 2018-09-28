#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<errno.h>
int main()
{
    int fd,errno;
    fd=open("dac.text",O_RDONLY);
    if(-1==fd)
    {
        printf("error file not exist %d\n",errno);
        perror("program");
        printf("file created and written\n");
        fd=open("dac.text",O_RDWR |O_CREAT,S_IRUSR |S_IWUSR |S_IRGRP);
        write(fd,"hello",5);
        close(fd);
    }
    else
    {
        write(fd,"hello",5);
        close(fd);
    }
    return 0;
}