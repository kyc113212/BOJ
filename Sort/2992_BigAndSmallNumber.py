import math
import sys
from itertools import permutations

input = sys.stdin.readline

# 2992 크면서 작은 수

s = input().rstrip()
num = int(s)
li = list(s)
li.sort()
flag = False
real_ans = 0
for i in permutations(li,len(li)):
    ans = ''
    for j in i:
        ans = ans + j
    if int(ans) > num:
        real_ans = ans
        flag = True
        break
if flag:
    print(real_ans)
else:
    print(0)

