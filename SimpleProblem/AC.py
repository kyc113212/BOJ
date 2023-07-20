import sys
from collections import deque
from heapq import heappop, heappush
sys.setrecursionlimit(10**8)

input = sys.stdin.readline

T = int(input())
for _ in range(T):
    cmd = input().rstrip()
    N = int(input())
    num = list(input().rstrip().split(','))
    num[0] = num[0][1:]
    num[-1] = num[-1][:-1]
    dq = deque()
    for i in range(len(num)):
        if num[i].isdigit():
            dq.append(int(num[i]))
    Rvs = False
    error_check = False
    for i in range(len(cmd)):
        if cmd[i] == 'R':
            if Rvs:
                Rvs = False
            else:
                Rvs = True
        if cmd[i] == 'D':
            if len(dq) == 0:
                error_check = True
                break
            else:
                if Rvs:
                    dq.pop()
                else:
                    dq.popleft()
    if error_check:
        print('error')
    else:
        if Rvs:
            print('[',end='')
            for i in range(len(dq) - 1,-1,-1):
                print(dq[i], end='')
                if i != 0:
                    print(',', end='')
            print(']')
           #print('[', ','.join(dq), ']', sep='')
        else:
            print('[', end='')
            for i in range(len(dq)):
                print(dq[i], end='')
                if i != len(dq) - 1:
                    print(',', end='')
            print(']')

