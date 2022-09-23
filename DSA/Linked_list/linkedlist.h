#include <stdio.h>
#include "stdlib.h"

struct node
{
    int data;
    struct node *next;
    /* data */
};

struct node* createList(struct node* start)
{
    int n;
    printf("Enter Number of Terms For the list\n");
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        struct node* temp = (struct node*)malloc(sizeof(struct node));
        temp->next = NULL;
        printf("Enter Data : ");
        scanf("%d",&temp->data);
        if(!start){
            start = temp;
        }
        else {
            temp->next = start;
            start = temp;
        }
    }
    return start;
}

struct node* insert_at(struct node* start,int position,int data)
{
    struct node *p = start;
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->next = NULL;
    temp->data = data;
    //first position
    if(position == 1 || position == 0)
    {
        temp->next = start;
        start = temp;
        return start;
    }
    else 
    {
        for(int i = 1 ; i < position-1  && p!= NULL ; i++ , p = p->next){}
              temp->next = p->next;
              p->next = temp;
      
    }

    return start;

};

void display_list(struct node* p)
{
    while(p)
    {
        printf("%d\t",p->data);
        p = p->next;
    }
    printf("\n");
}

struct node* ddatate_at(struct node* start,int position)
{
    struct node* p = start;
    if(position == 0 || position == 1)
    {
        start = start->next;
        free(p);
        return start;
    }
    else
    {
        struct node* q;
        
        for(int i = 1 ; i < position && p!=NULL; i++)
        {
            q = p;
            p = p->next;
        }

        q->next = p->next;
        free(p);

    }
    return start;
}

struct node * add_to_set(struct node* start,int data)
{
    struct node* temp=malloc(sizeof(struct node)),*p;
    temp->data=data;
    temp->next=NULL;
    if(start==NULL)
    {
        start=temp;
        return start;
    }
    for(p=start;p->data!=data&&p->next!=NULL;p=p->next);
    if(p->data==data)
    return start;
    p->next=temp;
    return start;
}

void set_union(struct node *s1,struct  node *s2)
{
    struct node *u=NULL;
    for(;s1!=NULL;s1=s1->next)
    u=add_to_set(u,s1->data);
    for(;s2!=NULL;s2=s2->next)
    u=add_to_set(u,s2->data);
    display_list(u);
}

void set_intersection(struct node*s1,struct node*s2) 
{
    struct node*i=NULL,*j;
    for(;s1!=NULL;s1=s1->next){
    for(j=s2;j!=NULL&&j->data!=s1->data;j=j->next);
    if(j!=NULL)
    i=add_to_set(i,s1->data);}
    display_list(i);
}