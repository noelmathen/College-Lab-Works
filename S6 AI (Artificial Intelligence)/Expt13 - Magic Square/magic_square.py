#MAGIC SQUARE
def generate_magic_square(n):
    magic_square = [[0] * n for _ in range(n)]

    num = 1
    i, j = 0, n // 2

    while num <= n * n:
        magic_square[i][j] = num
        num += 1
        newi, newj = (i - 1) % n, (j + 1) % n
        if magic_square[newi][newj]:
            i += 1
        else:
            i, j = newi, newj

    return magic_square

def print_magic_square(magic_square):
    n = len(magic_square)
    for i in range(n):
        for j in range(n):
            print(magic_square[i][j], end="\t")
        print()

# Test the function with odd order
n = int(input("Enter the order of the Magic Square : "))
magic_square = generate_magic_square(n)
print(f"Magic Square of order {n}:")
print_magic_square(magic_square)
