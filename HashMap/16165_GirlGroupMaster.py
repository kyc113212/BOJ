import heapq
import sys
from collections import deque
from datetime import datetime
from heapq import heappop, heappush
input = sys.stdin.readline


# 16165
N, M = map(int, input().split())
team_member = [[] for _ in range(N)]
team_idx = {}
member_team = {}
for n in range(N):
    team_name = input().rstrip()
    num_cnt = int(input())
    team_idx[team_name] = n
    for i in range(num_cnt):
        member = input().rstrip()
        team_member[n].append(member)
        member_team[member] = team_name
    team_member[n].sort()

for i in range(M):
    member_name = input().rstrip()
    qst = int(input())
    if qst == 1:
        print(member_team[member_name])
    else:
        for i in team_member[team_idx[member_name]]:
            print(i)
