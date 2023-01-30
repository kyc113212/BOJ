import copy
import math
import sys
from collections import deque
sys.setrecursionlimit(10**5)

input = sys.stdin.readline

#2239
def check_num(y, x):
    global board
    visited = [True] * 10
    for i in range(9):
        visited[int(board[y][i])] = False
    for i in range(9):
        visited[int(board[i][x])] = False
    # 작은칸도 포함해야한다
    std_y = y // 3
    std_x = x // 3

    for i in range(std_y*3,std_y*3 + 3):
        for j in range(std_x*3,std_x*3 + 3):
            visited[int(board[i][j])] = False

    ans_li = []
    for i in range(1,10):
        if visited[i]:
            ans_li.append(i)
    return ans_li

def solve(y, x):
    global zero_cnt, board
    if zero_cnt == 0:
        for i in range(9):
            for j in range(9):
                print(board[i][j],end='')
            print()
        return True
    for i in range(y,9):
        for j in range(x,9):
            if board[i][j] == '0':
                num_li = check_num(i,j)
                if not num_li:
                    return False
                for k in num_li:
                    board[i][j] = str(k)
                    zero_cnt -= 1
                    if solve(i,j + 1):
                        return True
                    zero_cnt += 1
                    board[i][j] = '0'
                return False
        x = 0

    return False





board = []
zero_cnt = 0
for _ in range(9):
    board.append(list(input().rstrip()))

for i in range(9):
    for j in range(9):
        if board[i][j] == '0':
            zero_cnt += 1

solve(0,0)
