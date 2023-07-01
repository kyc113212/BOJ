import sys
from collections import deque
from datetime import datetime
from heapq import heappop, heappush

input = sys.stdin.readline

sys.setrecursionlimit(10 ** 8)

# 24480

def dfs(v):
    global cnt
    graph[v].sort(reverse=True)
    for i in range(len(graph[v])):
        if visited[graph[v][i]] == 0:
            cnt += 1
            visited[graph[v][i]] = cnt
            dfs(graph[v][i])

N, M, R = map(int, input().split())
visited = [0] * (N+1)
graph = [[] for _ in range(N+1)]

for i in range(M):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)
cnt = 1
visited[R] = 1
dfs(R)
for i in range(1,N+1):
    if visited[i] == -1:
        print(0)
    else:
        print(visited[i])
