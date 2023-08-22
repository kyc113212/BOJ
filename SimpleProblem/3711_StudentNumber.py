import sys
from collections import deque
from datetime import datetime
from heapq import heappop, heappush

input = sys.stdin.readline

# 3711
for _ in range(int(input())):
    li = []
    for _ in range(int(input())):
        li.append(int(input()))
    ans = -1
    for i in range(1, 10**6):
        flag = True
        dc = {}
        for j in li:
            modV = j % i
            if modV in dc:
                flag = False
            else:
                dc[modV] = 1
        if flag:
            ans = i
            break
    print(ans)
