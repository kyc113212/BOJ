import sys
from collections import deque
from datetime import datetime
from heapq import heappop, heappush

input = sys.stdin.readline

N, M = map(int, input().split())
graph = [[] for _ in range(N)]
ans_list = [0] * N
for i in range(N):
    li = list(map(int,input().split()))
    li.sort(reverse=True)
    for j in range(len(li)):
        graph[i].append(li[j])

for i in range(M):
    max_val = 0
    for j in range(N):
        max_val = max(max_val, graph[j][i])
    for j in range(N):
        if max_val == graph[j][i]:
            ans_list[j] += 1
ans_max = max(ans_list)
for i in range(len(ans_list)):
    if ans_max == ans_list[i]:
        print(i+1,end=' ')
