#include <stdio.h>
void Merge_Char(char a[],int low,int mid,int high)
{
    int i = low , j = mid+1 , k = low;
    int b[100];
    while(i <= mid && j <= high)
    {
         if(a[i] <= a[j]){
            b[k++] = a[i++];
         }
         else b[k++] = a[j++];
    }

   if(i > mid){
    for(int m = j ; m <= high ; m++){
        b[k++] = a[m]; 
    }
   }
   else {

    for(int m = i ; m <= mid ; m++){
        b[k++] = a[m];
    }
   }

    for(int m = low ; m <= high ; m++)
    {
        
        a[m] = b[m];
    }
}
void MergeSort_Char(char a[],int low,int high)
{
    if(low < high){
        int mid = (low + high)/2;
        MergeSort_Char(a,low,mid);
        MergeSort_Char(a,mid+1,high);
        Merge_Char(a,low,mid,high);

    }
}

int main()
{
    char a[] = {'b','c','a'};
    int size = sizeof(a) / sizeof(a[0]);

    MergeSort_Char(a,0,size-1);

    for(int i = 0 ; i < size ;i++)
    {
        printf("%c\t",a[i]);
    }



}