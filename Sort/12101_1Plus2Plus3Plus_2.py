import sys
import math
from collections import deque
from itertools import permutations

input = sys.stdin.readline

def solve(sumV, dq):
    if sumV > n:
        return
    if sumV == n:
        ans = ''
        for i in range(len(dq)):
            if i != len(dq)-1:
                ans += str(dq[i])+'+'
            else:
                ans += str(dq[i])
        ans_li.append(ans)
        return
    for i in range(1,4):
        if sumV + i <= n:
            dq.append(i)
            solve(i + sumV, dq)
            dq.pop()

n, k = map(int, input().split())
dq = deque()
ans_li = []

for i in range(1,4):
    if i <= n:
        dq.append(i)
        solve(i, dq)
        dq.pop()
ans_li.sort()
if k > len(ans_li):
    print(-1)
else:
    print(ans_li[k-1])
