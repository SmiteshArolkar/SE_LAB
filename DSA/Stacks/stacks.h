#include "stdio.h"
#define MAX 30
int top = -1;
char stack[MAX];

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


void push(char item){
  if(isFull()){
    printf("Stack Overflow\n");
    return;
  }
  else {
    top++;
    stack[top] = item;
  }
}

char pop(){
  if(isEmpty()){
    printf("Stack UnderFlow\n");
  }
  else {
    printf("Item Poped : %d\n",stack[top]);
    return stack[top--];
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

