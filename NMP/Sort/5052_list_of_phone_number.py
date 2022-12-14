#5052

import sys
from collections import deque

input = sys.stdin.readline

if __name__ == '__main__':
    T = int(input())
    for _ in range(T):
        N = int(input())
        li = []
        for _ in range(N):
            li.append(input().rstrip())
        li.sort()
        flag = False
        for i in range(N - 1):
            if li[i+1][0:len(li[i])] == li[i]:
                flag = True
                break
        if flag:
            print('NO')
        else:
            print('YES')
