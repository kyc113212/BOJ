import sys
import math
from collections import deque
from itertools import permutations

input = sys.stdin.readline

for _ in range(int(input())):
    N = int(input())
    li = []
    maxV = 0
    max_idx = -1
    max_cnt = 0
    for i in range(N):
        temp = int(input())
        li.append(temp)
        if temp > maxV:
            max_idx = i
            maxV = temp
            max_cnt = 1
        elif temp == maxV:
            max_cnt += 1
    sum_v = sum(li)
    if max_cnt > 1:
        print('no winner')
    elif sum_v // 2 < maxV:
        print(f'majority winner {max_idx + 1}')
    else:
        print(f'minority winner {max_idx + 1}')

