import math
import sys
from collections import deque

input = sys.stdin.readline

#1895

R, C = map(int, input().split())
board = [list(map(int,input().split())) for _ in range(R)]
ans = []

for i in range(0, R-2):
    for j in range(0, C-2):
        temp = []
        for k in range(i,i+3):
            for m in range(j,j+3):
                temp.append(board[k][m])
        temp.sort()
        ans.append(temp[4])
T = int(input())
cnt = 0
for i in ans:
    if i >= T:
        cnt += 1
print(cnt)
