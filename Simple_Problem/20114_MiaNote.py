import sys
import math
from collections import deque
from itertools import permutations

input = sys.stdin.readline

def solve(i):
    for j in range(0,H):
        for k in range(i,i+W):
            if board[j][k] != '?':
                return board[j][k]
    return '?'

N, H, W = map(int, input().split())
board = [list(map(str,input().rstrip())) for _ in range(H)]
ans = ''
for i in range(0,N*W,W):
    ans += solve(i)
print(ans)
