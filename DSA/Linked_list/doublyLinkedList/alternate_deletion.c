#include <stdio.h>
#include <malloc.h>
struct NODE
{
    int info;
    struct NODE *next;
};
typedef struct NODE node;
node *altdel(node *, int);
node *createlist(node *, int);
void display(node *);
node *createlist(node *last, int size)
{
    if (size > 0)
    {
        int data;
        node *tmp;
        printf("enter data :");
        scanf("%d", &data);
        tmp = (node *)malloc(sizeof(node));
        tmp->info = data;
        tmp->next = tmp;
        last = tmp;
        for (int i = 1; i < size; i++)
        {
            printf("enter data :");
            scanf("%d", &data);
            tmp = (node *)malloc(sizeof(node));
            tmp->info = data;
            tmp->next = last->next;
            last->next = tmp;
            last = tmp;
        }
        return last;
    }
}
void display(node *last)
{
    if (last == NULL)
    {
        printf("empty list ....\n");
        return;
    }
    node *tmp = last->next;
    do
    {
        printf("%d ", tmp->info);
        tmp = tmp->next;
    } while (tmp != last->next);
}
node *altdel(node *last, int n)
{
    if (last == NULL)
        printf("empty list :");
    if (last->next == last)
        return last;
    else
    {
        node *tmp = last->next;
        do
        {
            node *q = tmp->next;
            tmp->next = q->next;
            free(q);
            tmp = tmp->next;
        } while (tmp->next != last);
        if (n%2 == 1)
            return last;
        else
        {
            tmp->next = last->next;
            free(last);
            return tmp;
        }
    }
}
int main()
{
    int n;
    node *last = NULL;
    printf("enter the number of nodes required : ");
    scanf("%d", &n);
    last = createlist(last, n);
    printf("the original list is : ");
    display(last);
    last = altdel(last, n);
    printf("\nthe list after deletion is : ");
    display(last);
    return 0;
}

/*
OP : /tmp/X3O3lvQdUP.o
enter the number of nodes required : 4
enter data :1
enter data :2
enter data :3
enter data :4
the original list is : 1 2 3 4 
the list after deletion is : 1 3 
*/