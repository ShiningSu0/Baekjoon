#N,K=map(int, input().split())
#a1=list(map(int, input().split()))
N,M=map(int,input().split())
ary=[]
for i in range(N):
    a=list(input())
    for j in range(len(a)):
        a[j]=int(a[j])
    ary.append(a)
visited=[[0]*M for i in range(N)]
visited[0][0]=1
wall=[[0]*M for i in range(N)]
'''
block=[]
dc = [1, -1, 0, 0]
dr = [0, 0, -1, 1]
for i in range(N):
    for j in range(M):
        cnt=0
        for k in range(4):
            r=i+dr[k]
            c=j+dc[k]
            if 0<=c<M and 0<=r<N and ary[r][c]==0 and ary[i][j]==1:
                cnt+=1
        if cnt!=0:
            block.append([i,j])
'''
def bfs(start_row, start_col,visited):

    dc = [1, -1, 0, 0]
    dr = [0, 0, -1, 1]
    queue = [[start_row, start_col,True]]
    while queue:
        row,col = queue[0][0], queue[0][1]
        block=queue[0][2]
        queue.pop(0)        
        for i in range(4):
            r = row + dr[i]
            c = col + dc[i]
            if 0 <= c < M and 0 <= r < N:
                if ary[r][c] == 0 and visited[r][c]==0 and block:
                    visited[r][c]=1+visited[row][col]
                    queue.append([r, c,block])
                elif ary[r][c] == 0 and wall[r][c]==0 and not block:
                    wall[r][c]=1+wall[row][col]
                    queue.append([r, c,block])
                if block and ary[r][c]==1 and wall[r][c]==0:
                    wall[r][c]=1+visited[row][col]
                    queue.append([r,c,0])
                

ans=[]
bfs(0,0,visited)
print(visited)
print(wall)
if visited[-1][-1]==0 and wall[-1][-1]==0:
    print(-1)
elif visited[-1][-1]!=0 and wall[-1][-1]==0:
    print(visited[-1][-1])
elif visited[-1][-1]==0 and wall[-1][-1]!=0:
    print(wall[-1][-1])
elif visited[-1][-1]!=0 and wall[-1][-1]!=0:
    print(min(visited[-1][-1],wall[-1][-1]))
'''
ans.append(visited[N-1][M-1])
for i in range(len(block)):
    visited=[[0]*M for i in range(N)]
    visited[0][0]=1
    ary[block[i][0]][block[i][1]]=0
    bfs(0,0,visited)
    ans.append(visited[N-1][M-1])


real=[]
for i in range(ans):
    if ans[i]>0:
        real.append(ans[i])
if len(real)>0:
    print(min(real))
else:
    print(-1)
'''