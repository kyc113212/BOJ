import sys
from collections import deque
from datetime import datetime
from heapq import heappop, heappush

input = sys.stdin.readline



# 15724
N, M = map(int, input().split())
board = [list(map(int,input().split())) for _ in range(N)]
DP = [[0] * (M+1) for _ in range(N+1)]
for i in range(N):
    for j in range(M):
        DP[i+1][j+1] += (board[i][j] + DP[i][j+1] + DP[i+1][j] - DP[i][j])

for _ in range(int(input())):
    y1,x1,y2,x2 = map(int, input().split())
    print(DP[y2][x2] - DP[y2][x1-1] - DP[y1-1][x2] + DP[y1-1][x1-1])
