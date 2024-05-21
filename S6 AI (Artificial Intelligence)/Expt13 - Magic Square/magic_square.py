n = int(input("Enter the order of the Magic Square: "))
magic_square = [[0] * n for _ in range(n)]
num, i, j = 1, 0, n // 2

while num <= n * n:
    magic_square[i][j], num = num, num + 1
    newi, newj = (i - 1) % n, (j + 1) % n
    if magic_square[newi][newj]:
        i += 1
    else:
        i, j = newi, newj

print(f"The magic constant is: {int((n*(n**2+1))/2)}")
print(f"Magic Square of order {n}:")
for row in magic_square:
    print("\t".join(map(str, row)))
