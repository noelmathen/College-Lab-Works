#include<stdio.h>
#define MAX 20
#define INF 9999
int cost[MAX][MAX]={
    {0, 1, 2, 0, 0 ,0}, 
    {1, 0, 3, 0, 0, 0},
    {2, 3, 0, 4, 5 ,6},
    {0, 0, 4, 0, 7, 0},
    {0, 0, 5, 7, 0, 8},
    {0, 0, 6, 0, 8, 0}
};
int n;
int visited[MAX]={0};

void prims(){
    visited[1]=1;
    int minCost=0;
    for(int ne=1; ne<n; ne++){
        int min=INF, a, b;
        for(int i=1; i<=n; i++){
            if(visited[i]){
                for(int j=1; j<=n; j++){
                    if(!visited[j] && cost[i][j] < min){
                        min = cost[i][j];
                        a=i;
                        b=j;
                    }
                }
            }
        }
        printf("\nEdge %d:- (%d --> %d) : %d",ne,a-1, b-1, min);
        minCost += min;
        visited[b]=1;
    }
    printf("\nMinimum Cost: %d",minCost);
}


void main(){
    printf("Enter number of nodes: ");
    scanf("%d",&n);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(cost[i][j]==0){
                cost[i][j]=INF;
            }
        }
    }
    prims();
}