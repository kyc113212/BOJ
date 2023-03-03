import heapq
import sys
from collections import deque
from heapq import heappush, heappop
import math
#sys.setrecursionlimit(10**9)

input = sys.stdin.readline

def solve(idx):
    global ans
    bin_num = bin(idx)[2:]
    bin_num += '0' * (N - len(bin_num))
    start = 0
    link = 0
    for i in range(N):
        for j in range(i,N):
            if bin_num[i] == '1' and bin_num[j] == '1':
                start += board[i][j] + board[j][i]
            elif bin_num[i] == '0' and bin_num[j] == '0':
                link += board[i][j] + board[j][i]
    ans = min(ans,abs(start-link))


N = int(input())
board = [list(map(int,input().split())) for _ in range(N)]
ans = sys.maxsize

n_size = 2 << N - 1
for i in range(1,n_size):
    solve(i)
print(ans)
