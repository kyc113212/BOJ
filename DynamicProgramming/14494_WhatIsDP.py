import heapq
import sys
from collections import deque
from heapq import heappush, heappop
import math

# sys.setrecursionlimit(10**9)

N, M = map(int, input().split())
MOD = 1000000007
board = [[0] * (M+1) for _ in range(N+1)]
board[1][1] = 1
for i in range(1,N+1):
    for j in range(1, M+1):
        if i == 1 and j == 1:
            continue
        board[i][j] = (board[i-1][j] + board[i][j-1] + board[i-1][j-1]) % MOD
print(board[N][M])
