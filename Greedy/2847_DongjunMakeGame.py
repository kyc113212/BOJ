import sys
import math

from collections import deque
from heapq import heappop, heappush

input = sys.stdin.readline


li = []
N = int(input())
ans = 0
for _ in range(N):
    li.append(int(input()))
origin = li[:]
left = 0
right = len(li) - 1

while True:
    min_idx = -1
    minV = sys.maxsize
    for i in range(left, N):
        if minV >= li[i]:
            minV = li[i]
            min_idx = i
    cnt = minV
    if min_idx == 0:
        break
    for i in range(min_idx - 1,-1,-1):
        cnt -= 1
        if cnt > li[i]:
            cnt = li[i]
        else:
            li[i] = cnt
    left = min_idx + 1
for i in range(len(li)):
    if li[i] < origin[i]:
        ans += (origin[i] - li[i])
print(ans)
