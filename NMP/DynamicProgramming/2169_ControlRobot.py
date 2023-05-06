import math
import sys
from collections import deque
from itertools import permutations
import re

input = sys.stdin.readline

# 2169
N, M = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(N)]

DP = [[-sys.maxsize] * M for _ in range(N)]
DP[0][0] = board[0][0]
for i in range(1, M):
    DP[0][i] = max(DP[0][i], DP[0][i - 1] + board[0][i])

for i in range(1, N):
    left_to_right = board[i][:]
    right_to_left = board[i][:]

    for j in range(0, M):
        if j == 0:
            left_to_right[j] += DP[i-1][j]
        else:
            left_to_right[j] += max(DP[i-1][j], left_to_right[j-1])
    for j in range(M-1, -1,-1):
        if j == M - 1:
            right_to_left[j] += DP[i - 1][j]
        else:
            right_to_left[j] += max(DP[i - 1][j], right_to_left[j + 1])
    for j in range(M):
        DP[i][j] = max(left_to_right[j], right_to_left[j])
print(DP[N-1][M-1])
