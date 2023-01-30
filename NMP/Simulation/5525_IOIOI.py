import sys
from collections import deque
from heapq import heappop, heappush

input = sys.stdin.readline

T = int(input())
N = int(input())
st = input().rstrip()
idx = 0
count = 0
ans = 0
while idx < N:
    if count >= T:
        ans += 1
    if st[idx:idx + 3] == 'IOI':
        count += 1
        idx += 2
    else:
        idx += 1
        count = 0
print(ans)
