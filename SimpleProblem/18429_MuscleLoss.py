import math
import sys
from itertools import permutations

input = sys.stdin.readline

def solve(item):
    cur_status = 500
    for i in range(len(item)):
        cur_status += W[item[i]]
        cur_status -= K
        if cur_status < 500:
            return False
    return True

N, K = map(int,input().split())
W = list(map(int,input().split()))
li = []
ans = 0
for i in range(N):
    li.append(i)

for item in permutations(li):
    if solve(item):
        ans += 1
print(ans)
