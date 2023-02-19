import math
import sys
from collections import deque

# sys.setrecursionlimit(10**5)
input = sys.stdin.readline

def preorder(c):
    if c == '.':
        return
    print(c,end='')
    preorder(li[c][0])
    preorder(li[c][1])


def inorder(c):
    if c == '.':
        return
    inorder(li[c][0])
    print(c,end='')
    inorder(li[c][1])

def postorder(c):
    if c == '.':
        return
    postorder(li[c][0])
    postorder(li[c][1])
    print(c,end='')

li = {}
for _ in range(int(input())):
    ro,l,r = map(str,input().split())
    li[ro] = (l,r)

preorder('A')
print()
inorder('A')
print()
postorder('A')

