#include <stdio.h>
int binarySearch(char a[],int low,int high,char x)
{
    if(low <= high){
        int mid = (low+high)/2;
        if(a[mid] == x) return mid;
        if(x < a[mid]){
            return binarySearch(a,low,mid-1,x);
        }
        else if(x > a[mid]) return binarySearch(a,mid+1,high,x);
    }
    else return -1;
}

int main()
{
    char a[] = {'a','b','c'};
    int size = sizeof(a) / sizeof(a[0]);

    printf("found at location %d\t",binarySearch(a,0,size,'b'));
}