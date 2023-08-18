import sys
from collections import deque
from datetime import datetime
from heapq import heappop, heappush

input = sys.stdin.readline

# 5883
li = []
dc = {}
for _ in range(int(input())):
    li.append(int(input()))
    if li[-1] not in dc:
        dc[li[-1]] = 1

ans = 0

# 삭제할 숫자를 선택
for k, v in dc.items():
    prev_num = -1
    temp_ans = 1
    for i in range(len(li)):
        if li[i] == k:
            continue
        elif li[i] != prev_num:
            ans = max(temp_ans,ans)
            temp_ans = 1
            prev_num = li[i]
        elif li[i] == prev_num:
            temp_ans += 1
        ans = max(temp_ans, ans)
print(ans)
