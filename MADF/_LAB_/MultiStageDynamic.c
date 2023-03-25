#include <stdio.h>
#include <stdlib.h>
#define MAX __INT32_MAX__
#define input(x) scanf("%d",&x)

int c[100][100];
int cost[50];
int p[20];
int d[50];

int min(int j, int r)
{
     int min = MAX, x;
     while (r > 0)
     {
          if (c[j][r] != MAX)
          {
               if ((c[j][r] + cost[r]) < min)
               {
                    min = c[j][r] + cost[r];
                    x = r;
               }
          }
          r--;
     }
     return x;
}
void Fgraph(int k, int n)
{
     int r = n - 1;
     cost[n - 1] = 0;
     for (int j = n - 2; j > 0; j--)
     {
          d[j] = min(j, r);
          cost[j] = c[j][d[j]] + cost[d[j]];
     }
     p[1] = 1;
     p[k] = n - 1;
     for (int j = 2; j <= k - 1; j++)
     {
          p[j] = d[p[j - 1]];
     }
}
int main()
{
     int n, y, k;
     
     printf("Enter the Number of Stages: \n");
     input(y);
     printf("Enter the Number of vertices: \n");
     input(n);
    
     n += 1;
     for (int i = 0; i < n; i++)
     {
          for (int j = 0; j < n; j++)
          {
               c[i][j] = MAX;
          }
     }
     int u = 0, v = 0, cost_i = MAX;
     printf(" --> Enter edge [(-1,-1)] to exit]\n");
     while (1)
     {
          printf("Enter Vertex A: ");
          input(u);
          printf("Enter Vertex B: ");
          input(v);
          if (u == -1 && v == -1)
               break;
          printf("Enter Cost from %d to %d: ", u, v);
          scanf("%d", &cost_i);
          c[u][v] = cost_i;
     }
     Fgraph(y, n);
     printf("\n");
     printf("COST FOR EVERY VERTEX ::");
     printf("\n");
     for (int i = n - 1; i > 0; i--)
     {
          printf("Cost[%d]: %d   ::  d[%d]: %d\n", i, cost[i], i, d[i]);
     }
     k = 1;
     printf("\n");
     printf("PATH :");
     printf("\n");
     for (int i = 1; i <= y; i++)
     {
          printf("%0d", p[i]);
          if ((k++) < y)
               printf("-->");
     }
     printf("\n");
}