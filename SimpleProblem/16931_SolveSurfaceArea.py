import heapq
import math
import sys
from collections import deque
from datetime import datetime
from heapq import heappop, heappush

input = sys.stdin.readline

# 16931

N, M = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(N)]
ans = 0
ans = N*M*2
for i in range(N):
    ans += board[i][0]
    for j in range(1, M):
        if board[i][j] > board[i][j-1]:
            ans += (board[i][j] - board[i][j-1])

for i in range(N):
    ans += board[i][M-1]
    for j in range(M-2,-1,-1):
        if board[i][j] > board[i][j+1]:
            ans += (board[i][j] - board[i][j+1])

for i in range(M):
    ans += board[0][i]
    for j in range(1, N):
        if board[j][i] > board[j-1][i]:
            ans += (board[j][i] - board[j-1][i])

for i in range(M):
    ans += board[N-1][i]
    for j in range(N - 2, -1, -1):
        if board[j][i] > board[j+1][i]:
            ans += (board[j][i] - board[j+1][i])
print(ans)
