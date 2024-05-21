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
        b = self.board
        for c in range(7-3):
            for r in range(6):
                if all(b[r][c+i] == piece for i in range(4)): return True
        for r in range(6-3):
            for c in range(7):
                if all(b[r+i][c] == piece for i in range(4)): return True
        for r in range(6-3):
            for c in range(7-3):
                if all(b[r+i][c+i] == piece for i in range(4)): return True
                if all(b[r+3-i][c+i] == piece for i in range(4)): return True
        return False

    def print_board(self):
        print("\n".join(" ".join(map(str, row)) for row in self.board) + "\n")

    def play(self):
        while True:
            self.print_board()
            col = int(input("Enter column number (1-7): ")) - 1
            while col < 0 or col > 6 or self.is_column_full(col):
                col = int(input("Column full or invalid. Enter again (1-7): ")) - 1
            self.move(2, col)
            if self.check_win(2):
                self.print_board()
                print("You win!")
                return
            col = random.choice([c for c in range(7) if not self.is_column_full(c)])
            self.move(1, col)
            if self.check_win(1):
                self.print_board()
                print("Computer wins!")
                return

game = ConnectFour()
game.play()
