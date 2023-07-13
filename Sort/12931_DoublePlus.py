import sys
from collections import deque
from datetime import datetime
from heapq import heappop, heappush
input = sys.stdin.readline

#12931
def solve_check(tli):
    for i in tli:
        if i != 0:
            return False
    return True


N = int(input())
li = list(map(int, input().split()))
cnt = 0
li.sort()
while True:
    for i in range(N):
        if li[i] % 2 == 1:
            li[i] -= 1
            cnt += 1
    if solve_check(li):
        break
    for i in range(N):
        li[i] = li[i] // 2
    cnt += 1

print(cnt)
