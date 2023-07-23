import heapq
import sys
from collections import deque
from datetime import datetime
from heapq import heappop, heappush
input = sys.stdin.readline

# 2133
N = int(input())
DP = [0] * 31
DP[0] = 1
DP[1] = 0
DP[2] = 3
for i in range(4, N+1):
    if i % 2 == 0:
        DP[i] += DP[i-2] * 3

    for j in range(4, i+1, 2):
        DP[i] += DP[i-j] * 2
print(DP[N])
