#include "stdio"
#define size 5

int c_queue[size];
int front = -1, rear = -1;

void enQueue_g(int data);
int deQueue_g();
int isFull_g();
int isEmpty_g();

void enQueue_l(int *c, int front, int rear);
int deQueue_l(int *c, int front, int rear);
int isFull_l(int front, int rear);
int isEmpty_l(int front, int rear);

void display_g();
void display_l();

int main()
{
}

void enQueue_g(int data)
{
    if (isFull_g())
    {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1)
        front = 0;
    rear = (rear + 1) % size;
    c_queue[rear] = data;
    printf("Element Inserted -> %d", c_queue[rear]);
}

int deQueue_g()
{
    if (isEmpty_g())
    {
        printf("Queue Empty\n");
        return -1;
    }
    else
    {
        int temp = c_queue[front];
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % size;
        }
        return temp;
    }
}

int isFull_g()
{
    if ((front == 0 && rear == size - 1) || (front == rear + 1)) return 1;
    return 0;
}

int isEmpty_g()
{
    if(front == -1) return 1;
    return 0;
}
