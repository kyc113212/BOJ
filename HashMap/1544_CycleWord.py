import sys
import math
from collections import deque
from itertools import permutations

input = sys.stdin.readline

check = set()
ans = 0
for _ in range(int(input())):
    s = deque(input().rstrip())
    ts = ''.join(s)
    if ts in check:
        continue
    for i in range(len(s)):
        check.add(''.join(s))
        s.append(s.popleft())
    ans += 1
print(ans)
