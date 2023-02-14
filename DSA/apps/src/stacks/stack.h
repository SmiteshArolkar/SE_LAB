#include "malloc.h"
#include "stdio.h"

struct stack{
    int data;
    struct stack* next;
};

typedef struct stack Stack;

Stack* newNode(int data)
{
    Stack* temp = (Stack*)malloc(sizeof(Stack));
    temp->next = NULL;
    temp->data = data;
    return temp;
}

Stack* push(int data,Stack* top)
{
    if(top == NULL)
    {
        return newNode(data);
    }
    else
    {
        Stack* temp = newNode(data);
        temp->next = top;
        return temp;
    }
}

Stack* pop(Stack* top)
{
    if(top)
    {
        Stack* temp = top;
        top = top->next;
        free(temp);
        return top;
    }
    return NULL;
}

int peek(Stack* top)
{
    return top->data;
}

void displayStack(Stack* top)
{
    while(top)
    {
        printf("%d\t",peek(top));
        top = top->next;
    }
    printf("\n");
}