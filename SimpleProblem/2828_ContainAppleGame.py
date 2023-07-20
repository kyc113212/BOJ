import heapq
import sys
from collections import deque
from heapq import heappush, heappop
import math
#sys.setrecursionlimit(10**9)

input = sys.stdin.readline

N, M = map(int,input().split())
li = []
for _ in range(int(input())):
    n = int(input())
    li.append(n)
st_idx = 1
end_idx = 1 + M - 1
ans = 0
for i in li:
    while True:
        if i > end_idx:
            st_idx += 1
            end_idx += 1
            ans += 1
        elif i < st_idx:
            st_idx -= 1
            end_idx -= 1
            ans += 1
        else:
            break
print(ans)
