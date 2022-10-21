import sys

input = sys.stdin.readline

if __name__ == "__main__":
    li = []
    li = list(input().split("-"))
    rst = ""
    for i in li:
        rst += i[0]

    print(rst)
