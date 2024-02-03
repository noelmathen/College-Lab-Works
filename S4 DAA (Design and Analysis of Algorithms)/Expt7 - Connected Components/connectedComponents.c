#include<stdio.h>
#include<stdlib.h>
#define MAX 20
int graph[MAX][MAX]={0};  // all values are initialized to zero

int visited[MAX]={0}, n;

void InputGraph(){
    printf("Enter the adjacency matrix: \n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &graph[i][j]);
        }
    }
}

void DFS(int startVertext){
    printf("%d  ", startVertext);
    visited[startVertext]=1;
    for (int j = 0; j < n; j++){
        if(graph[startVertext][j]==1 && !visited[j]){
            DFS(j);
        }
    }
}

void main(){
    printf("\n********CONNCECTED COMPONENTS********\n");
    printf("\nEnter the number of vertices: ");
    scanf("%d",&n);
    InputGraph();
    int componentCount = 1;
    for(int i=0; i<n; i++){
        if(!visited[i]){
            printf("\nComponent %d: ",componentCount);
            DFS(i); //the number of times DFS() is called is the number of different components in the graph
            componentCount++;
        }
    }
}


//TEST CASES
// = {
//     // {0, 1, 0, 0, 0},
//     // {1, 0, 1, 0, 0},
//     // {0, 1, 0, 0, 0},
//     // {0, 0, 0, 0, 1},
//     // {0, 0, 0, 1, 0}

//     {0, 0, 0, 0, 0, 0, 0, 0},
//     {0, 0, 1, 0, 0, 0, 0, 0},
//     {0, 1, 0, 0, 0, 0, 0, 0},
//     {0, 0, 0, 0, 1, 1, 0, 0},
//     {0, 0, 0, 1, 0, 1, 1, 0},
//     {0, 0, 0, 1, 1, 0, 1, 0},
//     {0, 0, 0, 0, 1, 1, 0, 0},
//     {0, 0, 0, 0, 0, 0, 0, 0}
// };
