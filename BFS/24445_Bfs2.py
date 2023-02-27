import sys
from collections import deque
from heapq import heappop, heappush
import math
#sys.setrecursionlimit(10**9)

input = sys.stdin.readline

def bfs():
   dq = deque()
   visited = [False] * (N + 1)
   dq.append(R)
   cnt = 1
   while len(dq) != 0:
      cv = dq.popleft()
      if visited[cv]:
         continue
      visited[cv] = True
      dist[cv] = cnt
      cnt = cnt + 1
      for i in range(len(graph[cv])):
         nv = graph[cv][i]
         if visited[nv]:
            continue
         dq.append(nv)

N, M, R = map(int, input().split())
graph = [[] for _ in range(N + 1)]
dist = [0] * (N + 1)
for _ in range(M):
   a, b = map(int, input().split())
   graph[a].append(b)
   graph[b].append(a)

for i in range(1, N + 1):
   graph[i].sort(reverse=True)

bfs()
for i in range(1,len(dist)):
   print(dist[i])
