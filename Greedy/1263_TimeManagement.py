import sys
from collections import deque
from datetime import datetime

input = sys.stdin.readline

# 1263
N = int(input())
li = []
for _ in range(N):
    A, B = map(int,input().split())
    li.append([A,B])
li.sort(key=lambda x:(x[1],x[0]))

ans = -1
start_time = li[0][1] - li[0][0]
while start_time >= 0:

    cur_time = start_time
    flag = True
    for i in range(len(li)):
        cur_time += li[i][0]
        if cur_time > li[i][1]:
            flag = False
            break
    if flag:
        ans = start_time
        break

    start_time -= 1
    if start_time < 0:
        break
print(ans)
