import heapq
import math
import sys
from collections import deque
from datetime import datetime
from heapq import heappop, heappush

input = sys.stdin.readline

# 2564

C, R = map(int, input().split())
li = []
for _ in range(int(input())):
    dir, pos = map(int,input().split())
    li.append([dir, pos])

d_dir, d_pos = map(int, input().split())
ans = 0
for i in range(len(li)):
    if d_dir == 1:
        if li[i][0] == 1:
            ans += abs(d_pos - li[i][1])
        elif li[i][0] == 2:
            ans += (R + min(li[i][1] + d_pos, C - d_pos + C - li[i][1]))
        elif li[i][0] == 3:
            ans += (li[i][1] + d_pos)
        elif li[i][0] == 4:
            ans += (C - d_pos + li[i][1])
    if d_dir == 2:
        if li[i][0] == 1:
            ans += (R + min(li[i][1] + d_pos, C - d_pos + C - li[i][1]))
        elif li[i][0] == 2:
            ans += (abs(li[i][1] - d_pos))
        elif li[i][0] == 3:
            ans += (R - li[i][1] + d_pos)
        elif li[i][0] == 4:
            ans += (R - li[i][1] + C - d_pos)
    if d_dir == 3:
        if li[i][0] == 1:
            ans += (d_pos + li[i][1])
        elif li[i][0] == 2:
            ans += (R - d_pos + li[i][1])
        elif li[i][0] == 3:
            ans += abs(li[i][1] - d_pos)
        elif li[i][0] == 4:
            ans += (C + min(li[i][1] + d_pos, R - d_pos + R - li[i][1]))
    if d_dir == 4:
        if li[i][0] == 1:
            ans += (d_pos + C-li[i][1])
        elif li[i][0] == 2:
            ans += (R-d_pos + C - li[i][1])
        elif li[i][0] == 3:
            ans += (C + min(li[i][1] + d_pos, R - d_pos + R - li[i][1]))
        elif li[i][0] == 4:
            ans += abs(li[i][1] - d_pos)
print(ans)
