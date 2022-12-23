import sys
from collections import deque

input = sys.stdin.readline

def dfs(idx, cnt):
    global maxV, visited
    if cnt >= 2:
        return
    for i in range(N):
        if graph[idx][i] == 'Y':
            if not visited[i]:
                maxV += 1
            visited[i] = True
            dfs(i, cnt + 1)

N = int(input())
graph = [input().rstrip() for _ in range(N)]
ans = 0
maxV = 0
visited = []

for i in range(N):
    maxV = 0
    visited = [False] * N
    visited[i] = True;
    dfs(i, 0)
    ans = max(ans, maxV)

print(ans)
