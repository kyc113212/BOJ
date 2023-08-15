import heapq
import sys
from collections import deque
from datetime import datetime
from heapq import heappop, heappush
input = sys.stdin.readline

# 17127

def solve(tdq, idx):
    global maxV, li
    if len(tdq) == 4:
        sumV = 0
        temp = 1
        for i in range(0, tdq[0] + 1):
            temp *= li[i]
        sumV += temp
        temp = 1
        for i in range(tdq[0] + 1, tdq[1] + 1):
            temp *= li[i]
        sumV += temp
        temp = 1
        for i in range(tdq[1] + 1, tdq[2] + 1):
            temp *= li[i]
        sumV += temp
        temp = 1
        for i in range(tdq[2] + 1, len(li)):
            temp *= li[i]
        sumV += temp
        temp = 1
        maxV = max(maxV, sumV)
    for i in range(idx,len(li)):
        tdq.append(i)
        solve(tdq, i+1)
        tdq.pop()

maxV = 0
N = int(input())
li = list(map(int, input().split()))
dq = deque()
solve(dq,0)
print(maxV)
