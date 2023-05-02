import sys
import math
from collections import deque
from itertools import permutations

input = sys.stdin.readline

N = int(input())
li = []
ans = 0
for _ in range(N):
    li.append(input().rstrip())
for i in range(N):
    for j in range(i+1,N):
        dc = {}
        flag = True
        visitied = [False] * 26
        for k in range(len(li[i])):
            if li[i][k] in dc:
                if dc[li[i][k]] != li[j][k]:
                    flag = False
                    break
            else:
                if visitied[ord(li[j][k]) - 97]:
                    flag = False
                    break
                dc[li[i][k]] = li[j][k]
                visitied[ord(li[j][k]) - 97] = True
        if flag:
            ans += 1
print(ans)
