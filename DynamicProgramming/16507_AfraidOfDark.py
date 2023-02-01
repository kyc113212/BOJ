import sys
from collections import deque
from heapq import heappop, heappush

input = sys.stdin.readline

R,C,Q = map(int,input().split())

board = [list(map(int,input().split())) for _ in range(R)]
DP = [list([0] * (C + 1)) for _ in range(R + 1)]

for i in range(1, R+1):
    for j in range(1, C+1):
        DP[i][j] += (board[i - 1][j - 1] + DP[i - 1][j] + DP[i][j - 1] - DP[i-1][j-1])

for _ in range(Q):
    r1,c1,r2,c2 = map(int,input().split())
    print((DP[r2][c2] - DP[r2][c1-1] - DP[r1-1][c2] + DP[r1-1][c1-1])//((r2-r1+1)*(c2-c1+1)))


