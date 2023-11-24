import heapq
import math
import sys
from collections import deque
from datetime import datetime
from heapq import heappop, heappush

input = sys.stdin.readline

# 28278
st = deque()
for _ in range(int(input())):
    cmd = list(map(int, input().split()))
    if cmd[0] == 1:
        st.append(cmd[1])
    elif cmd[0] == 2:
        if len(st) == 0:
            print(-1)
        else:
            print(st[-1])
            st.pop()
    elif cmd[0] == 3:
        print(len(st))
    elif cmd[0] == 4:
        if len(st) == 0:
            print(1)
        else:
            print(0)
    elif cmd[0] == 5:
        if len(st) == 0:
            print(-1)
        else:
            print(st[-1])
