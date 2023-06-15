import sys
from collections import deque
from datetime import datetime

input = sys.stdin.readline

dy = [0,1]
dx = [1,0]

# 6186
R, C = map(int,input().split())
board = [list(map(str,input().rstrip())) for _ in range(R)]
visited = [[False] * (C) for _ in range(R)]
cnt = 0
for i in range(R):
    for j in range(C):
        if not visited[i][j] and board[i][j] == '#':
            visited[i][j] = True
            cnt += 1
            for c in range(2):
                ny = i + dy[c]
                nx = j + dx[c]
                if 0 <= nx < C and 0 <= ny < R:
                    if board[ny][nx] == '#':
                        visited[ny][nx] = True
                        break
print(cnt)

