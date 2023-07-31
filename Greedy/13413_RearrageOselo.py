import sys
from collections import deque
from datetime import datetime
from heapq import heappop, heappush

input = sys.stdin.readline

for _ in range(int(input())):
    N = int(input())
    pro = list(input().rstrip())
    ans = list(input().rstrip())
    u_w_cnt, u_b_cnt, d_w_cnt, d_b_cnt = 0,0,0,0
    for i in range(len(pro)):
        if pro[i] != ans[i]:
            if pro[i] == 'W':
                u_w_cnt += 1
                d_b_cnt += 1
            else:
                u_b_cnt += 1
                d_w_cnt += 1
    print(max(u_w_cnt, d_w_cnt))
