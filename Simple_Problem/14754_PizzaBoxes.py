import sys
from collections import deque

input = sys.stdin.readline

# 14754
N, M = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(N)]
visited = [[False] * M for _ in range(N)]
sumV = 0
for i in range(N):
    for j in range(M):
        sumV += board[i][j]
for i in range(N):
    maxV = 0
    m_i, m_j = 0,0
    for j in range(M):
        if board[i][j] > maxV:
            m_i = i
            m_j = j
            maxV = board[i][j]
    if visited[m_i][m_j]:
        continue
    visited[m_i][m_j] = True
    sumV -= maxV
for i in range(M):
    maxV = 0
    m_i, m_j = 0, 0
    for j in range(N):
        if board[j][i] > maxV:
            m_i = i
            m_j = j
            maxV = board[j][i]
    if visited[m_j][m_i]:
        continue
    visited[m_j][m_i] = True
    sumV -= maxV
print(sumV)
