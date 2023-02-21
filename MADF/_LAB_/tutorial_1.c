// Binary Search
#include "stdio.h"

int time_1 = 0;
int time_2 = 0;

int Iterative(int arr[], int low, int high, int x)
{
    while (low <= high)
    {
        time_1++; // while loop
        int mid = (low + high) / 2;
        time_1++; // for mid statement
        if (arr[mid] < x)
        {
            low = mid + 1;
            time_1 += 2;
        }
        else if (arr[mid] > x)
        {
            high = mid - 1;
            time_1 += 3;
        }
        else
        {
            time_1 += 3;
            return mid;
        }
    }
    time_1++; // while loop
    time_1++; // return statement
    return -1;
}

int Recursive(int arr[], int low, int high, int x)
{
    time_2++; // recursive call
    time_2++; // if condition
    if (low <= high)
    {
        int mid = (low + high) / 2;
        time_2++; // mid
        time_2++;
        if (x > arr[mid])
        {
            time_2++;
            Recursive(arr, mid + 1, high, x);
        }
        else if (x < arr[mid])
        {
            time_2 += 2;
            Recursive(arr, low, mid - 1, x);
        }
        else
        {
            time_2 += 3;
            return mid;
        }
    }
    else
    {
        time_2 += 2;
        return -1;
    }
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80};
    printf("Array:");
    for (int i = 0; i < 8; i++)
        printf("%d",arr[i]);
    printf("\n");

    int noToSearch = 80, high = sizeof(arr) / sizeof(arr[0]);
    int x = Iterative(arr, 0, high, noToSearch);
    int y = Recursive(arr, 0, high, noToSearch);

    printf("Iterative\n");
    if (x != -1)
        printf("%d is present at %d\n", noToSearch, x + 1);
    else
        printf("%d is not present \n", noToSearch);
    printf("Iterative Step Count : %d\n", time_1);

    printf("Recursive\n");
    if (y != -1)
        printf("%d is present at %d\n", noToSearch, y + 1);
    else
        printf("%d is not present \n", noToSearch);
    printf("Recursive Step Count : %d \n", time_2);

    return 0;
}