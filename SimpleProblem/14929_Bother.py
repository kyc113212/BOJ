import sys
from collections import deque
from datetime import datetime

# 14929

N = int(input())
li = list(map(int, input().split()))
pre_sum = [0] * N
pre_sum[0] = li[0]
for i in range(1, N):
    pre_sum[i] = pre_sum[i-1] + li[i]
ans = 0
for i in range(N-1):
    ans += (li[i] * (pre_sum[N-1] - pre_sum[i]))
print(ans)
