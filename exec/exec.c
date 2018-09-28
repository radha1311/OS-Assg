 #include<stdio.h>
  #include <unistd.h>
int main()
{
    execl("/bin/dict","-I",NULL,NULL);
    return 0;
}
