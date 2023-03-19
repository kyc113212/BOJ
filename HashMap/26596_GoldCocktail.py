import math
import sys

input = sys.stdin.readline


def function(x):
    return x[1]


dc = {}
for _ in range(int(input())):
    A, B = map(str, input().split())
    if A in dc:
        dc[A] += int(B)
    else:
        dc[A] = int(B)

sorted_dc = sorted(dc.items(), key=function)
flag = False

for i in range(len(sorted_dc)):
    for j in range(i+1,len(sorted_dc)):
        if math.trunc(sorted_dc[i][1] * 1.618) == sorted_dc[j][1]:
            flag = True

if flag:
    print('Delicious!')
else:
    print('Not Delicious...')
