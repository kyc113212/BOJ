import heapq
import math
import sys
from collections import deque
from datetime import datetime
from heapq import heappop, heappush
input = sys.stdin.readline

for _ in range(int(input())):
    N = int(input())
    board = [list(map(str, input().rstrip())) for _ in range(N)]
    cur_robot = [i for i in range(N)]
    for i in range(len(board[0])):
        if len(cur_robot) == 1:
            break
        dc = {}
        for j in range(len(cur_robot)):
            if board[cur_robot[j]][i] in dc:
                continue
            else:
                dc[board[cur_robot[j]][i]] = 1
        if len(dc.keys()) == 1 or len(dc.keys()) == 3:
            continue
        else:
            temp_li = list(dc.keys())
            temp_li.sort()
            temp_robot = []
            if temp_li[0] == 'P' and temp_li[1] == 'R':
                # P만 살아남음
                for j in range(len(cur_robot)):
                    if board[cur_robot[j]][i] == 'P':
                        temp_robot.append(cur_robot[j])
            elif temp_li[0] == 'P' and temp_li[1] == 'S':
                # S만 살아남음
                for j in range(len(cur_robot)):
                    if board[cur_robot[j]][i] == 'S':
                        temp_robot.append(cur_robot[j])
            else:
                # R만 살아남음
                for j in range(len(cur_robot)):
                    if board[cur_robot[j]][i] == 'R':
                        temp_robot.append(cur_robot[j])
            cur_robot.clear()
            cur_robot = temp_robot.copy()
    if len(cur_robot) == 1:
        print(cur_robot[0] + 1)
    else:
        print(0)


