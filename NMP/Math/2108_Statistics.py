
import sys

input = sys.stdin.readline


li = []
for _ in range(int(input())):
    num = int(input())
    li.append(num)
li.sort()
# 산술 평균
print(round(sum(li)/len(li)))

#중앙값
print(li[len(li)//2])

#최빈값 - 동일한 count가 있다면 두번째 작은 값
dc = {}
for n in li:
    if n not in dc:
        dc[n] = 1
    else:
        dc[n] += 1
sted_li = sorted(dc.items(),key=lambda x : (-x[1],x[0]))
t = 0
if len(li) == 1:
    print(sted_li[0][0])
elif sted_li[0][1] == sted_li[1][1]:
    print(sted_li[1][0])
else:
    print(sted_li[0][0])

#범위
print(li[-1] - li[0])
