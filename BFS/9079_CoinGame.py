import sys
from collections import deque
from datetime import datetime

input = sys.stdin.readline

def bfs(init_v):
    visited = set()
    dq = deque()
    dq.append([init_v, 0])
    while len(dq) > 0:
        cv, cnt = dq.popleft()
        if cv == '111111111' or cv == '000000000':
            return cnt
        if cv in visited:
            continue
        visited.add(cv)
        cv = list(cv)
        for i in range(8):
            temp_v = cv.copy()
            if i == 0:
                idx = 0
                for k in range(3):
                    if temp_v[idx + k] == '1':
                        temp_v[idx + k] = '0'
                    else:
                        temp_v[idx + k] = '1'
                temp_v = ''.join(temp_v)
                if temp_v in visited:
                    continue
                else:
                    dq.append([temp_v, cnt + 1])
            elif i == 1:
                idx = 3
                for k in range(3):
                    if temp_v[idx + k] == '1':
                        temp_v[idx + k] = '0'
                    else:
                        temp_v[idx + k] = '1'
                temp_v = ''.join(temp_v)
                if temp_v in visited:
                    continue
                else:
                    dq.append([temp_v, cnt + 1])
            elif i == 2:
                idx = 6
                for k in range(3):
                    if temp_v[idx + k] == '1':
                        temp_v[idx + k] = '0'
                    else:
                        temp_v[idx + k] = '1'
                temp_v = ''.join(temp_v)
                if temp_v in visited:
                    continue
                else:
                    dq.append([temp_v, cnt + 1])
            elif i == 3:
                idx = 0
                for k in range(3):
                    if temp_v[idx + 3 * k] == '1':
                        temp_v[idx + 3 * k] = '0'
                    else:
                        temp_v[idx + 3 * k] = '1'
                temp_v = ''.join(temp_v)
                if temp_v in visited:
                    continue
                else:
                    dq.append([temp_v, cnt + 1])
            elif i == 4:
                idx = 1
                for k in range(3):
                    if temp_v[idx + 3 * k] == '1':
                        temp_v[idx + 3 * k] = '0'
                    else:
                        temp_v[idx + 3 * k] = '1'
                temp_v = ''.join(temp_v)
                if temp_v in visited:
                    continue
                else:
                    dq.append([temp_v, cnt + 1])
            elif i == 5:
                idx = 2
                for k in range(3):
                    if temp_v[idx + 3 * k] == '1':
                        temp_v[idx + 3 * k] = '0'
                    else:
                        temp_v[idx + 3 * k] = '1'
                temp_v = ''.join(temp_v)
                if temp_v in visited:
                    continue
                else:
                    dq.append([temp_v, cnt + 1])
            elif i == 6:
                for k in range(0,9,4):
                    if temp_v[k] == '1':
                        temp_v[k] = '0'
                    else:
                        temp_v[k] = '1'
                temp_v = ''.join(temp_v)
                if temp_v in visited:
                    continue
                else:
                    dq.append([temp_v, cnt + 1])
            elif i == 7:
                for k in range(2,7,2):
                    if temp_v[k] == '1':
                        temp_v[k] = '0'
                    else:
                        temp_v[k] = '1'
                temp_v = ''.join(temp_v)
                if temp_v in visited:
                    continue
                else:
                    dq.append([temp_v, cnt + 1])
    return -1


for _ in range(int(input())):
    board = [list(map(str,input().split())) for _ in range(3)]
    ans = ''
    for i in range(3):
        for j in range(3):
            if board[i][j] == 'H':
                ans += '1'
            else:
                ans += '0'
    print(bfs(ans))
