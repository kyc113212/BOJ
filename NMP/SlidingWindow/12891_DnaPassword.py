import heapq
import math
import sys
from collections import deque
from datetime import datetime
from heapq import heappop, heappush
input = sys.stdin.readline

# 12891

S, P = map(int, input().split())
st = list(map(str, input().rstrip()))
A, C, G, T = map(int, input().split())
cnt_a, cnt_c, cnt_g, cnt_t = 0, 0, 0, 0
ans = 0

for i in range(P):
    if st[i] == 'A':
        cnt_a += 1
    elif st[i] == 'C':
        cnt_c += 1
    elif st[i] == 'G':
        cnt_g += 1
    elif st[i] == 'T':
        cnt_t += 1

if cnt_a >= A and cnt_c >= C and cnt_g >= G and cnt_t >= T:
    ans += 1

for i in range(1,len(st) - P + 1):
    if st[i-1] == 'A':
        cnt_a -= 1
    elif st[i-1] == 'C':
        cnt_c -= 1
    elif st[i-1] == 'G':
        cnt_g -= 1
    elif st[i-1] == 'T':
        cnt_t -= 1

    if st[i+P-1] == 'A':
        cnt_a += 1
    elif st[i+P-1] == 'C':
        cnt_c += 1
    elif st[i+P-1] == 'G':
        cnt_g += 1
    elif st[i+P-1] == 'T':
        cnt_t += 1

    if cnt_a >= A and cnt_c >= C and cnt_g >= G and cnt_t >= T:
        ans += 1

print(ans)
