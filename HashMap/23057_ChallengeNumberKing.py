import sys
from collections import deque
from datetime import datetime
from heapq import heappop, heappush

input = sys.stdin.readline

sys.setrecursionlimit(10**8)

def solve(idx, num):
    global st, li
    if num > 0:
        st.add(num)
    for i in range(idx, len(li)):
        solve(i+1, num + li[i])


# 23057
st = set()
N = int(input())
li = list(map(int, input().split()))
li.sort()

solve(0, 0)
print(sum(li) - len(st))
