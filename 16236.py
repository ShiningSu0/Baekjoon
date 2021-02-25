N=int(input())
babyshark=[]
ary=[]
for i in range(N):
    a=list(map(int,input().split()))
    for j in range(len(a)):
        if a[j]==9:
            babyshark=[0,i,j]
            break
            
    ary.append(a)
    
def bfs(start_row,start_col,visited):
    dr=[0,0,1,-1]
    dc=[-1,1,0,0]
    global power,babyshark,flag,eat,answer
    queue=[[0,start_row,start_col]]
    candidate=[]
    while queue:
        time,row,col=queue[0][0],queue[0][1],queue[0][2]
        queue.pop(0)
        for i in range(4):
            r=row+dr[i]
            c=col+dc[i]
            if 0<=c<N and 0<=r<N and visited[r][c]==0:
                visited[r][c]=1+visited[row][col]
                if ary[r][c]==0 or ary[r][c]==power:
                    queue.append([visited[r][c],r,c])
                elif ary[r][c]>power:
                    continue
                else:
                    babyshark=[visited[r][c],r,c]
                  #  print('걸림',babyshark)
                    candidate.append(babyshark)
    if len(candidate)==0:  
        flag=False
        return 0
        
    else:
        candidate.sort()
        babyshark=candidate[0]
       # print(babyshark)
        eat+=1
        ary[babyshark[1]][babyshark[2]]=0
        answer+=babyshark[0]
       # print(visited)
        if eat==power:
            eat=0
            power+=1 
        return candidate[0]
power=2
eat=0
ary[babyshark[1]][babyshark[2]]=0
flag=True
answer=0
while flag:    
    visited=[[0]*N for i in range(N)]
    bfs(babyshark[1],babyshark[2],visited)

print(answer)