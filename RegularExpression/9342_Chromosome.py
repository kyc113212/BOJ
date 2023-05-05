import math
import sys
from collections import deque
from itertools import permutations
import re

input = sys.stdin.readline

#9342

p = re.compile('^[A-F]?A+F+C+[A-F]?$')
for _ in range(int(input())):
    s = input().rstrip()
    if p.match(s):
        print('Infected!')
    else:
        print('Good')
