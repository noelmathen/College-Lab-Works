n = int(input('Enter the number of queens: '))
board = [[0]*n for _ in range(n)]

def is_safe(row, col):
    for i in range(col):
        if(board[row][i]==1):
            return False
    
    for i, j in zip(range(row, -1, -1), range(col, -1, -1)):
        if(board[i][j]==1):
            return False
        
    for i, j in zip(range(row, n), range(col, -1, -1)):
        if(board[i][j]==1):
            return False
        
    return True

def solve_n_queen(col):
    if col>=n:
        return True
    for i in range(n):
        if is_safe(i, col):
            board[i][col] = 1
            if solve_n_queen(col+1):
                return True
            board[i][col] = 0
    return False

if solve_n_queen(0):
    for row in board:
        print(row)      
else:
    print('No solution is found')