#include "stdio.h"
#include "malloc.h"


struct NODE
{
    /* data */
    int data;
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
        scanf("%d",&temp->data);
        if(start == NULL)
        {
            start = temp;
            p = temp;
        }
        else{
            p->next = temp;
            p=p->next;
        }

    }
    return start;
}

void display_list(node* start)
{
    node* p = start;
    while(p){
        printf("%d\t",p->data);
        p  = p->next;
       }
    printf("\n");
}

node* search(node* start,int data)
{
    if(start == NULL)
    {
        printf("Element Not Found\n");
        return NULL;
    }
    if(start->data == data)
    {
        printf("Element found\n");
        return NULL;
    }
    else{
        search(start->next,data);
    }
}


int base_convert(int n, int base);
void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod);
int gcd(int a, int b);
void reverse_a_string(char*);

int main()
{
   int c;
   do
   {
    printf("\n1)Base Conversion\n2)Tower of Hanoi\n3)gcd\n4)Reverse String\n5)Search Linked List\n0)exit");
    scanf("%d",&c);
    switch (c)
    {
    case 1:printf("Enter Number and base(2-16)\n");
           {
            int a,b;
            scanf("%d %d",&a,&b);
            base_convert(a,b);
           }
        /* code */
        break;
    case 2:
           printf("Enter number of Discs\n");
           {
            int n;
            scanf("%d",&n);
            towerOfHanoi(n,'A','B','C');
            printf("\n");
           }
        /* code */
        break;
    case 3:printf("Enter 2 numbers\n");
    {
        int a,b;
        scanf("%d %d",&a,&b);
        printf("%d\n",gcd(a,b));
        
    }
        
        /* code */
        break;
    case 4:printf("Enter a String\n");
    {
        char a[100];
        scanf("%s",a);
        reverse_a_string(a);
        printf("\n");
    }
        /* code */
        break;
    case 5:
    {
        node* start = NULL;
        start = create_list(start);
        printf("Enter data to be searched\n");
        int data;
        scanf("%d",&data);
        search(start,data);
    }
        /* code */
        break;
    default:
        break;
    }

   }while(c);
}

int base_convert(int n, int base)
{
    if (n == 0)
    {
        printf("0");
        return 0;
    }
    if (n == 1)
    {
        printf("1");
        return 0;
    }
    else
    {
        base_convert(n / base, base);
    }
    if(base == 16)
    {
        switch (n%base)
        {
            case 10:printf("A");break;
            case 11:printf("B");break;
            case 12:printf("C");break;
            case 13:printf("D");break;
            case 14:printf("E");break;
            case 15:printf("F");break;
            default:printf("%d",n%base);
        }
    }
    else
    printf("%d", n % base);
}

void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod)
{
    if (n == 0)
    {
        return;
    }
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
    printf("Move disk %d from rod %c to rod %c \n", n, from_rod, to_rod);
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    if (a == b)
        return a;
    if (a > b)
        return gcd(a - b, b);
    else
        return gcd(a, b - a);
}

void reverse_a_string(char *a)
{
    if (*a)
    {
        reverse_a_string(a + 1);
        printf("%c", *a);
    }
}