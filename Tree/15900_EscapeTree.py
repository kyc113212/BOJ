import math
import sys
from collections import deque
from itertools import permutations
import re

input = sys.stdin.readline

# 15900
N = int(input())

tree = [[] for _ in range(N+1)]
visited = [False] * (N+1)
depth = [0] * (N+1)

for _ in range(N - 1):
    a, b = map(int,input().split())
    tree[a].append(b)
    tree[b].append(a)

dq = deque()
dq.append((1,0))
while len(dq) > 0:
    cv, c_depth = dq.popleft()
    visited[cv] = True
    for i in range(len(tree[cv])):
        nv = tree[cv][i]
        if visited[nv]:
            continue
        depth[nv] = c_depth + 1
        dq.append((nv, c_depth + 1))
ans = 0
for i in range(N+1):
    if len(tree[i]) == 1:
        ans += depth[i]
if ans % 2 == 0:
    print('No')
else:
    print('Yes')
