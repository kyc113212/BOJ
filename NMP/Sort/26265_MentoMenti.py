import sys
from collections import deque
from datetime import datetime

input = sys.stdin.readline

data = []
for _ in range(int(input())):
    A, B = map(str, input().split())
    data.append([A,B])

data = sorted(data, key=lambda x: x[1], reverse=True)
sorted_data = sorted(data, key=lambda x: x[0])

for i in range(len(data)):
    print(sorted_data[i][0],sorted_data[i][1],sep=' ')

