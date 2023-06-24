import sys
from collections import deque
from datetime import datetime

input = sys.stdin.readline


# 27964
N = int(input())
st = list(map(str,input().split()))
dc = {}
for i in st:
    if i[-6:] == 'Cheese':
        if i in dc:
            continue
        else:
            dc[i] = 1
if len(dc) >= 4:
    print('yummy')
else:
    print('sad')
