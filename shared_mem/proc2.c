#include <sys/mman.h>
#include <sys/stat.h>       
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
int fd;
int *count;
int main()
{
fd= shm_open("/dacsm", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
ftruncate(fd, sizeof(int));
count= (int*)mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
printf("count value: %d\n", *count);
return 0;

}