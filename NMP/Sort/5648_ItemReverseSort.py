import heapq
import math
import sys
from collections import deque
from datetime import datetime
from heapq import heappop, heappush

#input = sys.stdin.readline
li = deque()
try:
    while True:
        pre_li = list(map(int, input().split()))
        for i in pre_li:
            li.append(i)
except EOFError:
    pass

li.popleft()
ans = []
for i in li:
    ans.append(int(''.join(list(str(i))[::-1])))
ans.sort()
print(*ans,sep='\n')
