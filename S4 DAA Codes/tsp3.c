#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 10
#define INF 999999

int dist[MAX_VERTICES][MAX_VERTICES];
int n;

bool visited[MAX_VERTICES];
int minCost = INF;
int minPath[MAX_VERTICES];

void takeInput() {
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &dist[i][j]);
        }
    }
    printf("\nThe cost matrix will be:\n");
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d\t", dist[i][j]);
        }
        printf("\n");
    }
    
}

void tsp(int city, int count, int path[], int currentCost) {
    visited[city] = true;
    path[count] = city;

    if (count == n - 1 && dist[city][0] != 0) {
        // Valid path found
        if (currentCost + dist[city][0] < minCost) {
            // Update minimum cost and path
            minCost = currentCost + dist[city][0];
            for (int i = 0; i < n; i++) {
                minPath[i] = path[i];
            }
        }
    }
    else {
        for (int nextCity = 0; nextCity < n; nextCity++) {
            if (!visited[nextCity] && dist[city][nextCity] != 0) {
                tsp(nextCity, count + 1, path, currentCost + dist[city][nextCity]);
            }
        }
    }

    visited[city] = false;
}

void printSolution() {
    printf("The cost of the most efficient tour = %d\n", minCost);
    printf("Nodes visited in the most efficient tour: ");
    for (int i = 0; i < n; i++) {
        printf("%d", minPath[i]);
        if (i != n - 1) {
            printf(" -> ");
        }
    }
    printf(" -> %d\n", minPath[0]);
}

int main() {
    takeInput();

    int path[MAX_VERTICES];
    tsp(0, 0, path, 0); // Start from node 0

    printSolution();

    return 0;
}
