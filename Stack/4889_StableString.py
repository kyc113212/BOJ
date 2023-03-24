import heapq
import sys
from collections import deque
from heapq import heappush, heappop
import math

#sys.setrecursionlimit(10**9)
TC = 1

while True:
    s = input().rstrip()
    if s.find('-') >= 0:
        break
    ans = 0
    st = deque()
    for c in s:
        if len(st) == 0 and c == '}':
            st.append('{')
            ans += 1
        elif c == '}':
            st.pop()
        else:
            st.append(c)
    while len(st) != 0:
        # 나머지 처리
        if st[-1] == '{':
            ans += 1
            st.pop()
            st.pop()
    print(f'{TC}. {ans}')
    TC += 1

