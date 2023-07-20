import sys
from collections import deque
from heapq import heappop, heappush
sys.setrecursionlimit(10**8)

input = sys.stdin.readline

MOD = 1000000007
N = int(input())
std_mat = [[1,1],[1,0]]

def mul_mat(m1, m2):
    rst_mat = list([0]*2 for _ in range(2))
    for i in range(2):
        for j in range(2):
            for k in range(2):
                rst_mat[i][j] += (m1[i][k] * m2[k][j]) % MOD
    return rst_mat

def power_calc(C, n):
    if n == 1:
        return C
    else:
        temp_mat = power_calc(C, n // 2)
        if n % 2 == 0:
            return mul_mat(temp_mat,temp_mat)
        else:
            return mul_mat(mul_mat(temp_mat,temp_mat), C)
if N == 0:
    print(0)
else:
    ans_mat = power_calc(std_mat, N)
    print(ans_mat[1][0] % MOD)
