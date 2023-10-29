import heapq
import math
import sys
from collections import deque
from datetime import datetime
from heapq import heappop, heappush
input = sys.stdin.readline

N, M = map(int, input().split())

li = [0] * 100
li2 = [0] * 100
idx = 0
ans = 0

for _ in range(N):
    a, b = map(int, input().split())
    for i in range(idx, idx+a):
        li[i] = b
    idx += a
idx = 0
for _ in range(M):
    a, b = map(int ,input().split())
    for i in range(idx, idx + a):
        if li[i] < b:
            ans = max(ans, b - li[i])
    idx += a
print(ans)
