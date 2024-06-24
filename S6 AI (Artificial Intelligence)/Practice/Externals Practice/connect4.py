import numpy as np
import random

board = np.zeros((6,7), dtype=int)

def print_board():
    print("\nCurrent board:")
    print(np.flip(board, 0))
    print("\n")
    
def is_column_full(col):
    return board[0][col] != 0

def move(piece, col):
    for r in range(5, -1, -1):
        if board[r][col] == 0:
            board[r][col] = piece
            return
        
def check_win(piece):
    #horizontal
    for c in range(4):
        for r in range(6):
            if all(board[r][c+i]==piece for i in range(4)):
                return True
        
    #vertical
    for r in range(3):
        for c in range(7):
            if all(board[r+i][c]==piece for i in range(4)):
                return True
            
    #positive diagnol
    for r in range(3):
        for c in range(4):
            if all(board[r+i][c+i]==piece for i in range(4)):
                return True
            
    #negative diagnol
    for r in range(3, 6):
        for c in range(4):
            if all(board[r-1][c+i]==piece for i in range(4)):
                return True
            
    return False
    
    
def get_valid_column():
    col = int(input("Enter a column(1-7): ")) - 1
    try:
        if 0<=col<=6 and not is_column_full(col):
            return col
        else:
            print("Error in entered value. try again")
            
    except ValueError:
        print("Incorrect value entered. try again")
    

print("YOU are 2, COPMUTER is 1")
while True:
    print_board()
    
    #Players move:
    print("PLAYER's move:")
    col = get_valid_column()
    move(2, col)
    if check_win(2):
        print_board()
        print("PLAYER won!")
        break
    
    #Computers move:
    print("COMPUTERS's move:")
    col = random.choice([c for c in range(7) if not is_column_full(c)])
    move(1, col)
    if check_win(1):
        print_board()
        print("PLAYER won!")
        break