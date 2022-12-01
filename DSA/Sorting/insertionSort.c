#include "stdio.h"

int insertion_sort(int a[],int size)
{
    int i,j,temp;
    for(i = 1 ; i < size ; i++)
    {
        temp = a[i];

        j = i-1;

        while( j >= 0 && a[j] > temp)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = temp;
    }   
}
int main()
{
    int arr[] = {2,3,4,7,6,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    insertion_sort(arr,n);
    for(int i = 0 ; i < n;i++)
    {
        printf("%d\t",arr[i]);
    }
}