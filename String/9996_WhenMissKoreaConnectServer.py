import math
import sys
from itertools import permutations
from collections import deque

input = sys.stdin.readline

#9996

N = int(input())
s = list(input().rstrip().split('*'))
for _ in range(N):
    ts = input().rstrip()
    flag = True
    if len(s) > len(ts):
        flag = False
    idx = 0
    if s[0] != ts[0:len(s[0])]:
        flag = False

    for i in range(len(s[-1])):
        if len(ts)-len(s[-1])+i < 0:
            flag = False
            break
        if s[-1][i] != ts[len(ts)-len(s[-1])+i]:
            flag = False
            break
    for i in range(0,len(s)):
        kwd = s[i]
        if ts[idx:].find(kwd) > -1:
            tidx = ts[idx:].find(kwd)
            idx += (len(kwd) + tidx)
        else:
            flag = False
    if flag:
        print('DA')
    else:
        print('NE')

