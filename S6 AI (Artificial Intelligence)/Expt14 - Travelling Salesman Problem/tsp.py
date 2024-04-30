#TRAVELLING SALEMAN PROBLEM
n = 4
dist = [[0, 0, 0, 0, 0], [0, 0, 10, 15, 20], [
    0, 10, 0, 25, 25], [0, 15, 25, 0, 30], [0, 20, 25, 30, 0]]

memo = [[-1]*(1 << (n+1)) for _ in range(n+1)]
def fun(i, mask, parent):
    if mask == ((1 << i) | 3):
        return dist[1][i], [1, i]

    if memo[i][mask] != -1:
        return memo[i][mask]

    res = 10**9  # result of this sub-problem
    path = []

    for j in range(1, n+1):
        if (mask & (1 << j)) != 0 and j != i and j != 1:
            temp_res, temp_path = fun(j, mask & (~(1 << i)), j)
            if temp_res + dist[j][i] < res:
                res = temp_res + dist[j][i]
                path = temp_path + [i]

    memo[i][mask] = res, path 
    return res, path

ans = 10**9
optimal_path = []
for i in range(1, n+1):
    temp_res, temp_path = fun(i, (1 << (n+1))-1, i)
    if temp_res + dist[i][1] < ans:
        ans = temp_res + dist[i][1]
        optimal_path = temp_path + [1]

print("The cost of most efficient tour =", ans)
print("Optimal Path:", optimal_path)
