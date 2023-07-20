import heapq
import sys
from collections import deque
from datetime import datetime
from heapq import heappop, heappush
input = sys.stdin.readline

# 15312
hik = [3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1]
A = list(input().rstrip())
B = list(input().rstrip())
combine = []
for i in range(len(A)):
    combine.append(hik[(ord(A[i]) - 65)])
    combine.append(hik[(ord(B[i]) - 65)])

while len(combine) > 2:
    temp_combine = []
    for i in range(len(combine) - 1):
        temp_combine.append((combine[i] + combine[i+1]) % 10)
    combine = temp_combine.copy()
print(*combine,sep='')
