#include <stdio.h>
#define MAX 30
int stack[MAX];
int top = -1;

int isEmpty(){
  if(top == -1)
  return 1;
  return 0;
}

int isFull(){
  if(top == MAX-1)
  return 1;
  return 0;
}


void push(int item){
  if(isFull()){
    printf("Stack Overflow\n");
    return;
  }
  else {
    top++;
    stack[top] = item;
  }
}

void pop(){
  if(isEmpty()){
    printf("Stack UnderFlow\n");
    return;
  }
  else {
    printf("Item Poped : %d\n",stack[top]);
    top--;
  }
}

void peek(){
  if(isEmpty()) printf("Stack UnderFlow\n");
  else printf("Item At Top[%d] = %d\n",top+1,stack[top]);
}

void display(){
  if(isEmpty()) printf("Stack UnderFlow\n");
  else
  {
    printf("Stack Contents : \n");
    int i;
    for( i = top ; i >= 0 ; i--) printf("%d\t",stack[i]);
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
