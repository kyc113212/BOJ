import sys
from collections import deque
from datetime import datetime
from heapq import heappop, heappush

input = sys.stdin.readline

#2012
N = int(input())
li = []
for _ in range(N):
    li.append(int(input()))
li.sort()
ans = 0
for i in range(N):
    ans += (abs(i+1-li[i]))
print(ans)
