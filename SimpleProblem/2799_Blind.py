import sys
import math
from collections import deque
from itertools import permutations

input = sys.stdin.readline

R,C = map(int, input().split())
board = [list(input().rstrip()) for _ in range(R*5 + 1)]
ans = [0] * 5
TC = len(board[0])
TR = R*5 + 1
visited = [[False] * TC for _ in range(TR)]
for i in range(1, TR ,5):
    for j in range(1, TC, 5):
        star_cnt = 0
        for k in range(i,i+4):
            if board[k][j] == '*':
                star_cnt += 1
            else:
                break
        ans[star_cnt] += 1
print(*ans)
