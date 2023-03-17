import math
import sys

input = sys.stdin.readline

# 2437
N = int(input())
li = list(map(int, input().split()))
li.sort()
start_range = 0
end_range = 0
flag = False
ans = -1
for i in li:
    cur_st = start_range + i
    cur_ed = end_range + i
    if cur_st <= end_range + 1:
        start_range = start_range
        end_range = cur_ed
    else:
        flag = True
        ans = end_range + 1
        break
if flag:
    print(ans)
else:
    print(end_range + 1)

