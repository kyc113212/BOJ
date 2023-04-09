import math
import sys
from itertools import permutations
from collections import deque

input = sys.stdin.readline

# 13417
for _ in range(int(input())):
    N = int(input())
    li = list(map(str, input().split()))
    # 좌 우로 넣었을때 사전순으로 가장 빠른것
    ans = ''
    for i in li:
        if len(ans) == 0:
            ans = i
        elif ord(ans[0]) < ord(i):
            ans += i
        else:
            ans = i + ans
    print(ans)
