//Set Operations

#include "linkedlist.h"


int main()
{
    struct node *set1=NULL,*set2=NULL;
    int n1,n2;
    printf("Number of elements in Set 1 : ");
    scanf("%d",&n1);
    for(int i = 0; i<n1 ; i++)
    {
        int data;
        printf("Set 1 element %d = ",i+1);
        scanf("%d",&data);
        set1 = add_to_set(set1,data);
    }
    printf("Number of elements in Set 2 : ");
    scanf("%d",&n2);
    for(int i = 0 ; i < n2 ; i++)
    {
        printf("Set 1 element %d = ",i+1);
        int data;
        scanf("%d",&data);
        set2 = add_to_set(set2,data);
    }
    printf("Set 1 = ");
    display_list(set1);
    printf("\nSet 2 = ");
    display_list(set2);
    
    printf("\nUnion of Set 1 and Set 2 = ");
    set_union(set1,set2);
    printf("\nIntersection of Set 1 and Set 2 = ");
    set_intersection(set1,set2);    
    
}