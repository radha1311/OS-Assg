#include<stdio.h>
int Add (int, int);
int Sub (int, int);
int main()
{
   int n1, n2;
   printf("enter two numbers\n");
   scanf("%d %d",&n1,&n2);
   printf("Addition is: %d\n",Add( n1, n2)); 
    printf("Substraction is: %d",Sub( n1, n2)); 
   return 0;
}
