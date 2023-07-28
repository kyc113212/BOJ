import sys
from collections import deque
from datetime import datetime
from heapq import heappop, heappush

input = sys.stdin.readline

N = int(input())
DP = [0] * (N+1)
if N == 1:
    print('SK')
elif N == 2:
    print('CY')
elif N == 3:
    print('SK')
elif N == 4:
    print('SK')
else:
    DP[1] = 1
    DP[2] = 2
    DP[3] = 1
    DP[4] = 1
    for i in range(5, N+1):
        flag = False
        li = []
        if (DP[i-1] + 1) % 2 == 1:
            flag = True
            li.append(DP[i - 1] + 1)
        elif (DP[i - 3] + 1) % 2 == 1:
            li.append(DP[i - 3] + 1)
            flag = True
        elif (DP[i - 4] + 1) % 2 == 1:
            li.append(DP[i - 4] + 1)
            flag = True
        else:
            DP[i] = min(DP[i-1] + 1, DP[i-3] + 1, DP[i-4] + 1)
        if flag:
            DP[i] = min(li)
    if DP[N] % 2 == 1:
        print('SK')
    else:
        print('CY')
