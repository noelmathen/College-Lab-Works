import random

def backtrack_search(assignment, variables, domain, constraints):
    if len(assignment) == len(variables):
        return assignment.copy()

    var = select_unassigned_variable(assignment, variables)
    if var is None:
        return None

    random.shuffle(domain)
    for value in domain:
        assignment[var] = value
        if is_consistent(var, value, assignment, constraints):
            result = backtrack_search(assignment, variables, domain, constraints)
            if result is not None:
                return result
        assignment[var] = None

    return None

def select_unassigned_variable(assignment, variables):
    for var in variables:
        if var not in assignment:
            return var
    return None

def is_consistent(var, value, assignment, constraints):
    for constraint in constraints:
        if var in constraint[0]:
            related_var = constraint[0][0] if constraint[0][1] == var else constraint[0][1]
            if related_var in assignment and assignment[related_var] == value:
                return False
    return True

if __name__ == "__main__":
    assignment = {}
    variables = ['A', 'B', 'C', 'D', 'E', 'F', 'G']
    domain = ['Monday', 'Tuesday', 'Wednesday']
    constraints = [
        (('A', 'B'),),
        (('A', 'C'),),
        (('B', 'C'),),
        (('B', 'D'),),
        (('B', 'E'),),
        (('D', 'E'),),
        (('C', 'E'),),
        (('C', 'F'),),
        (('E', 'F'),),
        (('E', 'G'),),
        (('F', 'G'),)
    ]
    solution = backtrack_search(assignment, variables, domain, constraints)
    print(solution)
