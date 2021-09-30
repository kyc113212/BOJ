import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

dy = [-1,1,0,0]
dx = [0,0,-1,1]

def dfs(y,x):

    for i in range(4):
        ny = y + dy[i]
        nx = x + dx[i]
        if 0<=ny<N and 0 <=nx<M and visited[ny][nx] == 0 and graph[ny][nx] == 1:
            visited[ny][nx] = 1
            dfs(ny,nx)

if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        M, N, K = map(int, input().split())
        graph = [[0 for i in range(M)] for i in range(N)]
        for i in range(K):
            a, b = map(int, input().split())
            graph[b][a] = 1

        visited = [[0 for i in range(M)] for i in range(N)]

        cnt = 0
        for i in range(N):
            for j in range(M):
                if visited[i][j] == 0 and graph[i][j] == 1:
                    visited[i][j] = 1
                    dfs(i,j)
                    cnt += 1
        print(cnt)
