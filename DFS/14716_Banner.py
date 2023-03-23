import heapq
import sys
from collections import deque
from heapq import heappush, heappop
import math

sys.setrecursionlimit(10**9)

def dfs(y, x):
    visited[y][x] = True
    for i in range(8):
        ny = y + dy[i]
        nx = x + dx[i]
        if ny < 0 or nx < 0 or ny >= N or nx >= M:
            continue
        if visited[ny][nx]:
            continue
        if board[ny][nx] == 1:
            dfs(ny,nx)

dx = [0,1,1,1,0,-1,-1,-1]
dy = [1,1,0,-1,-1,-1,0,1]

N, M = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(N)]
visited = [[False] * M for _ in range(N)]
ans = 0

for i in range(N):
    for j in range(M):
        if not visited[i][j] and board[i][j] == 1:
            dfs(i,j)
            ans += 1

print(ans)
