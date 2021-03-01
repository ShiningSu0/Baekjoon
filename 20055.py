N,K=map(int,input().split())
robot=[0]*(2*N)
belt=list(map(int,input().split()))
cnt=0
ans=0
while True:
    cnt+=1
    ans+=1
    if 2*N-cnt<0:
        cnt=1
    pivot=2*N-cnt
    
    cumul=0
    #robot[(pivot+N-1)%(2*N)]=0
    #print(1,belt,robot)
    for i in range(1,N-1):
      #  print(i,robot)
        temp=(pivot+i)%(2*N)
        if robot[temp]==1 and robot[(temp+1)%(2*N)]==0 and belt[(temp+1)%(2*N)]>=1:
            robot[temp]=0                
            robot[(temp+1)%(2*N)]=1
            belt[(temp+1)%(2*N)]-=1
    
    robot[(pivot+N-1)%(2*N)]=0
    #print(2,belt,robot)        
    if robot[pivot]==0 and belt[pivot]>0:
        belt[pivot]-=1
        robot[pivot]=1
    for i in range(2*N):
        if belt[i]<=0:
            cumul+=1
    #print(3,belt,robot)
    if cumul>=K:
        print(ans)
        break