# Path: ao_star_algorithm.py

def ao_star_algorithm(graph, start_node, goal_node, heuristics):
    open_set = {start_node}
    closed_set = set()
    g = {start_node: 0}
    parents = {start_node: start_node}

    while open_set:
        n = min(open_set, key=lambda v: g[v] + heuristics[v])
        open_set.remove(n)
        closed_set.add(n)

        if n == goal_node:
            path = []
            while parents[n] != n:
                path.append(n)
                n = parents[n]
            path.append(start_node)
            path.reverse()
            return path

        for successors, weight in graph.get(n, []):
            combined_cost = g[n] + weight
            is_updated = False

            for m in successors:
                if m in closed_set:
                    continue

                if m not in open_set:
                    open_set.add(m)
                    parents[m] = n
                    g[m] = combined_cost
                    is_updated = True
                elif combined_cost < g[m]:
                    g[m] = combined_cost
                    parents[m] = n
                    is_updated = True

            if is_updated:
                for m in successors:
                    closed_set.discard(m)

    return None

if __name__ == "__main__":
    graph = eval(input("Enter your AND-OR graph: "))
    print("\nThe Graph you entered is: ")
    for key, value in graph.items():
        print(f"{key}: {value}")

    start_node = input("\nEnter the start node: ")
    goal_node = input("Enter the goal node: ")
    heuristics = eval(input("\nEnter the key-value corresponding to node and its heuristics: "))

    path = ao_star_algorithm(graph, start_node, goal_node, heuristics)

    if path:
        print(f"\nPath found: {path}")
    else:
        print('Path does not exist!')
