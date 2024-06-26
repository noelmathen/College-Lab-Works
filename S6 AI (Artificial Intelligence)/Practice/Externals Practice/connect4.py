import numpy as np
import random

board = np.zeros((6, 7), dtype=int)

def print_board():
    print("Board: ")
    print(np.flip(board, 0))
    print("\n")
    
    
def is_not_free(col):
    return board[0][col] != 0 
    

def input_valid_column():
    while True:
        try:
            col = int(input("Enter a valid colum(1-7): ")) - 1
            if 0<= col <=6 and not is_not_free(col):
                return col
        except:
            print("column input invalid")
            
            
def move(piece, col):
    for row in range(5, -1, -1):
        if board[row][col] == 0:
            board[row][col] = piece
            return


def check_win(piece):
    for c in range(4):
        for r in range(6):
            if all(board[r][c+i]==piece for i in range(4)):
                return True
            
    for r in range(3):
        for c in range(7):
            if all(board[r+i][c]==piece for i in range(4)):
                return True
            
    for r in range(3):
        for c in range(4):
            if all(board[r+i][c+i]==piece for i in range(4)):
                return True
            
    for r in range(3, 6):
        for c in range(4):
            if all(board[r-i][c+i]==piece for i in range(4)):
                return True
            
    return False


while True:
    print_board()
    
    #Player:
    print("Player's chance: ")
    col = input_valid_column()
    move(2, col)
    if check_win(2):
        print("Player won!")
        print_board()
        break
    
    #Computer:
    print("Computer's chance: ")
    col = random.choice([c for c in range(7) if not is_not_free(c)])
    move(1, col)
    if check_win(1):
        print("Computer won!")
        print_board()
        break