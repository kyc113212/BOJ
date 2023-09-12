import heapq
import math
import sys
from collections import deque
from datetime import datetime
from heapq import heappop, heappush
input = sys.stdin.readline

#1002

for _ in range(int(input())):
    x1,y1,r1,x2,y2,r2 = map(int, input().split())
    distance = ((x1-x2)**2 + (y1-y2)**2) ** (1/2)
    if r1 < r2:
        temp = r1
        r1 = r2
        r2 = temp
    if distance == 0 and r1 == r2:
        print(-1)
    elif distance == r1 + r2 or distance + r2 == r1:
        print(1)
    elif distance < r1 + r2 and r1-r2 < distance < r1+r2:
        print(2)
    else:
        print(0)
