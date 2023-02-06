/*

1. single linked list 11 functions
    create,search,count,delete,display,add at beg,end,before,after,rev,position
*/

#include "stdio.h"
#include "malloc.h"

struct LL
{
    int data;
    struct LL *next;
};
typedef struct LL ll;

ll *createLL(int size);
ll *searchLL(ll *start, int data);
int count(ll *start);
ll *delete_beg(ll *start);
ll *delete_end(ll *start);
ll *delete_position(ll *start, int position);
ll *delete_before(ll *start, int Node_data);
ll *delete_after(ll *start, int Node_data);
ll *reverseLL(ll *start);
ll *add_beg(ll *start, int data);
ll *add_end(ll *start, int data);
ll *add_before(ll *start, int Node_data);
ll *add_after(ll *start, int Node_data);
ll *add_position(ll *start, int position);

void displayLL(ll *start);

#include "stdio.h"
int main()
{
    ll *start = createLL(3);
    displayLL(start);
    // ll* ptr = searchLL(start,3); working
    // printf("Count = %d\t",count(start)); working
    // start = delete_beg(start); //working
    // start = delete_end(start); //woring
    // start = delete_position(start,3); working
    // start = delete_before(start,3); woring
    // start = delete_after(start,3); working
    // start = reverseLL(start); working
    displayLL(start);
}

ll *createLL(int size)
{
    ll *start = NULL, *ptr = NULL;
    for (int i = 0; i < size; i++)
    {
        ll *temp = (ll *)malloc(sizeof(ll));
        printf("Enter Node Data\n");
        scanf("%d", &temp->data);
        temp->next = NULL;
        if (start == NULL)
        {
            start = ptr = temp;
        }
        else
        {
            ptr->next = temp;
            ptr = temp;
        }
    }
    return start;
}

ll *searchLL(ll *start, int data)
{
    ll *ptr = start;
    for (ptr = start; ptr->data != data && ptr; ptr = ptr->next)
    {
    }
    return ptr;
}

int count(ll *start)
{
    int c = 0;
    while(start)
    {
        c++;
        start = start->next;
    }
    return c;
}

ll *delete_beg(ll *start)
{
    ll* ptr = start;
    start =  start->next;
    free(ptr);
    return start;
}

ll *delete_end(ll *start)
{
    ll* ptr = start,*q = ptr;
    while(ptr->next)
    {
        q = ptr;
        ptr = ptr->next;
    }
    q->next = NULL;
    return start;
}

ll *delete_position(ll *start, int position)
{
    ll* ptr = start, *q = ptr;
    if(position == 1) return delete_beg(start);
    for(int i = 0 ; i < position-1 ; i++)
    {
        q = ptr;
        ptr = ptr->next;
    }
    q->next = ptr->next;
    free(ptr);
    return start;
}

ll *delete_before(ll *start, int Node_data)
{
    ll* ptr = start,*q = ptr, * p = q;
    for(ptr = start; ptr->data != Node_data ; p = q ,q = ptr , ptr = ptr->next){}
    if(p == q && ptr != q) return delete_beg(start);
    else if(ptr != q){
        p->next = ptr;
        free(q);
    }
    return start;
}

ll *delete_after(ll *start, int Node_data)
{
    ll* ptr = start;
    for(ptr = start; ptr->data != Node_data ; ptr = ptr->next){}
    ll* q = ptr->next;
    ptr->next = ptr->next->next;
    free(q);
    return start;
}

ll *reverseLL(ll *start)
{
    ll* ptr = start,*q = NULL ,*p = ptr->next;
    while(ptr && ptr->next)
    {
        p = ptr->next;
        ptr->next = q;
        q = ptr;
        ptr = p;
    }
    ptr->next = q;
    return ptr;

}

void displayLL(ll *start)
{
    ll *ptr = start;
    while (ptr)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
        /* code */
    }
    printf("\n");
}