import math
import sys

input = sys.stdin.readline

N = int(input())
li = list(map(str,input().split()))
dc = {}
for i in li:
    dc[i] = 0
for _ in range(N):
    tli = list(map(str,input().split()))
    for sa in tli:
        dc[sa] += 1

sorted_dc = sorted(dc.items(), key=lambda x: (-x[1],x[0]))

for s in sorted_dc:
    print(s[0], s[1],sep=' ')
