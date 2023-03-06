import heapq
import sys
from collections import deque
from heapq import heappush, heappop
import math

# sys.setrecursionlimit(10**9)

input = sys.stdin.readline

N = int(input())
li = []
visited = [False] * N
for _ in range(N):
    li.append(input().rstrip())
ans = 0

for i in range(N):
    if visited[i]:
        continue
    ans += 1
    for j in range(i + 1, N):
        dc = {}
        for k in range(len(li[i])):
            if li[i][k] in dc:
                dc[li[i][k]] += 1
            else:
                dc[li[i][k]] = 1
        if len(li[i]) != len(li[j]):
            continue
        if visited[j]:
            continue
        for k in range(len(li[j])):
            if li[j][k] in dc:
                dc[li[j][k]] -= 1
        flag = True
        for v in dc.values():
            if v != 0:
                flag = False
                break
        if flag:
            visited[j] = True

print (ans)
