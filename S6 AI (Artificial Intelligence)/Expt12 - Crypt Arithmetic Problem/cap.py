#CRYPT ARITHMETIC PROBLEM
from itertools import permutations

def find_value(letter):
    return ord(letter.lower()) - ord('a') + 1

def solve(word1, word2, result):
    letters = set(word1 + word2 + result)
    if len(letters) > 10:
        return 0  # Stop searching if more than 10 unique characters
    
    solutions = []
    for perm in permutations(range(10)):
        assigned = {}
        cur_letter = 0
        for char in letters:
            if char not in assigned:
                assigned[char] = perm[cur_letter]
                cur_letter += 1

        if assigned[word1[0]] == 0 or assigned[word2[0]] == 0 or assigned[result[0]] == 0:
            continue  # Skip if leading zeros

        num1 = sum(assigned[char] * (10 ** (len(word1) - i - 1)) for i, char in enumerate(word1))
        num2 = sum(assigned[char] * (10 ** (len(word2) - i - 1)) for i, char in enumerate(word2))
        res = sum(assigned[char] * (10 ** (len(result) - i - 1)) for i, char in enumerate(result))

        if num1 + num2 == res:
            solutions.append((num1, num2, res))

    return solutions

if __name__ == "__main__":
    word1 = "send"
    word2 = "more"
    result = "money"

    solutions = solve(word1, word2, result)
    if solutions:
        print("Solutions:")
        for sol in solutions:
            print(sol)
    else:
        print("No solutions found.")