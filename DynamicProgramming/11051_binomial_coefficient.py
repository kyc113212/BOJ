import sys
input = sys.stdin.readline

def dfs(n,k):
    if n == 0 or n == k or k == 0:
        DP[n][k] = 1
        return 1
    elif DP[n][k] != -1:
        return DP[n][k]
    else:
        DP[n][k] = (dfs(n-1,k-1) % 10007) + (dfs(n-1,k) % 10007)
        return DP[n][k]


if __name__ == "__main__":
    N, K = map(int,input().split())

    DP = [[-1]*(K+1) for _ in range(N+ 1)]

    dfs(N,K)
    print(DP[N][K] % 10007)

