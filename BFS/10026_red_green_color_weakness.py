import sys
from collections import deque

input = sys.stdin.readline
sys.setrecursionlimit(1000000)

N = 0
three, two = 0, 0
dy = [-1, 1, 0, 0]
dx = [0, 0, -1, 1]
visited = []


def bfs(y, x, color):
    global N, dy, dx, visited

    dq = deque()
    dq.append((y, x))

    while dq:
        cy, cx = dq.popleft()
        if visited[cy][cx]:
            continue
        visited[cy][cx] = True

        for i in range(4):
            ny = cy + dy[i]
            nx = cx + dx[i]
            if ny < 0 or nx < 0 or nx >= N or ny >= N:
                continue
            if color != graph[ny][nx]:
                continue
            if visited[ny][nx]:
                continue
            dq.append((ny, nx))


if __name__ == "__main__":
    N = int(input())
    graph = []
    graph = [list(input().rstrip()) for _ in range(N)]

    visited = [[False] * N for _ in range(N)]
    for i in range(N):
        for j in range(N):
            if visited[i][j] == False:
                three += 1
                bfs(i, j, graph[i][j])

    for i in range(N):
        for j in range(N):
            if graph[i][j] == "G":
                graph[i][j] = "R"
    visited = [[False] * N for _ in range(N)]
    for i in range(N):
        for j in range(N):
            if visited[i][j] == False:
                two += 1
                bfs(i, j, graph[i][j])

    print(three,two)
