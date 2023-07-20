import math
import sys
from collections import deque

# sys.setrecursionlimit(10**5)
input = sys.stdin.readline

# 1251

def solve(tdq, idx):
    global ans
    if len(tdq) == 2:
        t1 = s[:tdq[0]]
        t2 = s[tdq[0]:tdq[1]]
        t3 = s[tdq[1]:]
        tans = t1[::-1] + t2[::-1] + t3[::-1]
        if ans == '':
            ans = tans
        else:
            ans = min(ans,tans)
        return

    for i in range(idx, len(s)):
        tdq.append(i)
        solve(tdq, i + 1)
        tdq.pop()

s = input().rstrip()
ans = ''
dq = deque()

for i in range(1,len(s)):
    dq.append(i)
    solve(dq, i + 1)
    dq.pop()
print(ans)
