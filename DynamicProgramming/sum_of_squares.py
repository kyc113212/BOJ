import sys
input = sys.stdin.readline

if __name__ == "__main__":
    N = int(input())

    dp = [987654321] * (N+1)
    dp[0] = 0
    for i in range(0,N+1):
        for j in range(int(i**(1/2)) + 1):
            dp[i] = min(dp[i], dp[i - j*j] + 1)

    print(dp[N])
