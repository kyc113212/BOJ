import sys
import math
from collections import deque
from itertools import permutations

input = sys.stdin.readline

for _ in range(int(input())):
    A, B = map(str,input().split())
    cnt = 0
    cnt = A.count(B)
    print(cnt + len(A) - cnt * len(B))
