import heapq
import sys
from collections import deque
from heapq import heappush, heappop
import math

# sys.setrecursionlimit(10**9)

N, M = map(int,input().split())
dc = {}
for _ in range(N):
    s = input().rstrip()
    if len(s) < M:
        continue
    if s in dc:
        dc[s] += 1
    else:
        dc[s] = 1
sorted_dc = sorted(dc.items(),key=lambda x : (-x[1], -len(x[0]), x[0]))
for i in sorted_dc:
    print(i[0])
