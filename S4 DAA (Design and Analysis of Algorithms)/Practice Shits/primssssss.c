#include <stdio.h>
#define MAX 10
#define INF 999
int cost[MAX][MAX];
int visited[MAX] = {0};

void prim(int n) {
    int mincost = 0;
    visited[1] = 1;
    for (int ne = 0; ne < n-1; ne++) {
        int min=INF, a, b;
        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                for (int j = 0; j < n; j++) {
                    if (!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }
        printf("\nEdge %d: (%d %d) cost: %d\n", ne, a, b, min);
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
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0) {
                cost[i][j] = INF;
            }
        }
    }
    prim(n);
    return 0;
}
