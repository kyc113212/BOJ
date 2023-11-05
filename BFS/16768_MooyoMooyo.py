import heapq
import math
import sys
from collections import deque
from datetime import datetime
from heapq import heappop, heappush

input = sys.stdin.readline

dy = [-1, 1, 0, 0]
dx = [0, 0, -1, 1]


def check():
    global board, R, C, K
    visited = [[False] * C for _ in range(R)]
    maxV = 0
    remove_list = []

    for i in range(R):
        for j in range(C):
            if not visited[i][j]:
                visited[i][j] = True
                dq = deque()
                dq.append([i, j])
                num = board[i][j]
                if num == '0':
                    continue
                cnt = 1
                temp_visited = [[False] * C for _ in range(R)]
                temp_visited[i][j] = True
                while len(dq) > 0:
                    cy, cx = dq.popleft()
                    for k in range(4):
                        ny = cy + dy[k]
                        nx = cx + dx[k]
                        if 0 <= ny < R and 0 <= nx < C:
                            if num == board[ny][nx] and not visited[ny][nx]:
                                visited[ny][nx] = True
                                temp_visited[ny][nx] = True
                                dq.append([ny, nx])
                                cnt += 1
                if cnt >= K:
                    for m in range(R):
                        for n in range(C):
                            if temp_visited[m][n]:
                                board[m][n] = '0'
                maxV = max(maxV, cnt)
    if maxV < K:
        return False
    return True


def move_block():
    global board
    for i in range(C):
        for j in range(R - 1, -1, -1):
            if board[j][i] == '0':
                for m in range(j, -1, -1):
                    if board[m][i] != '0':
                        board[j][i] = board[m][i]
                        board[m][i] = '0'
                        break


R, K = map(int, input().split())
board = []
board = [list(map(str, input().rstrip())) for _ in range(R)]
C = len(board[0])

while check():
    move_block()

for i in range(R):
    print(''.join(board[i]))
