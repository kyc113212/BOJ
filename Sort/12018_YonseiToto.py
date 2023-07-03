import sys
from collections import deque
from datetime import datetime
from heapq import heappop, heappush

input = sys.stdin.readline

# 12018

N, M = map(int, input().split())
mazino = []
for _ in range(N):
    P, L = map(int, input().split())
    li = list(map(int, input().split()))
    li.sort(reverse=True)
    if len(li) < L:
        mazino.append(1)
    else:
        mazino.append(li[L-1])
cnt = 0
temp_sum = 0
mazino.sort()
for i in range(len(mazino)):
    temp_sum += mazino[i]
    if temp_sum > M:
        break
    cnt += 1
print(cnt)
