import sys
from collections import deque
from heapq import heappop, heappush

input = sys.stdin.readline

N = int(input())
cnt = set()
li = list(map(int, input().split()))
for n in li:
    cnt.add(n)
sorted_cnt = sorted(cnt)
dc = {}
for i in range(len(sorted_cnt)):
    if sorted_cnt[i] not in dc:
        dc[sorted_cnt[i]] = i
for num in li:
    print(dc[num],end=' ')
