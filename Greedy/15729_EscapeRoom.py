import heapq
import sys
from collections import deque
from datetime import datetime
from heapq import heappop, heappush

#15729

input = sys.stdin.readline

N = int(input())
li = list(map(int, input().split()))

cnt = 0
for i in range(N):
    if li[i] == 1:
        cnt += 1
        for j in range(i, i+3):
            if j >= N:
                continue
            if li[j] == 1:
                li[j] = 0
            else:
                li[j] = 1
print(cnt)
