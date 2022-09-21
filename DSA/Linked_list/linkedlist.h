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

struct node* delete_at(struct node* start,int position)
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

struct node* set_Union(struct node* set1,struct node* set2, struct node* set3)
{
    //sets of same lenght
    struct node* p1 = set1;
    struct node* p2 = set2;
    struct node* p3 = set1;
    while (p3->next)
    {
        p3 = p3->next;
    }
    

    for(struct node* p = set2; p!= NULL ; p=p->next)
    {
        
    }
    
}