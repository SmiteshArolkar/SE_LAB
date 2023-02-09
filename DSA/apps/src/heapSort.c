#include "stdio.h"

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void heapify(int a[], int size, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && a[left] > a[largest])
        largest = left;
    if (right < size && a[right] > a[largest])
        largest = right;
    if (largest != i)
    {
        swap(&a[largest],&a[i]);
        heapify(a, size, largest);
    }
}

void heapSort(int a[], int size)
{
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapify(a, size, i);
    }

    for (int i = size - 1; i >= 0; i--)
    {
        swap(&a[0], &a[i]);
        heapify(a, i, 0);
    }
}

int main()
{
     int a[] = { 12, 11, 13, 5, 6, 7 };
    int size = sizeof(a) / sizeof(a[0]);
    heapSort(a, size);
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", a[i]);
    }
}