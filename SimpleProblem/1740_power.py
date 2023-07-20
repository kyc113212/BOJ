import sys
from collections import deque
from datetime import datetime
from heapq import heappop, heappush

input = sys.stdin.readline
# 1740
N = bin(int(input()))[2:]
ans = 0
cnt = len(N) - 1
for i in range(len(N)):
    if N[i] == '1':
        ans += pow(3,cnt - i)
print(ans)
