from collections import deque

def bfs(graph, start):
    visited = set()
    queue = deque([start])
    visited.add(start)

    while queue:
        node = queue.popleft()
        print(node, end=" ")

        for neighbor in graph[node]:
            if neighbor not in visited:
                queue.append(neighbor)
                visited.add(neighbor)

if __name__=='__main__':
    graph = {}
    n = int(input("Enter the number of nodes: "))
    for i in range(n):
        node = input(f"Enter node {i}: ")
        neighbors = input(f"Enter neighbors of node {node} separated by space: ").split()
        graph[node] = neighbors

    start = input("Enter the start node for BFS traversal: ")
    bfs(graph, start)
