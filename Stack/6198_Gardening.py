import heapq
import math
import sys
from collections import deque
from datetime import datetime
from heapq import heappop, heappush

input = sys.stdin.readline

# 6198
N = int(input())
li = []
for _ in range(N):
    li.append(int(input()))
st = deque()
st.append(li[0])
ans = 0
for i in range(1,len(li)):
    if li[i] < st[-1]:
        st.append(li[i])
        ans += (len(st) - 1)
    else:
        temp = 0
        # 뺄건 뺴야됨
        while True:
            st.pop()
            if len(st) == 0:
                st.append(li[i])
                break
            if st[-1] > li[i]:
                st.append(li[i])
                ans += (len(st) - 1)
                break
print(ans)
