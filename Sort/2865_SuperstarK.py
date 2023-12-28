import heapq
import math
import sys
from collections import deque
from datetime import datetime
from heapq import heappop, heappush

input = sys.stdin.readline

# 2865
N, M, K = map(int, input().split())
board = [[] for _ in range(N+1)]
ans = []
for i in range(M):
    li = list(map(float, input().split()))
    for j in range(0,len(li),2):
        board[int(li[j])].append(li[j+1])

for i in range(1, N+1):
    board[i].sort(reverse=True)
    ans.append(board[i][0])

ans.sort(reverse=True)
print(f'{round(sum(ans[:K]),1)}')
