import sys
from collections import deque
from datetime import datetime
from heapq import heappop, heappush

input = sys.stdin.readline

def solve(idx):
    global maxV, visited
    if not visited[graph[idx]]:
        maxV += 1
        visited[idx] = True
        solve(graph[idx])

# 3182
graph = []
global_maxV = 0
maxV = 0
max_idx = 0
for _ in range(int(input())):
    graph.append(int(input()) - 1)
visited = []
for i in range(len(graph)):
    visited = [False] * len(graph)
    maxV = 0
    solve(i)
    if maxV > global_maxV:
        global_maxV = maxV
        max_idx = i
print(max_idx+1)
