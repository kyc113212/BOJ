import sys
from collections import deque
from datetime import datetime
from heapq import heappop, heappush

input = sys.stdin.readline

# 17103

arr = [False] * 1000001
for i in range(2, int(1000001 ** (1 / 2))):
    for j in range(i * i, 1000001, i):
        arr[j] = True
temp = 0

for _ in range(int(input())):
    N = int(input())
    ans = 0
    for i in range(2, N // 2 + 1):
        if False == arr[i] and arr[N - i] == False:
            ans += 1
    print(ans)
