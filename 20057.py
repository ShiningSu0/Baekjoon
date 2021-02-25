N=int(input())
sand=[]
for i in range(N):
    a=list(map(int,input().split()))
    sand.append(a)
start=[int((N-1)/2),int((N-1)/2)]
import math
visited=[ [0]*N for i in range(N)]
dr=[0,1,0,-1]
dc=[-1,0,1,0]
cnt=0
cum=-1
row=start[0]
col=start[1]

def tornado(x,r,c):
    y=[x[0]+r,x[1]+c]
    ratio=[0.02,0.10,0.07,0.01,0.05,0.10,0.07,0.01,0.02]
    position=[[-2,0],[-1,-1],[-1,0],[-1,1],[0,-2],[1,-1],[1,0],[1,1],[2,0]]
    if r==dr[1] and c==dc[1]:
        for i in range(len(position)):
            temp=position[i][1]
            position[i][1]=position[i][0]
            position[i][0]=temp*(-1)
    elif r==dr[2] and c==dc[2]:
        for i in range(len(position)):
            temp=position[i][0]
            position[i][1]=position[i][1]*(-1)
            position[i][0]=temp*(-1)
    elif r==dr[3] and c==dc[3]:
        for i in range(len(position)):
            temp=position[i][1]
            position[i][1]=position[i][0]*(-1)
            position[i][0]=temp
    num=0
    for i in range(len(position)):
        if 0<=y[0]+position[i][0]<N and 0<=y[1]+position[i][1]<N:
            sand[y[0]+position[i][0]][y[1]+position[i][1]]=int(sand[y[0]][y[1]]*ratio[i])+sand[y[0]+position[i][0]][y[1]+position[i][1]]
        num+=int(sand[y[0]][y[1]]*ratio[i])
    if 0<=y[0]+r<N and 0<=y[1]+c<N:
        sand[y[0]+r][y[1]+c]=sand[y[0]+r][y[1]+c]+sand[y[0]][y[1]]-num
    sand[y[0]][y[1]]=0


sandcnt=0
for i in range(N):
    for j in range(N):
        sandcnt+=sand[i][j]
while cnt<N*N:
    x=[row,col]
    visited[row][col]=1
    if 0<=row+dr[(cum+1)%4]<N and 0<=col+dc[(cum+1)%4]<N and visited[row+dr[int((cum+1)%4)]][col+dc[int((cum+1)%4)]]==0:       
        row=row+dr[int((cum+1)%4)]
        col=col+dc[int((cum+1)%4)]
        cum+=1
        tornado(x,dr[int((cum)%4)],dc[int((cum)%4)])
    else:
        row=row+dr[int((cum)%4)]
        col=col+dc[int((cum)%4)]
        tornado(x,dr[int((cum)%4)],dc[int((cum)%4)])
    cnt+=1
for i in range(N):
    for j in range(N):
        sandcnt-=sand[i][j]
print(sandcnt)