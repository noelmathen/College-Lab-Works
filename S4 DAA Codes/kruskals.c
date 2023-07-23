#include <stdio.h>
#include <stdlib.h>

// Structure to represent an edge in the graph
struct Edge {
    int source, destination, weight;
};

// Function prototypes
void kruskalMST(struct Edge graph[], int V, int E);
int find(int parent[], int i);
void unionSets(int parent[], int rank[], int x, int y);

int main() {
    int V, E;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    printf("Enter the number of edges: ");
    scanf("%d", &E);

    struct Edge* graph = (struct Edge*)malloc(E * sizeof(struct Edge));

    printf("Enter the source, destination, and weight of each edge:\n");
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &graph[i].source, &graph[i].destination, &graph[i].weight);
    }

    kruskalMST(graph, V, E);

    free(graph);
    return 0;
}

// Comparison function used by qsort() to sort edges in non-decreasing order of their weight
int compareEdges(const void* a, const void* b) {
    struct Edge* edge1 = (struct Edge*)a;
    struct Edge* edge2 = (struct Edge*)b;
    return edge1->weight - edge2->weight;
}

// Kruskal's algorithm to find the Minimum Spanning Tree
void kruskalMST(struct Edge graph[], int V, int E) {
    // Sort all the edges in non-decreasing order of their weight
    qsort(graph, E, sizeof(struct Edge), compareEdges);

    int* parent = (int*)malloc(V * sizeof(int));
    int* rank = (int*)malloc(V * sizeof(int));

    // Initialize parent and rank arrays
    for (int i = 0; i < V; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    struct Edge* MST = (struct Edge*)malloc((V - 1) * sizeof(struct Edge)); // MST will have V-1 edges
    int edgeCount = 0; // Number of edges included in the MST
    int i = 0; // Index variable for the sorted edges

    while (edgeCount < V - 1 && i < E) {
        struct Edge nextEdge = graph[i++];

        int sourceParent = find(parent, nextEdge.source);
        int destParent = find(parent, nextEdge.destination);

        // If including this edge does not create a cycle, add it to the MST
        if (sourceParent != destParent) {
            MST[edgeCount++] = nextEdge;
            unionSets(parent, rank, sourceParent, destParent);
        }
    }

    printf("Minimum Spanning Tree:\n");
    for (int j = 0; j < edgeCount; j++) {
        printf("%d -- %d : %d\n", MST[j].source, MST[j].destination, MST[j].weight);
    }

    free(MST);
    free(rank);
    free(parent);
}

// Find the subset of an element 'i'
int find(int parent[], int i) {
    if (parent[i] != i) {
        parent[i] = find(parent, parent[i]);
    }
    return parent[i];
}

// Perform union of two subsets 'x' and 'y'
void unionSets(int parent[], int rank[], int x, int y) {
    int xroot = find(parent, x);
    int yroot = find(parent, y);

    if (rank[xroot] < rank[yroot]) {
        parent[xroot] = yroot;
    } else if (rank[xroot] > rank[yroot]) {
        parent[yroot] = xroot;
    } else {
        parent[yroot] = xroot;
        rank[xroot]++;
    }
}














