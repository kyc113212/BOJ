import sys
from heapq import heappop, heappush
from collections import deque

input = sys.stdin.readline

MOD = 1000000007

def fpow(C, n):
    if n == 1:
        return C
    else:
        x = fpow(C,n//2)
        if n % 2 == 0:
            return (x * x) % MOD
        else:
            return (x * x * C) % MOD

A = int(input())
X = int(input())

print(fpow(A,X) % MOD)
