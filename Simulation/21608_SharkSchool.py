import heapq
import math
import sys
from collections import deque
from datetime import datetime
from heapq import heappop, heappush
input = sys.stdin.readline

# 21608

dy = [-1,1,0,0]
dx = [0,0,-1,1]

N = int(input())
graph = [[] for _ in range(N*N)]
for i in range(N*N):
    tli = list(map(int, input().split()))
    for j in range(5):
        graph[i].append(tli[j])

board = [[0] * N for _ in range(N)]

for n in range(N*N):
    num = graph[n][0]
    va, pf = -1, -1
    y, x = -1, -1
    st = set()
    for i in range(1,5):
        st.add(graph[n][i])

    for i in range(N):
        for j in range(N):
            if board[i][j] == 0:
                tva, tpf = 0, 0
                for k in range(4):
                    ny = i + dy[k]
                    nx = j + dx[k]
                    if 0 <= ny < N and 0 <= nx < N:
                        if board[ny][nx] in st:
                            tpf += 1
                        if board[ny][nx] == 0:
                            tva += 1
                if tpf > pf:
                    y = i
                    x = j
                    pf = tpf
                    va = tva
                elif tpf == pf:
                    if tva > va:
                        y = i
                        x = j
                        va = tva
    board[y][x] = num

ans = 0
for i in range(N):
    for j in range(N):
        for k in range(N*N):
            if graph[k][0] == board[i][j]:
                t_ans = 0
                st = set()
                for m in range(1, 5):
                    st.add(graph[k][m])
                for m in range(4):
                    ny = i + dy[m]
                    nx = j + dx[m]
                    if 0 <= ny < N and 0 <= nx < N:
                        if board[ny][nx] in st:
                            t_ans += 1
                if t_ans == 1:
                    ans += 1
                elif t_ans == 2:
                    ans += 10
                elif t_ans == 3:
                    ans += 100
                elif t_ans == 4:
                    ans += 1000
                break
print(ans)


