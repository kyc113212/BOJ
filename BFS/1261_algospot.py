import sys
from collections import deque

input = sys.stdin.readline
#().rstrip()

if __name__ == "__main__":
    M,N = map(int,input().split())
    graph = [list(map(int,input().rstrip())) for _ in range(N)]
    a = 0
    visited = [[0 for _ in range(M)] for _ in range(N)]
    crash = [[100001 for _ in range(M)] for _ in range(N)]

    dq = deque()
    dq.append((0,0))
    visited[0][0] = 1
    crash[0][0] = 0
    dy = [-1,1,0,0]
    dx = [0,0,-1,1]
    ans = 100001

    while dq:
        y, x = dq.popleft()

        '''if y == N-1 and x == M-1:
            ans = min(ans,)
'''

        for i in range(4):
            ny = y + dy[i]
            nx = x + dx[i]

            if 0 <= ny < N and 0 <= nx < M:
                if graph[ny][nx] == 1:
                    if crash[ny][nx] > crash[y][x] + 1:
                        crash[ny][nx] = crash[y][x] + 1
                        dq.append((ny,nx))
                elif graph[ny][nx] == 0:
                    if crash[ny][nx] > crash[y][x]:
                        crash[ny][nx] = crash[y][x]
                        dq.append((ny, nx))

    print(crash[N-1][M-1])
