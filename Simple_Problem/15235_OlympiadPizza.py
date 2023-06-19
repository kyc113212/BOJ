import sys
from collections import deque
from datetime import datetime

input = sys.stdin.readline

# 15235
N = int(input())
li = list(map(int,input().split()))
time_ans = [0] * N
dq = deque()
for i in range(N):
    dq.append(i)
time = 1
while len(dq) > 0:
    cv = dq.popleft()
    li[cv] -= 1
    time_ans[cv] = time
    time += 1
    if li[cv] > 0:
        dq.append(cv)
print(*time_ans)
