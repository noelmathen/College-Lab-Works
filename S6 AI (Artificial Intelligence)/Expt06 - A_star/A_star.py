# Path: a_star_algorithm.py

def a_star_algorithm(graph, start_node, stop_node, heuristics):
    open_set = {start_node}
    closed_set = set()
    g = {start_node: 0}
    parents = {start_node: start_node}

    while open_set:
        n = min(open_set, key=lambda v: g[v] + heuristics[v])

        if n == stop_node:
            path = []
            while parents[n] != n:
                path.append(n)
                n = parents[n]
            path.append(start_node)
            path.reverse()
            return path

        open_set.remove(n)
        closed_set.add(n)

        for m, weight in graph.get(n, []):
            if m in closed_set:
                continue
            tentative_g = g[n] + weight

            if m not in open_set:
                open_set.add(m)
            elif tentative_g >= g[m]:
                continue

            parents[m] = n
            g[m] = tentative_g

    return None

if __name__ == "__main__":
    graph = eval(input("Enter your graph: "))
    print("\nThe Graph you entered is: ")
    for key, value in graph.items():
        print(f"{key}: {value}")

    start_node = input("\nEnter the start node: ")
    stop_node = input("Enter the stop node: ")
    heuristics = eval(input("\nEnter the key-value corresponding to parent and its heuristics: "))

    path = a_star_algorithm(graph, start_node, stop_node, heuristics)

    if path:
        print(f"\nPath found: {path}")
    else:
        print('Path does not exist!')
