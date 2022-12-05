#include "stdio.h"
#include "malloc.h"


struct vertex;

struct Edge
{
    struct Edge* next;
    struct vertex* vertex;
};
struct vertex
{
    int data;
    struct Edge* edge;
    struct vertex* next;
};

typedef struct Edge edge;
typedef struct vertex vertex;

vertex* insert(vertex* vert)
{
    int data;
    printf("Enter Data of the Node To be inserted\n");
    scanf("%d",&data);

    vertex* temp = (vertex*)malloc(sizeof(vertex));
    temp->data = data;
    temp->next = NULL;
    temp->edge = NULL;

    //inserting edge list

    int n;
    printf("Enter number of Edges\n");
    scanf("%d",&n);

    //check max edge logic


    for(int i = 0 ; i < n; i++)
    {
        edge* p = (edge*)malloc(sizeof(edge));
        p->next = NULL;
        p->vertex = NULL;
        printf("Enter data of destination vertex\n");
        int dest_data;
        scanf("%d",&dest_data);
        vertex* t;
        for(t = vert;t != NULL ; t = t->next)
        {
            if(dest_data == t->data)
            {
                printf("DATA found\n");
                break;
            }
        }
        
        p->vertex = t;
        edge* a = temp->edge;
        if(a == NULL)
        {
            a = p;
        }
        else
        {
            while(a->next)
            {
                a = a->next;
            }
            a->next = p;
        }


    }

    if(vert != NULL)
    {
        vertex* j = vert;
        while(j->next)
        {
            j = j->next;
        }
        j->next = temp;
    }
    else
    {
        vert = temp;
    }
    
    return vert;

}

void display(vertex* vert)
{
    vertex* t = vert;
    while(t)
    {
        printf("%d\n",t->data);
        t = t->next;
    }
}


int main()
{
    vertex* v = insert(v);

    v = insert(v);
    
    
    display(v);
}

