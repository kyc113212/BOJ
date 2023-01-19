import sys
from collections import deque
from heapq import heappop, heappush

input = sys.stdin.readline

N = int(input())

li = []
dc = {}
for _ in range(N):
    st = input().rstrip().split('.')[1]
    if st not in dc:
        dc[st] = 1
    else:
        dc[st] += 1

sorted_dict = sorted(dc.items(),key = lambda x : (x[0],x[1]))
for k in sorted_dict:
    print(k[0],k[1],sep=' ')

