import sys
from collections import deque
input = sys.stdin.readline

def bfs(v):
    visited = [0] * (N + 1)
    dq = deque()
    dq.append(v)
    visited[v] = 1
    cnt = 1

    while dq:
        cur_v = dq.popleft()
        for i in graph[cur_v]:
            next_v = i
            if visited[next_v] == 0:
                cnt += 1
                visited[next_v] = 1
                dq.append(next_v)

    return cnt



if __name__ == "__main__":
    N,M = map(int,input().split())
    graph = [[] * (N+1) for _ in range(N+1)]
    for i in range(M):
        a,b = map(int,input().split())
        graph[b].append(a)

    hacking = [0] * (N+1)
    rst = []
    maxV = 0

    for i in range(1,N+1):
        cnt = bfs(i)
        if maxV <= cnt:
            maxV = cnt
            rst.append([i,cnt])

    for i, cnt in rst:
        if maxV == cnt:
            print(i, end = ' ')

