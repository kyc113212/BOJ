import math
import sys
from itertools import permutations
from collections import deque
sys.setrecursionlimit(10**8)

input = sys.stdin.readline

def dfs(t_ans, cnt):
    global ans, li
    if int(N) >= int(t_ans):
        ans = max(ans,int(t_ans))
    if cnt == len(N):
        if int(N) >= int(t_ans):
            ans = max(ans,int(t_ans))
        return
    for i in range(len(li)):
        dfs(t_ans + str(li[i]), cnt + 1)

# 18511
N, K = map(str, input().split())
li = list(map(int, input().split()))
li.sort()
ans = 0

for i in range(len(li)):
    dfs(str(li[i]), 1)
print(ans)


