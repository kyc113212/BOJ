import heapq
import sys
from collections import deque
from heapq import heappush, heappop
import math

input = sys.stdin.readline
#sys.setrecursionlimit(10**9)
N, M = map(int, input().split())
li = []
ans = 0
ans_cost = 0
for _ in range(M):
    li.append(int(input()))
li.sort()
for i in range(len(li)):
    item_cnt = min(N, len(li) - i)
    if (item_cnt * li[i]) > ans:
        ans = item_cnt * li[i]
        ans_cost = li[i]
print(ans_cost, ans, sep = ' ')
