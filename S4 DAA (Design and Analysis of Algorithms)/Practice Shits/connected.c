#include<stdio.h>
#define MAX 100
int graph[MAX][MAX]  //TEST CASES
= {
    {0, 1, 0, 0, 0},
    {1, 0, 1, 0, 0},
    {0, 1, 0, 0, 0},
    {0, 0, 0, 0, 1},
    {0, 0, 0, 1, 0}

    // {0, 0, 0, 0, 0, 0, 0, 0},
    // {0, 0, 1, 0, 0, 0, 0, 0},
    // {0, 1, 0, 0, 0, 0, 0, 0},
    // {0, 0, 0, 0, 1, 1, 0, 0},
    // {0, 0, 0, 1, 0, 1, 1, 0},
    // {0, 0, 0, 1, 1, 0, 1, 0},
    // {0, 0, 0, 0, 1, 1, 0, 0},
    // {0, 0, 0, 0, 0, 0, 0, 0}
};

int visited[MAX] = {0}, stack[MAX], top=-1, n=5;
int component = 0;


void inputGraph(){
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &graph[i][j]);
        }
    }
}

void dfs(int i){
    printf("%d  ",i);
    visited[i] = 1;
    for(int j=0; j<n; j++){
        if(!visited[j] && graph[i][j]==1){
            dfs(j);
        }
    }
}

void main(){
    int start;
    // inputGraph();
    for(int i=0; i<n; i++){
        if(!visited[i]){
            printf("\nComponent %d: ",i+1);
            dfs(i);
            component++;
        }
    }
}
