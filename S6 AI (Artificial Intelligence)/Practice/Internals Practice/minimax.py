MIN, MAX = -1000, 1000

def minimax(depth, nodeValue, isMax, values, alpha, beta):
    if depth==3:
        return values[nodeValue]
    
    if isMax:
        best = MIN
        for i in range(2):
            value = minimax(depth+1, nodeValue*2+i, False, values, alpha, beta)
            best = max(best, value)
            alpha = max(best, alpha)
            if beta <= alpha:
                break
        return best
    else:
        best = MAX
        for i in range(2):
            value = minimax(depth+1, nodeValue*2+i, True, values, alpha, beta)        
            best = min(best, value)
            beta = min(beta, best)
            if beta <= alpha:
                break
        return best
    
            
values = [2, 3, 5, 9, 0, 1, 7, 5]
# values = [3, 5, 6, 9, 1, 2, 0, -1]

print(f'The optimal path is: {minimax(0, 0, True, values, MIN, MAX)}')