import math
import sys
from collections import deque

sys.setrecursionlimit(10**5)
input = sys.stdin.readline

def solve(l, r, depth):
    if depth == h:
        return
    mid = (l+r)//2
    ans[depth].append(li[mid])
    solve(l, mid, depth+1)
    solve(mid + 1, r, depth + 1)

h = int(input())
li = list(map(int,input().split()))
ans = list([] for _ in range(h))
solve(0, len(li), 0)
for i in range(h):
    print(*ans[i])
