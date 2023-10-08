import heapq
import math
import sys
from collections import deque
from datetime import datetime
from heapq import heappop, heappush
input = sys.stdin.readline

N, M = map(int, input().split())
li = []
for _ in range(M):
    A, B, C = map(str, input().split())
    li.append([int(A), int(B), C])
sorted_li = sorted(li, key = lambda x : (x[1], x[0]))
for a, b, c in sorted_li:
    print(c,end='')
