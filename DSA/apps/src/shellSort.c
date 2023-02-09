#include "stdio.h"

void shellSort(int a[], int size, int increment)
{
    int j;
    while (increment >= 1)
    {
        for (int i = increment; i < size; i++)
        {
            int k = a[i];
            for (j = i - increment; j >= 0 && a[j] > k; j = j - increment)
            {
                a[j + increment] = a[j];
            }
            a[j + increment] = k;
        }
        increment -= 2;
    }
}

int main()
{
    int a[] = {1, 3, 2, 6, 4, 9, 7, 8};
    int size = sizeof(a) / sizeof(a[0]);
    shellSort(a, size, 5);
    for (int i = 0; i < size; i++)
    {
        printf("%d\t",a[i]);
    }
}