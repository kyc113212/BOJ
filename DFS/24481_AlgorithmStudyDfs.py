import heapq
import math
import sys
from collections import deque
from datetime import datetime
from heapq import heappop, heappush

sys.setrecursionlimit(10**8)

input = sys.stdin.readline

# 24481

def dfs(idx, cnt):
    global visited, graph
    if visited[idx]:
        return
    visited[idx] = True
    cnt += 1
    for i in range(len(graph[idx])):
        if visited[graph[idx][i]]:
            continue
        ans[graph[idx][i]] = cnt
        dfs(graph[idx][i], cnt)

N, M, R = map(int, input().split())
graph = [[] for _ in range(N+1)]
visited = [False] * (N+1)
ans = [-1] * (N+1)
for i in range(M):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)
for i in range(1, N+1):
    graph[i].sort()

ans[R] = 0
dfs(R, 0)

for i in range(1,N+1):
    print(ans[i])

