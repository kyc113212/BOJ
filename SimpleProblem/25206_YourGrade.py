import heapq
import sys
from collections import deque
from heapq import heappush, heappop
import math

# sys.setrecursionlimit(10**9)

input = sys.stdin.readline

def return_n(n):
    if n == 'A+':
        return 4.5
    elif n == 'A0':
        return 4.0
    elif n == 'B+':
        return 3.5
    elif n == 'B0':
        return 3.0
    elif n == 'C+':
        return 2.5
    elif n == 'C0':
        return 2.0
    elif n == 'D+':
        return 1.5
    elif n == 'D0':
        return 1.0
    else:
        return 0.0
ans = 0
cnt = 0
for _ in range(20):
    s, n, g = map(str, input().split())
    if g == 'P':
        continue
    ans += float(n) * return_n(g)
    cnt += (1 * float(n))
ans_p = str(round(ans/cnt,6))
print(ans_p, '0' * (8 - len(ans_p)),sep='')
