import heapq
import sys
from collections import deque
from heapq import heappush, heappop
import math

# sys.setrecursionlimit(10**9)

S = input().rstrip()
cnt = 0
for _ in range(int(input())):
    ts = input().rstrip()
    for _ in range(len(ts) + 1):
        if ts.find(S) >= 0:
            cnt += 1
            break
        tts = ts[1:]
        tts += ts[0]
        ts = tts
print(cnt)
