import heapq
import math
import sys
from collections import deque
from datetime import datetime
from heapq import heappop, heappush

input = sys.stdin.readline

# 10655
li = []
for _ in range(int(input())):
    a,b = map(int, input().split())
    li.append([a,b])
temp = []
sum_len = 0
for i in range(1, len(li)):
    sum_len += (abs(li[i-1][0] - li[i][0]) + abs(li[i-1][1] - li[i][1]))
max_V = 0
for i in range(1, len(li) - 1):
    max_V = max(max_V, (abs(li[i-1][0] - li[i][0]) + abs(li[i-1][1] - li[i][1]) + abs(li[i][0] - li[i+1][0]) + abs(li[i][1] - li[i+1][1])) - (abs(li[i-1][0] - li[i+1][0]) + abs(li[i-1][1] - li[i+1][1])))
print(sum_len - max_V)
