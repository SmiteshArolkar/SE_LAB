#include "stdio.h"
#include "malloc.h"

struct NODE
{
    char data;
    struct NODE* next;
    /* data */
};

typedef struct NODE node;

node* createStack(node* top);
node* push(node* top,char data);
node* pop(node* top);
void display(node* top);

node*createStack(node* top)
{
    int n;
    printf("Enter Number of Elements\n");
    scanf("%d",&n);

    for(int i = 0 ; i < n ; i++)
    {
        printf("Enter Data\n");
        char data;
        fflush(stdin);
        scanf(" %c", &data);
        top = push(top,data);
    }
    return top;
}

node* push(node* top,char data)
{
    node* temp = (node*)malloc(sizeof(node));
    temp->next = top;
    top = temp;
    return top;
}

node* pop(node* top)
{
    if(top == NULL)
    {
        printf("Empty stack\n");
        return NULL;
    }
    node* temp = top;
    top = top->next;
    free(temp);
    return top;
}
void display(node* top)
{
    node* temp = top;
    while(temp)
    {
        printf(" %d",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int c;
    node* top = NULL;
    do{
        printf("1)create\n2)push\n3)pop\n4)display\n5)Postfix to infix\n0)exit\n");
        scanf("%d",&c);
        switch (c)
        {
        case 1:
        {
            top = createStack(top);
        }
            /* code */
            break;
        case 2:
        {
            printf("Enter Data to be Pushed\n");
            char data;
            scanf(" %c", &data);
            top = push(top,data);
        }
            /* code */
            break;
        case 3:
        {
            top = pop(top);
        }
            /* code */
            break;
        case 4:
        display(top);
            /* code */
            break;
        case 5:
            /* code */
            break;
        
        default:
            break;
        }
    }while(c);
}