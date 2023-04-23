####################################################
################ Lotto #############################
import sys

input = sys.stdin.readline
dy = [-1, -1, 0, 1, 1, 1, 0, -1]
dx = [0, 1, 1, 1, 0, -1, -1, -1]

while True:
    R, C = map(int, input().split())
    if R == 0 and C == 0:
        break
    board = [list(map(str, input().rstrip())) for _ in range(R)]
    ans_board = [[0] * C for _ in range(R)]
    for i in range(R):
        for j in range(C):
            if board[i][j] == '.':
                for k in range(8):
                    ny = i + dy[k]
                    nx = j + dx[k]
                    if 0 <= ny < R and 0 <= nx < C:
                        if board[ny][nx] == '*':
                            ans_board[i][j] += 1
            elif board[i][j] == '*':
                ans_board[i][j] = '*'
    for i in range(R):
        for j in range(C):
            print(ans_board[i][j],end='')
        print()
