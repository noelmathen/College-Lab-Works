n = int(input('Enter the order of square needed(odd numbers)'))
board = [[0]*n for _ in range(n)]
num, i, j = 1, 0, n//2

while num<=n*n:
    board[i][j], num = num, num+1
    newi, newj = (i-1)%n, (j+1)%n
    if board[newi][newj] != 0:
        i += 1
    else:
        i, j = newi, newj

for row in board:
    print("\t".join(map(str, row)))
