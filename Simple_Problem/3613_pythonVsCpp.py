import heapq
import sys
from collections import deque
from heapq import heappush, heappop
import math
#sys.setrecursionlimit(10**9)

input = sys.stdin.readline

s = input().rstrip()
java = True
cpp = True

if s[0] == '_':
    java, cpp = False, False
if s[-1] == '_':
    java, cpp = False, False
for i in range(1,len(s)):
    if s[i-1] == '_' and s[i] == '_':
        java, cpp = False, False
        break

# 모두 소문자에 언더바가 있는지 확인 : cpp
for i in s:
    if i.isupper():
        cpp = False
        break
# 언더바가 없고 첫번째는 소문자에다가 중간에 대문자가 있는지 확인 : java
if not cpp:
    Flag = False
    for i in s:
        if i == '_':
            java = False
            Flag = True
            break
    if not Flag:
        java_li = []
        if s[0].isupper():
            java = False
        else:
            temp = ''
            for i in s:
                if i.isupper():
                    java_li.append(temp)
                    temp = i.upper()
                else:
                    temp += i
            java_li.append(temp)

if cpp:
    temp_s = s.split('_')
    for i in range(len(temp_s)):
        if i == 0:
            print(temp_s[i],end='')
        else:
            print(temp_s[i][0].upper(),end='')
            print(temp_s[i][1:],end='')
elif java:
    for i in range(len(java_li)):
        print(java_li[i].lower(),end='')
        if i == len(java_li) - 1:
            continue
        else:
            print('_',end='')
else:
    print('Error!')



