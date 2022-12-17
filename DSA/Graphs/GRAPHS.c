#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node
{
    int data;
    struct Node *next;

} *front = NULL, *rear = NULL;
int a, b = 7;
void enqueue(int x)
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    if (t == NULL)
        printf("Queue is FUll\n");
    else
    {
        t->data = x;
        t->next = NULL;
        if (front == NULL)
            front = rear = t;
        else
        {
            rear->next = t;
            rear = t;
        }
    }
}
int dequeue()
{
    int x = -1;
    struct Node *t;

    if (front == NULL)
        printf("Queue is Empty\n");
    else
    {
        x = front->data;
        t = front;
        front = front->next;
        free(t);
    }
    return x;
}
int isEmpty()
{
    return front == NULL;
}
void BFS(int G[][10], int start, int n)
{
    int i = start, j;

    int visited[10] = {0};

    printf("%d ", i);
    visited[i] = 1;
    enqueue(i);

    while (!isEmpty())
    {
        i = dequeue();
        for (j = 1; j < n; j++)
        {
            if (G[i][j] == 1 && visited[j] == 0)
            {
                printf("%d ", j);
                visited[j] = 1;
                enqueue(j);
            }
        }
    }
}
void DFS(int G[][10], int start, int n)
{
    static int visited[10] = {0};
    int j;

    if (visited[start] == 0)
    {
        printf("%d ", start);
        visited[start] = 1;

        for (j = 1; j < n; j++)
        {
            if (G[start][j] == 1 && visited[j] == 0)
                DFS(G, j, n);
        }
    }
}
int main()
{
    int c = 7;
    srand(time(0));
    int G[10][10] = {
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 0, 0, 0},
        {0, 1, 0, 0, 1, 0, 0},
        {0, 1, 0, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0}};
    printf("\nGRAPH CREATED WITH 6 VERTICES !!\n ");
    printf("<<--ADJANCY MATRIX IS-->>\n");

    for (int i = 0; i < c; ++i)
    {

        for (int j = 0; j < c; ++j)
        {
            printf("  %d", G[i][j]);
        }
        printf("\n");
    }
    printf(" [ VERTEX 0 IS NOT INCLUDED ] \n");
    int a = 0;
    while (a != 5)
    {

        printf("\n1.ADD NEW VERTEX.\n2:ADD THREE NEW EDGES\n3:BFS \n4:DFS.\n5:EXIT \n");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            printf("__ ADJANCY MATRIX BEFORE ADDITION__  \n");

            for (int i = 0; i < c; ++i)
            {

                for (int j = 0; j < c; ++j)
                {
                    printf("  %d", G[i][j]);
                }
                printf("\n");
            }
            c++;
            for (int i = 0; i < c; ++i)
            {
                G[i][c - 1] = 0;

                
                G[c - 1][i] = 0;
            }
            printf("__ADJANCY MATRIX AFTER ADDITION__ \n");

            for (int i = 0; i < c; ++i)
            {

                for (int j = 0; j < c; ++j)
                {
                    printf("  %d", G[i][j]);
                }
                printf("\n");
            }
            break;
        case 2:
            int x, y;
            printf("__ADJANCY MATRIX BEFORE ADDITION__ \n");

            for (int i = 0; i < c; ++i)
            {

                for (int j = 0; j < c; ++j)
                {
                    printf("  %d", G[i][j]);
                }
                printf("\n");
            }
            for (int i = 0; i < 3; i++)
            {
                x = rand() % c;
                y = rand() % c;
                if (x == 0)
                    x++;
                if (y == 0)
                    y++;
                G[x][y] = 1;
            }
            printf("__ADJANCY MATRIX AFTER ADDITION__  \n");

            for (int i = 0; i < c; ++i)
            {

                for (int j = 0; j < c; ++j)
                {
                    printf("  %d", G[i][j]);
                }
                printf("\n");
            }
            break;
        case 3:
            printf("__BFS__ \n");
            BFS(G, 4, c);
            printf("\n");
            break;
        case 4:
            printf("__DFS__  \n");
            DFS(G, 4, c);
            printf("\n");
            break;
        default:
            printf("\n--------------\n");
        }
    }

    return 0;
}