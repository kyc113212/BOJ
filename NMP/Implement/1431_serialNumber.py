import sys
import math

from collections import deque
from heapq import heappop, heappush

input = sys.stdin.readline

def sum_disit(s):
    ans = 0
    for i in s:
        if i.isdigit():
            ans += int(i)
    return ans


li = []
N = int(input())
for _ in range(N):
    li.append(input().rstrip())
li.sort(key=lambda x:(len(x),sum_disit(x),x))
for v in li:
    print(v)
