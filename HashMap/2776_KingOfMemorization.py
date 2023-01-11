import sys
import math

from collections import deque
from heapq import heappop, heappush

input = sys.stdin.readline


T = int(input())
for _ in range(T):

    dc = {}
    N1 = int(input())
    li = list(map(int,input().split()))
    for v in li:
        dc[v] = 1
    N2 = int(input())
    li = list(map(int, input().split()))
    for v in range(N2):
        if li[v] in dc:
            print(1)
        else:
            print(0)
