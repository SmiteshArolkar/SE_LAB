#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *addatend(struct node *start, int data)
{
    struct node *tmp, *p;
    tmp = (struct node *)malloc(sizeof(struct node));
    p = start;
    while (p->next != NULL)
    {
        p = p->next;
    }
    tmp->data = data;
    tmp->next = NULL;
    tmp->prev = p;
    p->next = tmp;
    return start;
}
struct node *addatbeg(struct node *start, int data)
{
    struct node *tmp = (struct node *)malloc(sizeof(struct node));
    start = NULL;
    tmp->data = data;
    tmp->next = NULL;
    tmp->prev = NULL;
    start = tmp;
    return start;
}
struct node *create(struct node *start)
{
    int n, i, data;
    printf("\nEnter the number of nodes : ");
    scanf("%d", &n);
    struct node *tmp, *p;
    printf("\nEnter the data : ");
    scanf("%d", &data);
    start = addatbeg(start, data);
    p = start;
    for (i = 2; i <= n; i++)
    {
        printf("\nEnter the data : ");
        scanf("%d", &data);
        start = addatend(start, data);
    }
    return start;
}

void Display(struct node *start)
{
    struct node *p = start;
    while (p != NULL)
    {
        printf("\n%d ", p->data);
        p = p->next;
    }
}
void Search(struct node *start)
{
    struct node *p;
    int data;
    printf("\nEnter the data you want to search for : ");
    scanf("%d", &data);
    p = start;
    int pos = 1;
    while (pos != 0)
    {
        if (p->data == data)
        {
            printf("%d is found at %d", data, pos);
            pos--;
        }
    }
}
void count(struct node *start)
{
    struct node *p = NULL;
    int cnt = 0;
    p = start;
    while (p != NULL)
    {
        cnt++;
        p = p->next;
    }
    printf("\nThe total number of nodes are : %d", cnt);
}
struct node *addafter(struct node *start)
{
    int data, item;
    printf("\nEnter the data after which you want to insert the node : ");
    scanf("%d", &item);
    struct node *p = start;
    while (p != NULL)
    {
        if (p->data == item)
        {
            struct node *tmp = (struct node *)malloc(sizeof(struct node));
            printf("\nEnter the data : ");
            scanf("%d", &data);
            tmp->data = data;
            tmp->next = p->next;
            tmp->prev = p;
            p->next = tmp;
        }
        p = p->next;
    }
    return start;
}
struct node *addbefore(struct node *start)
{
    int data, item;
    struct node *p = NULL;
    printf("\nEnter the data after which you want to insert the node : ");
    scanf("%d", &item);
    if (start->data == item)
    {
        struct node *tmp = (struct node *)malloc(sizeof(struct node));
        printf("\nEnter the data : ");
        scanf("%d", &data);
        tmp->data = data;
        tmp->next = start;
        tmp->prev = NULL;
        start = tmp;
        return start;
    }
    p = start;
    while (p != NULL)
    {
        if (p->next->data == item)
        {
            struct node *tmp = (struct node *)malloc(sizeof(struct node));
            printf("\nEnter the data : ");
            scanf("%d", &data);
            tmp->data = data;
            tmp->next = p->next;
            tmp->prev = p;
            p->next = tmp;
            return start;
        }
        p = p->next;
    }
}
struct node *addatpos(struct node *start, int pos, int data)
{
    struct node *p = NULL, *tmp = (struct node *)malloc(sizeof(struct node));
    if (pos == 0)
    {
        return start;
    }
    while (pos != 0)
    {
        p = p->next;
        pos--;
    }
    tmp->data = data;
    tmp->next = p->next;
    tmp->prev = p;
    return start;
}

struct node *swap(struct node *start)
{
    struct node *p1 = NULL, *p2 = NULL, *p3 = NULL;
    p1 = start;
    if (p1 == NULL)
    {
        printf("\nList is Empty");
        return start;
    }
    p2 = p1->next;
    start = p2;
    while (p2 != NULL)
    {
        p1->next = p2->next;
        if (p2->next != NULL)
            p2->next->prev = p1;
        p2->next = p1;
        p2->prev = p3;
        if (p3 != NULL)
            p3->next = p2;
        p1->prev = p2;
        p3 = p1;
        p1 = p1->next;
        if(p1==NULL)
        break;
        p2=p1->next;
    }

    Display(start);
    return start;
}
int main()
{
    int choice, pos, data;
    struct node *start = NULL;
    while (1)
    {
        printf("\n1.Create");
        printf("\n2.Search");
        printf("\n3.Count");
        printf("\n4.Display");
        printf("\n5.Swap the adjacent elements");
        printf("\n6.delete");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            start = create(start);
            break;
        case 2:
            Display(start);
            break;
        case 4:
            Search(start);
            break;
        case 3:
            count(start);
            break;
        case 6:
            start = addafter(start);
            break;
        case 5:
            start = swap(start);
            break;
        case 10:
            start = addbefore(start);
            break;
        case 9:
            printf("\nEnter the position where you want to add the elements : ");
            scanf("%d", &pos);
            printf("\nEnter the element to be inserted : ");
            scanf("%d", &data);
            start = addatpos(start, pos, data);
            break;
        case 0:
            exit(1);
        }
    }
    return 0;
}
