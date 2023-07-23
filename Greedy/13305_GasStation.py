import heapq
import sys
from collections import deque
from datetime import datetime
from heapq import heappop, heappush
input = sys.stdin.readline

# 13305
N = int(input())
dist = list(map(int, input().split()))
cost = list(map(int, input().split()))
min_cost = cost[0]
for i in range(1, len(cost)):
    if cost[i] < min_cost:
        min_cost = cost[i]
    else:
        cost[i] = min_cost
ans = 0
for i in range(len(dist)):
    ans += (dist[i] * cost[i])
print(ans)
