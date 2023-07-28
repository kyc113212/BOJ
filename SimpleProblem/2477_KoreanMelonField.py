import heapq
import sys
from collections import deque
from datetime import datetime
from heapq import heappop, heappush

input = sys.stdin.readline

# 2477

N = int(input())
info = []
max_ver = 0
max_hor = 0

# long long short short

for _ in range(6):
    a, b = map(int, input().split())
    info.append([a,b])
    if a == 3 or a == 4:
        max_ver = max(max_ver, b)
    if a == 1 or a == 2:
        max_hor = max(max_hor, b)

flag = False

for i in range(5):
    if (info[i][1] == max_ver and info[i+1][1] == max_hor) or (info[i][1] == max_hor and info[i+1][1] == max_ver):
        flag = True
        hor = info[(i+3) % 6][1]
        ver = info[(i+4) % 6][1]
        print((max_ver * max_hor - (hor * ver)) * N)
        break
if not flag:
    if (info[0][1] == max_ver and info[-1][1] == max_hor) or (info[0][1] == max_hor and info[-1][1] == max_ver):
        hor = info[2][1]
        ver = info[3][1]
        print((max_ver*max_hor-(hor*ver))*N)
