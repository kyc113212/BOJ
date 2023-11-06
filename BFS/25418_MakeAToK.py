import heapq
import math
import sys
from collections import deque
from datetime import datetime
from heapq import heappop, heappush
input = sys.stdin.readline

# 25418
n, target = map(int, input().split())
st = set()

dq = deque()
dq.append([n,0])
while len(dq) > 0:
    v, cnt = dq.popleft()
    if v == target:
        print(cnt)
        break
    if v in st:
        continue
    st.add(v)
    n_v = v + 1
    if n_v > target:
        continue
    if n_v not in st:
        dq.append([n_v, cnt + 1])
    n_v = v * 2
    if n_v > target:
        continue
    if n_v not in st:
        dq.append([n_v, cnt + 1])
