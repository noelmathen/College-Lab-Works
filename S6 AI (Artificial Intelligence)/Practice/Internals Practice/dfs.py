def input_graph():
    for i in range(n):
        graph[i] = list(map(int, input().split()))

def bfs(start):
    visited[start]=1
    print(start, end=" ")
    for i in range(n):
        if graph[start][i]==1 and not visited[i]:
            bfs(i)

n= int(input('Enter number of nodes: '))
graph = [[0]*n for _ in range(n)]
visited = [0]*n
input_graph()
start = int(input('ENter the starting node: '))
print('bfs path is: ', end="")
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
# 0 1 1 1 0
# 1 0 0 0 0
# 1 0 0 0 1
# 1 0 0 0 0
# 0 0 1 0 0
# Output of this will be: 0 1 2 4 3


##Example 2:
# n = 5
# graph = [
#     [0, 1, 1, 1, 0],
#     [1, 0, 0, 0, 1],
#     [1, 0, 0, 0, 0],
#     [1, 0, 0, 0, 0],
#     [0, 1, 0, 0, 0]
# ] 
# 0 1 1 1 0
# 1 0 0 0 1
# 1 0 0 0 0
# 1 0 0 0 0
# 0 1 0 0 0
# Output of this will be: 0 1 4 2 3
