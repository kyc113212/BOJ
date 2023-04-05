import math
import sys
from itertools import permutations
from collections import deque

input = sys.stdin.readline

#1337

A = list(map(int, input().split()))
B = list(map(int, input().split()))

A_SCORE = 0
B_SCORE = 0
win_flag = -1
for i in range(9):
    prev_A = A_SCORE
    prev_B = B_SCORE
    A_SCORE += A[i]
    if A_SCORE > prev_B:
        win_flag = 0
    B_SCORE += B[i]

    if win_flag == 0 and A_SCORE < B_SCORE:
        win_flag = 1
    elif A_SCORE > B_SCORE:
        win_flag = 0



if win_flag == 1:
    print('Yes')
else:
    print('No')
