import heapq
import math
import sys
from collections import deque
from datetime import datetime
from heapq import heappop, heappush

input = sys.stdin.readline

li = []
for _ in range(int(input())):
    li.append(int(input()))
li.sort(reverse=True)
ans = 0
for i in range(len(li)):
    temp = li[i] - i
    if temp < 0:
        continue
    else:
        ans += temp
print(ans)
