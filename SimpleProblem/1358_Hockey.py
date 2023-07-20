import sys
from collections import deque
from datetime import datetime
from heapq import heappop, heappush

input = sys.stdin.readline

# 1358
W, H, X, Y, P = map(int, input().split())
cnt = 0
end_X = X + W
end_Y = Y + H
radius = H//2
left_circle_Y = Y + radius
right_circle_X = X + W
right_circle_Y = Y + radius
for i in range(P):
    a, b = map(int, input().split())
    flag = False
    if (a-X) ** 2 + (b-left_circle_Y) ** 2 <= radius**2:
        flag = True
    elif (right_circle_X-a) ** 2 + (b-right_circle_Y) ** 2 <= radius ** 2:
        flag = True
    elif X <= a <= X+W and Y <= b <= Y+H:
        flag = True
    if flag:
        cnt += 1
print(cnt)
