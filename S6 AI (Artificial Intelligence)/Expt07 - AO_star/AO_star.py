# Not sure whether this is correct

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


# Output:
# Enter the key-value corresponding to parent and its heuristics : {'A': -1, 'B': 4, 'C': 2, 'D': 3, 'E': 6, 'F': 8, 'G': 2, 'H': 0, 'I': 0, 'J': 0}

# Enter your graph : {'A': {'AND': [('C', 'D')], 'OR': ['B']}, 'B': {'OR': ['E', 'F']}, 'C': {'OR': ['G'], 'AND': [('H', 'I')]}, 'D': {'OR': ['J']}}

# Enter the start node : A

# Enter the goal node : J


# Expanding Node: A
# Expanding Node: B
# Expanding Node: C
# Expanding Node: D

# Nodes which gives optimal cost from the start node  A  are :
# CD -> HI -> J

# Optimal cost is  5