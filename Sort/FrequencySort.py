import math
import sys
from collections import deque

#sys.setrecursionlimit(10**6)
input = sys.stdin.readline

# 2910
N, C = map(int,input().split())
li = list(map(int,input().split()))
dc = {}
for i in range(len(li)):
    if li[i] not in dc:
        dc[li[i]] = [li[i], i, 1]
    else:
        dc[li[i]][2] += 1
d1 = sorted(dc.items(), key = lambda x : (-x[1][2], x[1][1], x[1][0]))

for key, value in d1:
    num = value[0]
    cnt = value[2]
    for _ in range(cnt):
        print(num,end=' ')
