import heapq
import sys
from collections import deque
from datetime import datetime
from heapq import heappop, heappush
input = sys.stdin.readline

# 19941
N, K = map(int, input().split())
board = list(input().rstrip())
ans = 0
visited = [False] * N
for i in range(N):
    if board[i] == 'H':
        for j in range(i-K, i+K+1):
            if j < 0 or j >= N:
                continue
            if board[j] == 'P' and not visited[j]:
                visited[j] = True
                ans += 1
                break
print(ans)
