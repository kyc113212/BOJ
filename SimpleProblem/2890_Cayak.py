import heapq
import sys
from collections import deque
from datetime import datetime
from heapq import heappop, heappush
input = sys.stdin.readline

R, C = map(int, input().split())
board = [list(map(str,input().rstrip())) for _ in range(R)]
ans = [0] * 10
graph = []

for i in range(R):
    st = -1
    ed = -1
    num = -1
    for j in range(1,C-1):
        if board[i][j-1] == 'S' and board[i][j].isdigit():
            st = 1
            num = int(board[i][j])
        if board[i][j].isdigit() and board[i][j+1] == '.':
            ed = j
            num = int(board[i][j])
        if board[i][j] == '.' and board[i][j+1].isdigit():
            st = j + 1
            num = int(board[i][j+1])
        if board[i][j].isdigit() and board[i][j+1] == 'F':
            ed = j
            num = int(board[i][j])
    graph.append([st,ed,num])

graph.sort(key=lambda x : (-x[1],-x[0]))

cnt = 1
ans[graph[0][2]] = cnt
for i in range(1,len(graph)):
    if graph[i][2] == -1:
        continue
    if graph[i][0] == graph[i-1][0] and graph[i][1] == graph[i-1][1]:
        ans[graph[i][2]] = cnt
    else:
        cnt += 1
        ans[graph[i][2]] = cnt
for i in range(1,10):
    print(ans[i])
