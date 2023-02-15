import sys
from collections import deque
from heapq import heappop, heappush
import math

input = sys.stdin.readline

def print_star(d_len, idx):
    # 첫 점 위치 설정
    for i in range(idx,d_len+idx):
        for j in range(idx,d_len+idx):
            if i == idx or i == d_len+idx-1 or j == idx or j == d_len+idx-1:
                li[i][j] = '*'


N = int(input())
s_len = (N-1) * 4 + 1
li = list([''] * s_len for _ in range(s_len))

for i in range(N):
    print_star(s_len - i * 4, i*2)

for i in range(s_len):
    for j in range(s_len):
        if li[i][j] == '*':
            print(li[i][j],end='')
        else:
            print(' ', end='')
    print()
