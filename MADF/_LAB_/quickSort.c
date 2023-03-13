#include <stdio.h>

#define forn(a,n) for (int i = 0; i < n; i++){printf("%d\t",a[i]);}


void swap(int *a,int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int a[],int low,int high)
{
    int pivot = a[high];
    int infinity_index = low-1;
    for(int j = low ; j < high ; j++){
        if(a[j] < pivot)
        {
            infinity_index++;
            swap(&a[infinity_index],&a[j]);
        }

    }
    swap(&a[infinity_index+1],&a[high]);
    return infinity_index+1;
}



void quickSort(int a[],int low,int high){
    //base Case
    if(low < high)
    {
        int pi = partition(a,low,high);

        quickSort(a,low,pi-1);
        quickSort(a,pi+1,high);


    }
    printf("\n");
    for(int i = low ; i < high + 1 ;i++)
    {
        printf("%d\t",a[i]);
    }


}


int main()
{
    int a[100];
    int n;
    scanf("%d",&n);
    for(int i = 0 ; i < n ;i++)
    {
        scanf("%d",&a[i]);
    }

    quickSort(a,0,n-1);
    printf("\nLast : \n");
    for(int i = 0 ; i < n ;i++)
    {
        printf("%d\t",a[i]);
    }

    printf("\n");

}

/* Alternate Partition do while method


int partition(int a[],int low,int high){
    int i = low+1 , j = high , piviot = a[low];

    do{
        do{
            i++;
        }while(a[i] < a[piviot] i<=j);//finds the element greater than piviot
        do{
            j--;
        }while(a[j] >= a[piviot]  && j>= i ) //finds the elements less than piviot
        if(i < j) swap(a,i,j);
    }while(i < j);
    //sawp piviot with j
    a[low] = a[j];
    a[j] = piviot;
    return j;
}
*/
#include <stdio.h>

void swap(char *a,char *b){
    char t = *a;
    *a = *b;
    *b = t;
}

int partition(char a[],int low,int high)
{
    int pivot = a[high];
    int infinity_index = low-1;
    for(int j = low ; j < high ; j++){
        if(a[j] < pivot)
        {
            infinity_index++;
            swap(&a[infinity_index],&a[j]);
        }

    }
    swap(&a[infinity_index+1],&a[high]);
    return infinity_index+1;
}

int main()
{
    char a[100];
    int low = 0 , high = 6;
    int k = 2;
    k--;
    printf("Enter size of Array\n");
    scanf("%d",&high);
    for(int i = 0 ; i < high ; i++)
    {
        scanf(" %c",&a[i]);
    }
    high == 0? high = 0 : high--;
    // user input 
    fflush(stdin);
    printf("Enter the Value of k\n");
    scanf("%d",&k);
    k == 0 ? k = 0 : k--;
    while(1)
    {
        int pi = partition(a,low,high);
        if(pi == k)
        {
            printf("%c is the %cnd smallest element\n",a[pi],k+1);
            break;
        }
        else if(k < pi)
        {
            high = pi - 1;
        }
        else low = pi+1;
    }
}