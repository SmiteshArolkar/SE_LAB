#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
void Display(struct node *tail);
struct node *create(struct node *tail, int data);
void split(struct node *last, int n)
{
    int i;
    struct node *l1 = NULL, *l2 = NULL, *p;
    p = last->next;
    for (i = 1; i <= n; i++)
    {
        if (i % 2 == 1)
        {
            l1 = create(l1, p->data);
        }
        else
        {
            l2 = create(l2, p->data);
        }
        p = p->next;
    }
    printf("\nThe splited list 1 is");
    Display(l1);
    printf("\nThe splited list 2 is\n");
    Display(l2);
}
struct node *tail = NULL;
struct node *addatbeg(struct node *tail, int data)
{
    struct node *tmp = (struct node *)malloc(sizeof(struct node));
    tmp->data = data;
    tmp->next = tail;
    tail = tmp;
    return tail;
}
struct node *addatend(struct node *tail, int data)
{
    struct node *tmp = (struct node *)malloc(sizeof(struct node));
    tmp->data = data;
    tmp->next = tail->next;
    tail->next = tmp;
    tail = tail->next;
    return tail;
}
struct node *create(struct node *tail, int data)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    if (tail == NULL)
    {
        temp->next = temp;
        tail = temp;
        return tail;
    }
    else
    {
        temp->next = tail->next;
        tail->next = temp;
        tail = temp;
        return tail;
    }
}

int Display(struct node *tail)
{
    struct node *p = NULL;
    int c=0;
    p = tail->next;
    do
    {
        printf("\n%d", p->data);
        c++;
        p = p->next;
    } while (p != tail->next);
    return c;
}
struct node* delalter(struct node *tail,int c)
{
    struct node *p=NULL,*tmp=NULL,*p1=NULL;
    p=tail->next;
    for(int i=0;i<c;i++){
        if(i%2==0){
            printf("\n%d",p->data);
        }else{
            tmp=p;
            
        }
    }
    c=Display(tail);
    return tail;
}
int main()
{
    int choice;
    int n, j, i,c=0;
    while (1)
    {
        printf("\n1.Create");
        printf("\n2.Display");
        printf("\n3.Delete alternate nodes");
        printf("\n4.Exit");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the number of elememts\n");
            scanf("%d", &n);
            for (i = 0; i < n; i++)
            {
                printf("Enter element to be insert\n");
                scanf("%d", &j);
                tail = create(tail, j);
            }
            break;
        case 2:
            c=Display(tail);
            break;
        case 5:
            split(tail, n);
            break;
        case 3:
            tail=delalter(tail,c);
            break;
        case 4:
            exit(1);
            break;
        }
    }
    return 0;
}
