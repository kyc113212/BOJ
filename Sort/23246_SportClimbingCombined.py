import sys
from collections import deque
from datetime import datetime

input = sys.stdin.readline


# 23246
N = int(input())
li = []
for i in range(N):
    N, A, B, C = map(int,input().split())
    li.append([N,A+B+C,A*B*C])

li.sort(key=lambda x:(x[2],x[1],x[0]))
for i in range(3):
    print(li[i][0], end = ' ')
