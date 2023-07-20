import math
import sys
from collections import deque

#sys.setrecursionlimit(10**9)
input = sys.stdin.readline


X, Y, W, S = map(int,input().split())
ans = 0
if W * 2 >= S:
    if W > S:
        if X < Y:
            ans = X * S
            if (Y - X) % 2 == 0:
                ans += (Y - X) * S
            else:
                ans += (Y - X - 1) * S + W
        else:
            ans = Y * S
            if (X - Y) % 2 == 0:
                ans += (X - Y) * S
            else:
                ans += (X - Y - 1) * S + W
            # ans = (X - Y) * S + Y * S
    elif X < Y:
        ans = (Y-X) * W + X * S
    else:
        ans = (X-Y) * W + Y * S
else:
    ans = (X+Y) * W
print(ans)
