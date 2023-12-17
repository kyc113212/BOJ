import heapq
import math
import sys
from collections import deque
from datetime import datetime
from heapq import heappop, heappush

input = sys.stdin.readline

# 2257
s = list(input().rstrip())
ans = 0
b_st = deque()
n_st = deque()

for i in range(len(s)):
    if s[i] == '(':
        b_st.append(s[i])
    elif s[i] == ')':
        temp = 0
        while True:
            if b_st[-1] == '(':
                b_st.pop()
                break
            temp += int(b_st[-1])
            b_st.pop()
        b_st.append(temp)
    elif s[i].isalpha():
        if s[i] == 'H':
            b_st.append(1)
        elif s[i] == 'C':
            b_st.append(12)
        elif s[i] == 'O':
            b_st.append(16)
    elif s[i].isdigit():
        b_st[-1] *= int(s[i])
print(sum(b_st))

