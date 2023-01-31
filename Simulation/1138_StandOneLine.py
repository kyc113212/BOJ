import sys
from collections import deque
from heapq import heappop, heappush

input = sys.stdin.readline

N = int(input())
li = list(map(int,input().split()))

# -1이면 본인 보다 큰 것
ans = [-1] * N
for i in range(N):
    left = li[i]
    cnt = 0
    for j in range(N):
        if cnt == left and ans[j] == -1:
            ans[j] = i + 1
            break
        if ans[j] == -1 or ans[j] > i+1:
            cnt += 1
for i in ans:
    print(i,end=' ')

