def takeInput():
    n = int(input("Enter the number of cities: "))
    dist = []
    print("Enter the adjacency matrix:")
    for _ in range(n):
        dist.append(list(map(int, input().split())))
    return n, dist

def tsp(city, count, path, currentCost, dist, visited, n, minCost, minPath):
    visited[city] = True
    path.append(city)
    if count == n - 1 and dist[city][0] != 0:
        totalCost = currentCost + dist[city][0]
        if totalCost < minCost[0]:
            minCost[0] = totalCost
            minPath[:] = path[:]
    else:
        for nextCity in range(n):
            if not visited[nextCity] and dist[city][nextCity] != 0:
                tsp(nextCity, count + 1, path, currentCost + dist[city][nextCity], dist, visited, n, minCost, minPath)
    visited[city] = False
    path.pop()

INF = 99999
n, dist = takeInput()
minCost = [INF]
minPath = []
visited = [False] * n
tsp(0, 0, [], 0, dist, visited, n, minCost, minPath)

print(f"The cost of the most efficient tour = {minCost[0]}")
print("Most efficient path: ", " -> ".join(map(str, minPath + [minPath[0]])))





# TEST CASES:
# 0 2 0 12 5
# 2 0 4 8 0
# 0 4 0 3 3
# 12 8 3 0 10
# 5 0 3 10 0
# int dist[MAX][MAX] = {  { 0, 2, 0, 12,  5},
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
# int dist[MAX][MAX] = {  {0, 10, 15, 20},
#                         {5, 0, 9, 10},
#                         {6, 13, 0, 12},
#                         {8, 8, 9 , 0}};
# int n=4;  
#  0->1->3->2->0  mincost: 35