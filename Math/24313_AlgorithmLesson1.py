import heapq
import math
import sys
from collections import deque
from datetime import datetime
from heapq import heappop, heappush
input = sys.stdin.readline

a, a0 = map(int, input().split())
c = int(input())
n0 = int(input())

flag = True
for i in range(n0,1000):
    if a*i+a0 > i*c:
        flag = False
        break
if flag:
    print(1)
else:
    print(0)
