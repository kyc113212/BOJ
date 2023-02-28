import sys
from collections import deque
from heapq import heappop, heappush
import math
#sys.setrecursionlimit(10**9)

input = sys.stdin.readline

N = int(input())
li = []
for _ in range(N):
   a, b = map(int,input().split())
   li.append((a,b))
li.sort(key = lambda x : (x[0],x[1]))
ans = 0
for a, b in li:
   if ans < a:
      ans = a + b
   else:
      ans += b
print(ans)

