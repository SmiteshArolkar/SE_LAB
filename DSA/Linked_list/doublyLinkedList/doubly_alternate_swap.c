#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
struct NODE
{
    int info;
    struct NODE *next;
    struct NODE *prev;
};
typedef struct NODE node;
node *createlist(node *, int);
node *addbegin(node *, int);
node *add_end(node *, int);
node *sum(node *, node *, node *);
void display(node *);
node *createlist(node *start, int n)
{
    int data;
    data = n % 10;
    start = addbegin(start, data);
    n = n / 10;
    while (n > 0)
    {
        data = n % 10;
        start = add_end(start, data);
        n = n / 10;
    }
    return start;
}
node *addbegin(node *start, int data)
{
    node *temp;
    temp = (node *)malloc(sizeof(node));
    temp->info = data;
    if (start == NULL)
    {
        temp->next = NULL;
        temp->prev = NULL;
        start = temp;
        return start;
    }
    else
    {
        temp->next = start;
        temp->prev = NULL;
        start->prev = temp;
        start = temp;
        return start;
    }
}
node *add_end(node *start, int data)
{
    node *temp = start, *p;
    p = (node *)malloc(sizeof(node));
    p->info = data;
    if (start == NULL)
    {
        start = p;
        p->prev = NULL;
        p->next = NULL;
    }
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = p;
    p->next = NULL;
    p->prev = temp;
    return start;
}
void display(node *start)
{
    node *temp = start;
    while (temp->next != NULL)
        temp = temp->next;
    do
    {
        printf("%d", temp->info);
        temp = temp->prev;
    } while (temp != NULL);
}
node *sum(node *temp1, node *temp2, node *startadd)
{
    int carry = 0;
    startadd = addbegin(startadd, ((temp1->info + temp2->info) % 10) + carry);
    carry = (temp1->info + temp2->info) / 10;
    temp1 = temp1->next;
    temp2 = temp2->next;
    while (temp1 != NULL || temp2 != NULL)
    {
        if (temp1 != NULL && temp2 != NULL)
        {
            startadd = add_end(startadd, (((temp1->info + temp2->info) % 10) + carry));
            carry = (temp1->info + temp2->info) / 10;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else if (temp1 == NULL)
        {
            while (temp2 != NULL)
            {
                startadd = add_end(startadd, temp2->info + carry);
                carry = 0;
                temp2 = temp2->next;
            }
        }
        else
        {
            while (temp1 != NULL)
            {
                startadd = add_end(startadd, temp1->info + carry);
                carry = 0;
                temp1 = temp1->next;
            }
        }
    }
    if (carry)
        startadd = add_end(startadd, carry);
    return startadd;
}
int main()
{
    node *start1, *start2, *startadd;
    start1 = start2 = startadd = NULL;
    int n1, n2;
    pritf("Enter Number of Elements in list\n");
    int n;
    scanf("%d",&n);
    for(int i = 0 ; i < n ; i++)
    {
        printf("Enter data\n");
        int data;
        scanf("%d",&data);
        start1->next = createlist(start1,data);
    }

}
/*
OP : 
/tmp/X3O3lvQdUP.o
enter the first number : 4
enter the second number : 5
the first list is : 4
the second list is : 5
the sum is : 9
*/