import sys
input = sys.stdin.readline

if __name__ == "__main__":
    N = int(input())
    dp = [-1] * 1001
    dp[0] = 0
    dp[1] = 1
    dp[2] = 3
    for i in range(3,N+1):
        dp[i] = dp[i-1] + 2 * dp[i-2]

    print(dp[N] % 10007)
