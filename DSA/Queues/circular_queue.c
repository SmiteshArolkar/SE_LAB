#include <stdio.h>
#define MAX 4
int queue[MAX];
int front = 0;
int rear = -1;

int isEmpty(){
  if(front == -1)
  return 1;
  return 0;
}

int isFull(){
  if((rear == MAX - 1 && front == 0) || front == -1)
  return 1;
  return 0;
}


void push(int item){
  if(isFull()){
    printf(" Overflow\n");
    return;
  }
  else {
    if(isEmpty())
    {
      front = rear = 0;
      queue[rear] = item;
    }
    else if(rear == MAX-1)
    {
      rear = 0;
      queue[rear] = item;
    }
    else
    queue[++rear] = item;
  }
}

void pop(){
  if(isEmpty()){
    printf("UnderFlow\n");
    return;
  }
  else {
    front++;
    if(front == MAX)
    {
      front = 0;
    }
  }
}

void peek(){
  if(isEmpty()) printf("UnderFlow\n");
  else printf("Item At Front[%d] = %d\n",front+1,queue[front]);
}

void display()
{
  if(isEmpty()) printf("UnderFlow\n");
  else
  {
    printf("Queue Contents : \n");
    int i;
    if(front > rear)
    {
      for(i = rear ; i < front ; i++)
      {
        printf("%d\t",queue[i]);
      }
    }
    
    for( i = front ; i <= rear ; i++)
    printf("%d\t",queue[i]);
    printf("\n");

  }
}



int main()
{
  int c;
  do {
    printf("1)Push\n2)Pop\n3)Peek\n4)display\n0)Exit\n");
    scanf("%d",&c);
    switch (c) {
      case 1 :
              printf("Enter Item\n");
              int item;
              scanf("%d",&item);
              push(item);
              break;
      case 2 :
              pop();
              break;
      case 3 :
              peek();
              break;
      case 4 :
              display();
              break;
      default : printf("Wrong Input\n");
                break;
    }
  } while(c);
}
