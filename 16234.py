ary=[]
import math
N,L,R=map(int,input().split())
for i in range(N):
    a=list(map(int,input().split()))
    ary.append(a)

def bfs(start_row, start_col,visited):
    dr = [0, 0, -1, 1]
    dc = [1, -1, 0, 0]
    queue = [[start_row, start_col]]
    temp=[[start_row, start_col]]
    while queue:
        cnt=0
        row,col = queue[0][0], queue[0][1]
        queue.pop(0)
        cnt+=1
        for i in range(4):
            r = row + dr[i]
            c = col + dc[i]
            if 0 <= c < N and 0 <= r < N and L<=abs(ary[row][col]-ary[r][c])<=R  and visited[r][c]==0:
                cnt+=1
                visited[r][c]=1 #(최단거리 : visited[r][c]=1+visited[row][col])
                queue.append([r, c])
               # if [r,c] not in temp:
                temp.append([r,c])
    return temp
IsTrue=True
cntt=0
while True:
    IsTrue=False
    visited=[[0]*N for i in range(N)]
    for i in range(N):
        for j in range(N):
            if visited[i][j]==0:
                visited[i][j]=1
                values=bfs(i,j,visited)
                if len(values)>1:
                    IsTrue=True
                    num = sum([ary[x][y] for x, y in values]) // len(values)
                    for x, y in values:
                        ary[x][y] = num
    if not IsTrue:
        break
    cntt+=1

print(cntt)

    


"""
def bfs(start_row, start_col,visited):

    dc = [1, -1, 0, 0]
    dr = [0, 0, -1, 1]
    queue = [[start_row, start_col]]
  #  queue = [[x, y]]
    while queue:
        row,col = queue[0][0], queue[0][1]
        cnt=0   
        queue.pop(0)
        for i in range(4):
            r = row + dr[i]
            c = col + dc[i]
            if 0 <= c < N and 0 <= r < N and L<=abs(ary[row][col]-ary[r][c])<=R and visited[r][c]==0:
                visited[r][c]=1 #(최단거리 : visited[r][c]=1+visited[row][col])
                cnt+=1
                queue.append([r, c])
    sumary=0
    if cnt==0:
        return 0
    else:
        for i in range(N):
            for j in range(N):
                if visited[i][j]==1:
                    sumary+=ary[i][j]
        val=math.floor(sumary/cnt)
        for i in range(N):
            for j in range(N):
                if visited[i][j]==1:
                    ary[i][j]=val
            return 1


visited=[[0]*N for i in range(N)]
ans=0
while True:
    visited=[[0]*N for i in range(N)]
    
    if bfs(0,0,visited):
        ans+=1
    else:
        break
    #print(visited)
    print(ary)
print(ans)
"""