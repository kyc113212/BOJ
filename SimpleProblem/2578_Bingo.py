import sys
from collections import deque
from heapq import heappop, heappush

input = sys.stdin.readline

def check_bingo():
    cnt = 0
    for i in range(5):
        flag = True
        for j in range(5):
            if visited[i][j] == 0:
                flag = False
                break
        if flag:
            cnt += 1
    for i in range(5):
        flag = True
        for j in range(5):
            if visited[j][i] == 0:
                flag = False
                break
        if flag:
            cnt += 1

    flag = True
    for i in range(5):
        if visited[i][i] == 0:
            flag = False
            break
    if flag:
        cnt += 1

    flag = True
    for i in range(5):
        if visited[i][4 - i] == 0:
            flag = False
            break
    if flag:
        cnt += 1

    return cnt

def find_num(num):
    for i in range(5):
        for j in range(5):
            if board[i][j] == num:
                visited[i][j] = 1
                return

board = [list(map(int,input().split())) for _ in range(5)]
visited = list([0] * 5 for _ in range(5))
num_list = []
for _ in range(5):
    num_list += list(map(int,input().split()))

cnt = 0
for t in range(25):
    find_num(num_list[t])
    cnt += 1
    if cnt >= 12 and check_bingo() >= 3:
        print(cnt)
        break




