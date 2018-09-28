#include<stdio.>
#include<string.h>

int main()
{
    FILE *fd;
    char w[30],wrd[30];
    int len,k,i,j=0,count=0;
    fd=fopen("/home/batch2/dac/osassg/dict","r");
    printf("Enter the word to be searched:\n");
    scanf("%s",wrd);
    len=strlen(wrd);
    for(i=1;i<99171;i++){
    while((w[j]=fgetc(fd))!='\n'){
        j++;
    }
    for(k=0;k<j;k++){
    if(w[k]==wrd[k])
    count++;
    }
    if(count==len && count==k){
        printf("match fount at line:%d\n",i)
        return 1;
    }
    j=0;
    count=0;
    }
    printf("match not found\n");
	return 0;
}
