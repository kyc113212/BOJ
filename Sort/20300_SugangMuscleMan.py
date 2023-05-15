import sys
from collections import deque

input = sys.stdin.readline

N = int(input())
li = list(map(int,input().split()))
li.sort()
maxV = 0
if len(li) % 2 == 0:
    for i in range(len(li)//2):
        maxV = max(maxV, li[i] + li[-1-i])
else:
    maxV = li[-1]
    for i in range(len(li)//2):
        maxV = max(maxV, li[i] + li[-2 - i])
print(maxV)
