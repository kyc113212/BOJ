import heapq
import sys
from collections import deque
from datetime import datetime
from heapq import heappop, heappush
input = sys.stdin.readline

# 14730
li = []
for _ in range(int(input())):
    A, B = map(int, input().split())
    li.append([A, B])

ans = 0
for i in range(len(li)):
    if li[i][1] == 0:
        continue
    else:
        ans += li[i][0] * li[i][1]

print(ans)
