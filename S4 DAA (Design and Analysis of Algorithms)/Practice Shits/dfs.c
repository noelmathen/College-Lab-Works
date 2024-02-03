#include<stdio.h>
#include<stdlib.h>

#define MAX_VERTICES 20
#define n 5

int visited[n];
int Graph[n][n] = {
    {0, 1, 1, 1, 0},
    {1, 0, 0, 0, 0},
    {1, 0, 0, 1, 1},
    {1, 0, 1, 0, 0},
    {0, 0, 1, 0, 0}
};


void DFS(int startVertext)
{
    printf("%d  ", startVertext);
    visited[startVertext]=1;
    for (int j = 0; j < n; j++)
    {
        if(Graph[startVertext][j]==1 && !visited[j])
        {
            DFS(j);
        }
    }
    
}

void main()
{
    printf("\nDEPTH FIRST SEARCH\n\n");
    for(int i=0; i<n; i++)
    {
        visited[i]=0;
    }
    
    int startVertex = 4;
    DFS(startVertex);

}










    // int n=5;


// printf("\n\nEnter the number of vertices: ");
    // scanf("%d", &N);
    // printf("\nEnter the adjacency matrix: ");
    // for (int i = 0; i < N; i++)
    // {
    //     for (int j = 0; j < N; j++)
    //     {
    //         scanf("%d", &Graph[i][j]);
    //     }
        
    // }
