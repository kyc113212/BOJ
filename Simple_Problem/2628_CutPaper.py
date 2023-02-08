import sys
from collections import deque
from heapq import heappop, heappush

input = sys.stdin.readline

C, R = map(int,input().split())
vr = []
hr = []
vr.append(0)
hr.append(0)
vr.append(C)
hr.append(R)
for _ in range(int(input())):
    a, b = map(int,input().split())
    if a == 0:
        hr.append(b)
    else:
        vr.append(b)

ans = 0
hr.sort()
vr.sort()

for i in range(len(hr) - 1):
    for j in range(len(vr) - 1):
        ans = max(ans,(vr[j+1] - vr[j]) * (hr[i+1] - hr[i]))
print(ans)
