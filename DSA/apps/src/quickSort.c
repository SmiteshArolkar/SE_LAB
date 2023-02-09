#include "stdio.h"

void swap(int *p, int *q)
{
    int temp = *p;
    *p = *q;
    *q = temp;
}

int partition(int a[], int low, int high)
{
    int piviot = a[high];
    int i = (low - 1);

    for (int j = low; j < high; j++)
    {
        if (a[j] < piviot)
        {
            i++;
            swap(&a[j], &a[i]);
        }
    }

    swap(&a[i + 1], &a[high]);
    return (i + 1);
}

void quickSort(int a[],int low,int high)
{
    if(low < high)
    {
        int pi = partition(a,low,high);

        quickSort(a,low,pi-1);
        quickSort(a,pi+1,high);
    }
}

int main() 
{
    int a[] = {10,2,5,4,7,6,8,8,9};
    int size = sizeof(a)/sizeof(a[0]);
    quickSort(a,0,size-1);
    for(int i = 0 ; i < size ; i++)
    {
        printf("%d\t",a[i]);
    }
    return 0;
}