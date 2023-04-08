import math
import sys
from itertools import permutations
from collections import deque

input = sys.stdin.readline

# 2303

N = int(input())
li = [map(int,input().split()) for _ in range(N)]
ans = [0] * N
for i in range(N):
    temp_ans = 0
    temp_mod = 0
    for j in permutations(li[i],3):
        temp_mod = max(temp_mod, sum(j) % 10)
    ans[i] = temp_mod
max_idx = -1
max_v = 0
for i in range(N):
    if max_v <= ans[i]:
        max_idx = i + 1
        max_v = ans[i]
print(max_idx)
