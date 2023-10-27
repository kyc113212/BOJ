import math
import sys
from collections import deque
from datetime import datetime
from heapq import heappop, heappush

input = sys.stdin.readline

N = int(input())
li = list(map(int, input().split()))
st = list(input().rstrip())

dc = {}

for c in st:
    if c in dc:
        dc[c] += 1
    else:
        dc[c] = 1

flag = True

for i in li:
    if 1 <= i <= 26:
        c = chr(i + 64)
        if c not in dc:
            flag = False
            break
        dc[c] -= 1
    elif 27 <= i <= 52:
        c = chr(i + 70)
        if c not in dc:
            flag = False
            break
        dc[c] -= 1
    elif i == 0:
        dc[" "] -= 1

for k,v in dc.items():
    if v != 0:
        flag = False
        break
if flag:
    print('y')
else:
    print('n')
