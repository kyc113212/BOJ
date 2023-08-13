import heapq
import sys
from collections import deque
from datetime import datetime
from heapq import heappop, heappush
input = sys.stdin.readline

# 17216

N = int(input())
li = list(map(int, input().split()))

maxV = 0
DP = [0] * len(li)
for i in range(N):
    DP[i] = li[i]
    for j in range(0,i+1):
        if li[j] > li[i] and DP[j] + li[i] > DP[i]:
            DP[i] = DP[j] + li[i]
print(max(DP))
