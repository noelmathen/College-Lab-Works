N = int(input("Enter number of queens: "))
board = [[0] * N for _ in range(N)]

def is_safe(row, col):
    # Check this row on left side
    for i in range(col):
        if board[row][i] == 1:
            return False

    # Check upper diagonal on left side
    for i, j in zip(range(row, -1, -1), range(col, -1, -1)):
        if board[i][j] == 1:
            return False

    # Check lower diagonal on left side
    for i, j in zip(range(row, N), range(col, -1, -1)):
        if board[i][j] == 1:
            return False

    return True

def solve_n_queens(col):
    if col >= N:
        return True
    for i in range(N):
        if is_safe(i, col):
            board[i][col] = 1
            if solve_n_queens(col + 1):
                return True
            board[i][col] = 0  # Backtrack
    return False

if solve_n_queens(0):
    for row in board:
        print(row)
else:
    print("Solution does not exist")

