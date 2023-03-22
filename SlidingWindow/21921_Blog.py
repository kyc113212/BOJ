import heapq
import sys
from collections import deque
from heapq import heappush, heappop
import math

# sys.setrecursionlimit(10**9)

N, X = map(int,input().split())
ans = 0
cnt = 0
li = list(map(int,input().split()))
c_sum = [0] * (len(li)+1)
for i in range(1, len(li) + 1):
    c_sum[i] = c_sum[i-1] + li[i - 1]
for i in range(X,len(li) + 1):
    t_ans = c_sum[i] - c_sum[i-X]
    if t_ans > ans:
        cnt = 0
        ans = t_ans
    if t_ans == ans:
        cnt += 1
if ans == 0:
    print('SAD')
else:
    print(ans)
    print(cnt)
