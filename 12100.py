N=int(input())
ary_v=[]
ary_h=[]
ans=0
for i in range(N):
    a=list(map(int,input().split()))
    ary_h.append(a)
for i in range(N):
    b=[]
    for j in range(N):
        b.append(ary_h[j][i])
    ary_v.append(b)
def isPossible(ary_h,aryqueue):
    possible_queue=[]
    ary_v=[]
    for i in range(N):
        b=[]
        for j in range(N):
            b.append(ary_h[j][i])
        ary_v.append(b)
    #print(ary_v)
    for i in range(N):
        while 0 in ary_h[i]:
            ary_h[i].pop(ary_h[i].index(0))
        for j in range(0,len(ary_h[i])-1):
            if ary_h[i][j]==ary_h[i][j+1] and ary_h[i][j]!=0:
                print('걸림')
                possible_queue.append(0)#0 -> 좌우
                break

    for i in range(N):
        while 0 in ary_v[i]:
            ary_v[i].pop(ary_v[i].index(0))
        for j in range(0,len(ary_v[i])-1):
            if ary_v[i][j]==ary_v[i][j+1] and ary_v[i][j]!=0:
                possible_queue.append(1)#1 -> 상하
                break    
    print(possible_queue)
    if 0 in possible_queue:
        temp_ary=[]
        for i in range(N):#좌
            temp=[]
            flag=0
            j=0
            while 0 in ary_h[i]:
                ary_h[i].pop(ary_h[i].index(0))
            while j<len(ary_h[i])-1:
                if ary_h[i][j]==ary_h[i][j+1] and ary_h[i][j]!=0 and flag==0:
                    temp.append(ary_h[i][j]*2)
                    j+=1
                    flag=1
                elif ary_h[i][j]!=0:
                    temp.append(ary_h[i][j])
                j+=1    
            while len(temp)<N:
                temp.append(0)
            temp_ary.append(temp)
        aryqueue.append(temp_ary)

        temp_ary=[]
        right=[]
        for i in range(N):
            temp=[]
            for j in range(N-1,-1,-1):
                temp.append(ary_h[i][j])
            right.append(temp)
        ary_h=right
        for i in range(N):#우
            temp=[]
            flag=0
            j=0
            while 0 in ary_h[i]:
                ary_h[i].pop(ary_h[i].index(0))
            while j<len(ary_h[i])-1:
                if ary_h[i][j]==ary_h[i][j+1] and ary_h[i][j]!=0 and flag==0:
                    temp.append(ary_h[i][j]*2)
                    j+=1
                    flag=1
                elif ary_h[i][j]!=0:
                    temp.append(ary_h[i][j])
                j+=1    
            while len(temp)<N:
                temp.append(0)
            temp_ary.append(temp)
        aryqueue.append(temp_ary)

    if 1 in possible_queue:

        temp_ary=[]
        for i in range(N):#상
            temp=[]
            flag=0
            j=0
            while 0 in ary_v[i]:
                ary_v[i].pop(ary_v[i].index(0))
            while j<len(ary_v[i])-1:
                if ary_v[i][j]==ary_v[i][j+1] and ary_v[i][j]!=0 and flag==0:
                    temp.append(ary_v[i][j]*2)
                    j+=1
                    flag=1
                elif ary_v[i][j]!=0:
                    temp.append(ary_v[i][j])
                j+=1    
            while len(temp)<N:
                temp.append(0)
            temp_ary.append(temp)
        aryqueue.append(temp_ary)


        temp_ary=[]
        down=[]
        for i in range(N):
            temp=[]
            for j in range(N-1,-1,-1):
                temp.append(ary_h[i][j])
            down.append(temp)
        ary_v=down
        for i in range(N):#하
            temp=[]
            flag=0
            j=0
            while 0 in ary_v[i]:
                ary_v[i].pop(ary_v[i].index(0))
            while j<len(ary_v[i])-1:
                if ary_h[i][j]==ary_h[i][j+1] and ary_h[i][j]!=0 and flag==0:
                    temp.append(ary_h[i][j]*2)
                    j+=1
                    flag=1
                elif ary_h[i][j]!=0:
                    temp.append(ary_h[i][j])
                j+=1    
            while len(temp)<N:
                temp.append(0)
            temp_ary.append(temp)
        aryqueue.append(temp_ary)

   # print(aryqueue)
    return aryqueue

cnt=0
aryqueue=[ary_h]
candidate=0
while cnt<5 and len(aryqueue)>0:
    cnt+=1
    isPossible(aryqueue.pop(),aryqueue)

#print(candidate)



