import sys
from collections import deque
from datetime import datetime
from heapq import heappop, heappush

input = sys.stdin.readline

def solve(l, r):
    min_v = sys.maxsize
    while l < r:
        mid = (l+r) // 2


# 14400

# 이분탐색으로 값을 찾자
# range는 max, min으로
x_val = []
y_val = []
for _ in range(int(input())):
    x, y = map(int, input().split())
    x_val.append(x)
    y_val.append(y)
x_val.sort()
y_val.sort()
min_x = x_val[len(x_val)//2]
min_y = y_val[len(x_val)//2]
ans = 0
for i in range(len(x_val)):
    ans += (abs(x_val[i]-min_x) + abs(y_val[i]-min_y))
print(ans)
