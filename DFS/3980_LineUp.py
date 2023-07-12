import sys
from collections import deque
from datetime import datetime
from heapq import heappop, heappush
input = sys.stdin.readline

# 3980

sys.setrecursionlimit(10**8)

board = []
visited = [False] * 11
num_cnt = [0] * 11
maxV = 0

def dfs(cnt, sumV, idx):
    global board, num_cnt, maxV
    if cnt == 11:
        maxV = max(maxV, sumV)
        return
    for i in range(11):
        if board[idx][i] == 0:
            continue
        else:
            if visited[i]:
                continue
            else:
                visited[i] = True
                sumV += board[idx][i]
                dfs(cnt + 1, sumV, idx + 1)
                sumV -= board[idx][i]
                visited[i] = False

for _ in range(int(input())):
    maxV = 0
    board.clear()
    num_cnt = [0] * 11
    visited = [False] * 11
    board = [list(map(int, input().split())) for _ in range(11)]
    dfs(0, 0, 0)
    print(maxV)
