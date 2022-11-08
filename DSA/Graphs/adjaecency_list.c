#include "stdio.h"
#include "malloc.h"

struct edge;
struct vertex{

    int value;
    struct vertex* next;
    struct edge* m_edge;
};

struct edge{
    struct vertex* vert;
    struct edge* next;
};

typedef struct edge edge;
typedef struct vertex vertex;

vertex* createGraph(int n);
vertex* addNode(vertex* v,int data);
vertex* addEdge(vertex* source,vertex* destinaton);
void displayGraph(vertex* v);

int main()
{

}

vertex* createGraph(int n)
{
    vertex *v = (vertex*)malloc(sizeof(vertex));
    vertex *temp = v;
    for(int i = 0 ; i < n-1; i++)
    {
         vertex *temp = (vertex*)malloc(sizeof(vertex));
        if(v == NULL)
        {
            temp->value = i+1;
            temp->next = NULL;
        }
        else
        {

        }
    }
}

