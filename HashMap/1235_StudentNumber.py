import math
import sys
from collections import deque

#sys.setrecursionlimit(10**6)
input = sys.stdin.readline

def solve():
    ans = 0
    for i in range(len(li[0])):
        dc = {}
        for j in range(len(li)):
            if li[j][i:] not in dc:
                dc[li[j][i:]] = 1
            else:
                ans = len(li[0]) - (i - 1)
                return ans

li = []
for _ in range(int(input())):
    li.append(input().rstrip())


print(solve())
