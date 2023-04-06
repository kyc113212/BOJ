import heapq
import sys
from collections import deque
from heapq import heappush, heappop
import math

input = sys.stdin.readline

N, M = map(int, input().split())
arr = [0] * (N+1)
li = list(map(int, input().split()))
li.sort()
for i in range(1, N+1):
    arr[i] = arr[i-1] + li[i-1]
for _ in range(M):
    A, B = map(int,input().split())
    print(arr[B] - arr[A-1])
