#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main()
{
int fdw;
fdw= open("abc", O_WRONLY);
write(fdw, "hello",6);
close(fdw);
return 0;
}
