import math
import sys
from collections import deque

input = sys.stdin.readline

# 9417

def gcd(a,b):
    while b != 0:
        c = a % b
        a = b
        b = c
    return a


for _ in range(int(input())):
    li = list(map(int, input().split()))
    dq = deque()
    max_gcd = 0
    for i in range(len(li)):
        for j in range(i + 1,len(li)):
            max_gcd = max(max_gcd, gcd(li[i], li[j]))
    print(max_gcd)


