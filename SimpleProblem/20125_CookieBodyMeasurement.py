import sys
from collections import deque
from datetime import datetime


# 20125

def find_top():
    for i in range(N):
        for j in range(N):
            if board[i][j] == '*':
                return i, j


N = int(input())
board = [list(map(str, input().rstrip())) for _ in range(N)]
head, left_h, right_h, waist, left_l, right_l = 0, 0, 0, 0, 0, 0

ty, tx = find_top()
hy, hx = 0, 0
for i in range(ty, N):
    if board[i][tx-1] == '*' and board[i][tx+1] == '*':
        hy, hx = i, tx
        break
    head += 1
for i in range(tx-1,-1,-1):
    if board[hy][i] == '*':
        left_h += 1
for i in range(tx+1,N):
    if board[hy][i] == '*':
        right_h += 1
gy = 0
for i in range(hy+1,N):
    if board[i][hx] == '*':
        waist += 1
        gy = i
for i in range(gy+1,N):
    if board[i][hx - 1] == '*':
        left_l += 1
    if board[i][hx+1] == '*':
        right_l += 1
print(hy+1, hx+1, sep = ' ')
print(left_h,right_h,waist,left_l,right_l,sep=' ')
