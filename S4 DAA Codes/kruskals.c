//modify this code such that u input the adjacency matrix...not the edges
#include <stdio.h>
#include <stdlib.h>

struct edge {
    int child, parent, weight;
}e[100], temp;

void main() {
    int i, j, nEdges, nVertices;
    printf("How many edges: ");
    scanf("%d", &nEdges);
    printf("How many vertices: ");
    scanf("%d", &nVertices);
    for (i = 0; i < nEdges; i++) {
        printf("\nEdge %d Details: ", i + 1);
        printf("\nEnter Parent Node: ", i + 1);
        scanf("%d", &e[i].parent);
        printf("Enter Child: ");
        scanf("%d", &e[i].child);
        printf("Enter Weight: ");
        scanf("%d", &e[i].weight);
    }

    for (i = 0; i < nEdges; i++) {
        for (j = i+1; j < nEdges; j++) {
            if (e[i].weight > e[j].weight) {    //sorting in ascending according to weight
                temp = e[i];
                e[i] = e[j];
                e[j] = temp;
            }
        }
    }

    int parent[1000]; //or int parent[nVertices + 1];
    for (i = 0; i <= nVertices; i++) {
        parent[i] = i;
    }

    int total = 0;
    printf("\nDisplaying edges in MST: \n");
    for (i = 0; i < nEdges; i++) {
        int u = e[i].parent;
        int v = e[i].child;
        // Check if adding this edge creates a cycle using the union-find algorithm. https://www.youtube.com/watch?v=mHz-mx-8lJ8
        while (parent[u] != u) {   //find u
            u = parent[u];
        }
        while (parent[v] != v) {   //find v
            v = parent[v];
        }
        if (u != v) {
            printf("%d --> %d : %d\n",e[i].parent, e[i].child ,e[i].weight);
            total += e[i].weight;
            parent[u] = v;         // Union(u,v)
        }
    }
    printf("Total Distance of MST: %d\n", total);
}
