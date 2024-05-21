from collections import defaultdict

def water_jug_solver(x, y):
    if (x, y) in visited:
        return False

    print(x, y)
    visited[(x, y)] = True

    if x == aim or y == aim:
        return True

    # Generate all possible next states and check each one
    return (water_jug_solver(0, y) or
            water_jug_solver(x, 0) or
            water_jug_solver(jug1, y) or
            water_jug_solver(x, jug2) or
            water_jug_solver(x + min(y, jug1 - x), y - min(y, jug1 - x)) or
            water_jug_solver(x - min(x, jug2 - y), y + min(x, jug2 - y)))

jug1 = int(input("Enter capacity of jug1: "))
jug2 = int(input("Enter capacity of jug2: "))
aim = int(input("Enter the desired aim: "))

visited = defaultdict(bool)

print("\nSteps:")
if not water_jug_solver(0, 0):
    print("No solution found.")
