import math
import sys
from collections import deque

sys.setrecursionlimit(10**6)
input = sys.stdin.readline

# 17609

def solve(l, r, p_cnt):
    global s
    if l >= r:
        return 0

    elif p_cnt == 0:
        if s[l] == s[r]:
            return solve(l+1, r-1, p_cnt)
        else:
            # 왼쪽 하나 빼고 진행
            temp = s[0:l] + s[l+1:]
            if temp == temp[::-1]:
                return 1
            # 오른쪽 하나 뺴고 진행
            temp = s[0:r] + s[r+1:]
            if temp == temp[::-1]:
                return 1
            return 2
    return 2

for _ in range(int(input())):
    s = input().rstrip()
    print(solve(0, len(s) - 1, 0))
