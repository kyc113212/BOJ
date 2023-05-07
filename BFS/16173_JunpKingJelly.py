import math
import sys
from collections import deque
from itertools import permutations
import re

input = sys.stdin.readline

# 16173

def bfs():
    dq = deque()
    dq.append((0,0,board[0][0]))

    while len(dq) > 0:
        cy, cx, jump_cnt = dq.popleft()
        if cy == N-1 and cx == N-1:
            return True
        for i in range(2):
            ny = cy + dy[i] * jump_cnt
            nx = cx + dx[i] * jump_cnt
            if ny >= N or nx >= N:
                continue
            if jump_cnt == 0:
                continue
            dq.append([ny,nx,board[ny][nx]])

    return False

dy = [0,1]
dx = [1,0]
N = int(input())
board = [list(map(int, input().split())) for _ in range(N)]
if bfs():
    print('HaruHaru')
else:
    print('Hing')
