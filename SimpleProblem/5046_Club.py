import sys
from collections import deque
from datetime import datetime
from heapq import heappop, heappush

input = sys.stdin.readline

N, B, H, W = map(int, input().split())
minV = sys.maxsize
for _ in range(H):
    cost = int(input())
    li = list(map(int, input().split()))
    for i in li:
        if i >= N:
            if cost * N > B:
                continue
            minV = min(minV, cost * N)
        else:
            continue
if minV == sys.maxsize:
    print('stay home')
else:
    print(minV)
