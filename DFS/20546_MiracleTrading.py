import sys
from collections import deque
from datetime import datetime
from heapq import heappop, heappush

input = sys.stdin.readline
sys.setrecursionlimit(10 ** 8)

# # 20546
def jun(remain, idx, stock_cnt):
    global bnp
    if idx == len(li):
        bnp = stock_cnt * li[-1] + remain
        return
    if li[idx] <= remain:
        temp_stock_cnt = (remain // li[idx])
        remain -= temp_stock_cnt * li[idx]
        jun(remain, idx + 1, stock_cnt + temp_stock_cnt)
    else:
        jun(remain, idx + 1, stock_cnt)


def sung(remain, idx, pm_cnt, stock_cnt):
    global timing
    if idx == 0:
        sung(remain, idx+1, pm_cnt, stock_cnt)
    else:
        if idx == len(li):
            timing = stock_cnt * li[-1] + remain
            return
        if li[idx] > li[idx - 1]:
            pm_cnt += 1
            if pm_cnt >= 3:
                # 전량 매도
                remain += (li[idx] * stock_cnt)
                stock_cnt = 0
                sung(remain, idx + 1, pm_cnt, stock_cnt)
            else:
                sung(remain, idx + 1, pm_cnt, stock_cnt)
        elif li[idx] < li[idx - 1]:
            if pm_cnt > 0:
                pm_cnt = -1
            else:
                pm_cnt -= 1
            if pm_cnt <= -3:
                # 전량 매수
                temp_stock_cnt = (remain // li[idx])
                remain -= temp_stock_cnt * li[idx]
                sung(remain, idx + 1, pm_cnt, stock_cnt + temp_stock_cnt)
            else:
                sung(remain, idx + 1, pm_cnt, stock_cnt)
        else:
            sung(remain, idx + 1, 0, stock_cnt)

N = int(input())
li = list(map(int, input().split()))

bnp = 0
timing = 0

jun(N, 0, 0)
sung(N, 0, 0, 0)
if bnp > timing:
    print("BNP")
elif bnp < timing:
    print("TIMING")
else:
    print("SAMESAME")
