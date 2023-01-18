import sys
from collections import deque
from heapq import heappop, heappush

input = sys.stdin.readline

N, M = map(int, input().split())
li = []
for _ in range(N):
    li.append(input().rstrip())

ansS = ''
for i in range(M):
    dc = {}
    for j in range(N):
        if li[j][i] not in dc:
            dc[li[j][i]] = 1
        else:
            dc[li[j][i]] += 1
    sort_dc = sorted(dc.items(), key = lambda item: (-item[1], item[0]))
    ansS += sort_dc[0][0]


tempV = 0
for i in range(N):
    for j in range(M):
        if li[i][j] != ansS[j]:
            tempV += 1
print(ansS)
print(tempV)
