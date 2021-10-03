import sys
import heapq
input = sys.stdin.readline
rst_dist = []

def dij(v):
    global dist
    dist = [9876543221] * (N+1)
    heap = []
    dist[v] = 0
    heapq.heappush(heap,[0,v])

    while heap:
        c_cost, c_vertex = heapq.heappop(heap)
        if dist[c_vertex] < c_cost:
            continue;
        for nn, nc in data[c_vertex]:
            nc += c_cost
            if nc < dist[nn]:
                dist[nn] = nc
                heapq.heappush(heap,[nc,nn])




if __name__ == "__main__":
    N, M, K = map(int, input().split())
    data = [[] * (N+1) for _ in range(N+1) ]
    rst_dist = [0] * (N + 1)
    dist = []

    for i in range(M):
        a,b,c = map(int,input().split())
        data[a].append([b,c])
        
    for i in range(1,N+1):
        dij(i)
        rst_dist[i] = dist[K]

    dij(K)
    for i in range(1,N+1):
        rst_dist[i] += dist[i]
    print(max(rst_dist))
