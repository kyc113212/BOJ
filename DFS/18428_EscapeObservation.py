import math
import sys
from itertools import permutations
from collections import deque

sys.setrecursionlimit(10**8)

input = sys.stdin.readline

# 18428

N = int(input())
board = [list(map(str,input().split())) for _ in range(N)]
teacher_pos = deque()
dy = [-1,1,0,0]
dx = [0,0,-1,1]

for i in range(N):
    for j in range(N):
        if board[i][j] == 'T':
            teacher_pos.append([i,j])

def solve():
    global board
    for i in range(len(teacher_pos)):
        t_y, t_x = teacher_pos[i][0], teacher_pos[i][1]
        # 좌, 우, 상, 하
        for d in range(4):
            ny = t_y
            nx = t_x
            while True:
                ny += dy[d]
                nx += dx[d]
                if ny >= N or nx >= N or nx < 0 or ny < 0:
                    break
                if board[ny][nx] == 'S':
                    return False
                if board[ny][nx] == 'T':
                    break
                if board[ny][nx] == 'O':
                    break
    return True

def dfs(y, x, cnt):
    global board
    if cnt == 3:
        if solve():
            return True
        return False
    for i in range(y,N):
        for j in range(x,N):
            if board[i][j] == 'X':
                board[i][j] = 'O'
                if dfs(i, j, cnt + 1):
                    return True
                board[i][j] = 'X'
        x = 0


flag = False
for i in range(N):
    for j in range(N):
        if board[i][j] == 'X':
            board[i][j] = 'O'
            if dfs(i, j ,1):
                flag = True
                break
            board[i][j] = 'X'
if flag:
    print('YES')
else:
    print('NO')
