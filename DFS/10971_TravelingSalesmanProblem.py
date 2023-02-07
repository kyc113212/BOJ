import copy
import math
import sys
from collections import deque
sys.setrecursionlimit(10**5)

input = sys.stdin.readline

#10971
def dfs(startV, nextV, cnt, sumV):
    global ans
    if cnt == N:
        if board[nextV][startV] == 0:
            return
        sumV += board[nextV][startV]
        ans = min(ans, sumV)
        return

    for i in range(N):
        if not visited[i] and board[nextV][i] != 0:
            visited[i] = True
            sumV += board[nextV][i]
            dfs(startV, i, cnt + 1, sumV)
            sumV -= board[nextV][i]
            visited[i] = False



N = int(input())
board = [list(map(int,input().split())) for _ in range(N)]
ans = 9876543210
visited = [False] * N

for i in range(N):
    visited = [False] * N
    visited[i] = True
    dfs(i, i, 1, 0)
print(ans)
