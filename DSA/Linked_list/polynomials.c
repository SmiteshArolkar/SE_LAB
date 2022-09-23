
#include <stdio.h>
#include <stdlib.h>

struct node{
  int coeff;
  int power;
  struct node * next;
};

struct node * add_after_LL(struct node *,struct node *);
struct node * add_begin_LL(struct node *,struct node *);
struct node * add_end_LL(struct node *,struct node *);
struct node * createLL(struct node *);
struct node * add_to_LL(struct node *,struct node *);
struct node *  multiply_poly(struct node *, struct node *);
struct node * edit_poly_LL(struct node * );
void displayLL(struct node *);
struct node * deleteTerm(struct node *, int);
int main(){
  struct node * polynomial1 = NULL, * polynomial2 = NULL, * p3 = NULL, *p4 = NULL;  
  int c,flag = 0,e;
  do{
    printf("1: accept 2 polynomials\n2: add the 2 polynomials\n3:  multiply_poly the 2 polynomials\n4: modify either of two polynomials\n5: display both polynomials\n");
    printf("0: exit the polynomial\n ");
    scanf("%d",&c);
    switch(c){ 
      case 1: 
        printf("Enter polynomial p1 :\n");
        polynomial1 = createLL(polynomial1);
        printf("Enter polynomial p2 :\n");
        polynomial2 = createLL(polynomial2);
        flag = 1;
        break;
      case 2: 
        if (flag == 0){
          printf("Polynomials have to be accepted\n");
          polynomial1 = createLL(polynomial1);
          polynomial2 = createLL(polynomial2);
          flag = 1;
        }
        p3 = add_to_LL(polynomial1, polynomial2);
        displayLL(p3);
        break;
      case 3: 
        if (flag == 0){
          printf("Polynomials have to be accepted\n");
          polynomial1 = createLL(polynomial1);
          polynomial2 = createLL(polynomial2);
          flag = 1;
        }
        p4 =  multiply_poly(polynomial1,polynomial2);
        displayLL(p4);
        break;
      case 4: 
        printf("Which polynomial to you wish to modify(1-p1,2-p2):");
        scanf("%d", &e);
        if (e==1){
          polynomial1 = edit_poly_LL(polynomial1);
        }else if(e==2){
          polynomial2 = edit_poly_LL(polynomial2);
        }
        break;
      case 5:
        displayLL(polynomial1);
        displayLL(polynomial2);
      case 6:
        break;
      default:
        printf("Enter correct input values\n");
    }
  }while(c);
  
  return 0;
}
struct node * createLL(struct node * start){
  start = NULL;
  struct node * temp;
  int n,a,b;
  printf("Enter number of terms:");
  scanf("%d",&n);
  while (n--){
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter coefficient and powernent (c,e):");
    scanf("%d,%d", &(temp->coeff),&(temp->power));
    temp->next = NULL;
    if (start == NULL){
      start = add_begin_LL(start,temp);
    }else{
      start = add_after_LL(start, temp);
    }
  }
  return start;
}
struct node * add_begin_LL(struct node * start, struct node * p){
  p->next = start;
  start = p;
  return start;
}
struct node * add_end_LL(struct node * start, struct node * p){
    struct node * temp = start;
    if (temp==NULL){
      start = p;
      return start;
    }
    while (temp->next != NULL )
      temp = temp->next;
    temp->next = p;
    return start;
}
struct node * add_after_LL(struct node * start, struct node * p){
  if ((start==NULL) || (p->power > start->power)){
    start = add_begin_LL(start,p);
    return start;
  }
  struct node * temp = start;
  while ((temp->next != NULL) && (p->power < temp->next->power)){
    temp = temp->next;
  }
  if (temp->next == NULL){
    if (p->power > temp->power){
      p->next = temp;
      start = p;
    }
    else if (p->power == temp->power){
      temp->coeff += p->coeff;
    }else if (p->power < temp->power){
      temp->next = p; 
    }
    return start;
  }else {
    if (p->power == temp->next->power)
      temp->next->coeff += p->coeff;
    else if (p->power > temp->next->power) {
      p->next = temp->next;
      temp->next = p;
    }
  }
  return start;
}
void displayLL(struct node * a){
    if (a==NULL){
        printf("Empty list\n");
        return;
    }
    printf("| ");
    while (a!= NULL){
        printf("%dX^%d + ",a->coeff, a->power);
        a = a->next;
  
    }
    printf(" + 0 = 0 |\n");
}

struct node * add_to_LL(struct node *a,struct node *b){
  struct node * sum = NULL;
  while (a!=NULL && b!= NULL)
  {
    struct node * temp = (struct node *)malloc(sizeof(struct node));
    if (a->power == b->power){
      temp->power = b->power;
      temp->coeff = a->coeff + b->coeff;
      temp->next = NULL;
      sum = add_end_LL(sum,temp);
      a = a->next;
      b = b->next;
    }else if (a->power > b->power){
      temp->power = a->power;
      temp->coeff = b->coeff;
      temp->next = NULL;
      sum = add_end_LL(sum,temp);
      a = a->next;
    }else if (b->power > a->power){
      temp->power = b->power;
      temp->coeff = b->coeff;
      temp->next = NULL;
      sum = add_end_LL(sum,temp);
      b = b->next;
    }
  }
  struct node * p;
  p = (a==NULL)?b:a;
  while (p!=NULL){
    struct node * temp = (struct node *)malloc(sizeof(struct node));
    temp->coeff = p->coeff;
    temp->power = p->power;
    temp->next = NULL;
    sum = add_begin_LL(sum, temp);
    p = p->next;
  }
  return sum;
}
struct node *  multiply_poly(struct node * p1, struct node *p2){
  struct node * product = NULL;
  struct node * a, *b;
  a = p1;
  b = p2;
  if (a==NULL || b==NULL)
    return product;
 while (a!=NULL){
  b = p2;
  while (b!=NULL){
    struct node * temp = (struct node *)malloc(sizeof(struct node));
    temp->coeff = a->coeff * b->coeff;
    temp->power = a->power + b->power;
    temp->next = NULL;
    product = add_after_LL(product, temp);
    b = b->next;
  }
  a = a->next;
 }
 return product;
}
struct node * edit_poly_LL(struct node * a){

  int c;
  printf("Enter \n\t1 to insert a term\n\t2 to delete a term\n:");
  scanf("%d", &c);
  struct node * temp = (struct node *)malloc(sizeof(struct node));
  if (c==1)
  {
    printf("Enter coefficient and powernent:");
    scanf("%d,%d",&(temp->coeff),&(temp->power));
    temp->next = NULL;
    a = add_after_LL(a,temp);
  }
  else if (c==2){
    printf("Enter powernent of term to be deleted:");
    scanf("%d",&c);
    a = deleteTerm(a, c);
  }
  else{
    printf("Only two options\nReturning unmodified start\n");
  }  
  return a;
}
struct node * deleteTerm(struct node * start, int exp){
  struct node * p = start;
  if (start == NULL)
    return start;
  else if (start->power == exp){
    p = start;
    start = start->next;
    free(p);
    return start;
  }
  while (p->next!=NULL){
    if (p->next->power == exp){
      struct node * temp = (struct node *)malloc(sizeof(struct node));      
      temp = p->next;
      p->next = temp->next;
      free(temp);
      return start;
    }
    p = p->next;
  }
  printf("Item %d not found in list\n");
  return start;
}

