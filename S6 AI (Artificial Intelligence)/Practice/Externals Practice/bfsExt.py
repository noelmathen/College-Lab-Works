from collections import deque

def input_graph():
    print("Enter the graph: ")
    for i in range(n):
        graph[i] = list(map(int, input().split()))
        

def bfs(start):
    queue = deque([start])
    visited[start]=1
    while queue:
        node = queue.popleft()
        print(node, end=" ")
        for i in range(n):
            if graph[node][i]==1 and not visited[i]:
                queue.append(i)
                visited[i]=1
            

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
print("The bfs path is: ", end="")
bfs(start)