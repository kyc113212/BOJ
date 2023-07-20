import sys
from collections import deque
from datetime import datetime

input = sys.stdin.readline

# 5426
for i in range(int(input())):
    s = input().rstrip()
    cnt = 0
    while True:
        if cnt * cnt == len(s):
            break
        cnt += 1
    board = [[' '] * cnt for _ in range(cnt)]
    idx = 0
    for i in range(cnt):
        for j in range(cnt):
            board[i][j] = s[idx]
            idx += 1
    temp_board = [[' '] * cnt for _ in range(cnt)]
    ans = ''
    for i in range(cnt):
        for j in range(cnt):
            ans += board[j][cnt-1-i]
    print(ans)
