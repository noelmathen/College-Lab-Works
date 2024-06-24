graph = []
minCost = 99999
minPath = []
visited = []

def takeInput():
    global n, graph, visited
    n = int(input("Enter the number of cities: "))
    graph = []
    print("Enter the adjacency matrix:")
    for _ in range(n):
        graph.append(list(map(int, input().split())))
    visited = [False] * n

def tsp(city, count, path, currentCost):
    global minCost, minPath, graph, visited, n
    visited[city] = True
    path.append(city)
    
    if count == n - 1 and graph[city][0] != 0:
        totalCost = currentCost + graph[city][0]
        if totalCost < minCost:
            minCost = totalCost
            minPath[:] = path[:]
    else:
        for nextCity in range(n):
            if not visited[nextCity] and graph[city][nextCity] != 0:
                tsp(nextCity, count + 1, path, currentCost + graph[city][nextCity])
    
    visited[city] = False
    path.pop()

# Main function
takeInput()
tsp(0, 0, [], 0)

print(f"The cost of the most efficient tour = {minCost}")
print("Most efficient path: ", " -> ".join(map(str, minPath + [minPath[0]])))





# TEST CASES:
# 0 2 0 12 5
# 2 0 4 8 0
# 0 4 0 3 3
# 12 8 3 0 10
# 5 0 3 10 0
# int graph[MAX][MAX] = {  { 0, 2, 0, 12,  5},
#                         { 2, 0, 4,  8,  0},
#                         { 0, 4, 0,  3,  3},
#                         {12, 8, 3,  0, 10},
#                         { 5, 0, 3, 10,  0}};
# int n=5; 
#  0->1->3->2->4->0  mincost: 21



# 0 10 15 20
# 5 0 9 10
# 6 13 0 12
# 8 8 9 0
# int graph[MAX][MAX] = {  {0, 10, 15, 20},
#                         {5, 0, 9, 10},
#                         {6, 13, 0, 12},
#                         {8, 8, 9 , 0}};
# int n=4;  
#  0->1->3->2->0  mincost: 35