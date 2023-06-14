import sys
from collections import deque
from datetime import datetime

# 14492
N = int(input())
mat1 = [list(map(int,input().split())) for _ in range(N)]
mat2 = [list(map(int,input().split())) for _ in range(N)]
ans_mat = [[0] * N for _ in range(N)]
for i in range(N):
    for j in range(N):
        for k in range(N):
            ans_mat[i][j] |= (mat1[i][k] & mat2[k][j])
ans = 0
for i in range(N):
    for j in range(N):
        if ans_mat[i][j] == 1:
            ans += 1
print(ans)
