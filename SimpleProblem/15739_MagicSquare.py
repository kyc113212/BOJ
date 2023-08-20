import heapq
import sys
from collections import deque
from datetime import datetime
from heapq import heappop, heappush
input = sys.stdin.readline

# 15739

flag = True
N = int(input())
board = [list(map(int, input().split())) for _ in range(N)]
dc = {}
for i in range(N):
    for j in range(N):
        if board[i][j] in dc:
            flag = False
            break
        else:
            dc[board[i][j]] = 1

compare_sum = sum(board[0])
for i in range(N):
    if sum(board[i]) != compare_sum:
        flag = False
        break
for i in range(N):
    temp_sumV = 0
    for j in range(N):
        temp_sumV += board[j][i]
    if temp_sumV != compare_sum:
        flag = False
        break
temp_sumV = 0
for i in range(N):
    temp_sumV += board[i][i]
if temp_sumV != compare_sum:
    flag = False
temp_sumV = 0
for i in range(N):
    temp_sumV += board[i][N-i-1]
if temp_sumV != compare_sum:
    flag = False
if flag:
    print("TRUE")
else:
    print("FALSE")
