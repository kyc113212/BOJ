import sys
from collections import deque
from datetime import datetime

input = sys.stdin.readline

# 14709

def solve():
    if len(graph[1]) != 2:
        return False
    if graph[1][0] == 3:
        if graph[1][1] != 4:
            return False
    elif graph[1][0] == 4:
        if graph[1][1] != 3:
            return False
    else:
        return False

    if len(graph[3]) != 2:
        return False
    if graph[3][0] == 1:
        if graph[3][1] != 4:
            return False
    elif graph[3][0] == 4:
        if graph[3][1] != 1:
            return False
    else:
        return False

    if len(graph[4]) != 2:
        return False
    if graph[4][0] == 1:
        if graph[4][1] != 3:
            return False
    elif graph[4][0] == 3:
        if graph[4][1] != 1:
            return False
    else:
        return False

    return True

N = int(input())
graph = [[] for _ in range(6)]
for i in range(N):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

if solve():
    print('Wa-pa-pa-pa-pa-pa-pow!')
else:
    print('Woof-meow-tweet-squeek')
