n=0
graph = []
minCost, minPath, visited = 99999, [], []

def takeInput():
    global n, graph, visited
    n=int(input("Enter the number of cities: "))
    print("Enter the adjacency graph: ")
    for _ in range(n):
        graph.append(list(map(int, input().split())))
    visited = [False]*n

def tsp(city, count, path, currentCost):
    global n, graph, minCost, minPath, visited
    visited[city]=True
    path.append(city)
     
    if count==n-1 and graph[city][0]!=0:
        totalCost = currentCost + graph[city][0]
        if totalCost < minCost:
            minCost = totalCost
            minPath[:] = path[:]
            
    else:
        for nextCity in range(n):
            if not visited[nextCity] and graph[city][nextCity]!=0:
                tsp(nextCity, count+1, path, currentCost+graph[city][nextCity])
    visited[city] = False
    path.pop()

takeInput()
tsp(0, 0, [], 0)

print(f"The min cost is: {minCost}")
print("Most efficient path: ", " -> ".join(map(str, minPath + [minPath[0]])))
