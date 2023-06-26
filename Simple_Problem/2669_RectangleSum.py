import sys
from collections import deque
from datetime import datetime

input = sys.stdin.readline

# 2669
board = [[0] * 101 for _ in range(101)]
for _ in range(4):
    x1, y1, x2, y2 = map(int, input().split())
    for i in range(x1,x2):
        for j in range(y1, y2):
            board[i][j] = 1

ans = 0

for i in range(101):
    for j in range(101):
        if board[i][j] == 1:
            ans += 1
print(ans)
