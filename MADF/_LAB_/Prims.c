#include <stdio.h>
#include <stdlib.h>
#define input(x) scanf("%d", &x)

#define MAX __INT32_MAX__

int cost[100][100];
int near[100];
int t[100][100];

void printArray(int a[],int n)
{
    for(int i = 1 ; i < n ; i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}

int Prims(int n_vertex)
{
    int i, j, k, u, v, n = n_vertex, min = MAX;
    for (i = 1; i <= n; i++)
    {
        for (j = i; j <= n; j++)
        {
            if (cost[i][j] < min)
            {
                min = cost[i][j];
                u = i;
                v = j;
            }
        }
    }
    t[0][0] = u;
    t[1][0] = v;
    near[u] = near[v] = 0;
    for (i = 1; i <= n; i++)
    {
        if (near[i] != 0)
        {
            if (cost[i][u] < cost[i][v])
            {
                near[i] = u;
            }
            else
            {
                near[i] = v;
            }
        }
        
    }
    printf("MinCost: ");
    printf("%d\n",cost[t[0][0]][t[1][0]]);
    printf("Near : ");
    printArray(near,n_vertex); 
    printf("\n");

    
    int m = cost[t[0][0]][t[1][0]];
    for (i = 1; i < n - 1; i++)
    {
        min = MAX;
        for (j = 1; j <= n; j++)
        {
            if (near[j] != 0 && cost[j][near[j]] < min)
            {
                min = cost[j][near[j]];
                k = j;
            }
        }
        m += min;
        printf("MinCost : %d\n",m);

        t[0][i] = k;
        t[1][i] = near[k];
        near[k] = 0;
        for (j = 1; j <= n; j++)
        {
            if (near[j] != 0 && cost[j][k] < cost[j][near[j]])
                near[j] = k;
        }
        /*for (int m = 0; m < n - 1; m++)
        {    
              int mcost = 0;
              mcost = mcost + cost[t[0][m]][t[1][m]];
        }*/

        printf("Near : ");
        printArray(near,n_vertex);
        printf("\n");
    }

    printf("\nEdges are: \n");
    for (i = 0; i < n - 1; i++)
    {
        printf("(%d,%d)\n", t[0][i], t[1][i]);
    }

    int mcost = 0;
    for (i = 0; i < n - 1; i++)
    {
        mcost = mcost + cost[t[0][i]][t[1][i]];
    }

    return(mcost);
    
}

int main()
{
    // User Input

    printf("Enter the Number of vertices\n");
    int n;
    input(n);
    n += 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cost[i][j] = MAX;
        near[i] = MAX;
    }
    int u = 0, v = 0, cost_i = MAX;
    do
    {

        printf("Enter Vertex A and B and Cost form A to B (-1 -1 to Exit)\n");
        input(u);
        input(v);
        input(cost_i);
        cost[u][v] = cost_i;
        cost[v][u] = cost_i;
    } while (u != -1 && v != -1);

    
    printf("!Minimun cost : %d",Prims(n-1));
}

