import heapq
import math
import sys
from collections import deque
from datetime import datetime
from heapq import heappop, heappush
input = sys.stdin.readline

P, N = map(int, input().split())
li = list(map(int, input().split()))
li.sort()
ans = 0
for i in li:
    if P >= 200:
        break
    P += i
    ans += 1

print(ans)
