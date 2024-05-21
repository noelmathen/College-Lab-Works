from collections import deque

def input_graph():
    print('Enter the adjacency matrix of the graph: ')
    for i in range(n):
        graph[i] = list(map(int, input().split()))

def bfs(start):
    queue = deque([start])
    visited[start] = 1
    while queue:
        node = queue.popleft()
        print(node, end=" ")
        for i in range(n):
            if graph[node][i] == 1 and not visited[i]:
                queue.append(i)
                visited[i] = 1

n = int(input('Enter the number of nodes: '))
graph = [[0] * n for _ in range(n)]
visited = [0] * n
input_graph()
start = int(input('Enter the starting node: '))
print(f'The path of BFS from node {start} is: ', end="")
bfs(start)


#If u don't want to give graph as input, code it directly:
#Comment line number 13, 14, 16 and paste this instead:

##Example 1:
# n = 5
# graph = [
#     [0, 1, 1, 1, 0],
#     [1, 0, 0, 0, 0],
#     [1, 0, 0, 0, 1],
#     [1, 0, 0, 0, 0],
#     [0, 0, 1, 0, 0]
# ]
# Output of this will be: 0 1 2 3 4


##Example 2:
# n = 5
# graph = [
#     [0, 1, 1, 1, 0],
#     [1, 0, 0, 0, 1],
#     [1, 0, 0, 0, 0],
#     [1, 0, 0, 0, 0],
#     [0, 1, 0, 0, 0]
# ] 
# Output of this will be: 0 1 2 3 4