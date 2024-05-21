from collections import defaultdict

def water_jug(x, y):
    if((x, y) in visited):
        return False
    
    print(x, y)
    visited[(x, y)]=True
    
    if x==aim or y==aim:
        return True
    
    return(water_jug(x, 0) or
           water_jug(0, y) or
           water_jug(jug1, y) or
           water_jug(x, jug2) or
           water_jug(x+min(y, jug1-x), y-min(y, jug1-x)) or
           water_jug(x-min(x, jug2-y), y+min(x, jug2-y)) 
    )


jug1 = int(input('Enter capacity of jug 1: '))
jug2 = int(input('Enter capacity of jug 2: '))
aim = int(input('Enter desired capacity: '))

visited = defaultdict(bool)

print("\nSteps:")
if not water_jug(0, 0):
    print('Solution not found!')
