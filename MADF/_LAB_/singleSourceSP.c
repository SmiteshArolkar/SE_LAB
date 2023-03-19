#include "stdio.h"
#define input(x) scanf("%d",&x);
#define MAX __INT32_MAX__
#define TRUE 1
#define FALSE 0
#define message(x) printf("%s",x)


// int cost[9][9] = {
//     MAX , MAX , MAX , MAX , MAX , MAX, MAX ,MAX , MAX ,
//     MAX , MAX , 12, 15 , 10, 20, MAX ,MAX , MAX ,
//     MAX , MAX , MAX , 11 , 11 , 8, MAX ,MAX , MAX ,
//     MAX , MAX , 13 , MAX , 7 , 10, MAX ,MAX , MAX ,
//     MAX , MAX , MAX , MAX , MAX , 4, 16 ,28 , MAX ,
//     MAX , MAX , MAX , MAX , MAX , MAX, 15 ,MAX , 29 ,
//     MAX , MAX , MAX , MAX , MAX , MAX, MAX ,12 , 16 ,
//     MAX , MAX , MAX , MAX , MAX , MAX, MAX ,MAX , 12 ,
//     MAX , MAX , MAX , MAX , MAX , MAX, MAX ,13 , MAX 
// };

// int dist[] = { 0 , 0, 0, 0, 0, 0, 0, 0, 0};

int cost[100][100];

int dist[100];

void printArray(int a[],int n)
{
    for(int i = 1 ; i <= n ; i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}

int shortestPath(int n , int start_vert)
{
    int i , s[10];
    for(i = 1 ; i <= n ; i++)
    {
        s[i] = FALSE;
        dist[i] = cost[start_vert][i];
    }
    
    s[start_vert] = TRUE;
    dist[start_vert] = 0;
    
    for(int j = 2 ; j <= n ; j++)
    {
        int min = MAX;
        int u = 0;
        for(int k = 1; k <= n ; k++)
        {
            if(s[k] == FALSE)
            {
                if(dist[k] < min)
                {
                    min = dist[k];
                    u = k;
                }
            }
        }
        
       

        s[u] = TRUE;
        message("U = : ");
        printf("%d ",u);

        for(int w = 1 ; w <= n ; w++)
        {
            if(cost[u][w] != MAX && s[w] == FALSE)
            {
                if(dist[w] > dist[u] + cost[u][w])
                dist[w] = dist[u] + cost[u][w];
            }
        }
        message("Dist Array : ");
        printArray(dist,n);
        
    }
    
    return dist[n];
   
}

int main()
{
    // int n = 8;
    // int path_len = shortestPath(8,1);


    // printf("Shortest Path Length = %d",path_len);

    //user input
    int n1;
    message("Enter number of vertices\n");
    input(n1);
    int u = 1 , v = 1;
    for(int i = 0 ; i <= n1 ; i++)
    {
        for(int j = 0 ; j <= n1 ; j++)
        cost[i][j] = MAX;
        dist[i] = 0;
    }
    while( u && v)
    {
        message("Enter Edge A to B with Cost ( 0 0 0 to exit)\n");
        input(u);
        input(v);
        input(cost[u][v]);
    }

    // for(int i = 0 ; i <= n1 ; i++)
    // {
    //     for(int j = 0 ; j <= n1 ;j++)
    //     {
    //         printf("%d ",cost[i][j]);
    //     }
    //     message("\n");
    // }

    int path_len = shortestPath(n1,1);
    printf("Shortest Path Length = %d",path_len);

    
}
