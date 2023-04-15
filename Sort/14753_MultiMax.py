import math
import sys
from itertools import permutations
from collections import deque

input = sys.stdin.readline

N = int(input())
li = list(map(int, input().split()))
li.sort(reverse=True)
maxV = 0
maxV = max(li[0] * li[1], li[0] * li[1] * li[2])
if li[-1] < 0 and li[-2] < 0:
    maxV = max(li[-1] * li[-2], li[-1] * li[-2] * li[-3], li[-1] * li[-2] * li[0], maxV)
print(maxV)
