import sys
from collections import deque
from heapq import heappop, heappush

input = sys.stdin.readline

N = input().rstrip()
ans = 0
len_s = len(N) - 1
fst_num = int(N) - 10 ** len_s + 1
ans += (fst_num * len(N))
for l in range(len_s,-1,-1):
    ans += int(9*(10**(l-1)) * l)
print(ans)
