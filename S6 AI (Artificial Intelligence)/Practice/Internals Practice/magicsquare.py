n = int(input('Enter order of magic square: '))
square = [[0]*n for _ in range(n)]
num, i, j = 1, 0, n//2

while num <= n*n:
    square[i][j], num = num, num+1
    newi, newj = (i-1)%n, (j+1)%n
    if square[newi][newj]:
        i+=1
    else:
        i, j = newi, newj
        
for row in square:
    print("\t".join(map(str, row)))
