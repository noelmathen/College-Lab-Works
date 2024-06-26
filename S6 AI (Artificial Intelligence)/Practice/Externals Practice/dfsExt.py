def input_graph():
    print("Enter the graph: ")
    for i in range(n):
        graph[i] = list(map(int, input().split()))
        

def dfs(start):
    visited[start]=1
    print(start, end=" ")
    for i in range(n):
        if graph[start][i]==1 and not visited[i]:
            dfs(i)

n = 5
graph = [
    [0, 1, 1, 1, 0],
    [1, 0, 0, 0, 0],
    [1, 0, 0, 0, 1],
    [1, 0, 0, 0, 0],
    [0, 0, 1, 0, 0]
]
visited = [0]*n
# input_graph()

start = 0
print("The DFS path is: ", end="")
dfs(start)