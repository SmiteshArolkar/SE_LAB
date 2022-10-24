#include "stdio.h"
#include "malloc.h"

struct NODE{
    int data;
    struct NODE* next;
};

typedef struct NODE node;
struct nodes{
    node* front;
    node* rear;
};
node* push(node* rear,int data);
node* pop(node* front);
void display(node* front);
struct nodes* createQue(node* front,node* rear);

struct nodes* createQue(node* front,node* rear)
{
    int n;
    printf("Enter Number of Elements\n");
    scanf("%d",&n);
    for(int i = 0 ; i < n; i++)
    {

        int data;
        printf("Enter Data\n");
        scanf("%d",&data);
        rear = push(rear,data);
        if(i == 0)
        {
            front = rear;
        }
    }
    struct nodes *a = (struct nodes*)malloc(sizeof(struct nodes));
    a->front = front;
    a->rear = rear;
    return a;
}

node* push(node* rear,int data)
{
    node* temp = (node*)malloc(sizeof(node));
    temp->next = NULL;
    temp->data = data;
    if(rear == NULL)
    {
        rear = temp;
    }
    else{
        rear->next = temp;
        rear = rear->next;
    }
    return rear;
}
node* pop(node* front)
{
    if(front == NULL)
    {
        printf("Queue Underflow\n");
        return NULL;
    }
    else{
        node* temp = front;
        front = front->next;
        free(temp);
    }
    return front;
}
void display(node* front)
{
    node* p = front;
    while(p)
    {
        printf("%d\t",p->data);
        p = p->next;
    }
    printf("\n");
}
int main()
{
    int c;
    node* front,*rear;
    front = rear = NULL;
    do
    {
        printf("1)create\n2)push\n3)pop\n4)display\n0)exit\n");
        scanf("%d",&c);
        switch (c)
        {
        case 1:
        {
            struct nodes *a = createQue(front,rear);
            front = a->front;
            rear = a->rear; 
        }
            /* code */
            break;

        case 2:
        {
            printf("enter data to be pushed\n");
            int data;
            scanf("%d",&data);
            rear = push(rear,data);
        }
            /* code */
            break;
        case 3:
        {
            front = pop(front);
        }
            /* code */
            break;
        case 4:
        display(front);
            /* code */
            break;
        
        
        default:
            break;
        }
        /* code */
    } while (c);
    
}