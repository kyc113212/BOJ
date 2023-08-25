import sys
from collections import deque
from datetime import datetime
from heapq import heappop, heappush

input = sys.stdin.readline

# 4821
while True:
    N = int(input())
    if N == 0:
        break
    visited = [False] * (N+1)
    li = list(map(str,input().split(',')))
    for i in range(len(li)):
        tli = list(li[i].split('-'))
        if len(tli) == 1:
            if int(tli[0]) <= N:
                visited[int(tli[0])] = True
        else:
            if int(tli[0]) > int(tli[1]):
                continue
            if int(tli[0]) > N:
                continue
            elif int(tli[1]) > N:
                tli[1] = N
            for j in range(int(tli[0]), int(tli[1]) + 1):
                visited[j] = True
    ans = 0
    for i in range(1,N+1):
        if visited[i]:
            ans += 1
    print(ans)
