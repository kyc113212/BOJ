import sys
from collections import deque
from datetime import datetime
from heapq import heappop, heappush

input = sys.stdin.readline

# 18110
def round2(num):
    return int(num) + (1 if num - int(num) >= 0.5 else 0)

li = []
N = int(input())
for _ in range(N):
    li.append(int(input()))
li.sort()
rng = len(li) * 0.15
rng = int(round2(rng))
sumV = 0
for i in range(rng,len(li)-rng):
    sumV += li[i]
if len(li) == 0:
    print(0)
else:
    print(int(round2(sumV/(len(li)-rng*2))))
