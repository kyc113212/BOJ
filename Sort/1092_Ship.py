import sys
from collections import deque
from heapq import heappop, heappush

input = sys.stdin.readline

N = int(input())
crain = list(map(int,input().split()))
M = int(input())
box = list(map(int,input().split()))

box.sort(reverse=True)
crain.sort(reverse=True)
ans = 0
box_cnt = 0
box_idx = 0
if crain[0] < box[0]:
    print(-1)
else:
    while True:
        for i in range(len(crain)):
            for idx in range(len(box)):
                if crain[i] >= box[idx]:
                    box.remove(box[idx])
                    break
        ans += 1
        if len(box) == 0:
            break
    print(ans)

