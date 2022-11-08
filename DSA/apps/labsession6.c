#include<stdio.h>
#include<stdlib.h>
struct node
{
  struct node *prev;
  int info;
  struct node *next;
};
struct node *insatbeg(struct node *start,int data);
struct node *insatend(struct node *start,int data);
 struct node *create( struct node *start)
{
    int data,i,n;
    printf("Enter the Number of Nodes\n");
    scanf("%d",&n);
    if(n==0)
    {
        printf("The List is Empty\n");
        return start;
    }
    else
    {
       printf("Enter the element\n");
       scanf("%d",&data);
       start=insatbeg(start,data);
       for(i=2;i<=n;i++)
       {
        printf("Enter the element");
        scanf("%d",&data);
        start=insatend(start,data);
       }
       return start;
    }
}
struct node *insatbeg(struct node *start,int data)
 {
    struct node *temp;

    temp=(struct node*)malloc(sizeof(struct node));
    temp->info=data;
    temp->prev=NULL;
    temp->next=start;
    start=temp;
    return start;
 }
struct node *insatend(struct node *start,int data)
 {
    struct node *temp,*p;
    p=start;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->info=data;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=temp;
    temp->prev=p;
    temp->next=NULL;
    return start;
 }
void display(struct node *start)
 {
    struct node *p;
    if (start==NULL)
    {
        printf("List is Empty\n");

    }
    else
    {
        p=start;
        while(p!=NULL)
        {
            printf("%d\n",p->info);
            p=p->next;
        }

    }
}
int count(struct node *start)
 {  int c=0;
    struct node *p;
    if (start==NULL)
    {
        printf("List is Empty\n");

    }
    else
    {
        p=start;
        while(p!=NULL)
        {
            p=p->next;
            c++;
        }

    }
    return c;
}
void search(struct node *start,int n)
 {
     struct node *p;
     int pos=1,r=0;
     p=start;
     while(p!=NULL)
     {
        if(p->info==n)
        {
            printf("Your Element is at %d position\n",pos);
            r=1;
        }
        pos++;
        p=p->next;
     }
     if(r==0)
     printf("Element not Found\n");
 }
struct node *insafter(struct node *start,int data,int n)
 {
    struct node *p,*temp;
    p=start;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->info=data;
    while(p!=NULL)
    {
        if(p->info==n)
        {
            temp->prev=p;
            temp->next=p->next;
            if(p->next==NULL)
               p->next->prev=temp;
            p->next=temp;
            printf("The Element is Inserted\n");
            return start;
        }
        p=p->next;
    }
    printf("The Element not Found\n");
    return start;
 }
struct node *insbefore(struct node *start,int data,int n)
 {
    struct node *p,*temp;
    p=start;
    if(start==NULL)
    {
    printf("The List is empty\n");
    return start;
    }
    if(start->info==n)
    {
    temp=(struct node*)malloc(sizeof(struct node));
    temp->info=data;
    temp->prev=NULL;
    temp->next=start;
    start=temp;
    return start;
    }

    while(p->next!=NULL)
    {
        if(p->next->info==n)
        {   temp=(struct node*)malloc(sizeof(struct node));
            temp->info=data;
            temp->next=p->next;
            p->next->prev=temp;
            p->next=temp;
            temp->prev=p;
            printf("The Element is Inserted\n");
            return start;
        }
        p=p->next;
    }
    printf("The Element not Found\n");
    return start;
 }
struct node *insatpos(struct node *start, int data, int pos)
 {

     struct node *temp,*p;
     int i;
     temp=(struct node *) malloc (sizeof(struct node));
     temp->info=data;
     if(pos==1)
     {
        temp->prev=NULL;
        temp->next=start;
        start=temp;
        return start;
     }
    p=start;
    for(i=1; i<pos-1 && p!=NULL; i++)
       {
         p=p->next;
       }
    if(p==NULL)
    printf("There are less than %d elements\n",pos);
    else
    {
       temp->next=p->next;
       p->next->prev=temp;
       p->next=temp;
       temp->prev=p;
    }
    return start;
}
struct node *del(struct node *start,int data)
{
  struct node *temp;
  if(start==NULL)
   {
     printf("The List is empty\n");
     return;
   }
  if(start->next==NULL)
  {
    if(start->info==data)
    {
      temp=start;
      start=NULL;
      free(temp);
      return start;
     }
    else
   {
     printf("Element not Found\n");
      return 0;
   }
  }
    if(start->info==data)
    {
      temp=start;
      start=start->next;
      free(temp);
      return start;
    }
   temp=start->next;
   while(temp!=NULL)
  {
    if(temp->info==data)
    {
      temp->prev->next=temp->next;
      temp->next->prev=temp->prev;
      free(temp);
      return start;
    }
  }
}
struct node *reverse(struct node *start)
{ struct node *p1,*p2;
  p1=start;
  p2=p1->next;
  p1->prev=p2;
  p1->next=NULL;
  while(p2!=NULL)
{
  p2->prev=p2->next;
  p2->next=p1;
  p1=p2;
  p2=p2->prev;
}
start=p1;
return start;
}
struct node* adjacent(struct node *start)
{
  struct node *p=NULL,*p1=NULL,*p2=NULL;
  p=start;
  p1=p->next;
  start=p1;
  p2=p1->next;
  while(p1!=NULL)
  {
    p2->prev=p;
    p->next=p1->next;
    p1->next=p;
    p1->prev=p->prev;
    p->prev=p1;
    p1=p->next;
    p2=p1->next;
  }
printf("\nElements are swapped");
return start;
}
int main()
{
    int j,n,data,c;
    struct node *start;
    start=NULL;
    while (1)
    {
        printf("1] Create Linked list\n");
        printf("2] Display Linked list\n");
        printf("3] Search in  Linked list\n");
        printf("4] Count number of elements in list\n");
        printf("5] Inserion at the beging of Linked list\n");
        printf("6] Inserion at the end of Linked list\n");
        printf("7] Inserion before a element in  Linked list\n");
        printf("8] Inserion after element in Linked list\n");
        printf("9] Inserion at the position in Linked list\n");
        printf("10] Deletion at position in Linked list\n");
        printf("11] Reversing of  Linked list\n");
        printf("12] Swap adjacentg elements\n");
        printf("13] Exit\n");
        printf("Enter Your Choice\n");
        scanf("%d",&j);
        switch (j)
        {
        case 1:
            start = create(start);
            break;
        case 2:
            display(start);
            break;
        case 3:
            printf("Entetr the Element to be searched\n");
            scanf("%d",&n);
            search(start,n);
            break;
        case 4:
            c=count(start);
            printf("The No. of elements in list = %d\n",c);
            break;
        case 5:
            printf("Entetr the Element to be inserted\n");
            scanf("%d",&n);
             start=insatbeg(start,n);
            break;
        case 6:
            printf("Entetr the Element to be inserted\n");
            scanf("%d",&n);
            start=insatend(start,n);
            break;
        case 7:
            printf("Entetr the Element to be inserted\n");
            scanf("%d",&data);
            printf("Enter Element before Which Element to br Inserted\n");
            scanf("%d",&n);
            start=insbefore(start,data,n);
            break;
        case 8:
            printf("Entetr the Element to be inserted\n");
            scanf("%d",&data);
            printf("Enter Element After Which Element to br Inserted\n");
            scanf("%d",&n);
            start=insafter(start,data,n);
            break;
        case 9:
            printf("Entetr the Element to be inserted\n");
            scanf("%d",&data);
            printf("Enter the position of Element to br Inserted\n");
            scanf("%d",&n);
            start=insatpos(start,data,n);
            break;
        case 10:
            printf("Entetr the Element to be delete\n");
            scanf("%d",&data);
            start=del(start,data);
            break;
        case 11:
             start=reverse(start);
             break;
        case 12:
              start=adjacent(start);
              break;
        case 13:
            exit(0);
        default:
            break;
        }

    }

}
