from itertools import permutations

def solve(word1, word2, result):
    letters = set(word1 + word2 + result)
    if len(letters) > 10:
        return []  # Too many letters to be assigned to unique digits

    solutions = []
    for perm in permutations(range(10), len(letters)):
        assigned = dict(zip(letters, perm))

        # Check for leading zeros
        if assigned[word1[0]] == 0 or assigned[word2[0]] == 0 or assigned[result[0]] == 0:
            continue

        # Convert words to numbers based on current assignment
        num1 = sum(assigned[char] * (10 ** (len(word1) - i - 1)) for i, char in enumerate(word1))
        num2 = sum(assigned[char] * (10 ** (len(word2) - i - 1)) for i, char in enumerate(word2))
        num3 = sum(assigned[char] * (10 ** (len(result) - i - 1)) for i, char in enumerate(result))

        # Check if the equation is satisfied
        if num1 + num2 == num3:
            solutions.append((num1, num2, num3))

    return solutions

word1 = "send"
word2 = "more"
result = "money"

solution = solve(word1, word2, result)
for sol in solution:
    print(sol)