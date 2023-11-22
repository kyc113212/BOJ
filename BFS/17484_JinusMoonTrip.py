import heapq
import math
import sys
from collections import deque
from datetime import datetime
from heapq import heappop, heappush
input = sys.stdin.readline

dx = [-1,0,1]
dy = [1,1,1]

# 17484
R, C = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(R)]
dq = deque()
ans = sys.maxsize
for i in range(C):
    dq.append([0,i,board[0][i], -1])
while len(dq) > 0:
    cy, cx, cnt, c_dir = dq.popleft()
    if cy == R-1:
        ans = min(ans, cnt)
        continue
    for i in range(3):
        if i == c_dir:
            continue
        ny = cy + dy[i]
        nx = cx + dx[i]
        if 0 <= nx < C and 0 <= ny < R:
            dq.append([ny,nx,cnt+board[ny][nx],i])
print(ans)
