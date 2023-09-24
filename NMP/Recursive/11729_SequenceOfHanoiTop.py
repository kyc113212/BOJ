import heapq
import math
import sys
from collections import deque
from datetime import datetime
from heapq import heappop, heappush
input = sys.stdin.readline

sys.setrecursionlimit(10**8)
N = int(input())

def move(n, from_, to_, other_):
    global cnt
    if n == 0:
        return
    cnt += 1
    move(n-1, from_, other_, to_)
    ans_list.append([from_,to_])
    move(n-1, other_, to_, from_)

cnt = 0
ans_list = []
move(N, 1, 3, 2)
print(cnt)
for i in range(len(ans_list)):
    print(ans_list[i][0],ans_list[i][1],sep=' ')
