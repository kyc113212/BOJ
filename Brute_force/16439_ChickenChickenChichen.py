import sys
from collections import deque
from datetime import datetime

input = sys.stdin.readline

# 16439
N, M = map(int,input().split())
board = [list(map(int,input().split())) for _ in range(N)]
dq = deque()
ans = 0

def solve(ttdq):
    global ans
    tans = 0
    for i in range(N):
        tans += max(board[i][ttdq[0]], board[i][ttdq[1]], board[i][ttdq[2]])

    ans = max(ans, tans)


def dfs(tdq, idx):
    if len(tdq) == 3:
        solve(tdq)
        return

    for i in range(idx,M):
        dq.append(i)
        dfs(tdq, i+1)
        dq.pop()

for i in range(M):
    dq.append(i)
    dfs(dq, i+1)
    dq.pop()

print(ans)
