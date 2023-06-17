import sys
from collections import deque
from datetime import datetime

input = sys.stdin.readline

dy = [-1,1,0,0]
dx = [0,0,-1,1]

def find_left_top():
    for i in range(R):
        for j in range(C):
            if board[i][j] == '#':
                return i, j


# 18242
R, C = map(int, input().split())
board = [list(map(str, input().rstrip())) for _ in range(R)]
left_top_y, left_top_x = find_left_top()
right_bottom_y = 0
right_bottom_x = 0
t_y = left_top_y + 1
t_x = left_top_x + 1
while True:
    if board[t_y][t_x] == '#':
        right_bottom_x = t_x
        right_bottom_y = t_y
        break
    t_y += 1
    t_x += 1
center_y = (left_top_y + right_bottom_y) // 2
center_x = (left_top_x + right_bottom_x) // 2

ans = -1

for i in range(4):
    ty = center_y
    tx = center_x
    while True:
        ty += dy[i]
        tx += dx[i]
        if ty < 0 or tx < 0 or ty >= R or tx >= C:
            ans = i
            break
        if board[ty][tx] == '#':
            break
if ans == 0:
    print('UP')
elif ans == 1:
    print('DOWN')
elif ans == 2:
    print('LEFT')
else:
    print('RIGHT')
