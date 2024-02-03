#include<stdio.h>

struct edge{
    int parent, child, weight;
}e[100], temp;
int nEdges, nVertices, total =0, parent[100]; 

void sortByWeight(){
    for(int i=0; i<nEdges; i++){
        for(int j=i+1; j<nEdges; j++){
            if(e[i].weight > e[j].weight){
                temp = e[i];
                e[i] = e[j];
                e[j] = temp;
            }
        }
    }
}

void input(){
    printf("Enter number of edges: ");
    scanf("%d", &nEdges);
    printf("Enter number of vertices: ");
    scanf("%d", &nVertices);
    for(int i=0; i<nEdges; i++){
        printf("\nFor edge %d: \n",i+1);
        printf("Enter parent: ");
        scanf("%d", &e[i].parent);
        printf("Enter chile: ");
        scanf("%d", &e[i].child);
        printf("Enter weight: ");
        scanf("%d", &e[i].weight);
    }
}

void kruskals(){
    for(int i=0;  i<nVertices; i++){
        parent[i] = i;
    }
    int count = 0;
    for(int i=0; i<nEdges; i++){
        int u = e[i].parent;
        int v = e[i].child;

        while(parent[u] != u){
            u = parent[u];
        }
        while(parent[v] != v){
            v = parent[v];
        }
        if(u!=v){
            printf("\n%d --> %d : %d",e[i].parent, e[i].child, e[i].weight);
            total += e[i].weight;
            parent[u] = v;
        }
    }
}

void main(){
    input();
    sortByWeight();
    kruskals();
}
