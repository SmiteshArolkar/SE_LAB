#include <stdio.h>

void Merge_desc(int a[], int low, int mid, int high)
{
    int i = low, j = mid + 1, k = low;
    int b[100];
    while (i <= mid && j <= high)
    {
        if (a[i] >= a[j])
        {
            b[k++] = a[i++];
        }
        else
            b[k++] = a[j++];
    }

    if (i > mid)
    {
        for (int m = j; m <= high; m++)
        {
            b[k++] = a[m];
        }
    }
    else
    {

        for (int m = i; m <= mid; m++)
        {
            b[k++] = a[m];
        }
    }

    for (int m = low; m <= high; m++)
    {

        a[m] = b[m];
    }
}
void MergeSort_desc(int a[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        MergeSort_desc(a, low, mid);
        MergeSort_desc(a, mid + 1, high);
        Merge_desc(a, low, mid, high);
    }
}

void Merge(int a[], int low, int mid, int high)
{
    int i = low, j = mid + 1, k = low;
    int b[100];
    while (i <= mid && j <= high)
    {
        if (a[i] <= a[j])
        {
            b[k++] = a[i++];
        }
        else
            b[k++] = a[j++];
    }

    if (i > mid)
    {
        for (int m = j; m <= high; m++)
        {
            b[k++] = a[m];
        }
    }
    else
    {

        for (int m = i; m <= mid; m++)
        {
            b[k++] = a[m];
        }
    }

    for (int m = low; m <= high; m++)
    {

        a[m] = b[m];
    }
}
void MergeSort(int a[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        MergeSort(a, low, mid);
        MergeSort(a, mid + 1, high);
        Merge(a, low, mid, high);
    }
}

void Merge_Char(char a[], int low, int mid, int high)
{
    int i = low, j = mid + 1, k = low;
    int b[100];
    while (i <= mid && j <= high)
    {
        if (a[i] <= a[j])
        {
            b[k++] = a[i++];
        }
        else
            b[k++] = a[j++];
    }

    if (i > mid)
    {
        for (int m = j; m <= high; m++)
        {
            b[k++] = a[m];
        }
    }
    else
    {

        for (int m = i; m <= mid; m++)
        {
            b[k++] = a[m];
        }
    }

    for (int m = low; m <= high; m++)
    {

        a[m] = b[m];
    }
}
void MergeSort_Char(char a[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        MergeSort_Char(a, low, mid);
        MergeSort_Char(a, mid + 1, high);
        Merge_Char(a, low, mid, high);
    }
}

int main()
{

    int a[] = {9, 8, 7, 6, 5, 4, 7};
    int size = sizeof(a) / sizeof(a[0]);
    MergeSort_desc(a, 0, size - 1);
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", a[i]);
    }
    char b[] = {'a', 'b', 'v'};
    int size_c = sizeof(a) / sizeof(a[0]);
    MergeSort_Char(b, 0, 2);
    printf("\nChar : \n");
    for (int i = 0; i < 3; i++)
    {
        printf("%c\t", b[i]);
    }
    // user input
    int d[100];
    printf("\nUser input\n");
    printf("Enter size\n");
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &d[i]);
    }
    MergeSort_desc(d, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        printf("%d\t", d[i]);
    }

    // user input
    char d_c[100];
    printf("\nUser input char\n");
    printf("Enter size\n");
    int n1;
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++)
    {
        scanf("%s", &d_c[i]);
    }
    MergeSort_Char(d_c, 0, n1 - 1);

    for (int i = 0; i < n1; i++)
    {
        printf("%c\t", d_c[i]);
    }
    printf("\n");
    return 0;
}