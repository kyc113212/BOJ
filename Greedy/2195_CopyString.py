import heapq
import math
import sys
from collections import deque
from datetime import datetime
from heapq import heappop, heappush

input = sys.stdin.readline

S = input().rstrip()
P = list(input().rstrip())
ans = 0
idx = 0
while True:
    for i in range(len(P),idx-1,-1):
        ts = ''.join(P[idx:i])
        tf = S.find(ts)
        if tf >= 0:
            idx = idx + len(list(ts))
            break
    if idx >= len(P):
        ans += 1
        break
    ans += 1
print(ans)
