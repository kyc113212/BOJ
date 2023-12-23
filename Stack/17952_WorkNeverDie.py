import heapq
import math
import sys
from collections import deque
from datetime import datetime
from heapq import heappop, heappush

input = sys.stdin.readline

# 17952

N = int(input())
dq = deque()
ans = 0
for i in range(N):
    li = list(map(int, input().split()))
    if li[0] == 0:
        if len(dq) > 0:
            dq[-1][2] -= 1
            if dq[-1][2] == 0:
                ans += dq[-1][1]
                dq.pop()
        else:
            continue
    elif li[0] == 1:
        dq.append([li[0],li[1],li[2]])
        dq[-1][2] -=1
        if dq[-1][2] == 0:
            ans += dq[-1][1]
            dq.pop()
print(ans)
