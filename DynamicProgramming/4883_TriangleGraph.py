import sys
from collections import deque
from datetime import datetime

#4883
TC = 1
while True:
    N = int(input())
    if N == 0:
        break
    board = [list(map(int, input().split())) for _ in range(N)]
    ans = board[0][1]
    DP = [[sys.maxsize, sys.maxsize, sys.maxsize] for _ in range(N)]
    DP[0][1] = board[0][1]
    DP[0][2] = board[0][1] + board[0][2]
    for i in range(1,N):
        for j in range(3):
            if i == 1:
                if j == 0:
                    DP[i][j] = DP[0][1] + board[i][j]
                elif j == 1:
                    DP[i][j] = min(DP[i - 1][0], DP[i - 1][1], DP[i - 1][2], DP[i][j - 1]) + board[i][j]
                else:
                    DP[i][j] = min(DP[i-1][1], DP[i-1][2], DP[i][j-1]) + board[i][j]
            else:
                if j == 0:
                    DP[i][j] = min(DP[i-1][0], DP[i-1][1]) + board[i][j]
                elif j == 1:
                    DP[i][j] = min(DP[i-1][0], DP[i-1][1], DP[i-1][2], DP[i][j-1]) + board[i][j]
                else:
                    DP[i][j] = min(DP[i-1][1], DP[i-1][2], DP[i][j-1]) + board[i][j]
    print(f'{TC}. {DP[N-1][1]}')
    TC += 1
