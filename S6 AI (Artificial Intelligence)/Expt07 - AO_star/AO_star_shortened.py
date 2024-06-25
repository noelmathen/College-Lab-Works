# This is correct, but not according to what we learned in class, or maams code.

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


## SAMPLE OUTPUT 1
#Input:
# Enter your AND-OR graph: {'A': [(['B', 'C'], 1)], 'B': [(['D'], 2)], 'C': [(['D'], 2)], 'D': []}

# The Graph you entered is:
# A: [(['B', 'C'], 1)]
# B: [(['D'], 2)]
# C: [(['D'], 2)]
# D: []

# Enter the start node: A
# Enter the goal node: D
# Enter the key-value corresponding to node and its heuristics: {'A': 3, 'B': 2, 'C': 2, 'D': 0}

#output:
# Path found: ['A', 'B', 'D']




## SAMPLE OUTPUT 2
#Input:
# Enter your AND-OR graph: {'A': [(['B'], 2), (['C'], 2)], 'B': [(['D'], 1)], 'C': [(['D'], 5)], 'D': []}

# The Graph you entered is:
# A: [(['B'], 2), (['C'], 2)]
# B: [(['D'], 1)]
# C: [(['D'], 5)]
# D: []

# Enter the start node: A
# Enter the goal node: D
# Enter the key-value corresponding to node and its heuristics: {'A': 3, 'B': 2, 'C': 6, 'D': 0}

#output:
# Path found: ['A', 'B', 'D']




## SAMPLE OUTPUT 3
#Input:
# Enter your AND-OR graph: {'A': [(['B'], 1), (['C'], 2)], 'B': [(['D'], 2)], 'C': [(['E'], 3)], 'D': [(['F'], 1)], 'E': [(['F'], 1)], 'F': []}

# The Graph you entered is:
# A: [(['B'], 1), (['C'], 2)]
# B: [(['D'], 2)]
# C: [(['E'], 3)]
# D: [(['F'], 1)]
# E: [(['F'], 1)]
# F: []

# Enter the start node: A
# Enter the goal node: F
# Enter the key-value corresponding to node and its heuristics: {'A': 4, 'B': 3, 'C': 3, 'D': 2, 'E': 2, 'F': 0}

#output:
# Path found: ['A', 'B', 'D', 'F']




## SAMPLE OUTPUT 4
#Input:
# Enter your AND-OR graph: {'A': [(['B'], 1), (['C'], 2)], 'B': [(['D'], 2)], 'C': [(['E'], 3)], 'D': [(['F'], 1)], 'E': [(['G'], 1)], 'F': [], 'G': []}

# The Graph you entered is:
# A: [(['B'], 1), (['C'], 2)]
# B: [(['D'], 2)]
# C: [(['E'], 3)]
# D: [(['F'], 1)]
# E: [(['G'], 1)]
# F: []
# G: []

# Enter the start node: A
# Enter the goal node: H
# Enter the key-value corresponding to node and its heuristics: {'A': 4, 'B': 3, 'C': 3, 'D': 2, 'E': 2, 'F': 1, 'G': 1, 'H': 0}

#output:
# Path does not exist!
