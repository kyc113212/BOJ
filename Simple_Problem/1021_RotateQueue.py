import math
import sys
from collections import deque

# sys.setrecursionlimit(10**5)
input = sys.stdin.readline

#1021

N, M = map(int,input().split())
dq = deque()

# 1~x 숫자
for i in range(N):
    dq.append(i+1)

li = list(map(int,input().split()))
cur_idx = 0
ans = 0

# 첫번째만 뺄 수 있다
for i in range(M):
    idx = dq.index(li[i])
    if idx <= len(dq) // 2:
        # 앞에서 뺸다
        while True:
            if dq[0] == li[i]:
                dq.popleft()
                break
            else:
                ans += 1
                dq.append(dq.popleft())
    else:
        while True:
            if dq[-1] == li[i]:
                ans += 1
                dq.pop()
                break
            else:
                ans += 1
                dq.appendleft(dq.pop())
print(ans)


