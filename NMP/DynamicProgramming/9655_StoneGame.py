import sys
from collections import deque
from datetime import datetime
from heapq import heappop, heappush

input = sys.stdin.readline

N = int(input())
DP = [0] * (N+1)
DP[1] = 1
DP[2] = 2
DP[3] = 1

for i in range(4,N+1):
    DP[i] = min(DP[i-1] + 1, DP[i-3] + 1)
if DP[N] % 2 == 1:
    print('SK')
else:
    print('CY')
