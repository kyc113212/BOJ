import math
import sys
from collections import deque
from itertools import permutations
import re

# 14594

input = sys.stdin.readline

N = int(input())
room = []
for i in range(N):
    room.append(i+1)
for i in range(int(input())):
    a, b = map(int, input().split())
    cur_or = room[b - 1]
    for j in range(a-1,b):
        room[j] = room[a - 1]
    for j in range(N):
        if room[j] == cur_or:
            room[j] = room[a-1]

cnt = 0
prev_room = 0
for i in range(N):
    if prev_room != room[i]:
        prev_room = room[i]
        cnt += 1
print(cnt)
