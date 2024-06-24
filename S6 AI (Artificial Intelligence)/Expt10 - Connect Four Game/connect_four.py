import numpy as np
import random

# Global variables
board = np.zeros((6, 7), dtype=int)

def move(piece, col):
    for row in range(5, -1, -1):
        if board[row][col] == 0:
            board[row][col] = piece
            return

def is_column_full(col):
    return board[0][col] != 0

def check_win(piece):
    # Check horizontal locations for win
    for c in range(4):
        for r in range(6):
            if all(board[r, c+i] == piece for i in range(4)):
                return True

    # Check vertical locations for win
    for r in range(3):
        for c in range(7):
            if all(board[r+i, c] == piece for i in range(4)):
                return True

    # Check positively sloped diagonals
    for r in range(3):
        for c in range(4):
            if all(board[r+i, c+i] == piece for i in range(4)):
                return True

    # Check negatively sloped diagonals
    for r in range(3, 6):
        for c in range(4):
            if all(board[r-i, c+i] == piece for i in range(4)):
                return True

    return False

def print_board():
    print("Current Board:")
    print(np.flip(board, 0))
    print("\n")

def get_valid_column():
    while True:
        try:
            col = int(input("Enter column number (1-7): ")) - 1
            if 0 <= col <= 6 and not is_column_full(col):
                return col
            else:
                print("Column is full or invalid. Please choose another column.\n")
        except ValueError:
            print("Invalid input. Please enter a number between 1 and 7.")

#Main function(beginning of code):
print("Welcome to Connect Four!")
print("Player is '2' and Computer is '1'.\n")
while True:
    print_board()

    # Player's move
    print("PLAYER's turn")
    col = get_valid_column()
    move(2, col)
    if check_win(2):
        print_board()
        print("Congratulations! You win!")
        break

    # Computer's move
    print("\nCOMPUTER's turn")
    col = random.choice([c for c in range(7) if not is_column_full(c)])
    move(1, col)
    if check_win(1):
        print_board()
        print("Computer wins! Better luck next time.")
        break

