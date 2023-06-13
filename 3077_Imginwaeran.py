import sys
from collections import deque
from datetime import datetime

# 3077
N = int(input())
slv = list(map(str,input().split()))
dc = {}
for i in range(len(slv)):
    dc[slv[i]] = i
ans = list(map(str,input().split()))

s_ans = 0

for i in range(len(ans)):
    for j in range(i+1,len(ans)):
        if dc[ans[i]] < dc[ans[j]]:
            s_ans += 1
print(f'{s_ans}/{(len(slv) * (len(slv) - 1))//2}')
