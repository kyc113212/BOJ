import heapq
import math
import sys
from collections import deque
from datetime import datetime
from heapq import heappop, heappush

input = sys.stdin.readline

# 28432

dc = {}
N = int(input())
idx = 0
pre = []
for i in range(N):
    s = input().rstrip()
    if s == '?':
        idx = i
    else:
        dc[s] = 1
    pre.append(s)

ans = ""
sub = []
for _ in range(int(input())):
    sub.append(input().rstrip())

if idx == 0 or idx == N-1:
    if idx == 0 and N > 1:
        e_n = list(pre[idx+1])[0]
        for s in sub:
            if s in pre:
                continue
            elif e_n == list(s)[-1]:
                ans = s
                break
    elif idx == 0 and N == 1:
        sorted_sub = sorted(sub, key=lambda x : (len(x)))
        ans = sorted_sub[0]
    elif idx == N-1:
        s_n = list(pre[idx-1])[-1]
        for s in sub:
            if s in pre:
                continue
            elif s_n == list(s)[0]:
                ans = s
                break
else:
    s_n = list(pre[idx-1])[-1]
    e_n = list(pre[idx+1])[0]
    for s in sub:
        li = list(s)
        if s not in dc and li[0] == s_n and li[-1] == e_n:
            ans = s
            break
print(ans)
