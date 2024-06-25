n = int(input('Enter the order of square needed (odd numbers): '))
board = [[0] * n for _ in range(n)]
num, i, j = 1, 0, n // 2

while num <= n * n:
    board[i][j] = num
    num += 1
    newi, newj = (i - 1) % n, (j + 1) % n
    if board[newi][newj] != 0:  # If the new position is already occupied
        i += 1
    else:
        i, j = newi, newj
        
magic_constant = n * (n**2 + 1) // 2
print(f"The magic constant is: {magic_constant}")

print(f"Magic Square of order {n}:")
for row in board:
    print("\t".join(map(str, row)))
