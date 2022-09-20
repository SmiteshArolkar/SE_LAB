#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct NODE {
int coeff;
int power;
struct NODE* next;
};


typedef struct NODE node;

node* create_list(node* start)
{
    int n;
    printf("Enter Number of elements\n");
    scanf("%d",&n);
    node* p = start;
    for(int i = 0 ; i < n ; i++)
    {
        node* temp = (node*)malloc(sizeof(node));
        temp->next = NULL;
        printf("Enter data\n");
        scanf("%d",&temp->coeff);
        if(!start){
        start = temp;
        p = temp;
        }
        else {
            p->next = temp;
        }

    }
    return start;
}

void display_list(node* p)
{
    while(p){
      if(p->power)
        printf("%dx%d\t",p->coeff,p->power);
      else printf("%d\t",p->coeff);
        p  = p->next;
       }
    printf("\n");
}

node* insert_begin(node* start,node* temp){
  temp->next = start;
  start = temp;
  return start;
}
node* insert_end(node* start,int data){
        node* temp = (node*)malloc(sizeof(node));
        temp->coeff = data;
        temp->next = NULL;
        node* p = start;
        while(p->next) { p = p->next; }
        p->next = temp;
        return start;
}



/*int main()
{
int c;
node* start = NULL;
do{
  printf("1) Create\n2)Insert_Begin\n3)Insert_End\n4)Display\n0)exit\n");
  scanf("%d",&c);
  switch(c)
  {
     case 1:
  }
}while(c);

}*/
