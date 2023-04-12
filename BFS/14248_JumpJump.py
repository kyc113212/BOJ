import sys
import math
from collections import deque
from itertools import permutations

input = sys.stdin.readline

def bfs():
    start_idx = int(input()) - 1
    dq = deque()
    dq.append(start_idx)
    visited = [False] * N

    while len(dq) != 0:
        cur_idx = dq.popleft()
        if visited[cur_idx]:
            continue
        visited[cur_idx] = True
        move_range = li[cur_idx]
        for d in [-move_range, move_range]:
            next_idx = cur_idx + d
            if 0<= next_idx < N and not visited[next_idx]:
                dq.append(next_idx)
    ans = 0
    for i in visited:
        if i:
            ans += 1
    return ans


N = int(input())
li = list(map(int, input().split()))

print(bfs())
