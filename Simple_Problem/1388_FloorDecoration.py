import sys
from collections import deque
from heapq import heappop, heappush
import math

input = sys.stdin.readline

N, M = map(int,input().split())
li = list(list(map(str,input().rstrip())) for _ in range(N))
ans = 0
for i in range(N):
    prev_char = li[i][0]
    if prev_char == '-':
        ans += 1
    for j in range(1,M):
        if prev_char == '|' and li[i][j] == '-':
            ans += 1
        prev_char = li[i][j]

for i in range(M):
    prev_char = li[0][i]
    if prev_char == '|':
        ans += 1
    for j in range(1,N):
        if prev_char == '-' and li[j][i] == '|':
            ans += 1
        prev_char = li[j][i]
print(ans)
