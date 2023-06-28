import heapq
import sys
from collections import deque
from heapq import heappop, heappush
from datetime import datetime

input = sys.stdin.readline
dy = [0,0,-1,1]
dx = [-1,1,0,0]

def bfs():
    visited_dist = [[[sys.maxsize] * C for _ in range(R)] for _ in range(4)]
    # visited에 방향에 따른 회전 수도 기록
    q = []
    dq = deque()
    s_x,s_y,e_x,e_y = 0,0,0,0
    cnt = 0
    for i in range(R):
        for j in range(C):
            if board[i][j] == 'C':
                if cnt == 0:
                    s_x = j
                    s_y = i
                    cnt += 1
                else:
                    e_x = j
                    e_y = i
    for i in range(4):
        ny = s_y + dy[i]
        nx = s_x + dx[i]
        if 0 <= ny < R and 0 <= nx < C and board[ny][nx] == '.':
            heapq.heappush(q,[0,ny,nx,i])
            #dq.append([ny,nx,i,0])
    for i in range(4):
        visited_dist[i][s_y][s_x] = 0
    while q:
        #cy, cx, cur_dir, cur_cnt = dq.popleft()
        cur_cnt, cy, cx, cur_dir = heapq.heappop(q)
        if cy == e_y and cx == e_x:
            return cur_cnt
        if visited_dist[cur_dir][cy][cx] <= cur_cnt:
            continue
        visited_dist[cur_dir][cy][cx] = cur_cnt
        for i in range(4):
            ny = cy + dy[i]
            nx = cx + dx[i]
            if 0 <= ny < R and 0 <= nx < C and (board[ny][nx] == '.' or board[ny][nx] == 'C'):
                if cur_dir != i:
                    if visited_dist[i][ny][nx] >= cur_cnt + 1:
                        heapq.heappush(q, [cur_cnt+1, ny, nx, i])
                        #dq.append([ny, nx, i, cur_cnt + 1])
                else:
                    if visited_dist[i][ny][nx] >= cur_cnt:
                        heapq.heappush(q, [cur_cnt, ny, nx, i])
                        #dq.append([ny, nx, i, cur_cnt])

# 6087
C, R = map(int, input().split())
board = [list(map(str,input().rstrip())) for _ in range(R)]
print(bfs())
