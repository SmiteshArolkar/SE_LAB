#include <stdio.h>
#define input(x) scanf("%d", &x)
int binarySearch(int a[], int low, int high, int x)
{
    if (low <= high)
    {
        int mid = (low + high) / 2;
        if (a[mid] == x)
            return mid;
        if (x < a[mid])
        {
            return binarySearch(a, low, mid - 1, x);
        }
        else if (x > a[mid])
            return binarySearch(a, mid + 1, high, x);
    }
    else
        return -1;
}

int main()
{
    int a[100];
    int n;
    printf("Enter Size of Array\n");
    input(n);

    printf("Enter Array\n");
    for (int i = 0; i < n; i++)
    {
        input(a[i]);
    }
    printf("Enter Element To be Searched\n");
    int x;
    input(x);

        printf("Found at Position %d\t", binarySearch(a, 0, n-1, x));
}