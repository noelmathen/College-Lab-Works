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


n = int(input("Enter the number of nodes: "))
graph = [[0]*n for _ in range(n)]
visited = [0]*n
input_graph()

start = int(input("Enter the start node: "))
print("The DFS path is: ", end="")
dfs(start)