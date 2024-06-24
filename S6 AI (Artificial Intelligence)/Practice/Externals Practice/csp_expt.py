import random

def select_unassigned_variables(assignments, variables):
    for var in variables:
        if var not in assignments:
            return var
    return None


def consistent(var, value, assignments, constraints):
    for constraint in constraints:
        if var in constraint[0]:
            related_var = constraint[0][0] if constraint[0][1]==var else constraint[0][1]
            if related_var in assignments and assignments[related_var]==value:
                return False
    return True


def backtrack_search(assignments, variables, domain, constraints):
    if len(assignments)==len(variables):
        return assignments
    
    var = select_unassigned_variables(assignments, variables)
    if var is None:
        return None
    
    random.shuffle(domain)
    for value in domain:
        assignments[var]=value
        if consistent(var, value, assignments, constraints):
            result = backtrack_search(assignments, variables, domain, constraints)
            if result is not None:
                return result
        assignments[var]=None
            
    


assignments = {}
variables = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H']
domain = ['Monday', 'Tuesday', 'Wednesday']
constraints = {
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
}

solution = backtrack_search(assignments, variables, domain, constraints)
print(solution)