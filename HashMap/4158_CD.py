import math
import sys
from collections import deque

#sys.setrecursionlimit(10**6)
input = sys.stdin.readline

while True:
    N, M = map(int, input().split())
    if N == 0 and M == 0:
        break
    dc = {}
    ans = 0
    for _ in range(N):
        n = int(input())
        dc[n] = 1

    for _ in range(M):
        n = int(input())
        if n in dc:
            ans += 1
    print(ans)

