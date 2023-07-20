import heapq
import sys
from collections import deque
from datetime import datetime
from heapq import heappop, heappush
input = sys.stdin.readline

# 16401

def check(mid):
    global li, M
    ans = 0
    for i in range(len(li)):
        ans += (li[i] // mid)
    if ans >= M:
        return True
    return False


M, N = map(int, input().split())
li = list(map(int, input().split()))
li.sort()
left = 1
right = li[-1]
ans = 0

while left <= right:
    mid = (left + right) // 2
    if check(mid):
        left = mid + 1
        ans = mid
    else:
        right = mid - 1
print(ans)
