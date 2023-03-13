#include "stdio.h"

void MinMax(int a[],int i,int j,int *max,int *min)
{
    int min1 = 0 , max1 = 0;
    if(i == j)
    {
        *max = a[i];
        *min = a[i];
        printf("max : %d min : %d\n",*max,*min);
        return;
    }
    else if(i == j-1)
    {
        if(a[i] > a[j]){
            *max = a[i];
            *min = a[j];
        }
        else{
            *max = a[j];
            *min = a[i];
        }
        printf("max : %d min : %d\n",*max,*min);
        return;
    }
    else{
        int mid = (i+j)/2;
        MinMax(a,i,mid,max,min);
        MinMax(a,mid+1,j,&max1,&min1);

        if(min1 < *min) *min = min1;
        if(max1 > *max) *max = max1;
        printf("max : %d min : %d\n",*max,*min);
        return;
    }
    
}

int main()
{
    int a[100];
    int size;

    scanf("%d",&size);
    for(int i = 0 ; i <  size ; i++)
    {
        scanf("%d",&a[i]);
    }

    int max = 0 , min = 0;
    MinMax(a,0,size-1,&max,&min);
    printf(" Final max : %d min : %d\n",max,min);
}