import heapq
import sys
from collections import deque
from heapq import heappush, heappop
import math

input = sys.stdin.readline
#sys.setrecursionlimit(10**9)
A, B, N, M = map(int,input().split())
visited = set()
dq = deque()
dq.append([N, 0])
ans = -1
dist = [-1, 1, A, B, -A, -B, A, B]

while len(dq) != 0:
    cur_p, cur_cnt = dq.popleft()
    if cur_p == M:
        ans = cur_cnt
        break
    if cur_p in visited:
        continue
    visited.add(cur_p)
    for i in range(6):
        next_p = cur_p + dist[i]
        if next_p < 0 or next_p > 100000:
            continue
        if next_p in visited:
            continue
        dq.append([next_p, cur_cnt+1])
    for i in range(6, 8):
        next_p = cur_p * dist[i]
        if next_p == 0:
            continue
        if next_p < 0 or next_p > 100000:
            continue
        if next_p in visited:
            continue
        dq.append([next_p, cur_cnt + 1])
print(ans)

