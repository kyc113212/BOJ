import sys
from collections import deque
from datetime import datetime
from heapq import heappop, heappush

input = sys.stdin.readline

N = int(input())
li = list(map(int, input().split()))
ans = 0
start = 0
end = 0
for i in range(1,N):
    if li[start] <= li[i]:
        ans = max(ans,li[i] - li[start])
        continue
    else:
        ans = max(ans, li[i-1]-li[start])
        start = i
print(ans)
