
// Merge Sort

#include "stdio.h"

#define PrintArray(a, n)        \
    for (int i = 0; i < n; i++) \
    {                           \
        printf("%d\t", a[i]);   \
    }

#define PrintArray_Char(a, n)   \
    for (int i = 0; i < n; i++) \
    {                           \
        printf("%c\t", a[i]);   \
    }

void Merge(int a[], int low, int mid, int high)
{
    int i = low, j = mid + 1, k = low;
    int b[100];
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            b[k++] = a[i++];
        }
        else
        {
            b[k++] = a[j++];
        }
    }

    while (i <= mid)
    {
        b[k++] = a[i++];
    }

    while (j <= high)
    {
        b[k++] = a[j++];
    }

    for (int t = low; t <= high; t++)
    {
        a[t] = b[t];
    }
}

void Merge_Char(char a[], int low, int mid, int high)
{
    int i = low, j = mid + 1, k = low;
    char b[100];
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            b[k++] = a[i++];
        }
        else
        {
            b[k++] = a[j++];
        }
    }

    while (i <= mid)
    {
        b[k++] = a[i++];
    }

    while (j <= high)
    {
        b[k++] = a[j++];
    }

    for (int t = low; t <= high; t++)
    {
        a[t] = b[t];
    }
}

void mergeSort_Char(char a[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergeSort_Char(a, low, mid);
        mergeSort_Char(a, mid + 1, high);
        Merge_Char(a, low, mid, high);
    }
}

void mergeSort(int a[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        Merge(a, low, mid, high);
    }
}

int main()
{
    int a[] = {10, 2, 5, 4, 7, 6, 8, 8, 9};
    int size = sizeof(a) / sizeof(a[0]);
    mergeSort(a, 0, size - 1);
    PrintArray(a, size);
    printf("\n");
    char b[] = {'b','c','s','g','d'};
    int size_C = sizeof(b)/sizeof(b[0]);
    mergeSort_Char(b,0,size_C-1);
    PrintArray_Char(b,size_C);
}
