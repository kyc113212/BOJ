import heapq
import math
import sys
from collections import deque
from datetime import datetime
from heapq import heappop, heappush

input = sys.stdin.readline

# 10384
T = int(input())

for i in range(1,T+1):
    s = list(input().rstrip())
    dc = {}
    for j in range(len(s)):
        if s[j].isalpha():
            c = s[j]
            if s[j].isupper():
                c = s[j].lower()
            if c in dc:
                dc[c] += 1
            else:
                dc[c] = 1
    temp = 0
    sorted_dc = sorted(dc.items(), key=lambda x : x[1])
    if len(dc.items()) < 26:
        print(f'Case {i}: Not a pangram')
    elif sorted_dc[0][1] == 1:
        print(f'Case {i}: Pangram!')
    elif sorted_dc[0][1] == 2:
        print(f'Case {i}: Double pangram!!')
    else:
        print(f'Case {i}: Triple pangram!!!')
