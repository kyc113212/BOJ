import heapq
import sys
from collections import deque
from datetime import datetime
from heapq import heappop, heappush

# 4803

sys.setrecursionlimit(10**8)

input = sys.stdin.readline

def isMerge(a, b):
    global parent
    if parent[a] == parent[b]:
        return True
    else:
        return False

def find(a):
    global parent
    if a == parent[a]:
        return a
    parent[a] = find(parent[a])
    return parent[a]

def merge(a, b):
    global parent
    a = find(a)
    b = find(b)
    if a > b:
        parent[a] = parent[b]
    else:
        parent[b] = parent[a]


T = 1
while True:
    N, M = map(int, input().split())
    if N == 0 and M == 0:
        break
    graph = []
    parent = [i for i in range(N+1)]
    for _ in range(M):
        a, b = map(int, input().split())
        graph.append([a,b])
    dc_cycle = {}
    for i in range(M):
        if not isMerge(graph[i][0], graph[i][1]):
            merge(graph[i][0], graph[i][1])
        else:
            if parent[graph[i][0]] in dc_cycle:
                continue
            else:
                dc_cycle[parent[graph[i][0]]] = 1
    dc = {}
    cnt = 0
    for i in range(1,N+1):
        v_parent = find(i)
        if v_parent in dc_cycle:
            continue
        else:
            if v_parent in dc:
                continue
            else:
                dc[v_parent] = 1
    if len(dc) == len(dc_cycle):
        print(f"Case {T}: No trees.")
    elif len(dc) == 1:
        print(f"Case {T}: There is one tree.")
    elif len(dc) > 1:
        print(f"Case {T}: A forest of {len(dc)} trees.")
    else:
        print(f"Case {T}: No trees.")
    T += 1

