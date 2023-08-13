import heapq
import sys
from collections import deque
from datetime import datetime
from heapq import heappop, heappush
input = sys.stdin.readline

# 13717
num_ans = 0
name_ans = ''
level_cnt = 0
for _ in range(int(input())):
    name = input().rstrip()
    L, C = map(int, input().split())
    temp = 0
    while True:
        if C - L < 0:
            break
        C -= L
        C += 2
        temp += 1
    if temp > level_cnt:
        level_cnt = temp
        name_ans = name
    num_ans += temp
print(num_ans, name_ans, sep='\n')
