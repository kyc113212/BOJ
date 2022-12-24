import sys
from collections import deque

input = sys.stdin.readline

def bfs():
    global dist,graph,N,M
    dq = deque()
    dq.append((1,0))

    while len(dq) != 0:
        c_v, c_dist = dq.popleft()
        if dist[c_v] <= c_dist:
            continue
        dist[c_v] = c_dist
        for n_v in graph[c_v]:
            if dist[n_v] <= c_dist + 1:
                continue
            dq.append((n_v, c_dist+1))


N, M = map(int,input().split())
dist = [sys.maxsize] * (N+1)
graph = [[] for _ in range(N+1)]
for _ in range(M):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)
bfs()
max_dist = 0
for i in range(1,len(dist)):
    if dist[i] == sys.maxsize:
        continue
    max_dist = max(dist[i], max_dist)
print(dist.index(max_dist), max_dist, dist.count(max_dist),sep=' ')
