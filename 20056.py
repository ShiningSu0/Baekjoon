N,M,K=map(int,input().split())
from copy import deepcopy
## 못풂
fireball=[]
for i in range(M):
    a=list(map(int,input().split()))#[r,c,m,s,d]
    a[0]=a[0]-1
    a[1]=a[1]-1
    fireball.append(a)
direction_r=[-1,-1,0,1,1,1,0,-1]
direction_c=[0,1,1,1,0,-1,-1,-1]
ary=[]
for i in range(N):
    a=[]
    for j in range(N):
        a.append([])
    ary.append(a)
cnt=0
while cnt<K:
    ary=[]
    for i in range(N):
        a=[]
        for j in range(N):
            a.append([])
        ary.append(a)
    cnt+=1
    while fireball:
        i=fireball.pop(0)
        print(i[0]+i[3]*direction_r[i[4]],i[1]+i[3]*direction_c[i[4]])
        #if 0<= i[0]+i[3]*direction_r[i[4]]<N and 0<= i[1]+i[3]*direction_c[i[4]]<N:
        new_row=i[0]+i[3]*direction_r[i[4]]%N
        new_col=i[1]+i[3]*direction_c[i[4]]%N
        if new_row<0:
            while new_row<0:
                new_row+=N
        elif new_row>=N:
            while new_row>=N:
                new_row-=N

        if new_col<0:
            while new_col<0:
                new_col+=N
        elif new_col>=N:
            while new_col>=N:
                new_col-=N

        ary[new_row][new_col].append(i)

    for i in range(N):
        for j in range(N):
            di=True
            if len(ary[i][j])==1:
                fireball.append(ary[i][j])
            elif len(ary[i][j])>1:
                r,c,m,s=i,j,0,0
                for k in range(len(ary[i][j])):
                    m+=ary[i][j][k][2]
                    s+=ary[i][j][k][3]
                    if k>=1 and ary[i][j][k][4]%2!=ary[i][j][k-1][4]%2:
                        di=False 
                if int(m/5)<1:
                    continue
#                    ary[i][j]=[]
                else:
                    if di:#모두 방향 동일
                        fireball.append([r,c,int(m/5),int(s//len(ary[i][j])),0])
                        fireball.append([r,c,int(m/5),int(s//len(ary[i][j])),2])
                        fireball.append([r,c,int(m/5),int(s//len(ary[i][j])),4])
                        fireball.append([r,c,int(m/5),int(s//len(ary[i][j])),6])
                        
                    else:
                        fireball.append([r,c,int(m/5),int(s//len(ary[i][j])),1])
                        fireball.append([r,c,int(m/5),int(s//len(ary[i][j])),3])
                        fireball.append([r,c,int(m/5),int(s//len(ary[i][j])),5])
                        fireball.append([r,c,int(m/5),int(s//len(ary[i][j])),7])
    maps=deepcopy(ary)
    if cnt==K:
        mass=0
        for i in range(N):
            for j in range(N):
                for k in range(len(maps[i][j])):
                    mass+=maps[i][j][k][2]
        print(mass)
        print(fireball)

print(ary)