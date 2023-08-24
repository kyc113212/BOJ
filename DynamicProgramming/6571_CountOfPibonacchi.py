import sys
from collections import deque
from datetime import datetime
from heapq import heappop, heappush

input = sys.stdin.readline

# 6571
DP = [0] * 1001
DP[1] = 1
DP[2] = 2
for i in range(3, 1001, 1):
    DP[i] = DP[i-1] + DP[i-2]
while True:
    A, B = map(int, input().split())
    if A == 0 and B == 0:
        break
    ans = 0
    for i in range(1, 1001, 1):
        if A <= DP[i] and DP[i] <= B:
            ans += 1
    print(ans)
