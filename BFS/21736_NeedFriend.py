import math
import sys
from itertools import permutations
from collections import deque

input = sys.stdin.readline

dy = [-1,1,0,0]
dx = [0,0,-1,1]

N, M = map(int, input().split())
board = [list(input().rstrip()) for _ in range(N)]
dq = deque()
visited = [[False] * M for _ in range(N)]
for i in range(N):
    for j in range(M):
        if board[i][j] == 'I':
            dq.append((i,j))
            visited[i][j] = True
ans = 0
while dq:
    cy, cx = dq.popleft()
    for i in range(4):
        ny = cy + dy[i]
        nx = cx + dx[i]
        if 0 <= ny < N and 0 <= nx < M:
            if not visited[ny][nx]:
                if board[ny][nx] == 'P':
                    ans += 1
                    visited[ny][nx] = True
                    dq.append((ny, nx))
                if board[ny][nx] == 'O':
                    visited[ny][nx] = True
                    dq.append((ny,nx))
if ans == 0:
    print('TT')
else:
    print(ans)
