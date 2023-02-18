import math
import sys
from collections import deque

# sys.setrecursionlimit(10**5)
input = sys.stdin.readline

N = int(input())
board = [0] * (N+1)
for _ in range(N - 1):
    a,b = map(int,input().split())
    board[a] += 1
    board[b] += 1

for _ in range(int(input())):
    a, b = map(int,input().split())
    if a == 1:
        if board[b] >= 2:
            print('yes')
        else:
            print('no')
    else:
        print('yes')
