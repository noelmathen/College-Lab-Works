#include<stdio.h>
#include<stdlib.h>
#define MAX 20
int graph[MAX][MAX];
//  =  {
//         {0, 0, 0, 0, 0, 0},
//         {0, 0, 0, 0, 0, 0},
//         {0, 0, 0, 1, 0, 0},
//         {0, 1, 0, 0, 0, 0},
//         {1, 1, 0, 0, 0, 0},
//         {1, 0, 1, 0, 0, 0} 
// };
int visited[MAX], n, stack[MAX], top=-1;

void inputGraph()
{
    printf("\nEnter adjacacy matrix: \n");
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
}

void initializeGraph()
{
    for(int i=0; i<n; i++)
    {
        visited[i]=0;
        for(int j=0; j<n; j++)
        {
            graph[i][j]=0;
        }
    }
}

void push(int x)
{
    stack[++top] = x;
}

int pop()
{
    return stack[top--];
}

void topsort(int start) {
    visited[start] = 1;
    for (int j = 0; j < n; j++) {
        if (graph[start][j] == 1 && !visited[j]) {
            topsort(j);
        }
    }
    push(start);
}

void printSortedNodes() {
    printf("Sorted nodes: ");
    for (int i = top; i >= 0; i--) {
        printf("%d  ",pop());
    }
    printf("\n");
}

void main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    initializeGraph();
    inputGraph();
    int start;
    printf("Enter the starting node: ");
    scanf("%d", &start);
    topsort(start);
    for(int i=0; i<n; i++)
    {
        if(!visited[i])
        {
            topsort(i);
        }
    }
    printSortedNodes();
}

