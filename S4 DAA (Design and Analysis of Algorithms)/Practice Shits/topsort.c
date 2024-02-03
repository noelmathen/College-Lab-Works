#include<stdio.h>
#define MAX 100
int graph[MAX][MAX]  =  {
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0},
        {0, 1, 0, 0, 0, 0},
        {1, 1, 0, 0, 0, 0},
        {1, 0, 1, 0, 0, 0} 
};
int visited[MAX] = {0}, stack[MAX], top=-1, n=6;

void inputGraph(){
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &graph[i][j]);
        }
    }
}

void push(int x){
    stack[++top] = x;
}

int pop(){
    return stack[top--];
}

void display(){
    for(int i=top; i>=0; i--){
        printf("%d  ", pop());
    }
}

void topSort(int i){
    visited[i] = 1;
    for(int j=0; j<n; j++){
        if(!visited[j] && graph[i][j]==1){
            topSort(j);
        }
    }
    push(i);
}

void main(){
    int start;
    // inputGraph();
    printf("Enter the starting node: ");
    scanf("%d", &start);
    for(int i=0; i<n; i++){
        if(!visited[i]){
            topSort(i);
        }
    }
    display();
}
