import copy
import math
import sys
from collections import deque

input = sys.stdin.readline

li = []
for _ in range(int(input())):
    li.append(int(input()))

cur_idx = 0
cur_num = 1

st = deque()
flag = False
ans = []

while True:

    if cur_num > len(li):
        break

    if len(st) == 0:
        st.append(cur_num)
        cur_num += 1
        ans.append('+')

    if st[len(st) - 1] == li[cur_idx]:
        ans.append('-')
        st.pop()
        cur_idx += 1
    else:
        st.append(cur_num)
        cur_num += 1
        ans.append('+')

st_len = len(st)
for _ in range(st_len):
    if st[len(st) - 1] == li[cur_idx]:
        ans.append('-')
        st.pop()
        cur_idx += 1
if len(st) == 0:
    for c in ans:
        print(c)
else:
    print('NO')
