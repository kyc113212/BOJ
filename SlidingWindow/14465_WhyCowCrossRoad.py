import math
import sys
from collections import deque

input = sys.stdin.readline

N, K, B = map(int, input().split())
visited = [0] * (N + 1)
prefix_sum = [0] * (N+1)
for i in range(B):
    visited[int(input())] = 1
for i in range(1,N+1):
    prefix_sum[i] = prefix_sum[i-1] + visited[i]

ans = sys.maxsize
for i in range(1, N+1-K):
    ans = min(ans, prefix_sum[i+K] - prefix_sum[i])
print(ans)
