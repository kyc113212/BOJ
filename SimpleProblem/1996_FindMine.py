import heapq
import sys
from collections import deque
from datetime import datetime
from heapq import heappop, heappush

dy = [-1,-1,-1,0,1,1,1,0]
dx = [-1,0,1,1,1,0,-1,-1]

# 1996
N = int(input())
board = [list(map(str, input().rstrip())) for _ in range(N)]
ans_board = [['.'] * N for _ in range(N)]

for i in range(N):
    for j in range(N):
        if board[i][j] != '.':
            ans_board[i][j] = '*'
        else:
            ans = 0
            for k in range(8):
                ny = i + dy[k]
                nx = j + dx[k]
                if 0 <= ny < N and 0 <= nx < N:
                    if board[ny][nx].isnumeric():
                        ans += int(board[ny][nx])
            if ans > 9:
                ans_board[i][j] = 'M'
            else:
                ans_board[i][j] = str(ans)
for i in range(N):
    print(*ans_board[i], sep='')


