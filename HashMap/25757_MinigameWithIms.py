import sys
from collections import deque
from datetime import datetime

input = sys.stdin.readline

# 25757
N, S = map(str,input().split())
dc = {}
for i in range(int(N)):
    s = input().rstrip()
    if s in dc:
        continue
    else:
        dc[s] = 1
if S == 'Y':
    print(len(dc))
elif S == 'F':
    print(len(dc) // 2)
else:
    print(len(dc) // 3)
