import heapq
import math
import sys
from collections import deque
from datetime import datetime
from heapq import heappop, heappush
input = sys.stdin.readline

s = input().rstrip()

ans = []

for i in range(1,len(s)):
    for j in range(i+1,len(s)):
        ans_s = ''
        temp = s[:i]
        ans_s += temp[::-1]
        temp = s[i:j]
        ans_s += temp[::-1]
        temp = s[j:]
        ans_s += temp[::-1]
        ans.append(ans_s)
ans.sort()
print(ans[0])
