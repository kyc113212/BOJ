import heapq
import sys
from collections import deque
from heapq import heappush, heappop
import math

input = sys.stdin.readline

li = []
for _ in range(int(input())):
    li.append(input().rstrip())
desc_li = sorted(li, reverse=True)
asc_li = sorted(li)
Reverse = True
Standard = True
for i in range(len(li)):
    if li[i] != desc_li[i]:
        Reverse = False
    if li[i] != asc_li[i]:
        Standard = False

if Reverse:
    print('DECREASING')
elif Standard:
    print('INCREASING')
else:
    print('NEITHER')
