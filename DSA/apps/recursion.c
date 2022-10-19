#include "stdio.h"
int base_convert(int n,int base);
char tower_hanoi(char c);

int main()
{
    base_convert(5,2);
}

int base_convert(int n,int base)
{
    if(n == 0)
    {
    printf("0");
    return 0;
    }
    if(n == 1)
    {
    printf("1");
    return 0;
    }
    else 
    {
       base_convert(n/base,base);
      
    }
     printf("%d",n%base);
}