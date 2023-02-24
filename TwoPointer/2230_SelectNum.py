import sys
from collections import deque
from heapq import heappop, heappush
import math
sys.setrecursionlimit(10**9)

input = sys.stdin.readline

li = []
N, M = map(int,input().split())
ans = sys.maxsize
left = 0
right = 0

for _ in range(N):
   num = int(input())
   li.append(num)
li.sort()

while right < N and left <= right:
   if li[right] - li[left] >= M:
      ans = min(ans, li[right] - li[left])
      left += 1
   else:
      right += 1
print(ans)
