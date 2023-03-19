import math
import sys

input = sys.stdin.readline

A, B, G = map(int, input().split())
liA = list(map(str,input().split()))
liB = list(map(str,input().split()))
dcA = {}
dcB = {}
for i in liA:
    dcA[i] = 1
for i in liB:
    dcB[i] = 1
cntA = 0
cntB = 0
ans = list(map(str,input().split()))
for i in ans:
    if i in dcA:
        cntA += 1
    elif i in dcB:
        cntB += 1
if cntA > cntB:
    print('A')
elif cntA < cntB:
    print('B')
else:
    print('TIE')
