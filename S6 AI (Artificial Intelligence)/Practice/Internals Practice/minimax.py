MIN, MAX = -1000, 1000

def minimax(depth, nodeIndex, isMax, values, alpha, beta):
    if depth==3:
        return values[nodeIndex]
    
    if isMax:
        best = MIN
        for i in range(2):
            val = minimax(depth+1, nodeIndex*2+i, False, values, alpha, beta)
            best = max(best, val)
            alpha = max(alpha, best)
            if beta <= alpha:
                break
        return best
    
    else:
        best = MAX
        for i in range(2):
            val = minimax(depth+1, nodeIndex*2+i, True, values, alpha, beta)
            best = min(best, val)
            beta = min(beta, best)
            if beta<=alpha:
                break
        return best

values = [3, 5, 6, 9, 1, 2, 0, -1]
print(f"The optimal path is: {minimax(0, 0, True, values, MIN, MAX)}")