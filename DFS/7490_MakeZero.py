import sys
from collections import deque
from datetime import datetime
from heapq import heappop, heappush

input = sys.stdin.readline


sys.setrecursionlimit(10**8)
# 7490

def dfs(n, tli, cnt):
    if cnt == n - 1:
        num_list = deque()
        new_op_list = deque()
        num_list.append(1)
        for i in range(len(tli)):
            if tli[i] == ' ':
                num_list[-1] = num_list[-1] * 10 + (i + 2)
            else:
                new_op_list.append(tli[i])
                num_list.append(i + 2)

        sumV = num_list[0]
        for i in range(len(new_op_list)):
            if new_op_list[i] == '+':
                sumV += num_list[i + 1]
            else:
                sumV -= num_list[i + 1]
        if sumV == 0:
            temp_ans = ''
            temp_cnt = 1
            idx = 0
            while True:
                temp_ans += str(temp_cnt)
                temp_ans += tli[idx]
                # print(temp_cnt,end='')
                # print(tli[idx],end='')
                idx+=1
                temp_cnt+=1
                if temp_cnt > n-1:
                    break
            temp_ans += str(temp_cnt)
            ans_list.append(temp_ans)
            # print(temp_cnt)
        return

    for i in range(3):
        if i == 0:
            tli.append('+')
            cnt += 1
            dfs(n, tli, cnt)
            cnt -= 1
            tli.pop()
        elif i == 1:
            tli.append('-')
            cnt += 1
            dfs(n, tli, cnt)
            cnt -= 1
            tli.pop()
        else:
            tli.append(' ')
            cnt += 1
            dfs(n, tli, cnt)
            cnt -= 1
            tli.pop()

ans_list = []

for _ in range(int(input())):
    ans_list.clear()
    N = int(input())
    li = deque()
    dfs(N, li, 0)
    ans_list.sort()
    for i in ans_list:
        print(i)
    print()
