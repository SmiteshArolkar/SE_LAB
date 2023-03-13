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
int kSmallest(char a[],int low,int high,int k){
    int pi = partition(a,low,high);
        if(pi == k)
        {
            printf("%c is the %dnd smallest element\n",a[pi],k+1);
            return a[pi];
        }
        else if(k < pi)
        {
            return kSmallest(a,low,pi-1,k);
        }
        else return kSmallest(a,pi+1,high,k);
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
    printf("Enter the Value of k\n");
    scanf("%d",&k);
    k == 0 ? k = 0 : k--;
    kSmallest(a,low,high,k);

}