import sys
from collections import deque
from heapq import heappop, heappush
import math
sys.setrecursionlimit(10**9)

input = sys.stdin.readline

def solve(tdq):
    global check, li, visited
    if len(tdq) == K:
        num = ''
        for i in range(len(tdq)):
            num += str(tdq[i])
        check.add(int(num))
        return
    for i in range(N):
        if visited[i]:
            continue
        tdq.append(li[i])
        visited[i] = True
        solve(tdq)
        tdq.pop()
        visited[i] = False

N = int(input())
K = int(input())
li = []
check = set()
dq = deque()
visited = [False] * N

for _ in range(N):
    num = int(input())
    li.append(num)

for i in range(N):
    dq.append(li[i])
    visited[i] = True
    solve(dq)
    visited[i] = False
    dq.pop()
print(len(check))
