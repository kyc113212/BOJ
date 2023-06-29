import sys
from collections import deque
from datetime import datetime
from heapq import heappop, heappush

input = sys.stdin.readline


def find(v):
    if parent[v] == v:
        return v
    parent[v] = find(parent[v])
    return parent[v]


def merge(a, b):
    a = find(a)
    b = find(b)
    if a == b:
        return
    if a > b:
        parent[a] = b
    elif a < b:
        parent[b] = a


N, M = map(int, input().split())
ans = 0
parent = [i for i in range(N)]
flag = False
for _ in range(M):
    a, b = map(int, input().split())
    if find(a) == find(b):
        ans += 1
        flag = True
        break
    merge(a, b)
    ans += 1
if flag:
    print(ans)
else:
    print(0)
