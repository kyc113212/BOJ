import sys
from collections import deque
from heapq import heappop, heappush

input = sys.stdin.readline

A,B = map(int, input().split())
while B != 0:
    temp = A % B
    A = B
    B = temp

print(''.join(['1'] * A))
