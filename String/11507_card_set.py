import sys
input = sys.stdin.readline

if __name__ == "__main__":

    cmd = input().rstrip()
    s = []
    visited = [[False] * 14 for _ in range(4)]
    flag = False
    for i in range(0,len(cmd),3):
        card = cmd[i]
        num = int(cmd[i+1] + cmd[i+2])
        if card == 'P':
            if visited[0][num] == True:
                flag = True
                break
            else:
                visited[0][num] = True
        if card == 'K':
            if visited[1][num] == True:
                flag = True
                break
            else:
                visited[1][num] = True
        if card == 'H':
            if visited[2][num] == True:
                flag = True
                break
            else:
                visited[2][num] = True
        if card == 'T':
            if visited[3][num] == True:
                flag = True
                break
            else:
                visited[3][num] = True

    if flag == True:
        print("GRESKA")
    else:
        for i in range(4):
            ans = 0
            for j in range(1,14):
                if visited[i][j] == True:
                    ans += 1
            print(13-ans, end = " ")
