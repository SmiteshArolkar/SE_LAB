#include "stdio.h"
#include "malloc.h"
#include "string.h"

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
char* postfix_to_infix(node* top,char postfix[],char infix[]);

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
node* pop_data(node* top,char *data)
{
    if(top == NULL)
    {
        printf("Empty stack\n");
        return NULL;
    }
    node* temp = top;
    top = top->next;
    *data = temp->data; 
    free(temp);
    return top;
}

char* postfix_to_infix(node* top,char postfix[],char infix[])
{
    int i = 0;
    char result[4]; 
    char infix[100];
    for(int j = 0 ; j < strlen(postfix) ; j++)
    {
        char symbol = postfix[j];
        switch (symbol)
        {
        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
        case '^': 
        char data;
        top = pop_data(top,&data);
        result[0] = '(';
        result[3] = data;
        result[2] = symbol;
        top = pop_data(top,&data);
        result[1] = data;
        result[4] = ')';
        for(int m = 0 ; m < 5 ; m++)
        {
            top = push(top,result[m]);
        }
                  
        break;
        
        default: //push on stack
            top = push(top,postfix[j]);
            break;
        }

    }
    while(top!=NULL)
    {
        char data;
        top = pop_data(top,&data);
        infix[i] = data;
        i++;
    }
    return infix;
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