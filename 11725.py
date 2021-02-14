N=int(input())

def bfs(ary, idx, visited):
    q=[idx]
    visited[idx]=True
    while q:
        v=q.pop(0)
        for i in range(len(ary[v])):
            if not visited[ary[v][i]]:
                q.append(ary[v][i])
                visited[ary[v][i]]=1
ary=[[] for i in range(N)]
for i in range(N-1):
    x,y=map(int, input().split())
    ary[x-1].append(y-1)
    ary[y-1].append(x-1)

visited=[0]*N
bfs(ary,0,visited)
