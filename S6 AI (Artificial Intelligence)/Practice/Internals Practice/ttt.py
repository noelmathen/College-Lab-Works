board, running, draw, win, player = [' ']*10, 0, -1, 1, 1
game=running

def DrawBoard():
    print("\n".join([
        (f" {board[1]} | {board[2]} | {board[3]} "),
        ("---|---|---"),
        (f" {board[4]} | {board[5]} | {board[6]} "),
        ("---|---|---"),
        (f" {board[7]} | {board[8]} | {board[9]} "),
    ]))
    
def CheckWin():
    win = [(1,2,3), (4,5,6), (7,8,9), (1,4,7), (2,5,8), (3,6,9), (1,5,9), (3,5,7)]
    for a, b, c in win:
        if board[a]==board[b]==board[c]!=' ':
            return win
    return draw if ' ' not in board[1:] else running
    
DrawBoard()

while game==running:
    print(f"Player {player}'s chance ({'X' if player==1 else 'O'}): ")
    choice = int(input('Enter a position[1-9]: '))
    if choice<1 or choice>9:
        print('Invalid entry! Enter position between 1 and 9')
        DrawBoard()
        continue
    
    if board[choice]==' ':
        board[choice]= 'X' if player==1 else 'O'
        player = 1 if player==2 else 2
        DrawBoard()
        game = CheckWin()
    else:
        print('position already taken')

if game==draw:
    print('\nGAME DRAW!')
else:
    print(f"\nPLAYER {1 if player==2 else 2} WON!")