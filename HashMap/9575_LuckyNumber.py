import heapq
import sys
from collections import deque
from heapq import heappush, heappop
import math

# sys.setrecursionlimit(10**9)

for _ in range(int(input())):
    NA = int(input())
    A = list(set(list(map(int, input().split()))))
    NB = int(input())
    B = list(set(list(map(int, input().split()))))
    NC = int(input())
    C = list(set(list(map(int, input().split()))))
    cnt = 0
    dc = {}
    for i in range(len(A)):
        for j in range(len(B)):
            for k in range(len(C)):
                sum = str(A[i] + B[j] + C[k])
                flag = True
                for t in sum:
                    if t != '5' and t != '8':
                        flag = False
                        break
                if flag and sum not in dc:
                    dc[sum] = 1
                    cnt += 1
    print(cnt)

