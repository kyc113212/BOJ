import sys
from collections import deque
from heapq import heappop, heappush

input = sys.stdin.readline

T = int(input())

for _ in range(T):
    N = int(input())
    li = list(map(int,input().split()))
    li.sort()
    ans = [0] * N
    end_idx = len(li)
    mid_idx = end_idx // 2
    end_idx -= 1
    ans[mid_idx] = li[end_idx]
    end_idx -= 1
    left = mid_idx - 1
    right = mid_idx + 1
    while end_idx >= 0:
        ans[left] = li[end_idx]
        end_idx -= 1
        left -= 1
        if end_idx < 0:
            break
        ans[right] = li[end_idx]
        end_idx -= 1
        right += 1
    maxV = abs(ans[0] - ans[-1])
    for idx in range(len(ans) - 1):
        maxV = max(maxV, abs(ans[idx]-ans[idx+1]))
    print(maxV)


