import sys
input = sys.stdin.readline

if __name__ == "__main__":
    N = int(input())
    alphabet = [0] * 27
    for i in range(N):
        s = input().rstrip()
        #for j in reversed(range(lens))
        for j in range(0,int(len(s))):
            alphabet[ord(s[j]) - 65] += (10 ** (int(len(s)) - j - 1))

    alphabet.sort(reverse=True)
    sum = 0
    cnt = 0
    for i in reversed(range(10)):
        sum += alphabet[9-i] * i
    print(sum)

