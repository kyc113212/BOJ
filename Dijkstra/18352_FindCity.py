import heapq
import sys
from collections import deque
from datetime import datetime
from heapq import heappop, heappush
input = sys.stdin.readline

class Node:
    def __init__(self, A, B):
        self.A = A
        self.B = B
    def __lt__(self, other):
        if self.B < other.B:
            return True
        else:
            return False
    # print사용해서 출력할 때 사용할 수 있다.
    def __str__(self):
        return self.A, self.B


# 18352
N, M, K, X = map(int, input().split())
graph = [[] for _ in range(N + 1)]
visited = [False] * (N+1)
ans = []
for i in range(M):
    a, b = map(int, input().split())
    graph[a].append(b)
heap = []
heapq.heappush(heap, Node(X,0))
while heap:
    hpq = heappop(heap)
    c_idx, c_dist = hpq.A, hpq.B
    if visited[c_idx]:
        continue
    visited[c_idx] = True
    if c_dist == K:
        ans.append(c_idx)
        continue
    if c_dist > K:
        break
    for v in graph[c_idx]:
        if visited[v]:
            continue
        heapq.heappush(heap, Node(v, c_dist + 1))
ans.sort()
if len(ans) == 0:
    print(-1)
else:
    for i in ans:
        print(i)
