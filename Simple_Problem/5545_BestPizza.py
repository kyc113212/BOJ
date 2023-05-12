import sys
from collections import deque

input = sys.stdin.readline

N = int(input())
A, B = map(int,input().split())
C = int(input())
li = []
for _ in range(N):
    li.append(int(input()))
li.sort(reverse=True)
prev_ans = C // A
for i in range(N):
    temp = (C + sum(li[:i+1])) // (A + B*(i+1))
    prev_ans = max(prev_ans, temp)
print(prev_ans)
