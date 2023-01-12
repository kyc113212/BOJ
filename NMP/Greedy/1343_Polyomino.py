import sys
import math

from collections import deque
from heapq import heappop, heappush

input = sys.stdin.readline

board = input().rstrip()
board = board.replace('XXXX','AAAA')
board = board.replace('XX','BB')
if 'X' in board:
    print(-1)
else:
    print(board)
