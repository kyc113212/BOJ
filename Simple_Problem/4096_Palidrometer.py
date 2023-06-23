import sys
from collections import deque
from datetime import datetime

input = sys.stdin.readline

while True:
    s = list(input().rstrip())
    const_len = len(s)
    if len(s) == 1 and s[0] == '0':
        break
    num_s = int(''.join(s))
    cnt = 0
    while True:
        temp_li = list(str(num_s))
        if len(temp_li) != const_len:
            li = ['0'] * (const_len - len(temp_li)) + temp_li
        else:
            li = temp_li
        if li == li[::-1]:
            print(cnt)
            break
        num_s += 1
        cnt += 1
