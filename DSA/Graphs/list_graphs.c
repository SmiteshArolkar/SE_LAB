
#include <stdio.h>
#include <stdlib.h>
#define MAX 100
    struct vertex;
struct edge
{
    struct vertex *v;
    struct edge *ne;
};
struct vertex
{
    struct vertex *nv;
    int info;
    struct edge *fe;
};
struct vertex *start = NULL;
struct vertex *addv(int item)
{
    struct vertex *temp, *p;
    temp = (struct vertex *)malloc(sizeof(struct
                                          vertex));
    temp->info = item;
    temp->fe = NULL;
    temp->nv = NULL;
    if (start == NULL)
    {
        start = temp;
        return start;
    }
    else
    {
        p = start;
        while (p->nv != NULL)
        {
            p = p->nv;
        }
        p->nv = temp;
    }
    return start;
}
struct vertex *loc(int u)
{
    struct vertex *p = start;
    while (p != NULL)
    {
        if (p->info == u)
        {
            return p;
        }
        p = p->nv;
    }
    return p;
}
void adde(int u, int v)
{
    struct vertex *p, *q;
    p = loc(u);
    q = loc(v);
    if (p != NULL && q != NULL)
    {
        struct edge *temp, *t;
        temp = (struct edge *)malloc(sizeof(struct
                                            edge));
        temp->v = q;
        temp->ne = NULL;
        if (p->fe == NULL)
        {
            p->fe = temp;
        }
        else
        {
            t = p->fe;
            while (t->ne != NULL)
            {
                t = t->ne;
            }
            t->ne = temp;
        }
    }
    else
    {
        printf("\nInvalid vertex entered");
    }
}
int n = 6;
int front = -1;
int rear = -1;
int status[MAX];
struct vertex *queue[MAX];
int isempty()
{
    if (front == -1 || front > rear)
    {
        return 1;
    }
    return 0;
}
void insert(struct vertex *v)
{
    if (front == -1)
    {
        front = 0;
    }
    rear = rear + 1;
    queue[rear] = v;
}
struct vertex *delete()
{
    if (isempty())
    {
        return NULL;
    }
    struct vertex *p;
    p = queue[front];
    front += 1;
    return p;
}
void BFS(struct vertex *p)
{
    struct edge *q;
    insert(p);
    status[p->info] = 1;
    while (!isempty())
    {
        p = delete ();
        printf("%d", p->info + 1);
        status[p->info] = 2;
        q = p->fe;
        while (q != NULL)
        {
            if (status[q->v->info] == 0)
            {
                insert(q->v);
                status[q->v->info] = 1;
            }
            q = q->ne;
        }
    }
}
void BFT()
{
    int i;
    for (i = 0; i < n; i++)
    {
        status[i] = 0;
    }
    printf("\nEnter starting vertex:");
    int v;
    scanf("%d", &v);
    struct vertex *p;
    p = loc(v);
    if (p != NULL)
    {
        printf("\nBFS Traversal:");
        BFS(p);
    }
    else
    {
        printf("\nInvalid vertex");
        return;
    }
    for (i = 0; i < n; i++)
    {
        if (status[i] == 0)
        {
            BFS(i);
        }
    }
    return;
}
struct vertex *stk[MAX];
int top = -1;
int isemptystk()
{
    if (top == -1)
    {
        return 1;
    }
    return 0;
}
void push(struct vertex *v)
{
    if (top == MAX - 1)
    {
        printf("\nStack Overflow");
        return;
    }
    else
    {
        top += 1;
        stk[top] = v;
        return;
    }
}
struct vertex *pop()
{
    if (isemptystk())
    {
        return NULL;
    }
    else
    {
        struct vertex *p;
        p = stk[top];
        top -= 1;
        return p;
    }
}
void DFS(struct vertex *v1)
{
    push(v1);
    struct edge *q;
    while (!isemptystk())
    {
        v1 = pop();
        if (status[v1->info] == 0)
        {
            printf("%d", v1->info + 1);
            status[v1->info] = 2;
        }
        q = v1->fe;
        while (q != NULL)
        {
            if (status[q->v->info] == 0)
            {
                push(q->v);
            }
            q = q->ne;
        }
    }
}
void DFT()
{
    int i;
    for (i = 0; i < n; i++)
    {
        status[i] = 0;
    }
    printf("\nEnter starting vertex:");
    int v;
    scanf("%d", &v);
    struct vertex *p;
    p = loc(v);
    if (p != NULL)
    {
        printf("\nDFS Traversal:");
        DFS(p);
    }
    else
    {
        printf("\nInvalid vertex");
    }
    for (i = 0; i < n; i++)
    {
        if (status[i] == 0)
        {
            DFS(i);
        }
    }
}
int main()
{
    int i;
    int vs, vd;
    int v;
    printf("\nEnter 6 vertices:");
    for (i = 0; i < n; i++)
    {
        printf("\nEnter vertex:");
        scanf("%d", &v);
        start = addv(v);
    }
    for (i = 0; i < n * n - 1; i++)
    {
        printf("\nEnter vertices:");
        scanf("%d %d", &vs, &vd);
        if ((vs == -1) && (vd == -1))
        {
            break;
        }
        else
        {
            adde(vs, vd);
        }
    }
    BFT();
    DFT();
}
