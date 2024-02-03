#include<stdio.h>
#include<stdbool.h>
#define MAX 20
int dist[MAX][MAX] = {
                        {0, 10, 15, 20},
                        {5, 0, 9, 10},
                        {6, 13, 0, 12},
                        {8, 8, 9 , 0} 
                    };
int n=4;

// int dist[MAX][MAX] = {  { 0, 2, 0, 12,  5},
//                         { 2, 0, 4,  8,  0},
//                         { 0, 4, 0,  3,  3},
//                         {12, 8, 3,  0, 10},
//                         { 5, 0, 3, 10,  0}};
// int n=5; 

int minCost=99999, minPath[MAX]={0};
bool visited[MAX]={false};

void inputGraph(){
    printf("enter the number of nodes: ");
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d",&dist[i][j]);
        }
    }
}

void display(){
    printf("\n\nMinimum cost: %d",minCost);
    printf("\nMinimum Path: ");
    for(int i=0; i<n; i++){
        printf("%d --> ",minPath[i]);
    }
    printf("%d",minPath[0]);
}

void tsp(int city, int count, int path[], int currentCost){
    visited[city] = true;
    path[count] = city;
    if(count == n-1 && dist[city][0] != 0){
        int totalCost = currentCost + dist[city][0];
        if(totalCost < minCost){
            minCost = totalCost;
            for(int i=0; i<n; i++){
                minPath[i] = path[i];
            }
        }
    } 
    else{
        for(int nextCity=0; nextCity<n; nextCity++){
            if(!visited[nextCity] && dist[city][nextCity] != 0){
                tsp(nextCity, count+1, path, currentCost + dist[city][nextCity]);
            }
        }
    }
    visited[city] = false;
}


void main(){
    // inputGrpah();
    int path[MAX]={0};
    tsp(0, 0, path, 0);
    display();
}

