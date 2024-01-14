import heapq
import math
import sys
from collections import deque
from datetime import datetime
from heapq import heappop, heappush

input = sys.stdin.readline

dy = [0,1,0,-1]
dx = [1,0,-1,0]

def rotate(y, x, lr, lc):
    global board, R
    dq = deque()
    sy = y
    sx = x
    ey = sy + lr - 1
    ex = sx + lc - 1
    cur_dir = 0
    while True:
        dq.append(board[y][x])
        if cur_dir == 0 and ex == x:
            cur_dir += 1
        elif cur_dir == 1 and ey == y:
            cur_dir += 1
        elif cur_dir == 2 and x == sx:
            cur_dir += 1

        y += dy[cur_dir]
        x += dx[cur_dir]

        if y == sy and x == sx:
            break
    for i in range(R):
        dq.append(dq.popleft())

    sy = y
    sx = x
    ey = sy + lr - 1
    ex = sx + lc - 1
    cur_dir = 0
    cnt = 0
    while True:
        board[y][x] = dq[cnt]
        cnt += 1
        if cur_dir == 0 and ex == x:
            cur_dir += 1
        elif cur_dir == 1 and ey == y:
            cur_dir += 1
        elif cur_dir == 2 and x == sx:
            cur_dir += 1

        y += dy[cur_dir]
        x += dx[cur_dir]

        if y == sy and x == sx:
            break
    temp = 0


N, M, R = map(int, input().split())
n,m = N, M
board = [list(map(int, input().split())) for _ in range(N)]
s_y, s_x = 0, 0
while True:
    rotate(s_y, s_x, N, M)
    s_y += 1
    s_x += 1
    N -= 2
    M -= 2
    if N == 0 or M == 0:
        break

for i in range(n):
    for j in range(m):
        print(board[i][j], end = ' ')
    print()
