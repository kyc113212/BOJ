import sys

from collections import deque
from heapq import heappop, heappush

input = sys.stdin.readline

MOD = 1000000007

def fpow(C,n):
    if n == 1:
        return C
    else:
        x = fpow(C, n//2)
        if n % 2 == 0:
            return (x*x) % MOD
        else:
            return (x*x*C) % MOD

N, K = map(int,input().split())
A, B = 1, 1
for i in range(1,N+1):
    A *= i
    A %= MOD

nk, k = 1, 1
for i in range(1,N-K+1):
    nk *= i
    nk %= MOD
for i in range(1,K+1):
    k *= i
    k %= MOD
B = (nk * k) % MOD

B = fpow(B,1000000005) % MOD
print((A*B)%MOD)
