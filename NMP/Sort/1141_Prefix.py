import sys
import math
from collections import deque
from itertools import permutations

input = sys.stdin.readline

li = []
for _ in range(int(input())):
    li.append(input().rstrip())
li.sort(key=lambda x : len(x))
visited = [False] * len(li)
cnt = 0
for i in range(len(li)):
    flag = False
    for j in range(i+1, len(li)):
        if li[i] == li[j][:len(li[i])]:
            flag = True
            break
    if not flag:
        cnt += 1
print(cnt)
