import sys
from collections import deque
from datetime import datetime
from heapq import heappop, heappush

input = sys.stdin.readline


# 1004
for _ in range(int(input())):
    x1, y1, x2, y2 = map(int, input().split())
    planet = []
    ans = 0
    for _ in range(int(input())):
        cx, cy, r = map(int, input().split())
        planet.append([cx,cy,r])
    in1 = [False] * len(planet)
    in2 = [False] * len(planet)
    for i in range(len(planet)):
        if ((x1-planet[i][0]) ** 2 + (y1-planet[i][1]) ** 2) <= (planet[i][2] ** 2):
            in1[i] = True
        if ((x2 - planet[i][0]) ** 2 + (y2 - planet[i][1]) ** 2) <= (planet[i][2] ** 2):
            in2[i] = True
    for i in range(len(in1)):
        if in1[i] != in2[i]:
            ans += 1
    print(ans)
