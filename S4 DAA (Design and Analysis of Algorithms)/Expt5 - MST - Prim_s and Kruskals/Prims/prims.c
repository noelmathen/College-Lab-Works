#include <stdio.h>
#define MAX 10
#define INF 999
int cost[MAX][MAX];
int visited[MAX] = {0};

void prim(int n) {
    int mincost = 0;
    visited[1] = 1;
    for (int ne = 1; ne < n; ne++) {
        int min=INF, a, b;
        for (int i = 1; i <= n; i++) {
            if (visited[i]) {
                for (int j = 1; j <= n; j++) {
                    if (!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }
        printf("\nEdge %d: (%d %d) cost: %d\n", ne, a-1, b-1, min);
        mincost += min;
        visited[b] = 1;
    }
    printf("Minimum cost = %d\n", mincost);
}

int main() {
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0) {
                cost[i][j] = INF;
            }
        }
    }
    prim(n);
    return 0;
}


// int G[V][V] = {
// //   {0, 9, 75, 0, 0},
// //   {9, 0, 95, 19, 42},
// //   {75, 95, 0, 51, 66},
// //   {0, 19, 51, 0, 31},
// //   {0, 42, 66, 31, 0}};

// // int G[V][V]={
// //     {0, 1, 2, 0, 0 ,0}, 
// //     {1, 0, 3, 0, 0, 0},
// //     {2, 3, 0, 4, 5 ,6},
// //     {0, 0, 4, 0, 7, 0},
// //     {0, 0, 5, 7, 0, 8},
// //     {0, 0, 6, 0, 8, 0}
// // };    output 2

// int G[V][V] = {
//     {0, 2, 0, 6, 0},
//     {2, 0, 3, 8, 5},
//     {0, 3, 0, 0, 7},
//     {6, 8, 0, 0, 9},
//     {0, 5, 7, 9, 0}
// };   output1
