import sys
from collections import deque
from datetime import datetime
from heapq import heappop, heappush

input = sys.stdin.readline

# 2057
# 20!까지는 알고 있어야됨
li = [0] * 21
li[0] = 1
li[1] = 1
temp = 1
for i in range(2, 21):
    li[i] = li[i-1] * i
N = int(input())
flag = True
idx = 19
if N == 0:
    print("NO")
else:
    while True:
        if li[idx] <= N:
            N -= li[idx]
        idx -= 1
        if N == 0:
            break
        if idx < 0:
            flag = False
            break
    if flag:
        print("YES")
    else:
        print("NO")
