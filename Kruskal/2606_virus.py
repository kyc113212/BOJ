#2606

import sys

input = sys.stdin.readline

N,M = 0, 0
parent = []

def find(x):
    if x != parent[x]:
        return find(parent[x])
    return x

def merge(a, b):
    a = find(a)
    b = find(b)

    if a == b:
        return
    if a < b:
        parent[b] = a
    else:
        parent[a] = b

if __name__ == '__main__':
    N = int(input())
    M = int(input())
    parent = [i for i in range(N+1)]
    for _ in range(M):
        a,b = map(int,input().split())
        merge(a,b)

    print(sum(1 for i in range(2,N+1) if find(1) == find(i)))
