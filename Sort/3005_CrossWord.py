import heapq
import sys
from collections import deque
from datetime import datetime
from heapq import heappop, heappush
input = sys.stdin.readline

# 3005

R, C = map(int, input().split())
board = [list(map(str,input().rstrip())) for _ in range(R)]

ans = []
for i in range(R):
    temp = ""
    for j in range(C):
        if board[i][j] == '#':
            if len(temp) >= 2:
                ans.append(temp)
            temp = ""
        else:
            temp += board[i][j]
    if len(temp) >= 2:
        ans.append(temp)


for i in range(C):
    temp = ""
    for j in range(R):
        if board[j][i] == '#':
            if len(temp) >= 2:
                ans.append(temp)
            temp = ""
        else:
            temp += board[j][i]
    if len(temp) >= 2:
        ans.append(temp)

ans.sort()
print(ans[0])
