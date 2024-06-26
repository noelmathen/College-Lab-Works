from itertools import permutations

def cap(word1, word2, result):
    letters = set(word1+word2+result)
    if len(letters)>10:
        return []
    
    for perm in permutations(range(10), len(letters)):
        assigned = dict(zip(letters, perm))
        if any(assigned[word[0]]==0 for word in [word1, word2, result]):
            continue
        
        num1 = int(''.join(str(assigned[char])  for char in word1))
        num2 = int(''.join(str(assigned[char])  for char in word2))
        num3 = int(''.join(str(assigned[char])  for char in result))
        
        if num1+num2==num3:
            return [(num1, num2, num3)]

    return []


word1, word2, result = "send", "more", "money"
answer = cap(word1, word2, result)
for sol in answer:
    print(sol)