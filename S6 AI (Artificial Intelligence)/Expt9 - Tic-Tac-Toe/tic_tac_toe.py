import random

def create_board():
    return [[' ' for _ in range(3)] for _ in range(3)]

def print_board(board):
    for row in board:
        print('|'.join(row))
        print('-' * 5)

def check_winner(board, player):
    # Check rows and columns
    for i in range(3):
        if all(board[i][j] == player for j in range(3)) or \
           all(board[j][i] == player for j in range(3)):
            return True
    
    # Check diagonals
    if all(board[i][i] == player for i in range(3)) or \
       all(board[i][2-i] == player for i in range(3)):
        return True
    
    return False

def is_board_filled(board):
    for row in board:
        if ' ' in row:
            return False
    return True

def start_game():
    board = create_board()
    players = ['X', 'O']
    current_player = random.choice(players)
    
    while True:
        print_board(board)
        print("Player", current_player, "'s turn")
        row = int(input("Enter row number (0-2): "))
        col = int(input("Enter column number (0-2): "))
        
        if board[row][col] == ' ':
            board[row][col] = current_player
            if check_winner(board, current_player):
                print_board(board)
                print("Player", current_player, "wins!")
                break
            elif is_board_filled(board):
                print_board(board)
                print("It's a draw!")
                break
            else:
                current_player = players[(players.index(current_player) + 1) % 2]
        else:
            print("That spot is already taken. Try again.")

# Start the game
start_game()
