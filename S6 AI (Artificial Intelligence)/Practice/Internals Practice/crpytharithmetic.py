from itertools import permutations

def cap(w1, w2, r):
    letters = set(w1+w2+r)
    if len(letters)>10:
        return []
    
    for perm in permutations(range(10), len(letters)):
        assigned = dict(zip(letters, perm))
        if any(assigned[word[0]] == 0 for word in [w1, w2, r]):
            continue
        
        num1 = int(''.join(str(assigned[char])for char in  w1))
        num2 = int(''.join(str(assigned[char])for char in  w2))
        num3 = int(''.join(str(assigned[char])for char in r))
        
        if num1 + num2 == num3:
            return [(num1, num2, num3)]

w1, w2, r = "send", "more", "money"
solution = cap(w1, w1, r)
for i in solution:
    print(i)