#include <stdio.h>
#define MAX 9999

int m[10][10];
int cost[10][10];
int t[10][10];
int parent[10];
int sr[10], dst[10], rate[10];
int kruskals(int, int);
void UNION(int, int);
int find(int);
int main()
{
    int n, e, cst, src, dest, mincost;
    printf("enter the number of the vertices : ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            m[i][j] = m[j][i] = 0;
            cost[i][j] = cost[j][i] = MAX;
        }
    }
    printf("enter the number of edges : ");
    scanf("%d", &e);
    for (int i = 0; i < e; i++)
    {
        printf("source vertex : ");
        scanf("%d", &src);
        printf("dest vertex : ");
        scanf("%d", &dest);
        printf("cost : ");
        scanf("%d", &cst);
        m[src][dest] = m[dest][src] = 1;
        cost[src][dest] = cost[dest][src] = cst;
    }
    mincost = kruskals(n, e);
    printf("The Min Cost is : %d ", mincost);
}
int kruskals(int n, int e)
{
    int k = 1;
    //finding edges
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (cost[i][j] != MAX)
            {
                sr[k] = i;
                dst[k] = j;
                rate[k] = cost[i][j];
                k++;
            }
        }
    }
    //sort the edges
    for (int i = 1; i < k; i++)
    {
        for (int j = 1; j < k - 1; j++)
        {
            if (rate[j] > rate[j + 1])
            {
                int t = sr[j], u = dst[j], v = rate[j];
                rate[j] = rate[j + 1];
                sr[j] = sr[j + 1];
                dst[j] = dst[j + 1];
                rate[j + 1] = v;
                sr[j + 1] = t;
                dst[j + 1] = u;
            }
        }
    }
    //initialize parent 
    for (int i = 1; i <= n; i++)
        parent[i] = -1;
    int i = 0, mincost = 0, x = 1;
    while (i < n - 1 && x < k)//for number of edges
    {
        int j = find(sr[x]), k = find(dst[x]);//find branched parents
        if (j != k)//if equal discard case
        {
            i = i + 1;
            t[i][1] = sr[x];
            t[i][2] = dst[x];
            mincost = mincost + cost[sr[x]][dst[x]];
            UNION(j, k);
            printf("\nmincost : %d ", mincost);
           // printf("\nEDGE INSERTED : %d %d ", t[i][1], t[i][2]);
            printf("\nParent : ");
            for (int i = 1; i <= n; i++)
                printf("%4d", parent[i]);
        }
        x++;
    }
    if (i != n - 1)
    {
        printf("\nno mst ...\n");
    }
    else
    {
        printf("\nMin Cost\n");
        for (int i = 1; i < n; i++)
        {
            printf("\t(%d,%d) cost = %d \n", t[i][1], t[i][2], cost[t[i][1]][t[i][2]]);
        }
        return mincost;
    }
}
void UNION(int i, int j)
{
    parent[i] = j;
}
int find(int i)
{
    while (parent[i] >= 0)
        i = parent[i];
    return i;
}
