import numpy as np
import random

class ConnectFour:
    def __init__(self):
        self.board = np.zeros((6, 7), dtype=int)

    def move(self, piece, col):
        for row in range(5, -1, -1):
            if self.board[row][col] == 0:
                self.board[row][col] = piece
                return

    def is_column_full(self, col):
        return self.board[0][col] != 0

    def check_win(self, piece):
        # Check horizontal locations for win
        for c in range(7-3):
            for r in range(6):
                if all(self.board[r, c+i] == piece for i in range(4)):
                    return True

        # Check vertical locations for win
        for r in range(6-3):
            for c in range(7):
                if all(self.board[r+i, c] == piece for i in range(4)):
                    return True

        # Check positively sloped diagonals
        for r in range(6-3):
            for c in range(7-3):
                if all(self.board[r+i, c+i] == piece for i in range(4)):
                    return True

        # Check negatively sloped diagonals
        for r in range(3, 6):
            for c in range(7-3):
                if all(self.board[r-i, c+i] == piece for i in range(4)):
                    return True

        return False

    def print_board(self):
        print("\nCurrent Board:")
        print(np.flip(self.board, 0))
        print("\n")

    def get_valid_column(self):
        while True:
            try:
                col = int(input("Enter column number (1-7): ")) - 1
                if 0 <= col <= 6 and not self.is_column_full(col):
                    return col
                else:
                    print("Column is full or invalid. Please choose another column.")
            except ValueError:
                print("Invalid input. Please enter a number between 1 and 7.")

    def play(self):
        print("Welcome to Connect Four!")
        print("Player is '2' and Computer is '1'.")
        while True:
            self.print_board()

            # Player's move
            print("Player's turn")
            col = self.get_valid_column()
            self.move(2, col)
            if self.check_win(2):
                self.print_board()
                print("Congratulations! You win!")
                break

            # Computer's move
            print("Computer's turn")
            col = random.choice([c for c in range(7) if not self.is_column_full(c)])
            self.move(1, col)
            if self.check_win(1):
                self.print_board()
                print("Computer wins! Better luck next time.")
                break

if __name__ == "__main__":
    game = ConnectFour()
    game.play()
