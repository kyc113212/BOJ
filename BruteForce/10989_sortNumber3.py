import sys
input = sys.stdin.readline

N = int(sys.stdin.readline())
arr = [0] * 10001
for i in range(N):
    arr[int(sys.stdin.readline())] += 1

for i in range(1, 10001):
    if arr[i] != 0:
        for j in range(arr[i]):
            print(i)

#if __name__ == "__main__":
