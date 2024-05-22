#Tic Tac Toe
board = [" "] * 10
running, win, draw = 0, 1, -1
game = running
player = 1

def drawboard():
  print("\n".join([
      f" {board[1]} | {board[2]} | {board[3]} ",
      f"---|---|---",
      f" {board[4]} | {board[5]} | {board[6]} ",
      f"---|---|---",
      f" {board[7]} | {board[8]} | {board[9]} "]))

def checkwin():
  win = [(1,2,3), (4,5,6), (7,8,9), (1,4,7), (2,5,8), (3,6,9), (1,5,9), (3,5,7)]
  for a,b,c in win:
    if board[a]==board[b]==board[c] and board[a]!= ' ':
      return win
  return draw if ' ' not in board[1:] else running

drawboard()

while game==running:
  print(f"Player {'X' if player==1 else 'O'}'s chance")
  choice = int(input("Enter position: "))
  if choice>9 or choice<0:
    print("Enter valid choice")
    drawboard()
    continue
  if board[choice] == ' ':
    board[choice] = 'X' if player==1 else 'O'
    player = 2 if player == 1 else 1
    game = checkwin()
    drawboard()
  else:
    print("Position already filled")
    drawboard()

if game==draw:
  print("Draw!")
else:
  print(f"Player {1 if player==2 else 2} wins")