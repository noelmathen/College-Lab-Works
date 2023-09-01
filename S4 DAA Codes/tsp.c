#include <stdio.h>
#include <stdbool.h>
#define MAX 10
#define INF 999999

int dist[MAX][MAX] = {0};
int n; 
int minCost = INF, minPath[MAX];
bool visited[MAX];

void takeInput() {
    printf("Enter the number of cities: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &dist[i][j]);
        }
    }
}

void tsp(int city, int count, int path[], int currentCost) {    //city = current city/node, count = no. of visited cities so for, path[] - An array that stores the current path being explored, current_cost = The current cost of the path being explored.
    visited[city] = true;   //mark the current city as visited
    path[count] = city; //keeps track of the current path being explored
    if (count == n - 1 && dist[city][0] != 0) { //This condition checks if all cities have been visited (count == n - 1) and if there exists a valid return path to the starting city (dist[city][0] != 0). If this condition is true, it means a valid tour has been found.
        // Valid path found
        int totalCost = currentCost + dist[city][0];    //updates the total cost
        if (totalCost < minCost) {  //find whether this is the mininum
            minCost = totalCost;
            for (int i = 0; i < n; i++) {
                minPath[i] = path[i];   //since this is a path which gives a min cost, this path is stored as the min path
            }
        }
    } 
    else {
        for (int nextCity = 0; nextCity < n; nextCity++) {
            if (!visited[nextCity] && dist[city][nextCity] != 0) {  //if the next city is not visited (!visited[nextCity]) and if there exist a path btween the current city and the next city( dist[][]!=0 )
                tsp(nextCity, count + 1, path, currentCost + dist[city][nextCity]); //recursive call. 
            }
        }
    }
    visited[city] = false;  // Before returning from the recursive call, the function marks the current city as unvisited by setting the corresponding element in the visited array to false. This is necessary to allow other paths to explore the current city again.
}

void printSolution() {
    printf("The cost of the most efficient tour = %d\n", minCost);
    printf("Most efficient path: ");
    for (int i = 0; i < n; i++) {
        printf("%d", minPath[i]);
        if (i != n - 1) {
            printf(" -> ");
        }
    }
    printf(" -> %d\n", minPath[0]); //to print the final(which is the initial) node. TSP starts and ends at the same node.
}

void main() {
    takeInput();
    int path[MAX];
    tsp(0, 0, path, 0); // Start from node 0
    printSolution();
}

// TEST CASES:
// int dist[MAX][MAX] = {  { 0, 2, 0, 12,  5},
//                         { 2, 0, 4,  8,  0},
//                         { 0, 4, 0,  3,  3},
//                         {12, 8, 3,  0, 10},
//                         { 5, 0, 3, 10,  0}};
// int n=5; 
//  0->1->3->2->4->0  mincost: 21


// int dist[MAX][MAX] = {  {0, 10, 15, 20},
//                         {5, 0, 9, 10},
//                         {6, 13, 0, 12},
//                         {8, 8, 9 , 0}};
// int n=4;  
//  0->1->3->2->0  mincost: 35

