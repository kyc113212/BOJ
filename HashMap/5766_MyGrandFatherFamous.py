import heapq
import math
import sys
from collections import deque
from datetime import datetime
from heapq import heappop, heappush

input = sys.stdin.readline

# 5766

while True:
    a, b = map(int, input().split())
    if a == 0 and b == 0:
        break
    board = [list(map(int, input().split())) for _ in range(a)]
    dc = {}
    for i in range(a):
        for j in range(b):
            if board[i][j] in dc:
                dc[board[i][j]] += 1
            else:
                dc[board[i][j]] = 1
    sorted_dc = sorted(dc.items(), key = lambda x:(-x[1],x[0]))
    num2 = -1
    for i in range(len(sorted_dc)):
        if sorted_dc[i][1] != sorted_dc[0][1]:
            num2 = sorted_dc[i][1]
            break
    ans = []
    for i in range(len(sorted_dc)):
        if sorted_dc[i][1] == num2:
            ans.append(sorted_dc[i][0])
    print(*ans,sep=' ')
