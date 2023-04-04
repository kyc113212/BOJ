import math
import sys
from itertools import permutations
from collections import deque

input = sys.stdin.readline

# 11899
s = input().rstrip()
ans = 0
st = deque()
for i in s:
    if i == ')':
        if len(st) == 0:
            ans += 1
        else:
            if st[-1] == '(':
                st.pop()
    else:
        st.append('(')
print(ans + len(st))
