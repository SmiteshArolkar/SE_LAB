// min max
#include "stdio.h"

int minmax(int a[], int i, int j, int *max, int *min)
{
    
    if( i > j) return -1;
    // base case
    if (i == j)
        *max = *min = a[i];
    else if (i == j - 1)
    {
        
        if (a[i] > a[j])
        {
            *max = a[i];
            *min = a[j];
        }
        else
        {
            *max = a[j];
            *min = a[i];
        }
        printf("%d %d range [ %d , %d] \n",*max,*min,i,j);
    }
    else
    {
        int mid = (i + j) / 2;
        minmax(a, i, mid, max, min);
        int *max1, *min1;                  // left tree call
        minmax(a, mid + 1, j, max1, min1); // right Sub tree call

        // combine
        if (*max1 > *max)
            *max = *max1;
        if (*min1 < *min)
            *min = *min1;
        
    }
    // divide into subproblems
}

int main()
{
    int a[] = {10, 2, 5, 4, 7, 6, 8, 8, 9};
    int *max = 0,*min = 0;
    int size = sizeof(a)/sizeof(a[0]);

    minmax(a,0,size,max,min);
    printf("%d",max);

}