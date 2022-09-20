#include "stdio.h"
#include "stdlib.h"

struct STUDENT{
    char address[100];
    char branch[10];
    char name[30];
    int roll;
};
typedef struct STUDENT student;
void Add_student(student* s)
{
    printf("Enter Student Name :\n");
    fgets(s->name,30,stdin);
    fgets(s->name,30,stdin);

    printf("Enter Student Address :\n");
    fgets(s->address,100,stdin);

    printf("Enter Student Branch :\n");
    fgets(s->branch,30,stdin);

    printf("Enter Student Roll Number :\n");
    scanf("%d",&s->roll);
}
int search_student(student* s,int* roll){
    if(*roll == s->roll){
          printf("Student Found !\n");   
          return 0;
          }
    return 1;
}
void display_student(student* s){
    printf("Name : %s\nAddress : %s\nBranch : %s\nRoll : %d\n",s->name,s->address,s->branch,s->roll);
}
void  edit_details(student* s){
    Add_student(s);
}


int main()
{
    int c;
    student s[100];
    int n;
    do
    {
        printf("1)Add Students\n2)Search Student\n3)Edit Student Details\n4)Display Details\n0)Exit\n");
        scanf("%d",&c);

        switch (c)
        {
        case 1 :  printf("Enter Number of Students to be Added\n");
                  scanf("%d",&n);
                  for(int i = 0 ; i < n ; i ++)
                  {
                    printf("Enter Details for Student %d\n",i+1);
                    Add_student(&s[i]);
                  }

            /* code */
            break;
        case 2 :  printf("Enter Roll Number to Be searched\n");int roll;
                  scanf("%d",&roll);
                  int pass = 1;
                  for(int i = 0 ; i < n ; i++)
                  {
                    pass = search_student(&s[i],&roll);
                    if(!pass)
                    break;
                  }
                  if(pass)printf("Student Entry Not Found\n");

                  break;
        case 3 :  printf("Enter Roll Number of Student whoose Details need to be Edited\n");
                  scanf("%d",&roll);
                  for(int i = 0 ; i< n ; i++)
                  if(s[i].roll == roll)
                  edit_details(&s[i]);
                  break;
        case 4 :  for(int i = 0 ; i < n ; i++){
                  printf("Details of Student %d \n",i+1);
                  display_student(&s[i]);
                  }
        break; 
        default:printf("Invalid Input\n");
            break;
        }
        /* code */
    } while (c);
    
}
