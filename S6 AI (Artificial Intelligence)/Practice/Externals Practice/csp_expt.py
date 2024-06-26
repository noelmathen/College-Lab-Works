import random


def select_unassigned_variable(variables, assignment):
    for var in variables:
        if var not in assignment:
            return var
    return None


def is_consistent(var, value, assignment, constraints):
    for constraint in constraints:
        if var in constraint[0]:
            related_var = constraint[0][0] if constraint[0][1]==var else constraint[0][1]
            if related_var in assignment and assignment[related_var]==var:
                return False
    return True


def csp(variables, domain, constraints, assignment):
    if len(assignment) == len(variables):
        return assignment
    
    var = select_unassigned_variable(variables, assignment)
    if var is None:
        return None
    
    random.shuffle(domain)
    for value in domain:
        assignment[var] = value
        if is_consistent(var, value, assignment, constraints):
            result = csp(variables, domain, constraints, assignment)
            if result is not None:
                return result
        assignment[var] = None


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

print(f"The result is: {csp(variables, domain, constraints, assignment)}")