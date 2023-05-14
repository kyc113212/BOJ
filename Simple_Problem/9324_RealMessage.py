import math
import sys
from collections import deque
from itertools import permutations
import re

# 9324
for _ in range(int(input())):
    s = list(input().rstrip())
    idx = 0
    dc = {}
    flag = True
    while idx < len(s):
        if s[idx] in dc:
            dc[s[idx]] += 1
        else:
            dc[s[idx]] = 1
        if dc[s[idx]] % 3 == 0:
            if idx == len(s) -1:
                flag = False
                break
            if s[idx+1] != s[idx]:
                flag = False
                break
            idx += 1
        idx += 1
    if not flag:
        print('FAKE')
    else:
        print('OK')

