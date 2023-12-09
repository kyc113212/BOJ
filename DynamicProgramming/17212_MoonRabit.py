import heapq
import math
import sys
from collections import deque
from datetime import datetime
from heapq import heappop, heappush

input = sys.stdin.readline

# 17212
N = int(input())
li = [i for i in range(N+1)]
temp = 0
if N == 0:
    print(0)
elif N == 1:
    print(1)
elif N == 2:
    print(1)
elif N == 3:
    print(2)
elif N == 4:
    print(2)
elif N == 5:
    print(1)
elif N == 6:
    print(2)
elif N == 7:
    print(1)
else:
    li[1] = 1
    li[2] = 1
    li[3] = 2
    li[4] = 2
    li[5] = 1
    li[6] = 2
    li[7] = 1
    for i in range(8, N + 1):
        li[i] = min(li[i - 1] + 1, li[i], li[i - 2] + 1, li[i - 5] + 1, li[i - 7] + 1)

    print(li[N])
