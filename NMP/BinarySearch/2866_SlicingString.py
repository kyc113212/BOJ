import sys
from collections import deque
from datetime import datetime
from heapq import heappop, heappush

input = sys.stdin.readline

def check_dup(M):
    global board
    dc = {}
    for j in range(C):
        temp = ''
        for i in range(M, R):
            temp += board[i][j]
        if temp in dc:
            return False
        else:
            dc[temp] = True
    return True


# 2866
R, C = map(int, input().split())
board = [list(input().rstrip()) for _ in range(R)]

left = 0
right = R - 1
ans = 0
while left <= right:
    mid = (left + right) // 2
    if check_dup(mid):
        left = mid + 1
        ans = mid
    else:
        right = mid - 1
print(ans)
