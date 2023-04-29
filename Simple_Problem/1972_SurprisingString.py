import math
import sys
from collections import deque

input = sys.stdin.readline

#1972
while True:
    # 다시 풀어야됨
    # 길이간 기준으로
    s = input().rstrip()
    if s == '*':
        break
    flag = True

    for i in range(1,len(s)):
        # 건너 뛸 기준
        dc = {}
        for j in range(len(s) - i):
            temp = s[j] + s[j+i]
            if temp not in dc:
                dc[temp] = 1
            else:
                flag = False

    if not flag:
        print(f'{s} is NOT surprising.')
    else:
        print(f'{s} is surprising.')

