import math
import sys
from collections import deque

input = sys.stdin.readline

def gcd(a, b):
    while b > 0:
        c = a % b
        a = b
        b = c
    return a

# 12871
a = input().rstrip()
b = input().rstrip()
lcm = (len(a) * len(b)) // gcd(len(a),len(b))
target_a = lcm // len(a)
target_b = lcm // len(b)
ans_a = ''
ans_b = ''
for i in range(target_a):
    ans_a += a
for i in range(target_b):
    ans_b += b
if ans_a == ans_b:
    print(1)
else:
    print(0)
