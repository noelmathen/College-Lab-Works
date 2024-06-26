def is_safe(row, col):
    for i in range(row):
        if board[row][i]==1:
            return False
    
    for i, j in zip(range(col, -1, -1), range(row, -1, -1)):
        if board[i][j]==1:
            return False
        
    for i, j in zip(range(row, n), range(row, -1, -1)):
        if board[i][j]==1:
            return False
    
    return True
        

def solve_n_queens(col):
    if col>=n:
        return True

    for i in range(n):
        if is_safe(i, col):
            board[i][col]=1
            if solve_n_queens(col+1):
                return True
            board[i][col]=0
    return False


n = int(input("Enter the number of queens: "))
board = [[0]*n for _ in range(n)]

if solve_n_queens(0):
    for row in board:
        print(row)
else:
    print("Solution not found!")