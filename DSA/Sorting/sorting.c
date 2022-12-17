#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void Bubble(int A[], int n)
{
    int i, j, flag = 0;

    for (i = 0; i < n - 1; i++)
    {
        flag = 0;
        for (j = 0; j < n - i - 1; j++)
        {
            if (A[j] > A[j + 1])
            {
                swap(&A[j], &A[j + 1]);
                flag = 1;
            }
        }
        if (flag == 0)
            break;
    }
}
int BinarySearch(int arr[], int key)
{
    int l, mid, h;
    l = 0;
    h = 9;
    while (l <= h)
    {
        mid = (l + h) / 2;
        if (key == arr[mid])
            return mid;
        else if (key < arr[mid])
            h = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}
void Insertion(int A[], int n)
{
    int i, j, x;

    for (i = 1; i < n; i++)
    {
        j = i - 1;
        x = A[i];
        while (j > -1 && A[j] > x)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = x;
    }
}
void SelectionSort(int A[], int n)
{
    int i, j, k;

    for (i = 0; i < n - 1; i++)
    {
        for (j = k = i; j < n; j++)
        {
            if (A[j] < A[k])
                k = j;
        }
        swap(&A[i], &A[k]);
    }
}
void Merge(int A[], int l, int mid, int h)
{
    int i = l, j = mid + 1, k = l;
    int B[100];

    while (i <= mid && j <= h)
    {
        if (A[i] < A[j])
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    }
    for (; i <= mid; i++)
        B[k++] = A[i];
    for (; j <= h; j++)
        B[k++] = A[j];

    for (i = l; i <= h; i++)
        A[i] = B[i];
}
void MergeSort(int A[], int l, int h)
{
    int mid;
    if (l < h)
    {
        mid = (l + h) / 2;
        MergeSort(A, l, mid);
        MergeSort(A, mid + 1, h);
        Merge(A, l, mid, h);
    }
}
int main()
{
    int A[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3}, n = 10, i;

    printf("ARRAY IS: \n");
    for (i = 0; i < 10; i++)
        printf("%d ", A[i]);
    printf("\n");

    int a = 0;
    while (a != 7)
    {

        printf("MENU\n1.LINEAR SEARCH.\n2.BINARY SEARCH.\n3.BUBBLE SORT.\n4.INSERTION SORT.\n5.SELECTION SORT.\n6.MERFGE SORT.\n7.EXIT.\n");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
        {
            int c;
            printf("ENTER ELEMENT TO BE SEARCHED: ");
            scanf("%d", &c);
            for (i = 0; i < 10; i++)
                if (c == A[i])
                    printf("ELEMENT FOUND AT POSITION %d!\n", i + 1);
        }
            break;
        case 2:
        {
            int d;
            printf("ENTER ELEMENT TO BE SEARCHED: ");
            scanf("%d", &d);
            printf("ELEMENT FOUND AT POSITION %d \n", BinarySearch(A, d) + 1);
        }
            break;
        case 3:
            Bubble(A, n);
            for (i = 0; i < 10; i++)
                printf("%d ", A[i]);
            printf("\n");
            break;
        case 4:
            Insertion(A, n);
            for (i = 0; i < 10; i++)
                printf("%d ", A[i]);
            printf("\n");
            break;
        case 5:
            SelectionSort(A, n);
            for (i = 0; i < 10; i++)
                printf("%d ", A[i]);
            printf("\n");
            break;
        case 6:
            MergeSort(A, 0, 9);
            for (i = 0; i < 10; i++)
                printf("%d ", A[i]);
            printf("\n");
            break;
        default:
            printf("----------------\n");
        }
    }
    return 0;
}