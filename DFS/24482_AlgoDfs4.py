import sys
from collections import deque

input = sys.stdin.readline

sys.setrecursionlimit(10 ** 8)


def dfs(v):
    graph[v].sort(reverse=True)
    for i in range(len(graph[v])):
        if depth[graph[v][i]] == -1:
            depth[graph[v][i]] = depth[v] + 1
            dfs(graph[v][i])

N, M, R = map(int, input().split())
graph = [[] for _ in range(N + 1)]
depth = [-1] * (N + 1)
visited = [False] * (N + 1)
for _ in range(M):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

depth[R] = 0
dfs(R)
for i in range(1, N + 1):
    print(depth[i])
