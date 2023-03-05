import math
import sys
from collections import deque

#sys.setrecursionlimit(10**6)
input = sys.stdin.readline

# 13414
K, L = map(int, input().split())
dc = {}
for i in range(L):
    num = str(input().rstrip())
    if num in dc:
        dc[num] = i
    else:
        dc[num] = i
d1 = sorted(dc.items(), key=lambda x:x[1])

if len(d1) <= K:
    for i in range(len(d1)):
        print(d1[i][0])
else:
    for k in range(K):
        print(d1[k][0])
