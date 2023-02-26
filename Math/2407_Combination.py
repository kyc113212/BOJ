import math
import sys
from collections import deque

sys.setrecursionlimit(10**9)
input = sys.stdin.readline

# 2407

def combi(n, m):
    if com_arr[n][m] != 0:
        return com_arr[n][m]
    if n == m:
        return 1
    if m == 1:
        return n
    if n == 1:
        return 1
    if n == 0:
        return 1
    if m == 0:
        return 1

    com_arr[n][m] = combi(n-1,m) + combi(n-1,m-1)
    return com_arr[n][m]


N, M = map(int, input().split())
com_arr = list([0] * (M+1) for _ in range(N + 1))
print(combi(N,M))
