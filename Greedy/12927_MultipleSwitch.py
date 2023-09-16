import heapq
import math
import sys
from collections import deque
from datetime import datetime
from heapq import heappop, heappush
input = sys.stdin.readline

s = list(input().rstrip())
cnt = 0
for i in range(len(s)):
    if s[i] == 'Y':
        cnt += 1
        for j in range(i,len(s),i+1):
            if s[j] == 'Y':
                s[j] = 'N'
            else:
                s[j] = 'Y'
print(cnt)
