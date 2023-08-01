import sys
from collections import deque
from datetime import datetime
from heapq import heappop, heappush

input = sys.stdin.readline

max_row = 0
max_col = 0
info = []
dy = [-1,1,0,0]
dx = [0,0,-1,1]

for _ in range(int(input())):
    A, B = map(int, input().split())
    info.append([A,B])
    max_row = max(max_row, A)
    max_col = max(max_col, B)

board = [[0] * (max_col + 20) for _ in range(max_row + 20)]

for i in range(len(info)):
    for j in range(info[i][0]+1, info[i][0]+11):
        for k in range(info[i][1] + 1, info[i][1] + 11):
            board[j][k] = 1

ans = 0
for i in range(max_row + 20):
    for j in range(max_col + 20):
        if board[i][j] == 0:
            for k in range(4):
                ny = i + dy[k]
                nx = j + dx[k]
                if 0 <= ny < max_row + 20 and 0 <= nx < max_col + 20:
                    if board[ny][nx] == 1:
                        ans += 1
print(ans)


