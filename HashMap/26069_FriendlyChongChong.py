import math
import sys

input = sys.stdin.readline

# 26069

dc = {}
flag = False
for _ in range(int(input())):
    A, B = map(str, input().split())

    if flag:
        if A in dc and B in dc:
            continue
        if A in dc and B not in dc:
            dc[B] = 1
        elif A not in dc and B in dc:
            dc[A] = 1
    else:
        if A == 'ChongChong' or B == 'ChongChong':
            flag = True
            dc['ChongChong'] = 1
        if A == 'ChongChong':
            dc[B] = 1
        elif B == 'ChongChong':
            dc[A] = 1
print(len(dc))

