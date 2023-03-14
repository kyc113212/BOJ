import math
import sys
from collections import deque

#sys.setrecursionlimit(10**6)
input = sys.stdin.readline

# 14940

N, M = map(int, input().split())
board = [list(map(int,input().split())) for _ in range(N)]
visited = [[False] * M for _ in range(N)]
ans_map = [[-1] * M for _ in range(N)]
dy = [-1,1,0,0]
dx = [0,0,-1,1]
dq = deque()
sy = -1
sx = -1
flag = False
for i in range(N):
    for j in range(M):
        if board[i][j] == 2:
            sy = i
            sx = j
            dq.append([i,j,0])
            flag = True
            break
    if flag:
        break

while len(dq) != 0:
    cy, cx, cnt = dq.popleft()
    if visited[cy][cx]:
        continue
    visited[cy][cx] = True
    ans_map[cy][cx] = cnt
    for i in range(4):
        ny = cy + dy[i]
        nx = cx + dx[i]
        if ny < 0 or nx < 0 or ny >= N or nx >= M:
            continue
        if visited[ny][nx]:
            continue
        if board[ny][nx] == 0:
            continue
        dq.append([ny,nx,cnt+1])
for i in range(N):
    for j in range(M):
        if ans_map[i][j] == -1 and board[i][j] == 0:
            print(0,end=' ')
        elif ans_map[i][j] == -1 and board[i][j] == 1:
            print(-1,end=' ')
        else:
            print(ans_map[i][j], end = ' ')
    print()
