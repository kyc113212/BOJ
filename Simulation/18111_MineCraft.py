import copy
import sys

input = sys.stdin.readline

#18111
# max, min 값을 board의 최대 최소로 정하고 min값 찾아보기

def solve():
    # 블록의 갯수는 한정되어 있다.
    # 블록을 빼면 2초
    # 블록을 쌓으면 1초
    # 일단 블록을 뺴는 작업부터 먼저 한다.
    # 이후에 남은 블럭으로 채워 넣는다
    # 시간에 대한 이슈가 있댜. 2차원배열은 통과하지 못하고 1차원 배열로 했을때 통과한다
    min_height = 0
    min_time = sys.maxsize
    for cur_h in range(min_h, max_h+1):
        temp_B = B
        temp_time = 0
        #빼는 작업
        for i in range(N * M):
            if board[i] > cur_h:
                temp_B += (board[i] - cur_h)
                temp_time += (board[i] - cur_h) * 2
            elif board[i] < cur_h:
                temp_B -= (cur_h - board[i])
                temp_time += (cur_h - board[i])

        if temp_B >= 0:
            if min_time >= temp_time:
                min_height = cur_h
                min_time = temp_time
    return min_height, min_time


N, M, B = map(int,input().split())

board = []
for _ in range(N):
    board += list(map(int,input().split()))
min_h = min(board)
max_h = max(board)

ans_height, ans_time = solve()
print(ans_time,ans_height,sep=' ')
