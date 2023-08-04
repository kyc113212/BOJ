import sys
from collections import deque
from datetime import datetime
from heapq import heappop, heappush

input = sys.stdin.readline

li = []
for _ in range(int(input())):
    li.append(int(input()))
total_sum = sum(li) // 2
ans = []
sub_sum = 0
for i in range(1,len(li),2):
    sub_sum += li[i]
ans.append(total_sum-sub_sum)
for i in range(len(li)-1):
    ans.append(li[i] - ans[-1])
for i in ans:
    print(i)
