import sys
import math
from collections import deque
from itertools import permutations

input = sys.stdin.readline

for _ in range(int(input())):
    J, M = map(int, input().split())
    ans = []
    for _ in range(M):
        R, C = map(int, input().split())
        ans.append(R*C)
    ans.sort(reverse=True)
    cnt = 0
    for i in ans:
        J -= i
        cnt += 1
        if J <= 0:
            break
    print(cnt)
