import sys
from collections import deque
from datetime import datetime
from heapq import heappop, heappush

input = sys.stdin.readline

# 28353
N, K = map(int, input().split())
li = list(map(int, input().split()))
li.sort()
ans = 0
left = 0
right = int(len(li)) - 1
while left < right:
    if li[left] + li[right] > K:
        right -= 1
    else:
        ans += 1
        left += 1
        right -= 1
print(ans)
