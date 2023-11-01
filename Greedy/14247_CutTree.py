import heapq
import math
import sys
from collections import deque
from datetime import datetime
from heapq import heappop, heappush
input = sys.stdin.readline

N = int(input())
tree = list(map(int, input().split()))
growth = list(map(int, input().split()))
growth.sort(reverse=True)
ans = 0
cnt = 0
for i in range(N-1,-1,-1):
    ans += growth[cnt] * i
    cnt += 1
print(ans + sum(tree))
