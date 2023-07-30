import heapq
import sys
from collections import deque
from datetime import datetime
from heapq import heappop, heappush

input = sys.stdin.readline

# 1213
S = list(input().rstrip())
dc = {}
for i in range(len(S)):
    if S[i] in dc:
        dc[S[i]] += 1
    else:
        dc[S[i]] = 1
odd_cnt = 0
odd_num = 0
odd_char = ''
for k, v in dc.items():
    if v % 2 == 1:
        odd_cnt += 1
        odd_num = v
        odd_char = k

sorted_dc = sorted(dc.items(), key=lambda x: x[0])

flag = True
ans = ""
if len(S) % 2 == 0:
    if odd_cnt > 0:
        flag = False
    else:
        for i in range(len(sorted_dc)):
            ans += (sorted_dc[i][0] * int(sorted_dc[i][1] // 2))
        ans += ans[::-1]
else:
    if odd_cnt > 1:
        flag = False
    elif odd_cnt == 1:
        if dc[odd_char] == 1:
            # 하나가 있으면 일단 뺴야됨
            for i in range(len(sorted_dc)):
                if sorted_dc[i][0] == odd_char:
                    continue
                else:
                    ans += (sorted_dc[i][0] * int(sorted_dc[i][1] // 2))
            ans += odd_char + ans[::-1]
        else:
            for i in range(len(sorted_dc)):
                ans += (sorted_dc[i][0] * int(sorted_dc[i][1] // 2))
            ans += odd_char + ans[::-1]
if not flag:
    print('I\'m Sorry Hansoo')
else:
    print(ans)

