import sys
from collections import deque
from datetime import datetime
from heapq import heappop, heappush

input = sys.stdin.readline
# 1485
def solve(tli):
    ab_d = (tli[0][0] - tli[1][0]) ** 2 + (tli[0][1] - tli[1][1]) ** 2
    ac_d = (tli[0][0] - tli[2][0]) ** 2 + (tli[0][1] - tli[2][1]) ** 2
    bd_d = (tli[3][0] - tli[1][0]) ** 2 + (tli[3][1] - tli[1][1]) ** 2
    cd_d = (tli[3][0] - tli[2][0]) ** 2 + (tli[3][1] - tli[2][1]) ** 2
    bc_d = (tli[1][0] - tli[2][0]) ** 2 + (tli[1][1] - tli[2][1]) ** 2
    ad_d = (tli[0][0] - tli[3][0]) ** 2 + (tli[0][1] - tli[3][1]) ** 2
    if ab_d == ac_d == bd_d == cd_d:
        if bc_d == ad_d:
            return 1

    return 0

for _ in range(int(input())):
    li = []
    for _ in range(4):
        x, y = map(int, input().split())
        li.append([x, y])
    li.sort(key=lambda x: (x[0], x[1]))
    print(solve(li))
