import numpy as np
import random

class ConnectFour:
    def __init__(self):
        self.board = np.zeros((6, 7), dtype=int)
        self.stacks = [5] * 7
        self.player_piece = 1
        self.computer_piece = 2

    def print_board(self):
        print(self.board[::-1])

    def move(self, column):
        if self.stacks[column] < 0:
            print("Column is full. Try another column.")
            return False

        self.board[self.stacks[column], column] = self.player_piece
        self.stacks[column] -= 1
        return True

    def computer_move(self):
        column = random.randint(0, 6)
        while self.stacks[column] < 0:
            column = random.randint(0, 6)
        self.board[self.stacks[column], column] = self.computer_piece
        self.stacks[column] -= 1

    def check_winner(self):
        # Check rows
        for row in range(6):
            for col in range(4):
                if self.board[row, col] == self.board[row, col+1] == self.board[row, col+2] == self.board[row, col+3] != 0:
                    return self.board[row, col]

        # Check columns
        for col in range(7):
            for row in range(3):
                if self.board[row, col] == self.board[row+1, col] == self.board[row+2, col] == self.board[row+3, col] != 0:
                    return self.board[row, col]

        # Check diagonals
        for row in range(3):
            for col in range(4):
                if self.board[row, col] == self.board[row+1, col+1] == self.board[row+2, col+2] == self.board[row+3, col+3] != 0:
                    return self.board[row, col]

        for row in range(3):
            for col in range(3, 7):
                if self.board[row, col] == self.board[row+1, col-1] == self.board[row+2, col-2] == self.board[row+3, col-3] != 0:
                    return self.board[row, col]

        return 0

    def play(self):
        winner = 0
        while winner == 0:
            self.print_board()
            column = int(input("Enter column number (0-6): "))
            if not self.move(column):
                continue
            winner = self.check_winner()
            if winner != 0:
                break
            self.computer_move()
            winner = self.check_winner()

        self.print_board()
        if winner == self.player_piece:
            print("Congratulations! You win!")
        elif winner == self.computer_piece:
            print("Computer wins!")
        else:
            print("It's a draw!")

# Example usage
game = ConnectFour()
game.play()
