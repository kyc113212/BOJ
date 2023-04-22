import math
import sys
from collections import deque

input = sys.stdin.readline

li = []
for _ in range(int(input())):
    A, B = map(int, input().split())
    li.append([A, B])
li.sort(key=lambda x: (-x[0], x[1]))
cut_line = li[4][0]
ans = 0
for i in range(5,len(li)):
    if li[i][0] == cut_line:
        ans += 1
print(ans)
