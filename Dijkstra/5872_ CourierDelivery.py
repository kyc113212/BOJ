import heapq
import sys
from collections import deque
from heapq import heappop, heappush
from datetime import datetime

input = sys.stdin.readline

def dijkstra():
    q = []
    heapq.heappush(q, [0, 1])
    total = [sys.maxsize] * (N+1)
    while q:
        c_cost, c_v = heapq.heappop(q)
        if c_v == N:
            return c_cost
        if c_cost >= total[c_v]:
            continue
        total[c_v] = c_cost
        for n_cost, n_v in graph[c_v]:
            n_dist = c_cost + n_cost
            if total[n_v] <= n_dist:
                continue
            heapq.heappush(q,[n_dist, n_v])
    return -1



N, M = map(int, input().split())
graph = [[] for _ in range(N + 1)]
for i in range(M):
    a, b, c = map(int, input().split())
    graph[a].append([c, b])
    graph[b].append([c, a])
print(dijkstra())
