import heapq
import sys
from collections import deque
from heapq import heappush, heappop
import math
#sys.setrecursionlimit(10**9)

input = sys.stdin.readline

#deque에 넣어도 되는지 확인 필요
class Node:
    def __init__(self, A, B):
        self.A = A
        self.B = B
    def __lt__(self, other):
        if self.B < other.B:
            return True
        else:
            return False
    def __str__(self):
        return self.A, self.B

def solve(idx):
    heap = []
    visited = [False] * (N + 1)
    heapq.heappush(heap, Node(idx, 0))
    ans = 0
    while len(heap) != 0:
        hpq = heapq.heappop(heap)
        c_idx, c_dist = hpq.A, hpq.B
        if visited[c_idx]:
            continue
        visited[c_idx] = True
        ans += items[c_idx]
        for i in range(len(graph[c_idx])):
            n_v = graph[c_idx][i][0]
            n_d = graph[c_idx][i][1]
            if visited[n_v]:
                continue
            if c_dist + n_d > M:
                continue
            heapq.heappush(heap,Node(n_v,c_dist + n_d))

    return ans


N, M, R = map(int,input().split())
items = [0] + list(map(int,input().split()))
graph = [[] * (N+1) for _ in range(N + 1)]
for _ in range(R):
    a,b,c = map(int,input().split())
    graph[a].append([b,c])
    graph[b].append([a,c])

ans_main = 0

# 시작은 1부터 N까지 한다
for i in range(1, N+1):
    ans_main = max(solve(i), ans_main)
print(ans_main)

