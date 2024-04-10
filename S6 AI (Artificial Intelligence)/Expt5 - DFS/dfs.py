def dfs(graph, node, visited):
    if node not in visited:
        print(node, end=" ")
        visited.add(node)
        for neighbor in graph[node]:
            dfs(graph, neighbor, visited)

if __name__ == '__main__':
    graph = {}
    n = int(input("Enter the number of nodes: "))
    for i in range(n):
        node = input(f"Enter node {i}: ")
        neighbors = input(f"Enter neighbors of node {node} separated by space: ").split()
        graph[node] = neighbors

    start = input("Enter the start node for DFS traversal: ")
    dfs(graph, start, set())
